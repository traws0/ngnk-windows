#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define f0(f,T,e...) S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define f1(f,T,e...) f0(f,T,LN(a);e)
#define h0(f,T,op) f0(f,T,i(PD(n,a),r[i]=a[0] op b[i])n) //atom op list, no overflows
#define h1(f,T,op) f1(f,T,i(PD(n,a),r[i]=a[i] op b[i])n) //list op list, no overflows
h0(alL,L,+)h1(aLL,L,+)h0(mlL,L,*)h1(mLL,L,*)h0(adD,D,+)h1(aDD,D,+)h0(mdD,D,*)h1(mDD,D,*)
#define G(T) (32/Z(T))
#define g0(f,T,T1,op) f0(f,T,Li=0;W(i<n,T1 v[G(T)];j(G(T),v[j]=a[0]op b[j])j(G(T),P(v[j]<N##T||W##T<v[j],i))j(G(T),r[j]=v[j])i+=G(T);        b+=G(T);r+=G(T))i)
#define g1(f,T,T1,op) f1(f,T,Li=0;W(i<n,T1 v[G(T)];j(G(T),v[j]=a[j]op b[j])j(G(T),P(v[j]<N##T||W##T<v[j],i))j(G(T),r[j]=v[j])i+=G(T);a+=G(T);b+=G(T);r+=G(T))i)
g0(ahH,H,I,+)g0(aiI,I,L,+)g0(mhH,H,I,*)g0(miI,I,L,*)g1(aHH,H,I,+)g1(aII,I,L,+)g1(mHH,H,I,*)g1(mII,I,L,*)

SN A adm(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v?3:1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(!k,Xd(ad(v?gd(x)*gd(y):gd(x)+gd(y)))az(v?gl(x)*gl(y):gl(x)+gl(y)))Y(k==2||(k==3&&xr==1),SWP(x,y))El(k==3&&xn-yn,x,y)
 Au=yr-1?atn(yt,yn):y;
 Lm=CH(yt-tH+4*(k==3)+8*v,&ahH,aiI,alL,adD,aHH,aII,aLL,aDD,mhH,miI,mlL,mdD,mHH,mII,mLL,mDD)(xtP?(V*)&x:xC,yC,uC,un);
 Y(m<yn,write(1,"OVERFLOW\n",9);exit(1))
 x(y-u?y(u):u))
A2(add,adm(x,y,0))
A2(mul,adm(x,y,1))
