/number theory
primes:{$[x<10;:(x>)#o 10;]
        r:1+2*&@[(-2!x)#0x010000010001010001010001000001;!3;:;0x01]{$[x@-2!y;@[x;-2!y*y+2*!-2!2+(-y)+(-y)!-1+2*#x;:;0x00];x]}/7+2*!0|-2!-5+_%x
        r[0]:2;r}
isprime:{p:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61;$[x<62;:~^p?x;~&/p!'x;:0]
         b:|2\x-1;s:b?1;d:s_b;sqr:{x!y*y}[x];ad:(x!*)/((-1+#d)sqr\2 3 61)@&d;a2sd:(s-1)sqr\ad;&/(1=ad)||/a2sd=x-1}
totients:{(!x){[n1;r;p] i:p*1+!(-p)!n1;r[i]:(-p)!r[i]*p-1;r}[x-1]/primes x}
sigma1:{a:(x#1){[r;p] n:#r;m:1+(-p)!n-1;q:-1_(n>)(p*)\p;@[r;p*!m;*;@[m#p+1;(-1_q)*!'1+(--1_q)!'m-1;+;1_q]]}/p:primes 2+_%x /sum of divisors
        p:(#p)_primes x;a[p*!'1+(-p)!'-1+#a]*:p+1;a[0]:0;a}
cfsqrt:{a0:_%x;$[x=a0*a0;0;*|+{[a0;x] ~(2*a0)=x 2}[a0]({[N;a0;m;d;a] m:(d*a)-m;d:(-d)!N-m*m;a:(-d)!a0+m;m,d,a}[x;a0].)\0 1,a0]}
pell:  {$[x=*/2#_%x;:0N;];r:|0 1{(x 1;y/|x)}/|c:-1_cfsqrt x;$[2!#c;1 0+2*/'r**r;r]}
pelln1:{$[x=*/2#_%x;:0N;];r:|0 1{(x 1;y/|x)}/|c:-1_cfsqrt x;$[2!#c;r;0N]}
gcd:{*|(*:)(|!\)/x,y}

/combinatorics
prm:{(x-1){,'/(!1+#x){(,(#*y)#x),y+y>x-1}\:x}/,,0}
cmb:{$[x=1;,!y;(,&#'*'u),,'/u:i+(x-1)o'y-i:1+!1+y-x]}
gon:{-2!y*(4-x)+(x-2)*y} /y-th x-agonal number

/bignum
big:10\
small:10/
carry:{(~**x)_((*x),0)+0,*|x:0 10\x}/
sum:{carry@+/(&'(|/l)-l:#'x),'x}
add:{sum(x;y)}
mul:{carry@@[&-1+(#x)+#y;(!#x)+\:!#y;+;x*\:y]}
max:{$[(#x)<#y;y;(#y)<#x;x;0<*(x-y)^0;x;y]}
lt:{d:(#x)-#y;$[d;d<0;*>(x;y)]}
sqrt:{[a] (1,&l){[a;r;i] {[a;i;r] R:r;R[i]+:1;$[lt[mul[R;R];a];R;r]}[a;i]/r}[a]/!l:-2!-1+#a}
