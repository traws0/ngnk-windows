#include<math.h> // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#include"a.h"
#define hf(f,T,e...) S N f(OV*RE a0,V*RE r0,Nn)_(O T*a=a0;T*r=r0;LN(a)LN(r)e)
#define NG(T) hf(neg##T,T,Ni=0;I g=ZA/SZ(T);W(i<n,I o=0;j(g,o|=a[j]==(T)(1<<SZ(T)*8-1))P(o,i)j(g,r[j]=-a[j])a+=g;r+=g;i+=g)n)
#define F1(f,T,c...) hf(f##T,T,i(PD(n,a),r[i]=({c;}))n)
TD size_t(*F1)(OV*,V*,N);NG(B)NG(H)NG(I)F1(neg,L,-a[i])F1(neg,D,-a[i])

A pen(Ax,A1*f)_(XmMA(eac1f(x,f))et1(x))
#define FX(a...) ({Ay=xr-1?atn(xt,xn):x;{a;}x-y?x(y):y;})
A1(neg,XmMA(eac1f(x,neg))Xzc(az(-gl(x)))Xd(ad(-gd(x)))XC(neg(cH(x)))
 XZD(S O F1 f[]={negB,negH,negI,negL,negD};Nn=xn;Ay=xr>1?atn(xt,n):x;Nm=f[xt-tB](xV,yV,n);
  I(m<n,I(x-y,x=wdn(x,m,n,n-m);y=wdn(y,0,m,n))E(x=y=wdn(y,0,n,n))N mw=m*yW;f[xt-tB](xV+(x-y?0:mw),yV+mw,n-m))x-y?x(y):y)
 et1(x))
A1(not,XmMA(eac1f(x,not))XF(x(ai(x==au)))eql(xtsS?as(0):ai(0),x))
A1(nul,XmMA(eac1f(x,nul))XF(x(ai(x==au)))eql(_R(cn[xt]),x))

A1(flr,Xc(fir(flr(enl(x))))XC(Az=K("`c$@[!256;65+!26;+;32]");FX(i(PD(xn,xC),yc=zC[xc])))
 XdD(Ay=atn(xt+tl-td,xn);x2(i(yn,yl=xd<0?(L)xd-(xd<(L)xd):(L)xd)y))XsS(cS(flr(str(x))))XzZ(x)XmMA(eac1f(x,flr))et1(x))

#define h(k,f) A1(k,XdD(Ay=xr-1?atn(xt,xn):x;i(PD(xn,xD),yd=f(xd));x-y?x(y):y)XmMA(eac1f(x,k))k(N(cD(x))))
h(ksin,sin)h(kcos,cos)h(klog,log)h(kexp,exp)h(sqr,__builtin_sqrt)
