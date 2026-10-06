#!../../k

/x:values,y:depths
e:{$[^i:*&0&':5=y;(x;y);[x[((-1+#x)&i+1;0|i-2)]+:x i-!2;x[i-1]:0;y[i-1]-:1;(x;y)_'i]]}/ /explode
s:{$[^i:*&9<x;(x;y);(?[x;i+!2;-2!0 1+x i];?[y;i+!2;2#1+y i])]}/ /split
m:{+/x*(+*\3-2\-1+\16 8 4 2 1@y)@'y-1}/ /magnitude

a:(s@e/)/0 1+,' /add
d:{$[x~*x;0;1+,/o'x]} /depths
x:(,//;d)@\:/:_`j?'0:"i/18" /input
m@a/x /part1
|/(m@a/)'x@+&~=#x /part2
