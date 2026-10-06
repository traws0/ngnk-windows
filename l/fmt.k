\d fmt
cls:@[&256;c;:;1+!#c:("0"+!10;".";"<>=^";"+- ";"_,";"bcdeEfFgGnosxX%")]
CLS:`other`digit`dot`align`sign`group`type@cls@
spec:`chr`align`sign`digit`group`dot`digit`type
mtch:`fill`align`sign`width`group`dot`prec`type
lex:{s:((p:1~cls@*x)#,,"<"),(&~=':1=cls@x)_x;p_'|,/'((#s)#'0N 2#((),/:;,:;CLS;{`digit}))@'\:s}

init:{$[`align~x[0;1];((0 1;2#*|x);2_'x);((();"");x)]}
prs0:{{(a;cs):x;$[(spec@y)~cs[0;0];(a,'(y;-1#*'cs);1_'cs);x]}/[i;(#**i:init@x)_!#spec]}
prs:{$[#**|r:prs0@lex@x;`err@"prs: ",`k@r;>/`dot`digit=spec@s@0 1+(s:**r)?`dot;`err@"prs";(mtch@**r)!*|*r]}

DFLT:`fill`align`sign`width`type!(" <-0s")
dflt:{x[`aligndef]:^(!x)?`align
  x[f@w]:(.DFLT)@w:&^(!x)?f:!DFLT
  x[f]:*'x[f:`fill`align`sign`group`dot`type`prec]
  x[f]:.'x[f:`prec];
  x}

D:`c$"0"+!10
fills:{(f;a;l):x;@[(l|#y)#f;(!#y)+-2!0|(l-#y)*"<^>"?a;:;y]}
filln:{(f;l):x;(c#y),fills[(f;">";l-c)](c:^D?*y)_y}
sign:{r:z;s:0N 2#"+- -";$[~x~"-";s[^x;y],r;(("";"-")y),r]}
grp0:{r:z,(c:(-y)!#1_z)#x;r@<<@[&#r;(#r)-(y+1)*1+!c;:;1]}
grp:{(c#z),grp0[x;y]@(c:^D?*z)_z}

A:`c$,/("0"+!10;"A"+!6)
cnv:{_A@(2 8 10 16@2^"bodx"?x)\y}

fmti:{r:sign[x`sign;y<0;cnv[x`type]{x|-x}y]
  r:$[^x`group;r;grp[x`group;4-^"box"?x`type;r]]
  (f;a):$["0"~*x`width;"0=";(x`fill),">"]
  a:$[x`aligndef;a;x`align]
  $["="~a;:filln[f,.x`width]r;fills[(f,a),.x`width]r]}
fmts:{fills[(x`fill`align),.x`width;y]}
fmt:{f:$[`c~_t:@y;fmts;`i~t;fmti;:`err@"nyi"];f[dflt@prs@x;y]}

e0:{$[`c~@*x;x;`k x]}:
/e1:e0@.;
r:{<\~^"{}"?x}_
lvl:{s:+\(0 -1 1 0@&#'b)@g:<,/b:4#x;s@&(#s)#1 0}
m:{$[*|r:lvl@b:&'"{}"=\:x;`err@"mismatched";];!/+(@/1<:\,/b)0N 2#,/.=r}
rl:{op^:op@&|':(~^?/1(-1+)\d@op)&(~^?/1(1+)\op:@/1<:\!d:m x);(op;d@op)}
sp:{1_'(,/0,(@/1<:\,/r)@&~lvl@r:rl x)_x}
spl:{$[|/^c:0,*|&":"=x;:.x;];(v;f):(-1 1*~:\":<"~(*|:;@[;1])@'sp)_'sp:c_x;fmt[f;.v]}

e:e0@spl@
f:{p:sp@x; ,/((#p)#(r;e))@'p}@" ",
\d .

/
f:fmt.f
fmt:fmt.fmt

f"{245+352346:~^25x}"
fmt[".> 25,";-234234]
\
