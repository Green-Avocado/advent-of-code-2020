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

Since all seats are filled except possibly ones at the ends, every split (`B` or `F` and `L` or `R`) should have an even number of people, except at the ends.

We can start by using `awk` to traverse the binary tree with a depth of 1, and pipe it into `wc -l` to count the number of results.

```
$ awk '/^F/' input | wc -l
428
$ awk '/^B/' input | wc -l
354
```

Both are still positive, so we have to traverse another layer:

```
$ awk '/^FF/' input | wc -l
172
$ awk '/^BF/' input | wc -l
255
```

This tells us that there is an odd number of tickets starting with `BF` and also an odd number starting with `BB`.
Our ticket must fall in this category.

Note that the `BB` section is and end section, while `BF` is between `BB` and `FB`.

The odd number in `BB` is likely due to it being located at the rear, so some seats dont exist.
So our ticket must start with `BF`.

From here, we can continue to traverse the binary tree, following the odd path.

```
$ awk '/^BFF/' input | wc -l
127
$ awk '/^BFFF/' input | wc -l
64
$ awk '/^BFFBF/' input | wc -l
31
$ awk '/^BFFBFF/' input | wc -l
15
$ awk '/^BFFBFFF/' input | wc -l
7
```

The same is done to find the column:

```
$ awk '/^BFFBFFFL/' input | wc -l
4
$ awk '/^BFFBFFFRL/' input | wc -l
2
```

Through process of elimination, our ticket must begin with `BFFBFFFRR`.

If we search the input file for this sequence, we find that one of the two remaining possibilities is already taken:

```
$ awk '/^BFFBFFFRR/' input
BFFBFFFRRL
```

Therefore, our ticket must be the other option: `BFFBFFFRRR`.

We can convert this to an id using the same method from part 1:

```
row = 64 + 0 + 0 + 8 + 0 + 0 + 0 = 72
col = 4 + 2 + 1 = 7
```

This gives is our id:

```
id = 72 * 8 + 7 = 583
```

