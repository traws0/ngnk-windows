#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rndl(L*r,UL n){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 F(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rnd(Ln,L m)_(Y(n==NL,n=-m)Ax=aL(absL(n));rndl(xl,xn);Y(m,Y(m<=1ll<<32,F(xn,xli=(UI)xli*(UL)m>>32))E(F(xn,xli=(UL)xli%m)))
 Y(n<0,n=-n;el(n>m,x)F(n,Lk=m-n+i;Lv=((UL*)xl)[i]%=k+1;L*p=&xli;F(i,Y(xli==v,*p=k;B)))Ay=rnd(n,0);F(n,SWP(xli,xl[(UL)yli%(i+1)]))yr)x)
SN L fndA(Ax/*0*/,Ay/*1*/)_(asrt(xtA);F(xn,P(mtc_(xai,y),i))NL)L fpA(A*p,Ay)_(Ax=*p;Ln=xn,i=fndA(x,y);P(i<0,*p=apd(x,y);n)yr;i)
#define f_(T) NO L fnd##T(Ax/*0*/,T v)_(F(xn,P(((T*)dat(x))[i]==v,i))NL)\
              L fp##T(A*p,T v)_(Ax=*p;Ln=xn,i=fnd##T(x,v);P(i<0,*p=apv(x,&v);n)i)
f_(C)f_(H)f_(I)f_(L)
A2(fnd,
 P(xtt,P(xts,Li=gl(K("``j`hex`aes?",x));en(i<0,y)(A1*[]){des,jsr,unh,aes1}[i](y))et(!xtil,x,y)
       P(ytl,rnd(gl(gL(x)),gl(y)))P(yti,K("{`i$x?`l$y}",x,y))P(ytc,K("{`c$\"aA\"[y~\"A\"]+x?26}",x,y))K("{y@x?#y}",x,y))
 P(xtm,Az=gkv(&x);idx(x,fnd(z,y)))
 en(xtM,x,y)
 P(ytt,P(!xtA&&fun(y),xr;yr;al(NL))
       fir(fnd(x,enl(y))))
 P(!xtA&&ytA,ear(cv('?'),A(x,y),2))
 P(!xtA&&yt-xt,xr;rsh(len(y),mR(cn[tl])))
 Au=aL(yn);I w=Zt[xt];
  Y(w==0,F(un,uli=fndC(x,yci)))
 EY(w==1,F(un,uli=fndH(x,yhi)))
 EY(w==2,F(un,uli=fndI(x,yii)))
 EY(w==3,F(un,uli=fndL(x,yli)))
 E(F(un,Az=get(y,i);uli=fndA(x,z);zr))
 xr;yr;u)
