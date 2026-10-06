#!k
$[x;."\\cd ",c:*x;]
k:{$[82<#x:`k x;(80#x),"..";x]} /truncated `k@
d:>/"/9"<\: /is digit?
t@:<t:(^:)_`I$-2_'({".k"~-2#x}')#0:,"." /all-digit k files without the .k extension
$[1<#x;t@:&~(`I$1_x)'t;]; /filter those between argv[1] and argv[2]
`exit@|/{x:-2#$100+x
         e:.[1::;,"o/",x;""] /expected
         a:`x(,x,".k";"")    /actual
         $[e~a;;`0:(""
                    "FAIL ",c,"/",x,".k"
                    " expected:",k e
                    "   actual:",k a)]
         e~a}'t
