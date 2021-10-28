#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define B2 H
#define H2 I
#define I2 L
#define GZ(T) (ZA/SZ(T))
#define hf(f,T,e...)     S N f(OV*RE a0,OV*RE b0,V*RE r0,Nn)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define hN(f,T,l,o)      hf(f,T,I(l,LN(a))i(PD(n,a),r[i]=a[l*i]o b[i])n) //+ and * for widest types, no overflow
#define hO(f,T,l,g,e...) hf(f,T,I(l,LN(a))Li=0;W(i<n,e;i+=g;a+=l*g;b+=g;r+=g)i) //support overflows
#define hA(f,T,l,g)      hO(f,T,l,g,T v[g],o=0;j(g,T u=a[l*j]+b[j];o|=(a[l*j]^u)&(b[j]^u);v[j]=u)P(o>>SZ(T)*8-1,i)Mc(r,v,ZA))
#define hM(f,T,l,g)      hO(f,T,l,g,T##2 v[g];j(g,v[j]=a[l*j]*(T##2)b[j])j(g,P(v[j]-(T)v[j],i))j(g,r[j]=v[j]))
#define ho(t,T)          hA(a##t##T,T,0,GZ(T))hA(a##T##T,T,1,GZ(T))hM(m##t##T,T,0,GZ(T))hM(m##T##T,T,1,GZ(T))
#define hn(t,T)          hN(a##t##T,T,0,+)hN(a##T##T,T,1,+)hN(m##t##T,T,0,*)hN(m##T##T,T,1,*)
ho(b,B)ho(h,H)ho(i,I)hn(l,L)hn(d,D)
S C tZx(Ax)_(Xz(tZ(gl_(x)))Xd(tD)XZD(xt)tn)
A adm(Ax,Ay,Iv)_(
 P(xti&&yti,Lm=xv,n=yv;az(v?m*n:m+n))
 P(xtz&&ytz,Lm=gl(x),n=gl(y);az(v?m*n:m+n))
 P((1<<xt|1<<yt)&(1<<tm|1<<tM|1<<tA),eac2f(x,y,v?mul:add))
 XcC(adm(cH(x),y,v))
 YcC(adm(x,cH(y),v))
 P(xtdD-ytdD,adm(cD(x),cD(y),v))
 Ct=max(tZx(x),tZx(y));P(t==tn,et2(x,y))
 x=Ny(cT[t](x));
 y=Nx(cT[t](y));
 Ik=2*xtT+ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))
 I(k==2||(k==3&&xr==1),SWP(x,y))
 S O TY(&abB)f[][2][5]={{{abB,ahH,aiI,alL,adD},{aBB,aHH,aII,aLL,aDD}},{{mbB,mhH,miI,mlL,mdD},{mBB,mHH,mII,mLL,mDD}}};
 Nn=yn;P(k==3&&xn-n,el2(x,y))Az=yr-1?atn(yt,n):y;Lm=f[v][k==3][yt-tB](xtP?(V*)&x:xV,yV,zV,n);
 I(m<n,I(k-3,x=cT[xt+1+tC-tc](x))E(x=wdn(x,m,n,n-m))
       I(y-z,y=wdn(y,m,n,n-m);z=wdn(z,0,m,n))E(y=z=wdn(z,0,n,n))
       N l=m*zW;f[v][k==3][yt-tB](xtP?(V*)&x:xV,yV+(y-z?0:l),zV+l,n-m))
 x(y-z?y(z):z))
