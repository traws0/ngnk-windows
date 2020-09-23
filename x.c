#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE

//serialize
S A f8(L v,A y)_(catc(y,(V*)&v,8))
S A2(f,y=Nx(apc(y,xt));
 P(xtX||xtS,y=Nx(f8(xn,y));F(xn,y=Nx(f(get(x,i),y)))xr;y)
 P(xtaA,f(AT(tX,x),y))
 P(xts,O C*s=syp(gs(x));I n=strlen(s)+1;y=Nx(apc(y,n));catc(y,s,n))
 P(pkd(x),f8(x,y))
 P(fun(x),f(AT(tX,x),Nx(apc(y,xv<<3|xk))))
 I l=8*xtT;A u=catc(y,xc-l,l+xn*tZ[xt]);xr;u)
A1(ser,f(x,aC(0)))

//deserialize
S C*s,*p;
#define h(n) ({Ed(p-s<n);C*r=s;s+=n;r;})
#define h1 (*(C*)h(1))
#define h8 (*(L*)h(8))
S A g()_(C t=h1;Ed(!in(t,tn))
 P(t==tX||t==tS,L n=h8;Ed(!in(n,1ll<<45))A x=AN(0,atn(t,n));F(n,x=apd(x,Nx(g())))x)
 P(t==ta||t==tA,A x=N(g());Ed(!xtX||xn-2||At(xx)>tA||At(xy)>tA||len_(xx)-len_(xy))AT(t,x))
 P(t==ts,C n=h1;as(syP(h(n))))
 P(pkdt(t),h8)
 P(funt(t),C vk=h1;AT(t,AK(vk&7,AV(vk>>3,N(g())))))
 L n=t<ta?h8:1;Ed(!in(n,1ll<<45))atnv(t,n,h(n*tZ[t])))
A1(des,Ed(!xtC,x)s=xc;p=s+xn;dex(x,g()))
