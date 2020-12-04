# Brainfuck part 1

Written for https://copy.sh/brainfuck/.

Code is also available
[here](https://fatiherikli.github.io/brainfuck-visualizer/#bWFpbigpCis+Wy1dCgppbml0IHdpZHRoIEAgKGVicCBhZGQgMSkKPisKPj4rWyw8KysrK1s+LS0tLS0tLS08LV08Kz4+XTw8LQpbPF0KCmluaXQgcG9zeCBAIChlYnAgYWRkIDIpCj4+KwpbPF0KCmluaXQgdHJlZXMgQCAoZWJwIGFkZCAzKQo+Pj4rCls8XQoKCgojIyMgTUFJTiBMT09QICMjIwo8Wz4KCgoKcmV0dXJuIHZhbHVlIGZvciBmbiBjYWxsCj4+Pj4rCls8XQoKY3Agd2lkdGggdG8gKGVicCBhZGQgNCkKPgo+Pj4+Wy1dPlstXTw8PDw8Cls+Pj4+Kz4rPDw8PDwtXT4+Pj4+Wy08PDw8PCs+Pj4+Pl08Cls8XQoKY3AgcG9zeCB0byAoZWJwIGFkZCA1KQo+Pgo+Pj4+Wy1dPlstXTw8PDw8Cls+Pj4+Kz4rPDw8PDwtXT4+Pj4+Wy08PDw8PCs+Pj4+Pl08Cls8XQoKCgpjaGFuZ2Vwb3MocG9zeCB3aWR0aCkKPj4+Pj4+PlstXQoKKGVicCBzdWIgMSkgPSAoZWJwIHN1YiAxKSBhZGQgMwo8CisrKwpbPl0KCmNwIChlYnAgc3ViIDEpIGFkZCAxIHRvIChlYnAgYWRkIDEpCjwKPj5bLV0+Wy1dPDw8Cls+Pis+Kzw8PC1dPj4+Wy08PDwrPj4+XTwrCls8XQoKY3AgKGVicCBzdWIgMikgdG8gKGVicCBhZGQgMikKPDwKPj4+PlstXT5bLV08PDw8PApbPj4+Pis+Kzw8PDw8LV0+Pj4+PlstPDw8PDwrPj4+Pj5dPApbPF0KCmNtcCAoZWJwIGFkZCAxKSBndCAoZWJwIGFkZCAyKQo+CltbLT5dPFs8XT5dPDw8Cls8XQoKaWYgKGVicCBhZGQgMSkKKGVicCBzdWIgMSkgPSAoZWJwIHN1YiAxKSBzdWIgKGVicCBzdWIgMikgYWRkIDEKZW5kaWYKPgpbPDw8Wy0+LTxdPis+PlstXV08Cls8XQoKcmV0IChlYnAgc3ViIDEpCjwKPDxbLV0+PgpbLTw8Kz4+XQo8Wy1dPApbPF0KCgoKcG9zeCA9IGNoYW5nZXBvcyhwb3N4IHdpZHRoKQo+PlstXQo+PlstPDwrPj5dPApbPF0KCnJldHVybiB2YWx1ZSBmb3IgZm4gY2FsbAo+Pj4+KwpbPF0KCmNwIHBvc3ggdG8gKGVicCBhZGQgNCkKPj4KPj4+Wy1dPlstXTw8PDwKWz4+Pis+Kzw8PDwtXT4+Pj5bLTw8PDwrPj4+Pl08Cls8XQoKCgpjaGVja3RyZWUocG9zeCkKPj4+Pj4+Wy1dCgooZWJwIGFkZCAxKSA9ICooaW5wdXQgYWRkIChlYnAgc3ViIDEpKQo+Kwo8PApbLT4+LDw8XSsKWz5dCgpjbXAgKGVicCBhZGQgMSkgbmVxIDQ2Cj4KKys+KysrKysrWy08LS0tLS0tLS0+XTw8Cls8XQoKaWYgKGVicCBhZGQgMSkgdGhlbgooZWJwIHN1YiAxKSA9IDIgCmVuZGlmCj4KW1stXTw8Wy1dKys+Pl08Cls8XQoKcmVhZCB0byAnICcgb3IgJ2JhbmcnCj4rCls+LAogICAgPisrKytbPC0tLS0tLS0tPi1dPDwtPls8Kz5bLT4rPF1dPlstPCs+XTwKICAgIC08LTw8Kys+Pj5bPCs8PC0tPj4+Wy0+KzxdXT5bLTwrPl08CjxdPApbPF0KCnJldCAoZWJwIHN1YiAxKQo8CjxbLV0+ClstPCs+XQo8Cls8XQoKCgppZiBjaGVja3RyZWUocG9zeCkgZ3QgMSB0aGVuCnRyZWVzID0gdHJlZXMgYWRkIDEKZW5kaWYKPj4+Cj4tCiAgICBbCiAgICAgICAgLTwrPls8LT5bLT4rPF1dPlstPCs+XTwKICAgICAgICAtPDw8PDwtPj4+Pj5bPDw8PDwrPj4+Pj5bLT4rPF1dPlstPCs+XTwKICAgICAgICAtPCs8PDw8LT4+Pj4+WzwtPDw8PCs+Pj4+PlstPis8XV0+Wy08Kz5dPAogICAgWy1dXQo8Cls8XQoKCgo8XT4rCiMjIyBFTkQgTUFJTiBMT09QICMjIwoKCgpwdXRzKHRyZWVzIHN1YiAxIGFkZCA0OCkKPj4+Ci0KPisrKysrK1s8KysrKysrKys+LV08Ci4KWzxdCg==).

Input is as copied from https://adventofcode.com/2020/day/3,
lines are separated by spaces,
must be terminated with a `!`.

For example:
```
..##....... #...#...#.. .#....#..#. ..#.#...#.# .#...##..#. ..#.##..... .#.#.#....# .#........# #.##...#... #...##....# .#..#...#.#!
```

From the original example produces 7 as expected.

Note that values greater than 9 will print as a different ASCII character with a value of `n + 48`.

## Code format

The source code is loosely based on x86 calling convention.

The location of EBP is represented by a cell with a value of 0.
This allows for the `[<]` sequence to move the pointer to EBP.

To maintain this behaviour, all allocated cells must have a non-zero value after being initialised, except during an operation.

As a result, some values, such as the number of trees, are stored as 1 greater than the actual value.

Since there are no registers available, what would normally be handled by a register, such as the return value of a function, is handled on the stack.

### Function Prologue

To call a function:

 - push 1 (allocate memory for the return value)
 - push function parameters
 - move the pointer to the cell after local variables

This creates the new stack frame with the pointer at EBP.

For example:

```brainfuck
return value for fn call
>>>>+
[<]

cp posx to (ebp add 4)
>>
>>>[-]>[-]<<<<
[>>>+>+<<<<-]>>>>[-<<<<+>>>>]<
[<]



checktree(posx)
>>>>>>[-]
```

### Function Body

All operations within a function must return to EBP using [<]

Local variables are pushed after EBP.

For example:

```brainfuck
(ebp add 1) = *(input add (ebp sub 1))
>+
<<
[->>,<<]+
[>]

cmp (ebp add 1) neq 46
>
++>++++++[-<-------->]<<
[<]

if (ebp add 1) then
(ebp sub 1) = 2 
endif
>
[[-]<<[-]++>>]<
[<]

read to ' ' or 'bang'
>+
[>,
    >++++[<-------->-]<<->[<+>[->+<]]>[-<+>]<
    -<-<<++>>>[<+<<-->>>[->+<]]>[-<+>]<
<]<
[<]
```

### Function Epilogue

The return instruction sets the value of the cell which was allocated for the return value (the cell pushed before function parameters).

All function parameter cells are zeroed.

The pointer is returned to the EBP of the calling function.

For example:

```brainfuck
ret (ebp sub 1)
<
<[-]>
[-<+>]
<
[<]
```

### Note

Due to a minor oversight on how the main loop would terminate, the `main()` function has 1 parameter, set to 1 if the loop should continue and 0 otherwise.

This was done to avoid restructuring the local variables of `main()`.

### Improvements

The use of `[>]` to navigate to the cell in which to push data would have made it much easier to modify code and add or remove local variables.

