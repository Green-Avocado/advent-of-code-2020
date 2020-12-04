main()
[-]

init width @ (ebp add 1)
>+
>>+[,<++++[>--------<-]<+>>]<<-
[<]

init posx @ (ebp add 2)
>>+
[<]

init trees @ (ebp add 3)
>>>+
[<]


### MAIN LOOP ###
+[-

return value for fn call
>>>>+
[<]

cp width to (ebp add 4)
>
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]

cp posx to (ebp add 5)
>>
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]



changepos(posx width)
>>>>>>>[-]

(ebp sub 1) = (ebp sub 1) add 3
<
+++
[>]

cp (ebp sub 1) add 1 to (ebp add 1)
<
>>[-]>[-]<<<
[>>+>+<<<-]>>>[-<<<+>>>]<+
[<]

cp (ebp sub 2) to (ebp add 2)
<<
>>>>[-]>[-]<<<<<
[>>>>+>+<<<<<-]>>>>>[-<<<<<+>>>>>]<
[<]

cmp (ebp add 1) gt (ebp add 2)
>
[[->]<[<]>]<<<
[<]

if (ebp add 1)
(ebp sub 1) = (ebp sub 1) sub (ebp sub 2) add 1
endif
>
[<<<[->-<]>+>>[-]]<
[<]

ret (ebp sub 1)
<
<<[-]>>
[-<<+>>]
<[-]<
[<]



posx = changepos(posx width)
>>[-]
>>[-<<+>>]<
[<]

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

read to ' '
>+
[,>++++[<-------->-]<]<
[<]

ret (ebp sub 1)
<
<[-]>
[-<+>]
<
[<]


if checktree(posx) gt 1 then
trees = trees add 1
endif
>>>
>-[[-]<+>]<
[<]


+]-
### END MAIN LOOP ###
