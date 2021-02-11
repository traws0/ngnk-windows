#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define  h(f,T,e...)      S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;AL(b)AL(r)e)
#define hn(f,l,T,o)      h(f,T,Y(l,AL(a))i(PD(n,a),r[i]=a[l*i]o b[i])n) //+ and * for widest types, no overflow
#define ho(f,l,T,g,e...) h(f,T,Y(l,AL(a))Li=0;W(i<n,e;j(g,r[j]=v[j])i+=g;a+=l*g;b+=g;r+=g)i)
#define hA(f,l,T,g)      ho(f,l,T,g,T v[g];j(g,v[j]=a[l*j]+b[j])T o=0;j(g,o|=(a[l*j]^v[j])&(b[j]^v[j]))P(o>>Z(T)*8-1,i))
#define hM(f,l,T,R,g)    ho(f,l,T,g,R v[g];j(g,v[j]=a[l*j]*(R)b[j])j(g,P(v[j]<=N##T||W##T<=v[j],i)))
#define ha(f,l,T)        hA(f,l,T,  (32/Z(T)))
#define hm(f,l,T,R)      hM(f,l,T,R,(32/Z(T)))
ha(ahH,0,H  )ha(aiI,0,I  )ha(aHH,1,H  )ha(aII,1,I  )hn(alL,0,L,+)hn(aLL,1,L,+)hn(adD,0,D,+)hn(aDD,1,D,+)
hm(mhH,0,H,I)hm(miI,0,I,L)hm(mHH,1,H,I)hm(mII,1,I,L)hn(mlL,0,L,*)hn(mLL,1,L,*)hn(mdD,0,D,*)hn(mDD,1,D,*)
S A f(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v?3:1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))Y(k==2||(k==3&&xr==1),SWP(x,y))
 S TY(&ahH)f[][2][4]={{{ahH,aiI,alL,adD},{aHH,aII,aLL,aDD}},{{mhH,miI,mlL,mdD},{mHH,mII,mLL,mDD}}};
 Ln=yn;El(k==3&&xn-n,x,y)Au=yr-1?atn(yt,n):y;Lm=f[v][k==3][yt-tH](xtP?(V*)&x:xC,yC,uC,n);
 Y(m<n,Y(k-3,x=CH(xt-tc,&gH,gI,gL)(x))E(x=wdn(x,m,n,n-m))
       Y(y-u,y=wdn(y,m,n,n-m);u=wdn(u,0,m,n))E(y=u=wdn(u,0,n,n))
       L mw=m*ZT[ut];f[v][k==3][yt-tH](xtP?(V*)&x:xC,yC+(y-u?0:mw),uC+mw,n-m))
 x(y-u?y(u):u))
A2(add,f(x,y,0))A2(mul,f(x,y,1))
