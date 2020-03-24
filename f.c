#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S A rnd(L n,L m)_(S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 Y(n==_0Nl,n=-m)A x=aL(absL(n));F(n,xli=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=d<<45|d>>19)Y(m&(m-1),F(xn,xli=(UL)xli%m))EY(m,F(xn,xli&=m-1))
 Y(n<0,n=-n;P(n>m,el(x))F(n,L k=m-n+i;L v=((UL*)xl)[i]%=k+1;Fj(i,Y(xlj==v,xli=k;B)))A y=rnd(n,0);F(n,L j=(UL)yli%(i+1);SWP(xli,xlj))yr)x)
S L fnda(A x,A y/*0*/)_(asrt(xtX); F(xn,P(mtc_(xai,y),i))_0Nl)L fpa(A*p,A y)_(A x=*p;L n=xn;F(n,P(mtc_(xai,y),yr;i))*p=apd(x,y);n)
S L fndc(A x,C v)_(asrt(tz(xt)==0);F(xn,P(xci==v,i))_0Nl)     L fpc(A*p,C v)_(A x=*p;L n=xn;F(n,P(xci==v,i))*p=apv(x,&v);n)
  L fndi(A x,I v)_(asrt(tz(xt)==2);F(xn,P(xii==v,i))_0Nl)     L fpi(A*p,I v)_(A x=*p;L n=xn;F(n,P(xii==v,i))*p=apv(x,&v);n)
  L fndl(A x,L v)_(asrt(tz(xt)==3);F(xn,P(xli==v,i))_0Nl)     L fpl(A*p,L v)_(A x=*p;L n=xn;F(n,P(xli==v,i))*p=apv(x,&v);n)
A2(fnd,
 P(xts,I v=gs(x);!v?des(y):v==Qj?json(y):ed(y))
 P(xtil,ytl?rnd(gl(gL(x)),gl(y)):ytc||yti||ytT?K("{$[`c=t:@y;`c$$[y~\"A\";y;\"a\"]+x?26;`i=t;`i$x?`l$y;y@x?#y]}",x,y):et(y))
 P(xtt,et(x,y))
 P(xta,A z=gkv(&x);idx(x,fnd(z,y)))
 P(xtA,en(x,y))
 P(ytt,fir(fnd(x,enl(y))))
 P(!xtX&&ytX,ear(cv('?'),A_(x,y),2))
 P(!xtX&&yt-xt,xr;rsh(len(y),mR(cn[tl])))
 A u=aL(yn);I w=tz(xt);P(ref(x),F(un,A z=get(y,i);uli=fnda(x,z);zr)xr;yr;u)
 P(w==0,F(un,uli=fndc(x,yci))xr;yr;u)
 P(w==2,F(un,uli=fndi(x,yii))xr;yr;u)
 P(w==3,F(un,uli=fndl(x,yli))xr;yr;u)
 en(x,y,u))
