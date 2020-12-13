#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rndl(L*r,UL n){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 F(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rnd(Ln,L m)_(Y(n==NL,n=-m)Ax=aL(absL(n));rndl(xL,xn);Y(m,Y(m<=1ll<<32,F(xn,xl=(UI)xl*(UL)m>>32))E(F(xn,xl=(UL)xl%m)))
 Y(n<0,n=-n;el(n>m,x)F(n,Lk=m-n+i;Lv=((UL*)xL)[i]%=k+1;L*p=&xl;F(i,Y(xl==v,*p=k;B)))Ay=rnd(n,0);F(n,SWP(xl,xL[(UL)yl%(i+1)]))yr)x)
SN L fndA(Ax/*0*/,Ay/*1*/)_(Q(xtA);F(xn,P(mtc_(xa,y),i))NL)L fpA(A*p,Ay)_(Ax=*p;Ln=xn,i=fndA(x,y);P(i<0,*p=apd(x,y);n)yr;i)
#define fnd_(T) NO L fnd##T(Ax/*0*/,T v)_(F(xn,P(((T*)dat(x))[i]==v,i))NL)\
                   L fp##T(A*p,T v)_(Ax=*p;Ln=xn,i=fnd##T(x,v);P(i<0,*p=apv(x,&v);n)i)
fnd_(C)fnd_(H)fnd_(I)fnd_(L)
#define f_(T) NO I f##T(OV*a0,I n,OV*b0)_(O T*a=a0,v=*(T*)b0;F(n,P(a[i]==v,i))NI)
f_(C)f_(H)f_(I)f_(L)
I fAI(Ax,Iv)_(fI(xI,xn,&v))
A2(fnd,
 P(xtt,P(xts,SF(x,y,"``j`hex`aes",des,jsr,unh,aes1))et(!xtil,x,y)P(ytl,rnd(gl(gL(x)),gl(y)))
       P(yti,K("{`i$x?`l$y}",x,y))P(ytc,K("{`c$\"aA\"[y~\"A\"]+x?26}",x,y))K("{y@x?#y}",x,y))
 P(xtm,Az=gkv(&x);idx(x,fnd(z,y)))
 en(xtM,x,y)
 P(ytt,P(!xtA&&fun(y),xr;yr;al(NL))
       fir(fnd(x,enl(y))))
 P(!xtA&&ytA,ear(cv('?'),A(x,y),2))
 P(!xtA&&yt-xt,xr;rsh(len(y),mR(cn[tl])))
 Au=aL(yn);I w=Zt[xt];
  Y(w==0,F(un,ul=fndC(x,yc)))
 EY(w==1,F(un,ul=fndH(x,yh)))
 EY(w==2,F(un,ul=fndI(x,yi)))
 EY(w==3,F(un,ul=fndL(x,yl)))
 E(F(un,Az=get(y,i);ul=fndA(x,z);zr))
 xr;yr;u)
