#!../../k
x:0:"i/05"
e:x?"" /index of empty line
c:(^:)_'(+e#x)1+4*!9 /crate stacks as top-to-bottom strings (including digits)
(m;f;t):0 -1 -1+`I$(+" "\'1_e_x)1 3 5 /(move;from;to)
h:{(x_y;(x#y),z)} /move x items from the beginning of list y to the beginning of list z
g:`0:*'c{[c;m;f;t]@[c;f,t;:;h[m;c f;c t]]}/
g[1;{m}#f;{m}#t] /part1
g[m;f;t]         /part2
