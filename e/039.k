\l 0.k
/primitive triples: a=m^2-n^2 b=2mn c=m^2+n^2 P=2m(m+n) where gcd(m,n)=1 and m>n>0
l:1000
mn:1+|cmb[2;l]
P:2*/+\mn
i:&P<l+1;P@:i;mn:mn@\:i
P@:&1=gcd'/mn
*>#'=,/P*1+!'(-P)!'l
/840
