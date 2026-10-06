#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE

Z A f(A,A,C);
Z C VER=0x01;
Z A sh=0;
Z A ser_(A x,C m)_(P((UC)m>1,en(x))sh=emp(tS);A y=aC(0);y=f(x,apc(y,VER),m);mr(sh);x(y))
Z A ff(L v,A y)_(cts(y,(V*)&v,8))
Z A fi(I v,A y)_(cts(y,(V*)&v,4))
Z A fA(A x,A y,C m)_(/*01*/N n=xn;y=fi(n,y);F(n|!n,y=N(f(xa,y,m)))y)
Z A f(A x,A y,C m)_(/*01*/
 X(
   RmMA(fA(x,apc(y,xt),m))
   RE(y=ff(xL[0],apc(y,xt));ff(xL[1],y))
   RS(y=fi(xn,apc(y,xt));F(xn,y=N(f(as(xi),y,m)))y)
   Rs(U u=xv;P(!(u&1<<31),ff(x,apc(y,xt)));A z=fnd(sh,x);P(gl_(z)-NL,ff(x,apc(y,xt|0x80)))
      PSH(sh,x);y=ff(x,apc(y,xt));S s=su(u);I n=SL(s)+1;y=apc(y,n);cts(y,s,n))
   R6(ti,tc,tu,tv,tw,tx,ff(x,apc(y,xt)))
   R4(to,tp,tq,tr,Q(xw==4);P(!m,fA(x,apc(apc(y,xt),(xtr?xE:0)<<3|xk),m))P(m==1,y=fi(xn,apc(y,xt|0x80));ff(x,y))ed(y))
   R_(P(!m,y=fi(xn,apc(y,xt));cts(y,xV,xtB?(xn+7>>3):(xn<<xw-3)))P(m==1,y=fi(xn,apc(y,xt|0x80));ff(x,y))ed(y)))0)
A1(ser, /*1*/ser_(x,0))
A2(ser2,/*11*/P(!xtz,ed(x(y)))x(ser_(y,xv)))

#define h(n) ({P(p-s<n,ed0());C*r=s;s+=n;r;})
#define h1 (*(C*)h(1))
#define h4 (*(I*)h(4))
#define h8 (*(L*)h(8))
Z A0 g;Z C*s,*p;
A des_(C* x, I n)_(sh=am(emp(tS),emp(tS));s=x;p=s+n;C ver=h1;P(ver!=VER,0)A y=N(g());mr(sh);y)
Z A0(gA,I n=h4;P(!(n<(W)(1ll<<45)),ed0())A x=aA(n);F(n|!n,P(!(xa=g()),mrn(i,xA);AZ(x);x(0)))x)
Z A0(g,C t=h1;B r=t&0x80;t&=0x7f;P(!(t<(W)tn),ed0())
 S(t,
  RA(gA())
  RE(L i,j;i=h8;j=h8;A x=aE(i,j);AT(t,x))
  R2(tm,tM,A x=N(gA());P(!xtA||xn-2||_t(xx)>tM||_t(xy)>tM||_N(xx)-_N(xy),ed(x))AT(t,mut(x)))
  RS(I n=h4;P(!(n<(W)(1ll<<45)),ed0())A x=aS(n);F(n,xi=Nx(g()))x)
  Rs(P(!r,A x=h8;U u=xv;P(u&1<<31,N n=h1;A y=sym(h(n));sh=a4(sh,x,av,y);y)x)A x=h8,y=sh;y1(x))
  R2(ti,tc,Lt(t)|(U)h8)
  R4(tu,tv,tw,tx,h8)
  R4(to,tp,tq,tr,P(!r,C c=h1;A x=N(gA());AT(t,AK(c&7,t==tr?AW(c>>3,x):x)))I n=h4;V*a=(V*)h8;a?aV(t,n,a):an(n,t))
  R_(I n=h4;P(!(n<(W)(1ll<<45)),ed0())P(r,V*a=(V*)h8;a?aV(t,n,a):an(n,t))P(t==tB,I m=n+7>>3;AN(n,AT(tB,aV(tC,m,h(m)))))aV(t,n,h(n*(1<<Tw[t]-3)))))0)
A1(des,XC(N(des_(xC, xn),ed(x)))ed(x))
