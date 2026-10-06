#!../../k
x:0:"i/14"
r@:<r:,/'" -> "\'2_x /rules
e@:<e:?,//r          /elements
E:+e@!2##e           /pairs of elements
t:((2##E)#0).[;;+;1]/E?r@\:((0 2;2 1);0 1) /transition matrix
v:+/E~\:/:2':*x      /initial vector
c:e=**x              /correction for first element
d:{(|/x)-&/x}        /max-min difference
m:(+/*)\:            /matrix multiplication
f:d@c+/(2##e)#m[t]/[;v]@
f 10                 /part1
f 40                 /part2
