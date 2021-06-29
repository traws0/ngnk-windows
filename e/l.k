P:{$[x<10;(x>)#o 10 /primes <x
 @[;0;:;2]1+2*&@[(-2!x)#0x010000010001010001010001000001;!3;:;0x01]{$[x@-2!y;@[x;-2!y*y+2*!-2!2+(-y)+(-y)!-1+2*#x;:;0x00];x]}/7+2*!0|-2!-5+R x]}
Q:{p:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 /is x prime?
 $[x<62;~^p?x;+/~p!'x;0;&/(1=a)|/x=1+(s-1)q\a:(x!*)/((-1+#d)(q:x!*/2#,:)\2 7 61)@&d:(s:*&b)_b:|2\x-1]}
T:{(!x){i:z*1+!(-z)!x-1;y[i]:(-z)!y[i]*z-1;y}[x]/P x} /totients
S1:{a:(x#1){[r;p]n:#r;m:1+(-p)!n-1;q:-1_(n>)(p*)\p;@[r;p*!m;*;@[m#p+1;(-1_q)*!'1+(--1_q)!'m-1;+;1_q]]}/p:P 2+R x /sigma1(sum of divisors)
 p:(#p)_P x;a[p*!'1+(-p)!'-1+#a]*:p+1;a[0]:0;a}
CF:{$[x=r*r:R x;,0;*|+(~(2*r)=*|:)({[x;r;m;d;a]m,d,(-d:(-d)!x-m*m)!r+m:(d*a)-m}[x;r].)\0 1,r]} /continued-fraction sqrt
G:*|(*:)(|!\)/,;H:-2!0N-1;S:{x@<x};R:_%:;Gon:{-2!y*4-x+y*2-x} /G:gcd,H:halfmaxint,S:sort,R:sqrt,Gon:y-th x-gonal number
Pe:{(x-1){,/'((,(#*x)##x),x)(~i=\:i)*i+i<\:i:!1+#x}/0}        /permutations(non-lexicographic)
Co:{*|(y-x){((,(1|#*x)#-1+**y),x),'y}\/,''y+!'-!1+x}          /combinations(lexicographic)
B:10\;Z:10/;K:{(~**x)_x:((*x),0)+0,*|x:0 10\x}/;A:{K@+/(&'(|/l)-l:#'x),'x:(x;y)};MX:{(-10|-#x)#x} /B:big,Z:small,K:carry,A:add,MX:mod 10^10
M:{K@[&-1+(#x)+#y;(!#x)+\:!#y;+;x*\:y]};L:{$[d:(#x)-#y;d<0;*>(x;y)]};Pw:{x/((-1+#z)(x/2#,:)\y)@&z:|2\z} /M:mul,L:less,Pw:power[mul]
