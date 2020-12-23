#!../k
n:`i$#a:`i$-1+.'*0:"i/23"
l:@[n#0i;a;:;(1_a),*a]      /linked list
f:{u:2(l@)\l x              /x:current cup, u:the 3 cups after x
   l[x]:l[*|u]              /bypass them
   d:(|/u=)(n!-1i+)/n!x-1i  /d:destination cup
   l[*|u]:l[d];l[d]:*u      /insert u after d
   l[x]}                    /return new current cup
100 f/*a;.,/$1i+1_(l@)\0i   /part1

n:1000000i
a:@[`i$!n;!#a;:;a]          /generate ints up to n and put a at the beginning
l:@[n#0i;a;:;(1_a),*a]
10000000 f/*a;*/1+(*l;l@*l) /part2
