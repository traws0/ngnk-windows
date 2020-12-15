#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rndl(L*r,UL n){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 F(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rnd(Ln,L m)_(Y(n==NL,n=-m)Ax=aL(absL(n));rndl(xL,xn);Y(m,Y(m<=1ll<<32,F(xn,xl=(UI)xl*(UL)m>>32))E(F(xn,xl=(UL)xl%m)))
 Y(n<0,n=-n;el(n>m,x)F(n,Lk=m-n+i;Lv=((UL*)xL)[i]%=k+1;L*p=&xl;F(i,Y(xl==v,*p=k;B)))Ay=rnd(n,0);F(n,SWP(xl,xL[(UL)yl%(i+1)]))yr)x)
SN I fAA(Ax/*0*/,Ay/*0*/)_(Q(xtA);F(xn,P(mtc_(xa,y),i))NI)
I fpA(A*p,Ay)_(Ax=*p;In=xn,i=fAA(x,y);P(i<0,*p=apd(x,y);n)yr;i)
#define f_(T)  NO I  f##T(OV*p,I n,OV*q)_(O T*a=p,v=*(T*)q;F(n,P(a[i]==v,i))NI)
#define fp_(T) NO I fp##T(A*p,T v)_(Ax=*p;In=xn,i=f##T(xC,n,&v);P(i<0,*p=apv(x,&v);n)i)
f_(C)f_(H)f_(I)f_(L) fp_(C)fp_(H)fp_(I)fp_(L)
I fAI(Ax,Iv)_(fI(xI,xn,&v))
S L NINL(Iv)_(v==NI?NL:v)
A2(fnd,
 Xtt(Xts(SF(x,y,"``j`hex`aes",des,jsr,unh,aes1))et(!xtil,x,y)Ytl(rnd(gl(gL(x)),gl(y)))
     Yti(K("{`i$x?`l$y}",x,y))Ytc(K("{`c$\"aA\"[y~\"A\"]+x?26}",x,y))K("{y@x?#y}",x,y))
 Xtm(Az=gkv(&x);idx(x,fnd(z,y)))
 en(xtM,x,y)
 Ytt(P(!xtA&&fun(y),xr;yr;al(NL))
     fir(fnd(x,enl(y))))
 XtA(Au=aL(yn);F(un,Az=get(y,i);ul=NINL(fAA(x,z));zr)xr;yr;u)
 YtA(ear(cv('?'),A(x,y),2))
 P(yt-xt,xr;rsh(len(y),mR(cn[tl])))
 Au=aL(yn);TY(fC)*f=CH(Zt[xt],&fC,fH,fI,fL);F(un,ul=NINL(f(xC,xn,yC+i*ZT[xt])))xr;yr;u)
