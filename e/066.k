\l 0.k
pell:{a0:_%x;$[x=a0*a0;:,0;]
      c:-1_*|+(~(2*a0)=*|:)({[N;a0;m;d;a] m:(d*a)-m;d:(-d)!N-m*m;a:(-d)!a0+m;m,d,a}[x;a0].)\0 1,a0 /cfrac sqrt
      r:*|(big'0 1){(x 1;add[*x;mul[y;x 1]])}/|big'c
      $[2!#c;add[big 1;add/2#,mul/2#,r];r]}
*&a~\:max/a:pell'!1+1000
/661
