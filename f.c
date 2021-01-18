#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rndL(L*r,UL n){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 i(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rnd(Ln,Lm)_(Y(n==NL,Ed(m<0)n=-m)Ax=aL(absL(n));rndL(xL,xn);Y(m,Y(m<=1ll<<32,i(xn,xl=(UI)xl*(UL)m>>32))E(i(xn,xl=(UL)xl%m)))
 Y(n<0,n=-n;El(n>m,x)i(n,Lk=m-n+i;Lv=((UL*)xL)[i]%=k+1;L*p=&xl;j(i,Y(xl==v,*p=k;B)))Ay=rnd(n,0);m2(y,i(n,SWP(xl,xL[(UL)yl%(i+1)]))0))x)
S A rndD(Ln)_(A x=AT(tD,rnd(n,0));i(n,xl=xl&-1ull>>12|1023ll<<52)x)
SN I fAA(Ax,Ay/*00*/)_(Q(xtA);i(xn,P(mtc_(xa,y),i))NI)
I fpA(A*p,Ay/*1*/)_(Ax=*p;In=xn,i=fAA(x,y);P(i<0,_q(*p,y);n)y(0);i)
#define f_(T)  NO I  f##T(OV*p,I n,OV*q)_(O T*a=p,v=*(T*)q;i(n,P(a[i]==v,i))NI)
#define fp_(T) NO I fp##T(A*p,T v)_(Ax=*p;In=xn,i=f##T(xC,n,&v);P(i<0,*p=apv(x,&v);n)i)
f_(C)f_(H)f_(I)f_(L) fp_(C)fp_(H)fp_(I)fp_(L)
I fAI(Ax,Iv)_(fI(xI,xn,&v))
S L NINL(Iv)_(v==NI?NL:v)
S I sup(A*p,A*q)_(Q(xtzZ&&ytzZ);Ax=*p,y=*q;A1*f=CH(max(tT(xt),tT(yt))-tH,&gH,gI,gL);*p=x=Ny(f(x));*q=y=Nx(f(y));1)
A2(fnd,
 Xs(SF(x,y,"``j`hex`aes",des,jsr,unh,aes1))
 Xz(Yz(rnd(gl(gL(x)),gl(y)))Yc(K("{`c$\"aA\"[y~\"A\"]+x?26}",x,y))Yd(mul(sub(rndD(gl(gL(x))),ad(1)),y))K("{y@x?#y}",x,y))
 Xm(idx(x,Nx(fnd(kv(&x),y))))
 P(ytt||ytm,P(!xtA&&ytF,x(y(al(NL))))fir(fnd(x,enl(y))))
 XA(Au=aL(yn);i(un,Az=get(y,i);ul=NINL(fAA(x,z));z(0))x(y(u)))
 YA(ear(cv('?'),A(x,y),2))
 P(xtZ&&ytZ,N(sup(&x,&y));Au=aL(yn);TY(fC)*f=CH(Zt[xt],&fC,fH,fI,fL);i(un,ul=NINL(f(xC,xn,yC+i*ZT[xt])))x(y(u)))
 K("{$[#x:(*&x~\\:)'y;x;!0]}",x,y))
