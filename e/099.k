\l 0.k
d:10 /digits of precision
fp:{x:big x;(#x;d#x,&d)}
fmul:{r:mul[x 1;y 1];$[4<r d;r:carry@@[r;d-1;+;1];];(x[0]+y[0]+(#r)-2*d;d#r)}
fpow:{fmul/((-1+#e){fmul[x;x]}\fp x)@&e:|2\y}
1+*&r~\:r@*>r:fpow/'.'0:"p099_base_exp.txt"
/709
