# awk part 1

Since the ID is `row * 8 + col`, we need to find the greatest row number and break ties using the greatest column number.

For this approach, it can be useful to think of the tickets as a binary number.

## Rows

A `B` tells us to keep the higher seat numbers, while `F` tells us to keep lower ones.

To convert this to a binary number, a `B` is equivalent to a `1` and `F` is equivalent to a `0`.

The greatest row number will have the greatest number of leading `B`s.

We can filter the input to list only those with a leading `B` using `awk`, piping it into `wc -l` to count lines only:

```
$ awk '/^B/' input | wc -l
354
```

This list is still quite large, so we can also filter for those with a leading `BB`:

```
$ awk '/^BB/' input
99
```

We can keep adding `B`s until we get no matching results:

```
$ awk '/^BBB/' input
0
```

This tells us that the ticket with the greatest id has 2 leading `B`s, followed by at least one `F`.
So we replace the last `B` in the above command with an `F` and keep adding `B`s:

```
$ awk '/^BBFB/' input
35
$ awk '/^BBFBB/' input
3
$ awk '/^BBFBBB/' input
0
```

This process can be repeated until we have all 7 characters specifying row:

```
$ awk '/^BBFBBFB/' input
0
$ awk '/^BBFBBFF/' input
3
```

Now we know that the ticket with start with `BBFBBFF`.
Here are the possible tickets:

```
$ awk '/^BBFBBFF/' input        
BBFBBFFLLL
BBFBBFFLRL
BBFBBFFLLR
```

## Columns

Here we will use a similar technique.

In this case, `L` is equivalent to a `0` in binary, and `R` is equivalent to a `1`.

Since we only have 3 remaining candidates, the use of `awk` is unnecessary here.
However, if it were necessary, as would be the case if there were more possible columns, the same process from above could be repeated, substituting `B` for `R` and `L` for `F`.


```
$ awk '/^BBFBBFFR/' input | wc -l
0
$ awk '/^BBFBBFFLR/' input | wc -l
1
```

Once we reach an output of `1`, we know we've found the ticket with the greatest id:

```
$ awk '/^BBFBBFFLR/' input
BBFBBFFLRL
```

## Convert to numeric id

The row and column numbers can be calculated as if we were converting binary to decimal:

```
row = 64 + 32 + 0 + 8 + 4 + 0 + 0 = 108
col = 0 + 2 + 0 = 2
```

This gives us our highest id:

```
108 * 8 + 2 = 866
```

# awk part 2

