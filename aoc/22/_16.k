#!../../k
(v;r;h):``I`$+{x:" "\x^",";(x 1;5_-1_x 4;9_x)}'0:"i/16" /valve;rate;neighbours
g:(1;_1e9;0)g|2*=#g:^h?\:v /graph
g:{x(&/+)\:x}/g /shortest paths

i:?(v?`AA),&0<r /keep only "interesting" vertices (AA and those with rate >0)
g.:2#,i
r@:i
n:#i

p2:n(2*)\1
N:p2 n
s:(n;N;31)
a:s#-1
a[0;0;0]:0

/x:current valve, y:remaining valves, z:time
{Y:&y;$[0>z;0;(z*r x)+0|/o'[Y;@[y;;:;0]'Y;(z-1)-g[x]Y]]}[0;0<r;30] /part1
