#!../k
skip:15 22 23
k:{$[82<#x:`k x;(80#x),"..";x]}
a@:<a:{(".k"~-2#x)&4=#x}#0:,"."
u:{(|6$|$-1000!500+x),"ms"}
OK:1
t:-`t[]
{1(2#x)," ";e:.[1::;,"o/",2#x;""];t:-`t[];r:`x(,x;"");t+:`t[];OK&:ok:e~r
 1$[ok;"ok ",u[t],"\n";"FAIL\n expected:",k[e],"\n   actual:",k[r],"\n"]}'a^{x,".k"}'$skip;
t+:`t[]
1"      ",u[t],$[#skip;" (skipped: ",`k[skip],")";""],"\n";
`exit@~OK
