\l 0.k
R:{$[1<*|x;(-gcd/x)!x;x]} /rational
ops:({(+/x*|y;*|x*y)}     /+
     {(-/x*|y;*|x*y)}     /-
     *                    /*
     {x*|$[0>*y;-y;y]})   /div
bkt:{a:x 0;b:x 1;c:x 2;d:x 3;f:y 0;g:y 1;h:y 2 /all bracket placements over 4 values x and 3 functions y
     fab:f[a;b];fbc:f[b;c]
     R'(h[g[fab;c];d]
        h[g[a;fbc];d]
        h[fab;g[c;d]]
        h[a;g[fbc;d]]
        h[a;g[b;f[c;d]]])}
howfar:{+/&\@[~!100;{(99&0|*x)*x[1]=1}@+,/,/(x@+prm 4)bkt/:\:ops@+!3##ops;:;1]}
10/*c@&v=|/v:howfar'((!10),'1)c:+cmb[4;10]
/1258
