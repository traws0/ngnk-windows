#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE

S D sind(D x)_( //mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
 S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,-2.33177897192836082e-8,
  2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sind(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)

TD size_t(*F1)(OV*,V*,N);
#define hf(f,T,e...) S N f(OV*RE a0,V*RE r0,Nn)_(O T*a=a0;T*r=r0;AL(a)AL(r)e)
#define NG(T) hf(neg##T,T,Ni=0;W(i<n,I o=0;j(ZA/Z(T),o|=a[j]==(T)(1<<Z(T)*8-1))P(o,i)j(ZA/Z(T),r[j]=-a[j])a+=ZA/Z(T);r+=ZA/Z(T);i+=ZA/Z(T))n)
#define F1(f,T,c...) hf(f##T,T,i(PD(n,a),r[i]=({c;}))n)
NG(B)NG(H)NG(I)F1(neg,L,-a[i])F1(neg,D,-a[i])
F1(sqr,D,__builtin_sqrt(a[i]))F1(sin,D,sind(a[i]))F1(flr,C,a[i]+32*cAZ(a[i]))

#define R1(f,a...) A1(f,XmMA(eac1(f,x))a)
SN A fx(Ax,F1 f)_(P(xr==1,f(xC,xC,xn);x)Au=atn(xt,xn);x2(f(xC,uC,un);u))
R1(neg,Xz(az(-gl(x)))Xd(ad(-gd(x)))XcC(neg(gH(x)))P(!xtZD,et1(x))
 S O F1 f[]={negB,negH,negI,negL,negD};
 Nn=xn;Au=xr>1?atn(xt,n):x;Nm=f[xt-tB](xC,uC,n);
 Y(m<n,Y(x-u,x=wdn(x,m,n,n-m);u=wdn(u,0,m,n))E(x=u=wdn(u,0,n,n))
       N mw=m*ZT[ut];f[xt-tB](xC+(x-u?0:mw),uC+mw,n-m))
 x-u?x(u):u)
R1(not,XF(x(ai(x==au0)))eql(x,xtsS?as(0):ac(0)))
R1(sqr,fx(N(gD(x)),sqrD))
R1(sin,fx(N(gD(x)),sinD))
R1(nul,XF(x(ai(x==au0)))eql(x,mR(cn[xt])))
R1(flr,XC(fx(x,flrC))Xc(fir(flr(enl(x))))XzZ(x)XsS(K("`$_$:",x))
 x=N(gD(x));Au=atn(xt+tl-td,xn);x2(i(un,ul=xd<0?(L)xd-(xd<(L)xd):(L)xd)u))
