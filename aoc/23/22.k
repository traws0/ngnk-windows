#!../../k
x:0:"i/22"

/x:("1,0,1~1,2,1"
/   "0,0,2~2,0,2"
/   "0,2,3~2,2,3"
/   "0,0,4~0,2,4"
/   "2,0,5~2,2,5"
/   "0,1,6~2,1,6"
/   "1,1,8~1,1,9")

n:#x
b:+(,/.'"~"\)'x /bricks
b:b@\:<b 2      /sort by z0
h:10 10#0       /heights
f:10 10#-1      /fallen brick ids
s:n#,!0         /s[i]: supporters of brick i

drop:{[i;x0;y0;z0;x1;y1;z1]
 X:x0_!1+x1
 Y:y0_!1+y1
 hXY:,/h[X;Y]
 fXY:,/f[X;Y]
 m:|/hXY
 s[i]:?fXY[&m=hXY]^-1
 h[X;Y]:m+1+z1-z0
 f[X;Y]:i}

drop'[!n].b;
+/~@[&n;s@&1=#'s;:;1] /1
