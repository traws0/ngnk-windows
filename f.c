#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
// ","/"abcd",'"=0x",/:+"0123456789abcdef"@(16#16)\2/|+4 64#(n{(|(8#2)\30)@2/'3'0,x,0}\n=!2*n)@'n:256
S UL a[]={0xd5a986ae75c9a33b,0x1016d8e3483a8f0f,0x81f9e6260eb8e5df,0xfa9b718d8d0769bf};
UL rnd1()_(Lv=a[1]<<17;a[2]^=a[0];a[3]^=a[1];a[1]^=a[2];a[0]^=a[3];a[2]^=v;a[3]=rot(a[3],45);a[0]+a[3])
A1(prng,P(x==au,aV(tL,4,a))XzZ(x=cL(rshN(4,x));Mc(a,xV,SZ a);x(au))et1(x))
S UI rm(UL m)_((UI)rnd1()*m>>32)
S V shf(L*r,Nn){i(n,Ij=rm(i+1);SWP(r[i],r[j]))}
S A ro(UL n,UL m)_(Ct=m?tZ(m-1):tL;Ax=atn(t,n);P(t==tB,i(n,xb=rm(m))x)P(t==tH,i(n,xh=rm(m))x)P(t==tI,i(n,xi=rm(m))x)
 i(n,xl=rnd1())I(m,i(n,xl=(UL)xl%m))x)
S A de(UL n,UL m)_(P(n>m,el0())Ax=ro(n,0);i(n,UL k=m-n+i;xl%=k+1;j(i,B(xL[j]==xl,xl=k)))shf(xV,n);x)
S A rd(Ln,Lm)_(P(m<0,ed0())n<0?de(n-NL?-n:m,m):ro(n,m))
AL(rndD,add(ai(-1),AT(tD,add(al(1023ll<<52),N(rd(n,1ll<<52))))))
S ALA(rnd,Xz(rd(n,gl(x)))Xc(cC(add(xv-'A'?ac('a'):x,Nx(rd(n,26)))))Xd(mul(x,Nx(rndD(n))))XMT(idx(x,Nx(rd(n,xN))))et1(x))

#define h(T)\
 NI L f##T(OV*p,Nn,Lv)_(O T*a=p,q=v;P(v-q||!n,NL)Ii=0,g=ZA/SZ(*a),f=0;W(i<n&&!f,j(g,f|=a[i++]==q))i-=g;j(g,B(a[i]==q)i++)i<n?i:NL)\
 NI V F##T(OV*p,Nm,TY(fB)f,OV*q,Nn,L*r){O T*a=q;i(n,r[i]=f(p,m,a[i]))}\
 NI L fp##T(A*p,T v)_(Ax=*p;Nn=xn;Li=f##T(xV,n,v);P(i<0,*p=apv(x,&v);n)i)
h(B)h(H)h(I)h(L)
S L fA(Ax,Ay/*00*/)_(i(xN,Az=get(x,i);P(mtc_(z,y),z(0);i)z(0))NL)
L fpA(A*p,Ay/*1*/)_(Ax=*p;Nn=xn;i(n,P(mtc_(xa,y),y(0);i))_q(*p,y);n)
L fAI(Ax,Iv)_(fI(xV,xn,v))
I rnk(Ax/*0*/)_(XA(P(!xn,2)Iv=rnk(xx);P(v<0,v)i(xn,P(v-rnk(xa),-1))v+1)XmM(rnk(xy))xtT) //-1 for mixed rank
I urnk(Ax/*0*/)_(XA(xn?urnk(xx)+1:2)XmM(urnk(xy))xtT)//assuming unirank
S A2(sdf,K("{a:&/x;b:1+|/x;@[(b-a)#0N;|x-a;:;|!#x]y-a}",x,y)) //small-domain find
A2(fnd,
 P(xtT&&!xtA&&!ytmMA,
  P(xtZ&&ytzZ||xt==TT[yt],
   P(Tz[xt]<2&&xn>99&&yN>99,sdf(x,y))
   V(f,CH(Tz[xt],&fB,fH,fI,fL))Yt(x(az(f(xV,xn,gl(y)))))
   Az=aL(yn);Ii=Tz[yt];x2(y2(CH(i,&FB,FH,FI,FL)(xV,xn,f,yV,yn,zV);z)))
  Az=cn[tl];zR;x(y(ytt?z:rshN(yN,z))))
 Xm(Az=kv(&x);idx(x,Nx(fnd(z,y))))
 Ik=urnk(x),l=urnk(y);P(k==l+1,x(y(az(fA(x,y)))))P(k<=l,ear(QUE,x,y))er2(x,y))

A2(que,Xt(Xz(rnd(gl(x),y))Xs(Ss("","j","hex")Sf(x,y,des,js0,unh))et2(x,y))fnd(x,y))
