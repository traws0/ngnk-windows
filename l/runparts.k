#!../k
argv:`argv[]
skip:$[3>#argv;!0;`I$","\argv 2]
k:{$[82<#x:`k x;(80#x),"..";x]}
a@:<`I$-2_'a:(>/"/9"<\:*:')#0:,"."
u:{(|6$|$-1000!500+x),"ms"}
OK:1
t:-`t[]
{1@-2_x;e:.[1::;,"o/",-2_x;""];t:-`t[];r:`x(,x;"");t+:`t[];OK&:ok:e~r
 1$[ok;u[t],"\n";"FAIL\n expected:",k[e],"\n   actual:",k[r],"\n"]}'a^{x,".k"}'$skip;
t+:`t[]
1"      ",u[t],$[#skip;" (skipped: ",`k[skip],")";""],"\n";
`exit@~OK
