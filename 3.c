#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define v2(f,T,e...) S L f(OV*RE a0,OV*RE b0,V*RE r0,Ln)_(O T*a=a0,*b=b0;T*r=r0;LN(b)LN(r)e)
#define V2(f,T,e...) v2(f,T,LN(a);e)

#define h0(f,T,op) v2(f,T,i(PD(n,a),r[i]=*a   op b[i])n) //atom-list, no overflows
#define h1(f,T,op) V2(f,T,i(PD(n,a),r[i]=a[i] op b[i])n) //list-list, no overflows
h0(alL,L,+)h1(aLL,L,+)h0(mlL,L,*)h1(mLL,L,*)h0(adD,D,+)h1(aDD,D,+)h0(mdD,D,*)h1(mDD,D,*)

#define g (32/Z(H))
v2(ahH,H,Li=0;W(i<n,j(g,r[i+j]=*a    +b[i+j])i+=g)i)
v2(mhH,H,Li=0;W(i<n,j(g,r[i+j]=*a    *b[i+j])i+=g)i)
V2(aHH,H,Li=0;W(i<n,j(g,r[i+j]=a[i+j]+b[i+j])i+=g)n)
V2(mHH,H,Li=0;W(i<n,j(g,r[i+j]=a[i+j]*b[i+j])i+=g)n)
#undef g

#define g (32/Z(I))
v2(aiI,I,Li=0;W(i<n,j(g,r[i+j]=*a    +b[i+j])i+=g)i)
v2(miI,I,Li=0;W(i<n,j(g,r[i+j]=*a    *b[i+j])i+=g)i)
V2(aII,I,Li=0;W(i<n,j(g,r[i+j]=a[i+j]+b[i+j])i+=g)n)
V2(mII,I,Li=0;W(i<n,j(g,r[i+j]=a[i+j]*b[i+j])i+=g)n)
#undef g

A2(add,P(xtmMA||ytmMA,eac(av(1),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;P(!k,Xd(ad(gd(x)+gd(y)))az(gl(x)+gl(y)))
 Y(k==2||(k==3&&xr==1),SWP(x,y))El(k==3&&xn-yn,x,y)
 Au=yr-1?atn(yt,yn):y;CH(yt-tH+4*(k==3),&ahH,aiI,alL,adD,aHH,aII,aLL,aDD)(xtP?(V*)&x:xC,yC,uC,un);x(y-u?y(u):u))
A2(mul,P(xtmMA||ytmMA,eac(av(3),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;P(!k,Xd(ad(gd(x)*gd(y)))az(gl(x)*gl(y)))
 Y(k==2||(k==3&&xr==1),SWP(x,y))El(k==3&&xn-yn,x,y)
 Au=yr-1?atn(yt,yn):y;CH(yt-tH+4*(k==3),&mhH,miI,mlL,mdD,mHH,mII,mLL,mDD)(xtP?(V*)&x:xC,yC,uC,un);x(y-u?y(u):u))
