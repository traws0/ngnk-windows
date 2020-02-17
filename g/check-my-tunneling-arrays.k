/https://codegolf.stackexchange.com/questions/171681/check-my-tunneling-arrays/171719#171719
f:{*/(x<0)|(x<#x)&(~x=!#x)&x=x?x?x}
\l 0.k
t[-1 -1 -1 6 -1 -1 3 -1 -1;1]
t[1 0                     ;1]
t[0 1                     ;0]
t[4 2 1 -1 0 -1           ;1]
t[2 3 0 1                 ;1]
t[1 2 0                   ;0]
t[-1 2 -1                 ;0]
t[!0                      ;1]
t[-1 -2 -3                ;1]
t[1 0 3                   ;0]
t[,1                      ;0]
