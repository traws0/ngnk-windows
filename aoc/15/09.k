#!../../k
\l ../../l/maths.k
(a;b;d):```I$'+{(" "\x)0 2 4}'0:"i/09"
n:#l:?a,b /l:locations
g:@[&n*n;n/l?(a,b;b,a);:;d,d] /graph(flat)
r:+/g@2 n/':prm n
&/r /part1
|/r /part2
