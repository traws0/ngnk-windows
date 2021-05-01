#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE

//serialize
S A f8(Lv,Ay)_(cts(y,(V*)&v,8))
S A2(f,y=Nx(apc(y,xt));
 P(xtA||xtS,y=Nx(f8(xn,y));i(xn,y=Nx(f(get(x,i),y)))x(y))
 XmMA(f(AT(tA,mut(x)),y))
 Xs(Lv=gi(x);Qs=syp(&v);In=sn(s)+1;y=Nx(apc(y,n));cts(y,s,n))
 XP(f8(x,y))
 XF(f(AT(tA,mut(x)),Nx(apc(y,xv<<3|xk))))
 In=8*xtT;x(cts(y,xC-n,n+xn*ZT[xt])))
A1(ser,f(x,aC0))

//deserialize
S C*s,*p;
#define h(n) ({Ed(p-s<n);C*r=s;s+=n;r;})
#define h1 (*(C*)h(1))
#define h8 (*(L*)h(8))
S A0(g,Ct=h1;Ed(!in(t,tn))
 P(t==tA||t==tS,Ln=h8;Ed(!in(n,1ll<<45))Ax=AN(0,atn(t,n));i(n,xq(Nx(g())))x)
 P(t==tm||t==tM,Ax=N(g());Ed(!xtA||xn-2||At(xx)>tM||At(xy)>tM||_N(xx)-_N(xy))AT(t,mut(x)))
 P(t==ts,Cn=h1;as(syP(h(n))))
 P(_P(t),h8)
 P(_F(t),Cc=h1;AT(t,AK(c&7,AV(c>>3,N(g())))))
 Ln=t<tm?h8:1;Ed(!in(n,1ll<<45))atnv(t,n,h(n*ZT[t])))
A1(des,Ed(!xtC,x)s=xC;p=s+xn;x(g()))
