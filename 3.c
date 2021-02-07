#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define h(f,T,e...) S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define hn(l,f,T,o) h(f,T,Y(l,LN(a))i(PD(n,a),r[i]=a[l*i]o b[i])n) //+ and * for widest types, no overflow
hn(0,alL,L,+)hn(1,aLL,L,+)hn(0,mlL,L,*)hn(1,mLL,L,*)hn(0,adD,D,+)hn(1,aDD,D,+)hn(0,mdD,D,*)hn(1,mDD,D,*)

#define G(T) (32/Z(T))
#define ho(l,f,T,e...) h(f,T,Y(l,LN(a))Li=0;W(i<n,e;j(G(T),r[j]=v[j])i+=G(T);a+=l*G(T);b+=G(T);r+=G(T))i)
#define ha(l,f,T)   ho(l,f,T,T v[G(T)];j(G(T),v[j]=a[l*j]+b[j])T o=0;j(G(T),o|=(a[l*j]^v[j])&(b[j]^v[j]))P(o>>Z(T)*8-1,i))
#define hm(l,f,T,R) ho(l,f,T,R v[G(T)];j(G(T),v[j]=a[l*j]*(R)b[j])j(G(T),P(v[j]<=N##T||W##T<=v[j],i)))
ha(0,ahH,H  )ha(0,aiI,I  )ha(1,aHH,H  )ha(1,aII,I  ) //+
hm(0,mhH,H,I)hm(0,miI,I,L)hm(1,mHH,H,I)hm(1,mII,I,L) //*

S A w(Ax,Li,Lj,Ln)_(Ct=xt;Q(c3(tC,t,tI));Au=atn(t+1,n);wf[t-tC](xC+ZT[t]*i,uC,j-i);x(u)) //widen
SN A f(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v?3:1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))Y(k==2||(k==3&&xr==1),SWP(x,y))
 S TY(&ahH)f[2][2][4]={{{ahH,aiI,alL,adD},{aHH,aII,aLL,aDD}},{{mhH,miI,mlL,mdD},{mHH,mII,mLL,mDD}}};
 Ln=yn;El(k==3&&xn-n,x,y)Au=yr-1?atn(yt,n):y;Lm=f[v][k==3][yt-tH](xtP?(V*)&x:xC,yC,uC,n);
 Y(m<n,
  Y(k-3,x=CH(xt-tc,&gH,gI,gL)(x))E(x=w(x,m,n,n-m))
  Y(y-u,y=w(y,m,n,n-m);u=w(u,0,m,n))E(y=u=w(u,0,n,n))
  L mw=m*ZT[ut];f[v][k==3][yt-tH](xtP?(V*)&x:xC,yC+(y-u?0:mw),uC+mw,n-m))
 x(y-u?y(u):u))
A2(add,f(x,y,0))A2(mul,f(x,y,1))
