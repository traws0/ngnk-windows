#!../../k
x:0:"i/19"

(r;p):(0,*>~#'x)_x /rules,emptyline,parts
(rn;rl):+("{"\-1_)'r /rule names,rule lists
r:(`$rn)!+'{:[1=#x;-1 -1 0,`$x;("xmas"?**x;x[0;1]-"=";`I$2_*x),`$x 1]}''":"\''","\'rl
p:`I$(2_'","\-1_1_)'1_p
f:{(v;c;i;k):r y;k@*&c=-1|1&x[v]-i} /apply rule (x:part;y:nameOfRule) (v:xmas variable;c:comparison(+1|-1),i:integer;k:nextRule)
+/(+/'p)*`A={(~|/`A`R=)f[x]/`in}'p /1

V:*/0|1--/ /volume
E:|/>/ /empty?
X:(|;&)@' /intersection
g:{:[E[x]|`R~y;:();`A~y;:,x;]
   (v;c;i;k):r[y;;z]
   X: :[0>v;:o[x;k;0]
        0>c;(.[x;1,v;:;i-1];.[x;0,v;:;i])
            (.[x;0,v;:;i+1];.[x;1,v;:;i])]
   o[X 0;k;0],o[X 1;y;1+z]}
r:g[4#'1 4000;`in;0]
+/V'r /2
