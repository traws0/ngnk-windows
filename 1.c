#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define R1(f,a...) A1(f,XmMA(ea1(f,x))a)
#define ngT(T,bb...) SN I ng##T(OV*a0,V*r0,Ln)_(O T*a=a0;T*r=r0;LN(a)LN(r)Cb=0;i(PD(n,a),bb;r[i]=-a[i])b)
ngT(H,b|=a[i]==NH)ngT(I,b|=a[i]==NI)ngT(L)ngT(D)
R1(neg,Xz(az(-gl(x)))Xd(ad(-gd(x)))XcC(neg(gH(x)))P(!c3(tH,xt,tD),et1(x))
 Au=xr>1?atn(xt,xn):x;CH(xt-tH,(int(*)(OV*,V*,L))(V*)&ngH,(V*)ngI,(V*)ngL,(V*)ngD)(xC,uC,xn);x==u?u:x(u))
R1(not,XF(x(ah(x==au0)))eql(x,xtsS?as(0):ac(0)))
R1(sqr,x=N(gD(x));Au=xr-1?atn(xt,xn):x;iud(__builtin_sqrt(xd));x==u?u:x(u))
R1(nul,eql(x,mR(cn[xt])))
R1(flr,Xc(fir(flr(enl(x))))XC(Au=aC(xn);m2(x,iuc(xc+32*c3('A',xc,'Z'))))XzZ(x)XsS(K("`$_$:",x))
 x=N(gD(x));Au=atn(xtd?tl:tL,xn);m2(x,iul(xd<0?(L)xd-(xd<(L)xd):(L)xd)))
//mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
S D sinD(D x)_(S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,
  -2.33177897192836082e-8,2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sinD(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)
R1(sin,x=N(gD(x));Au=xr-1?atn(xt,xn):x;iud(sinD(xd));xC==uC?u:x(u))
