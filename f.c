#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S UL r1()_(S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 Lv=b<<17;c^=a;d^=b;b^=c;a^=d;c^=v;d=rot(d,45);a+d)
S UI rm(UL m)_((UI)r1()*m>>32)
S V shf(L*r,Nn){i(n,UI j=rm(i+1);SWP(r[i],r[j]))}
S A ro(UL n,UL m)_(Ax=aL(n);i(n,xl=r1())Y(m,Y(m<=1ll<<32,i(n,xl=rm(m)))E(i(n,xl=(UL)xl%m)))x)
S A de(UL n,UL m)_(El(n>m)Ax=ro(n,0);i(n,UL k=m-n+i;xl%=k+1;j(i,B(xL[j]==xl,xl=k)))shf(xL,n);x)
S A rd(Ln,Lm)_(Ed(m<0)n<0?de(n-NL?-n:m,m):ro(n,m))
S A rnd(Ln,Ax)_(Xz(rd(n,gl(x)))Xc(gC(add(xv-'A'?ac('a'):x,Nx(rd(n,26)))))
 Xd(mul(x,add(ad(-1),Nx(AT(tD,add(al(1023ll<<52),rd(n,1ll<<52)))))))XMT(idx(x,Nx(rd(n,xN))))et1(x))

#define h(T) NI L f##T(OV*p,Nn,Lv)_(P(v-(T)v,NL)O T*a=p,w=(T)v;i(n,P(a[i]==w,i))NL)\
             NI V F##T(OV*p,Nm,TY(fB)f,OV*q,Nn,L*r){O T*a=q;i(n,r[i]=f(p,m,a[i]))}\
             NI L fp##T(A*p,T v)_(Ax=*p;Nn=xn;Li=f##T(xC,n,v);P(i<0,*p=apv(x,&v);n)i)
h(B)h(H)h(I)h(L)
S L fA(Ax,Ay/*00*/)_(i(xN,Az=get(x,i);P(mtc_(z,y),z(0);i)z(0))NL)
L fpA(A*p,Ay/*1*/)_(Ax=*p;Nn=xn;i(xn,P(mtc_(xa,y),y(0);i))_q(*p,y);n)
L fAI(Ax,Iv)_(fI(xI,xn,v))
I rnk(Ax/*0*/)_(XA(xn?rnk(xx)+1:2)XmMA(rnk(xy))xtT)//rank(assuming unirank)
A2(fnd,P(xtZ&&ytzZ||xtC&&ytcC||xtS&&ytsS||xtD&&ytdD,TY(fB)*f=CH(Zt[xt],&fB,fH,fI,fL);Yt(x(az(f(xC,xn,gl(y)))))
        Az=aL(yn);x2(y2(CH(Zt[yt],&FB,FH,FI,FL)(xC,xn,f,yC,yn,zL);z)))
 Xm(Az=kv(&x);idx(x,Nx(fnd(z,y))))
 Ik=rnk(x),l=rnk(y);P(k==l+1,x(y(az(fA(x,y)))))P(k<=l,ear(cv('?'),A(x,y),2))er2(x,y))

A2(que,Xt(Xz(rnd(gl(x),y))Xs(Ss("","j","hex","aes","e")Sf(x,y,des,js0,unh,aes1,log))et2(x,y))fnd(x,y))
