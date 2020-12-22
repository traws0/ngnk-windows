#!../k
/very slow
a:0:"i/22"
a:`c$.''1 2_'(0,&~#'a)_a

N:10000000
a:a,'`c$&'N-n:#'a

r:{x+!y-x}                    /range
d:{a@'r/'x}                   /data slices between pairs of ptrs
e:|/-/'                       /game end condition
s:{+/x*|1+!#x:,/d x}          /score
p:{.[`a;y,,x[y;1]+!#z;:;z]    /append
   .[x;y,1;+;#z]}
f:{c:a@'*'x;x:1 0+/:x;w:</c
   p[x;w;c w,~w]}
s e f/0,'n /part1

m:() /memory
f:{$[~^*m?,k:d x;:!1 2;m,:,k] /repeated position
 c:a@'*'x;x:1 0+/:x           /draw cards
 w:</$[&/~c>--/'x             /winner
       --/'g a@'(*'x)+!'`l$c  /subgame
       c]
 p[x;w;c w,~w]}
g:{A:a;n:#'x;a::x,'`c$&'N-n;M:m;m::();r:e f/0,'n;m::M;a::A;r}
s e f/0,'n
