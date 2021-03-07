#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE

S D sind(D x)_( //mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
 S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,-2.33177897192836082e-8,
  2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sind(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)

TD int(*F1)(OV*,V*,N);
#define F1(f,T,c...) S I f##T(OV*a0,V*r0,Nn)_(O T*a=a0;T*r=r0;I b=0;i(PD(n,a),r[i]=({c;}))b)
F1(neg,B,b|=a[i]==NB;-a[i])
F1(neg,H,b|=a[i]==NH;-a[i])
F1(neg,I,b|=a[i]==NI;-a[i])
F1(neg,L,-a[i])
F1(neg,D,-a[i])
F1(sqr,D,__builtin_sqrt(a[i]))
F1(sin,D,sind(a[i]))
F1(flr,C,a[i]+32*c3('A',a[i],'Z'))

#define R1(f,a...) A1(f,XmMA(ea1(f,x))a)
SN A fx(Ax,F1 f)_(P(xr==1,f(xC,xC,xn);x)Au=atn(xt,xn);m2(x,f(xC,uC,un);u))
R1(neg,Xz(az(-gl(x)))Xd(ad(-gd(x)))XcC(neg(gH(x)))P(!xtZ&&!xtD,et1(x))
 Au=xr>1?atn(xt,xn):x;CH(xt-tB,&negB,negH,negI,negL,negD)(xC,uC,xn);x==u?u:x(u))
R1(not,XF(x(ah(x==au0)))eql(x,xtsS?as(0):ac(0)))
R1(sqr,fx(N(gD(x)),sqrD))
R1(sin,fx(N(gD(x)),sinD))
R1(nul,XF(x(ah(x==au0)))eql(x,mR(cn[xt])))
R1(flr,XC(fx(x,flrC))Xc(fir(flr(enl(x))))XzZ(x)XsS(K("`$_$:",x))
 x=N(gD(x));Au=atn(xt+tl-td,xn);m2(x,iul(xd<0?(L)xd-(xd<(L)xd):(L)xd)))
