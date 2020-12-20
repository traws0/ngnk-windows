#!../k
(i;t):+0 1_/:1_'(&~#'a)_a:(,""),0:"i/20"
i:(.-1_5_*)'i;t=:"#";m:_%#t;n:#*t /i:ids,t:tiles,m:matrix size(in tiles),n:tile size(in pixels)
o4:3(+|:)\;o8:{,/+o4'(x;+x)} /orientations
b:{2/+*'o8 x}'t /tile borders as ints
e:1=#'=,/b /dict: tile border -> is edge
*/i@&4=+/e@+b /part1

row:+(m-1){(j;O):x;j:*^[;j]@&|/u:b[j][8!4+O]=+b;O:*&u@'j;(j;O)}\
(vb;vo):row j,*&e b@j:*&4=+/e@+b                     /first column: tile borders and orientations
(Rb;Ro):+row'vb{$[e b[x][8!y+2];x,8!y+2;x,8!y-2]}'vo /whole matrix: tile borders and orientations
R:((|+:;+:)@(2#m)#2!+/!2#m)@'' Ro{o8[y][x]}''t Rb /".#"@,/,'/' 9,''' 9,''R /combined matrix
R:,/,'/'(1_-1_1_'-1_')''R /trim tile borders
M:("                  # " /monster
   "#    ##    ##    ###"
   " #  #  #  #  #  #   ")="#"
Mj:!Mw:#*M;Mi:!Mh:#M /width,height and indices
Mn:~(M;+M) /negated or negated-flipped
w2:{,/(!#x),''&'x} /2d where
p:w2@|/(M;|M;|'M;||'M){x~x&y}/:/:\: +'Mh'Mw'' R;{R[x+Mi;y+Mj]*:Mn 0;}/'p;
p:w2@|/(M;|M;|'M;||'M){x~x&y}/:/:\:++'Mh'Mw''+R;{R[x+Mj;y+Mi]*:Mn 1;}/'p;
`l$+//R
