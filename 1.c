#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define R1(f,a...) A1(f,XmMA(ea1(f,x))a)
S A az(Lv)_(-1ul<<15<=v&&v<1l<<15?ah(v):-1ul<<31<=v&&v<1l<<31?ai(v):al(v))
R1(neg,Xz(az(-gl(x)))Xd(ad(-gd(x)))XcC(neg(gH(x)))Xt(Et(1,x);0)
 Au=atn(xt,xn);XH(i(un,P(xh==NH,neg(gI(u(x))))uh=-xh)u)XI(i(un,P(xi==NI,neg(gL(u(x))))ui=-xi)u)
 XL(i(un,ul=-xl)u)XD(i(un,ud=-xd)u)Et(1,x,u);0)
R1(not,XF(I r=x==au0;x(ah(r)))eql(x,xtsS?as(0):ac(0)))
R1(sqr,x=N(gD(x));Au=xr-1?atn(xt,xn):x;i(un,ud=__builtin_sqrt(xd))xC==uC?u:x(u))
R1(nul,eql(x,mR(cn[xt])))
R1(flr,Xc(fir(flr(enl(x))))XC(Au=aC(xn);m2(x,i(un,uc=xc+32*c3('A',xc,'Z'))u))XzZ(x)XsS(K("`$_$:",x))
 x=N(gD(x));Au=atn(xtd?tl:tL,xn);m2(x,i(un,ul=xd<0?(L)xd-(xd<(L)xd):(L)xd)u))
//mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
S D sinD(D x)_(S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,
  -2.33177897192836082e-8,2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sinD(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)
R1(sin,x=N(gD(x));Au=xr-1?atn(xt,xn):x;i(un,ud=sinD(xd))xC==uC?u:x(u))
