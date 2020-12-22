#!../k
/very slow
a:0:"i/22"
a:`c$.''1 2_'(0,&~#'a)_a

s:{+/x*|1+!#x:,/x} /score
e:&/#:' /game end
s e{@[1_'x;w;,;c w,~w:</c:*'x]}/a /part1

m:() /memory
f:{
 $[~^*m?,x;:(,0;!0);] /repeated position
 m,:,x /remember
 c:*'x;x:1_'x /draw cards
 w:$[&/~c>#'x;</#'g@c#'x;</c] /winner
 @[x;w;,;c w,~w]}
g:{M:m;m::();r:e f/x;m::M;r}
s g a

