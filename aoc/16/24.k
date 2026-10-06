#!../../k
\l ../../l/maths.k
x:0:"i/24"           /input
d,:-d:1,#*x          /directions
a:,/x                /flattened
w:#a                 /infinity
i:&~"#"=a            /walkable
j@:<a j:&~"0">a      /digits
h:d+\:i              /neighbours
g:{{@[x;i;&;1+&/x h]}/[@[(#a)#w;x;:;0]]j}'j /graph
p:+prm@1+!-1+#g      /permutations
&/{+/g[-1_0,x]@'x}'p /part1
&/{+/g[0,x]@'x,0}'p  /part2
