#!../k
/slow
n:`i$#a:`i$-1+.'*0:"i/23"
l:@[n#0i;a;:;(1_a),*a]      /linked list
f:{d:*(n!x-1 2 3 4i)^u,v,w:l v:l u:l x
   *l[x,w,d]:l w,d,x}
100 f/*a;.,/$1i+1_(l@)\0i   /part1

n:1000000i
a:@[`i$!n;!#a;:;a]          /generate ints up to n and put a at the beginning
l:@[n#0i;a;:;(1_a),*a]
10000000 f/*a;*/1+(*l;l@*l) /part2
