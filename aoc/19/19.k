#!../../k
\l l.k
f:*|I[`I$","\*0:"i/19"]@ /intcode machine

+/f@!2#50                /part1

s:100                    /square size
d:f 1|:\!:               /x-th diagonal of the grid
ij:-2 0!'(s>+/d@)(2*)/1  /the first diagonal with sum s is between i and j
k:*|{$[-2<-/x;x;s>+/d@m:-2!+/x;(1+m),*|x;(*x),m]}/ij /binary search
10000/i,k-s+i:*&d k      /part2
