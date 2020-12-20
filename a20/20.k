#!../k
(i;t):{((.-1_5_*)'x;"#"=y)}/+0 1_/:1_'(&~#'a)_a:(,""),0:"i/20" /ids,tiles
k:_%#t;n:#*t                 /k:matrix size(in tiles),n:tile size(in pixels)
o4:3(+|:)\;o8:{,/+o4'(x;+x)} /orientations
b:{2/+*'o8 x}'t              /tile borders as ints
e:1=#'=,/b                   /dict: tile border -> is edge
*/i@&4=+/e@+b                /part1

row:+(k-1){(j;O):x;j:*^[;j]@&|/u:+b[j;8!4+O]=b;O:*&u@'j;(j;O)}\
c:row j,*&e b@j:*&4=+/e@+b                   /first column: tile borders and orientations
r:+row'{$[e b[x][8!y+2];x,8!y+2;x,8!y-2]}'/c /whole matrix: tile borders and orientations
r:((|+:;+:)@(2#k)#2!+/!2#k)@''{o8[t x]y}''/r /".#"@,/,'/' 9,''' 9,''r /orient tiles
r:,/,'/'(1_-1_1_'-1_')''r                    /trim tile borders, glue tiles together
m:("                  # "                    /monster
   "#    ##    ##    ###"
   " #  #  #  #  #  #   ")="#"
mij:!'(h:#m;w:#*m);M:~(m;+m);W:{,/(!#x),''&'x} /W:2d where
f:{p:W@|/(m;|m;|'m;||'m){x~x&y}/:/:\:a(+:)/+'h'w''a(+:)/r;{r[x+mij a;y+mij@~a]*:M a;}/'p;}
a:0;f[];a:1;f[];`l$+//r
