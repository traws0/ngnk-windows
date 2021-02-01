#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define f0(f,T,e...) S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define f1(f,T,e...) f0(f,T,LN(a);e)

#define h0(f,T,op) f0(f,T,i(PD(n,a),r[i]=*a   op b[i])n) //atom-list, no overflows
#define h1(f,T,op) f1(f,T,i(PD(n,a),r[i]=a[i] op b[i])n) //list-list, no overflows
h0(alL,L,+)h1(aLL,L,+)h0(mlL,L,*)h1(mLL,L,*)h0(adD,D,+)h1(aDD,D,+)h0(mdD,D,*)h1(mDD,D,*)

#define ZG 32

#define g (ZG/Z(H))
f0(ahH,H,Li=0;W(i<n,j(g,r[i+j]=*a    +b[i+j])i+=g)i)
f0(mhH,H,Li=0;W(i<n,j(g,r[i+j]=*a    *b[i+j])i+=g)i)
f1(aHH,H,Li=0;W(i<n,j(g,r[i+j]=a[i+j]+b[i+j])i+=g)i)
f1(mHH,H,Li=0;W(i<n,j(g,r[i+j]=a[i+j]*b[i+j])i+=g)i)
#undef g

#define g (ZG/Z(I))
f0(aiI,I,Li=0;W(i<n,j(g,r[i+j]=*a    +b[i+j])i+=g)i)
f0(miI,I,Li=0;W(i<n,j(g,r[i+j]=*a    *b[i+j])i+=g)i)
f1(aII,I,Li=0;W(i<n,j(g,r[i+j]=a[i+j]+b[i+j])i+=g)i)
f1(mII,I,Li=0;W(i<n,j(g,r[i+j]=a[i+j]*b[i+j])i+=g)i)
#undef g

A2(add,P(xtmMA||ytmMA,eac(av(1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;P(!k,Xd(ad(gd(x)+gd(y)))az(gl(x)+gl(y)))
 Y(k==2||(k==3&&xr==1),SWP(x,y))El(k==3&&xn-yn,x,y)
 Au=yr-1?atn(yt,yn):y;CH(yt-tH+4*(k==3),&ahH,aiI,alL,adD,aHH,aII,aLL,aDD)(xtP?(V*)&x:xC,yC,uC,un);x(y-u?y(u):u))
A2(mul,P(xtmMA||ytmMA,eac(av(3),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;P(!k,Xd(ad(gd(x)*gd(y)))az(gl(x)*gl(y)))
 Y(k==2||(k==3&&xr==1),SWP(x,y))El(k==3&&xn-yn,x,y)
 Au=yr-1?atn(yt,yn):y;CH(yt-tH+4*(k==3),&mhH,miI,mlL,mdD,mHH,mII,mLL,mDD)(xtP?(V*)&x:xC,yC,uC,un);x(y-u?y(u):u))
