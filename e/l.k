\l ../l/maths.k

tot:{(!x){i:z*1+!(-z)!x-1;y[i]:(-z)!y[i]*z-1;y}[x]/pri x} /totients
sg1:{a:(x#1){[r;p]n:#r;m:1+(-p)!n-1;q:-1_(n>)(p*)\p;@[r;p*!m;*;@[m#p+1;(-1_q)*!'1+(--1_q)!'m-1;+;1_q]]}/p:pri 2+_%x /sigma1(sum of divisors)
 p:(#p)_pri x;a[p*!'1+(-p)!'-1+#a]*:p+1;a[0]:0;a}
cfs:{$[x=r*r:_%x;,0;*|+(~(2*r)=*|:)({[x;r;m;d;a]m,d,(-d:(-d)!x-m*m)!r+m:(d*a)-m}[x;r].)\0 1,r]} /continued-fraction sqrt
gon:{-2!y*4-x+y*2-x} /y-th x-gonal number
lot:-2!0N-1 /a lot (half maxint)
srt:{x@<x}

big:10\
wee:10/
car:{(~**x)_x:((*x),0)+0,*|x:0 10\x}/ /carry
add:{car@+/(&'(|/l)-l:#'x),'x:(x;y)}
mul:{car@[&-1+(#x)+#y;(!#x)+\:!#y;+;x*\:y]}
ltn:{$[d:(#x)-#y;d<0;*>(x;y)]}
m10:{(-10|-#x)#x} /mod 10^10
pow:{x/((-1+#z)(x/2#,:)\y)@&z:|2\z} /y to the power of z, using x as multiplication
