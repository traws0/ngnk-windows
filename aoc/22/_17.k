#!../../k
X:-61+*0:"i/17" / "<":-1 ">":1
/X:-61+">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>"

/rocks
R:((0 0 0 0;0 1 2 3)         /-
   (-2 -1 -1 -1 0;1 0 1 2 1) /+
   (-2 -1 0 0 0;2 2 0 1 2)   /J
   (-3 -2 -1 0;0 0 0 0)      /I
   (-1 -1 0 0;0 1 0 1))      /O

i:0 /index in X
a:7#'&4 999 /sliding window over the infinite grid
t:0;p:0 2 /falling rock type and position
h:4

pr:{`0:(,""),".#@"a.[;;:;2]/+p+R t} /print
m:{p+:x*c:&/~a./:+R[t]+p+x;c} /m[(di;dj)]: move by di,dj if possible; return true iff moved
M:{m 0,X i;i+:1;i*:i<#X;m 1 0}(::)/ /move current piece to the bottom; arg and result are index in X
F:{M[]
 .[`a;;:;1]'+p+R t
 t+:1;t*:t<#R
 p::(-&/*R t),2
 e:+/&\~|/'a
 E:4+*p
 h+:E-e
 a::(#a)#(E#,&7),e_a
 0}

2022 F/0;
h-/&\~|/'a
