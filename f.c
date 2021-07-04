#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S V rn(L*r,Nn){S UL a=0xd5a986ae75c9a33b,b=0x1016d8e3483a8f0f,c=0x81f9e6260eb8e5df,d=0xfa9b718d8d0769bf;
 i(n,r[i]=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rot(d,45))}
S A rL(Ln,Lm)_(Y(n==NL,Ed(m<0)n=-m)
 Ax=aL(absL(n));rn(xL,xn);Y(m,Y(m<=1ll<<32,i(xn,xl=(UI)xl*(UL)m>>32))E(i(xn,xl=(UL)xl%m)))
 Y(n<0,n=-n;El(n>m,x)i(n,Lk=m-n+i;Lv=((UL*)xL)[i]%=k+1;L*p=&xl;j(i,Y(xl==v,*p=k;BR)))Ay=rL(n,0);m2(y,i(n,SWP(xl,xL[(UL)yl%(i+1)]))0))x)
S A rD(Ln)_(A x=AT(tD,rL(n,0));i(n,xl=xl&-1ull>>12|1023ll<<52)x)
S A rnd(Lm,Ax)_(Xz(rL(m,gl(x)))Xc(gC(add(gi(x)=='A'?x:ac('a'),Nx(rL(m,26)))))Xd(mul(x,add(ad(-1),Nx(rD(m)))))
 XMT(idx(x,Nx(rL(m,xN))))et1(x))

#define h(T) NO L f##T(OV*p,Nn,Lv)_(P(v-(T)v,NL)O T*a=p,w=(T)v;i(n,P(a[i]==w,i))NL)\
             NO L fp##T(A*p,T v)_(Ax=*p;Nn=xn;Li=f##T(xC,n,v);P(i<0,*p=apv(x,&v);n)i)\
             NO V ff##T(OV*p,Nm,TY(fB)f,OV*q,Nn,L*r){O T*a=q;i(n,r[i]=f(p,m,a[i]))}
h(B)h(H)h(I)h(L)
S L fA(Ax,Ay/*00*/)_(i(xN,Az=get(x,i);P(mtc_(z,y),z(0);i)z(0))NL)
L fpA(A*p,Ay/*1*/)_(Ax=*p;Nn=xn;i(xn,P(mtc_(xa,y),y(0);i))_q(*p,y);n)
L fAI(Ax,Iv)_(fI(xI,xn,v))
S I rnk_(Ax/*0*/)_(Xt(0)XA(P(!xn,2)Iv=rnk_(xx);P(v<0,v)i(xn,P(v-rnk_(xa),-1))v+1)XT(1)-1)
A2(fnd,P(xtZ&&ytzZ||xtC&&ytcC||xtS&&ytsS||xtD&&ytdD,TY(fB)*f=CH(Zt[xt],&fB,fH,fI,fL);Yt(x(az(f(xC,xn,gl(y)))))
        Au=aL(yn);x(m2(y,CH(Zt[yt],&ffB,ffH,ffI,ffL)(xC,xn,f,yC,yn,uL);u)))
//       Ymt(fir(N(fnd(x,enl(y)))))
       I r=rnk_(x),s=rnk_(y);
       P(r<0||s<0,er2(x,y))
       P(r==s,Au=aL(yN);i(un,Az=get(y,i);ul=z(fA(x,z)))x(y(u)))
       P(r==s+1,x(y(az(fA(x,y)))))
       P(r<=s,ear(cv('?'),A(x,y),2))
       er2(x,y))

A2(que,Xz(rnd(gl(x),y))Xs(Ss("","j","hex","aes")Sf(x,y,s,des,jsr,unh,aes1))Xm(Az=kv(&x);idx(x,Nx(fnd(z,y))))fnd(x,y))
