#!../../k
p:" "\'0:"i/12"
k:{$["cpy"~*x;x[2],"::",x[1]
     "inc"~*x;x[1],"+:1"
     "dec"~*x;x[1],"-:1"
     "jnz"~*x;":$[",x[1],";",($y+`I$x 2),";",($1+y),"]"]}
j@:<j:?0,/p{$["jnz"~*x;y+1,`I$x 2;!0]}'!#p /jnz targets
h:j!.'{"{",(";"/x),"}"}'(j_p k'!#p),','$1_j,#p /program fragments
a:b:c:d:0  ;((#p)>){h[x]0}/0;a /part1
a:b:d:0;c:1;((#p)>){h[x]0}/0;a /part2
