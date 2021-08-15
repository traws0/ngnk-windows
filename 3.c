#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#define B2 H
#define H2 I
#define I2 L
#define GZ(T) (ZA/SZ(T))
#define hf(f,T,e...)     S N f(OV*RE a0,OV*RE b0,V*RE r0,Nn)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define hN(f,T,l,o)      hf(f,T,I(l,LN(a))i(PD(n,a),r[i]=a[l*i]o b[i])n) //+ and * for widest types, no overflow
#define hO(f,T,l,g,e...) hf(f,T,I(l,LN(a))Li=0;W(i<n,e;j(g,r[j]=v[j])i+=g;a+=l*g;b+=g;r+=g)i) //support overflows
#define hA(f,T,l,g)      hO(f,T,l,g,T v[g];j(g,v[j]=a[l*j]+b[j])T o=0;j(g,o|=(a[l*j]^v[j])&(b[j]^v[j]))P(o>>SZ(T)*8-1,i))
#define hM(f,T,l,g)      hO(f,T,l,g,T##2 v[g];j(g,v[j]=a[l*j]*(T##2)b[j])j(g,P(v[j]-(T)v[j],i)))
#define ho(t,T)          hA(a##t##T,T,0,GZ(T))hA(a##T##T,T,1,GZ(T))hM(m##t##T,T,0,GZ(T))hM(m##T##T,T,1,GZ(T))
#define hn(t,T)          hN(a##t##T,T,0,+)hN(a##T##T,T,1,+)hN(m##t##T,T,0,*)hN(m##T##T,T,1,*)
ho(b,B)ho(h,H)ho(i,I)hn(l,L)hn(d,D)
A adm(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac2(x,y,v?MUL:ADD))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))I(k==2||(k==3&&xr==1),SWP(x,y))
 S O TY(&abB)f[][2][5]={{{abB,ahH,aiI,alL,adD},{aBB,aHH,aII,aLL,aDD}},{{mbB,mhH,miI,mlL,mdD},{mBB,mHH,mII,mLL,mDD}}};
 Nn=yn;El(k==3&&xn-n,x,y)Az=yr-1?atn(yt,n):y;Lm=f[v][k==3][yt-tB](xtP?(V*)&x:xC,yC,zC,n);
 I(m<n,I(k-3,x=ct[xt+1+tC-tc](x))E(x=wdn(x,m,n,n-m))
       I(y-z,y=wdn(y,m,n,n-m);z=wdn(z,0,m,n))E(y=z=wdn(z,0,n,n))
       N l=m*ZT[zt];f[v][k==3][yt-tB](xtP?(V*)&x:xC,yC+(y-z?0:l),zC+l,n-m))
 x(y-z?y(z):z))
