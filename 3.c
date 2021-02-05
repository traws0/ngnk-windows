#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define IF(x,y...) IF##x(y)
#define IF0(x)
#define IF1(x) x

#define h(f,T,e...) S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define hn(l,f,T,o) h(f,T,IF(l,LN(a));i(PD(n,a),r[i]=a[IF(l,i+)0]o b[i])n)
hn(0,alL,L,+)hn(1,aLL,L,+)hn(0,mlL,L,*)hn(1,mLL,L,*)hn(0,adD,D,+)hn(1,aDD,D,+)hn(0,mdD,D,*)hn(1,mDD,D,*)

#define G(T) (32/Z(T))
#define ha(l,f,T,R) h(f,T,IF(l,LN(a));T v[G(T)];Li=0;\
  W(i<n,\
   j(G(T),v[j]=a[IF(l,j+)0]+b[j])\
   T o=0;j(G(T),o|=(a[IF(l,j+)0]^v[j])&(b[j]^v[j]))P(o>>Z(T)*8-1,i)\
   j(G(T),r[j]=v[j])\
   i+=G(T);IF(l,a+=G(T));b+=G(T);r+=G(T))\
  i)
#define hm(l,f,T,R) h(f,T,IF(l,LN(a));R v[G(T)];Li=0;\
  W(i<n,\
   j(G(T),v[j]=a[IF(l,j+)0]*(R)b[j])\
   j(G(T),P(v[j]<N##T||W##T<v[j],i))\
   j(G(T),r[j]=v[j])\
   i+=G(T);IF(l,a+=G(T));b+=G(T);r+=G(T))\
  i)
ha(0,ahH,H,I)ha(0,aiI,I,L)ha(1,aHH,H,I)ha(1,aII,I,L) //+
hm(0,mhH,H,I)hm(0,miI,I,L)hm(1,mHH,H,I)hm(1,mII,I,L) //*

S A w(Ax,Li,Lj,Ln)_(Ct=xt;Q(c3(tC,t,tI));Au=atn(t+1,n);wf[t-tC](xC+ZT[t]*i,uC,j-i);x(u)) //widen
SN A f(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v?3:1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))Y(k==2||(k==3&&xr==1),SWP(x,y))
 S TY(&ahH)f[]={ahH,aiI,alL,adD,aHH,aII,aLL,aDD,mhH,miI,mlL,mdD,mHH,mII,mLL,mDD};
 Ln=yn;El(k==3&&xn-n,x,y)Au=yr-1?atn(yt,n):y;Lm=f[yt-tH+4*(k==3)+8*v](xtP?(V*)&x:xC,yC,uC,n);
 Y(m<n,
  Y(k-3,x=CH(xt-tc,&gH,gI,gL)(x))E(x=w(x,m,n,n-m))
  Y(y-u,y=w(y,m,n,n-m);u=w(u,0,m,n))E(y=u=w(u,0,n,n))
  L mw=m*ZT[ut];f[yt-tH+4*(k==3)+8*v](xtP?(V*)&x:xC,yC+(y-u?0:mw),uC+mw,n-m))
 x(y-u?y(u):u))
A2(add,f(x,y,0))A2(mul,f(x,y,1))
