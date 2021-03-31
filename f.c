#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rndL(L*r,Nn){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 i(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rnd(Ln,Lm)_(Y(n==NL,Ed(m<0)n=-m)
 Au=aL(absL(n));rndL(uL,un);Y(m,Y(m<=1ll<<32,iul((UI)ul*(UL)m>>32))E(iul((UL)ul%m)))
 Y(n<0,n=-n;El(n>m,u)i(n,Lk=m-n+i;Lv=((UL*)uL)[i]%=k+1;L*p=&ul;j(i,Y(ul==v,*p=k;BR)))Ay=rnd(n,0);m2(y,i(n,SWP(ul,uL[(UL)yl%(i+1)]))0))u)
S A rndD(Ln)_(A x=AT(tD,rnd(n,0));i(n,xl=xl&-1ull>>12|1023ll<<52)x)

#define h(T) NO L f##T(OV*p,Nn,Lv)_(P(v-(T)v,NL)O T*a=p,w=(T)v;i(n,P(a[i]==w,i))NL)\
 NO L fp##T(A*p,T v)_(Ax=*p;Nn=xn;Li=f##T(xC,n,v);P(i<0,*p=apv(x,&v);n)i)
h(B)h(H)h(I)h(L)
S L fA(Ax,Ay/*00*/)_(i(xN,Az=get(x,i);P(mtc_(z,y),z(0);i)z(0))NL)
L fpA(A*p,Ay/*1*/)_(Ax=*p;Nn=xn;i(xn,P(mtc_(xa,y),y(0);i))_q(*p,y);n)
L fAI(Ax,Iv)_(fI(xI,xn,v))
A2(fnd,Xs(Ss("","j","hex","aes")Sf(x,y,s,des,jsr,unh,aes1))
 Xz(Yz(rnd(gl(x),gl(y)))Yc(K("{`c$\"aA\"[y~\"A\"]+x?26}",x,y))Yd(mul(sub(rndD(gl(x)),ad(1)),y))K("{y@x?#y}",x,y))
 Xm(Az=kv(&x);idx(x,Nx(fnd(z,y))))
 XZ(TY(fB)*f=CH(Zt[xt],&fB,fH,fI,fL);Yz(x(az(f(xC,xn,gl(y)))))
    YZ(Au=aL(yn);x(m2(y,ytB?iul(f(xC,xn,yb)):ytH?iul(f(xC,xn,yh)):ytI?iul(f(xC,xn,yi)):iul(f(xC,xn,yl)))))
    K("{$[y~*y;0N;(#y)#0N]}",x,y))
 P((xtS&&ytsS)||(xtC&&ytcC)||(xtD&&ytdD),fnd(AT(tB+Zt[xt],mut(x)),AT(tB+Zt[xt]+(tc-tC)*ytt,mut(y))))
 Ymt(fir(N(fnd(x,enl(y)))))
 Au=aL(yN);x(y(iul(Az=get(y,i);z(fA(x,z))))))
