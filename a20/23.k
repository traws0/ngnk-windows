#!../k
n:#a:-1+.'*0:"i/23"
l:@[&n;a;:;(1_a),*a]      /linked list
f:{d:*(n!x-1 2 3 4)^u,v,w:l v:l u:l x
   *l[x,w,d]:l w,d,x}
100 f/*a;.,/$1+1_(l@)\0

/slow
n:1000000
a:@[!n;!#a;:;a]
l:@[&n;a;:;(1_a),*a]
10000000 f/*a;*/1+(*l;l@*l)
