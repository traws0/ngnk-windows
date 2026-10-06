#!../../k
/only part1, slow
x:".ABCD"?,/0:"i/23"
T:"x"=("#############" /template
       "#xx.x.x.x.xx#"
       "###x#x#x#x###"
       "  #x#x#x#x#"
       "  #########")
c:0 1 10 100 1000 /cost
x@:&,/T;p:+&T
d:{$[</6<x,y;+/a|-a:-/p@x,y;0N]}/:\:/2#,!#p /distances
m:{$[</6<x,y;(&0>(p[x;1]-*|+7#p)*(p[y;1]-*|+7#p)),$[y>10;y-4;!0],y;!0]}/:\:/2#,!#p /intermediate nodes

h0:{$[~a:x y;();|/x@m[y; 6+a];();~a=x@10+a;();,(5/@[x;y, 6+a;:;0,a];c[a]*d[y; 6+a])]}
h1:{$[~a:x y;();|/x@m[y;10+a];();   x@10+a;();,(5/@[x;y,10+a;:;0,a];c[a]*d[y;10+a])]}
h2:{$[~a:x y;();(y>10)&a=y-10;();(y<11)&(y>6)&(a=y-6)&a=x[y+4];();|/x@z,-1_m[z;y];();,(5/@[x;y,z;:;0,a];c[a]*d[z;y])]}
h:{x:(15#5)\x;(,/h0[x]'!7),(,/h1[x]'!7),,/,/(7+!8)h2[x]/:\:!7} /child states

b:(,5/x)!,0 /current best
t:5/0 0 0 0 0 0 0 1 2 3 4 1 2 3 4 /target state
v:!0 /visited
i:0 /counter
{u:*&{x=&/x}b
 $[u~t;[ \`v,b u;:b u];]
 $[1000=i+:1;[i::0; \,(u;b u;#b)];]
 v,:u
 cd:h u /children and their distances
 (c;d):$[#cd;+cd;(();!0)]
 i:&^v?c;c@:i;d@:i
 b[c]&:d+b u
 b[u]:999999999
 -1+x}/0

/
for part2 insert
  #D#C#B#A#
  #D#B#A#C#
\
