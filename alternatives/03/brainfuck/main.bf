main()

init width = (rbp add 1)
>+
>>+[,<++++[>--------<-]<+>>]<<-
[<]

init posx
>>+
[<]

init trees
>>>+
[<]

return value for fn call
>>>>+
[<]

cp width to (rbp add 4)
>
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]

cp posx to (rbp add 5)
>>
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]



changepos()
>>>>>>>[-]

(rbp sub 1) = (rbp sub 1) add 3
<
+++
[>]

cp (rbp sub 1) to (rbp add 1)
<
>>[-]>[-]<<<
[>>+>+<<<-]>>>[-<<<+>>>]<
[<]

cp (rbp sub 2) to (rbp add 2)
<<
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]

cmp (rbp add 1) leq (rbp add 2)
>
[[->]<[<]>]<<<
[<]

if (rbp add 1)
(rbp sub 1) = (rbp sub 1) sub (rbp sub 2)
endif
>
[<<<[->-<]>>>[-]]<
[<]

ret (rbp sub 1)
<
<<[-]>>
[-<<+>>]
<[-]<
[<]



posx = changepos()
>>[-]
>>[-<<+>>]<
[<]

return value for fn call
>>>>+
[<]

cp posx to (rbp add 4)
>>
>>>[-]>[-]<<<<
[>>>+>+<<<<-]>>>>[-<<<<+>>>>]<
[<]

