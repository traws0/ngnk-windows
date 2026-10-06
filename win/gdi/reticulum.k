/ "reticulum" from https://beyondloom.com/tools/specialk.html 
/ the shader runs once per pixel; here each step runs on all pixels at once.  make -f win/makefile reticulum
L:`"o/win/gdi.dll";win:L 2:(`win;4);draw:L 2:(`draw;1);poll:L 2:(`poll;1);C:L 2:(`vcos;1);S:L 2:(`vsin;1)

n:200;i:!n*n                                                  / n*n pixels, shown 3x: 600*600 like specialk
P:0.5+(n!i;n-1+_i%n)                                          / pos.xy: pixel centres, gl y points up
D:0.5-(P,1)%n                                                 / .5-(pos.xy;1)%size.x
N:{%+/x*x}                                                    / N:#x, vector length. C S: simd cos sin from gdi.dll
f:{[t;x;y;z]z:z-t*0.01;c:C a:z*0.1;s:S a                      / x.z-:frame*.01; a:x.z*.1
 p:((x*c)+y*s;(y*c)-x*s;z);0.1-N(C 2#p)+S 1_p}                / x.xy*:mat[cos a;sin a;-sin a;cos a]; .1-#(cos x.xy)+sin x.yz
fr:{p:32{y+D*\:f[x]. y}[x]/0 0 0                             / p:32{x+f[x]*.5-(pos.xy;1)%size.x}/0 0 0
 256/_255*0|1&(2 5 9+S p)%\:N p}                               / col:((2 5 9+sin p)%#p),1  as 0xrrggbb

{*x>27=x 4}{draw fr 0.06*x 5}/win[n;n;3;"reticulum - esc to quit"];   / until closed or esc. frame: 60/s of wall-clock time
