#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
S L cD(Dd)_(Lv=*(L*)&d;v^(UL)(v>>63)>>1) //comparable double
#define hh(v,fb,fh,fi,fl,fd) S B v##b(B x,B y)_(fb) S H v##h(H x,H y)_(fh) S I v##i(I x,I y)_(fi) S L v##l(L x,L y)_(fl) S D v##d(D x,D y)_(fd)
#define hd(v,f_,fd) hh(v,f_,f_,f_,f_,fd)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hd(dvd,y?x/y:0,x/y)hd(mod,x>0?(y%x+x)%x:x?y/-x:y,ND)
h(mnm,min(x,y))h(mxm,max(x,y))hd(ltn,x<y,cD(x)<cD(y))hd(gtn,x>y,cD(x)>cD(y))hd(eql,x==y,*(L*)&x==*(L*)&y)
#undef h

#define ht(v,t,T,tT,Tt,TT,R) ht0(v,t,T,R)\
 SN I v##t##t(T*RE a,T*RE b,R*RE r,UL n)_(*r=v##t(*a,*b);0)\
 SN I v##t##T(T*RE a,T*RE b,R*RE r,UL n)tT\
 SN I v##T##t(T*RE a,T*RE b,R*RE r,UL n)Tt\
 SN I v##T##T(T*RE a,T*RE b,R*RE r,UL n)TT
#define ht0(v,t,T,R)\
 SN I v##T##s(R*RE a,T*RE b,R*RE r,UL n)_(R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))            0)\
 SN I v##T##p(T*RE a,T*RE b,R*RE r,UL n)_(T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)\
 SN I v##T##a(T*RE a,UL n,L*RE p,L m,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))0)
#define v(v,bB,Bb,BB,hH,Hh,HH,iI,Ii,II,lL,Ll,LL,dD,Dd,DD,rl,rd) \
 ht(v,b,B,bB,Bb,BB,B)ht(v,h,H,hH,Hh,HH,H)ht(v,i,I,iI,Ii,II,I)ht(v,l,L,lL,Ll,LL,rl)ht(v,d,D,dD,Dd,DD,rd)
#define v0(v,rl,rd) ht0(v,b,B,B)ht0(v,h,H,H)ht0(v,i,I,I)ht0(v,l,L,rl)ht0(v,d,D,rd)
#define tT(f) _(AL(b)AL(r)TY(*a)c=*a;i(PD(n,a),*r++=f(c,*b++))0)
#define Tt(f) _(AL(a)AL(r)TY(*b)c=*b;i(PD(n,a),*r++=f(*a++,c))0)
#define TT(f) _(AL(a)AL(b)AL(r)      i(PD(n,a),*r++=f(*a++,*b++))0)
#define s(x) _(x(b,a,r,n))
#define n(x) _(TY(*b)c=-*b;x(a,&c,r,n))
//    bB       Bb       BB       hH       Hh       HH       iI       Ii       II       lL       Ll       LL       dD       Dd       DD
v(dvd,tT(dvdb),Tt(dvdb),TT(dvdb),tT(dvdh),Tt(dvdh),TT(dvdh),tT(dvdi),Tt(dvdi),TT(dvdi),tT(dvdl),Tt(dvdl),TT(dvdl),tT(dvdd),Tt(dvdd),TT(dvdd),L,D) // % 4
v(mod,tT(modb),Tt(modb),TT(modb),tT(modh),Tt(modh),TT(modh),tT(modi),Tt(modi),TT(modi),tT(modl),Tt(modl),TT(modl),tT(modd),Tt(modd),TT(modd),L,D) // ! 5
v(mnm,tT(mnmb),s(mnmbB),TT(mnmb),tT(mnmh),s(mnmhH),TT(mnmh),tT(mnmi),s(mnmiI),TT(mnmi),tT(mnml),s(mnmlL),TT(mnml),tT(mnmd),s(mnmdD),TT(mnmd),L,D) // & 6
v(mxm,tT(mxmb),s(mxmbB),TT(mxmb),tT(mxmh),s(mxmhH),TT(mxmh),tT(mxmi),s(mxmiI),TT(mxmi),tT(mxml),s(mxmlL),TT(mxml),tT(mxmd),s(mxmdD),TT(mxmd),L,D) // | 7
v(ltn,tT(ltnb),Tt(ltnb),TT(ltnb),tT(ltnh),Tt(ltnh),TT(ltnh),tT(ltni),Tt(ltni),TT(ltni),tT(ltnl),Tt(ltnl),TT(ltnl),tT(ltnd),Tt(ltnd),TT(ltnd),L,I) // < 8
v(eql,tT(eqlb),s(eqlbB),TT(eqlb),tT(eqlh),s(eqlhH),TT(eqlh),tT(eqli),s(eqliI),TT(eqli),tT(eqll),s(eqllL),TT(eqll),tT(eqld),s(eqldD),TT(eqld),L,I) // = 10
v0(dex,L,D)v0(add,L,D)v0(sub,L,D)v0(mul,L,D)v0(gtn,L,I)
#undef Tt
#undef tT

#define h(v,t,T) {v##t##t,v##t##T,v##T##t,v##T##T},
#define g(a...) {0},{0},{0},{0},h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a){0},h(eql,a)
OV*arf[][11][4]={{g(b,B)},{g(h,H)},{g(i,I)},{g(l,L)},{g(d,D)}};
#undef g
#undef h

#define h(v,T,R,r0) SN I v##T##r(R*RE a,T*RE b,UL n)_(R c=*a;i(n,c=v##r0(c,b[i]))*a=c;n)
#define g(a...) h(dex,a)h(add,a)h(sub,a)h(mul,a)h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a)h(gtn,a)h(eql,a)
g(B,L,l)g(H,L,l)g(I,L,l)g(L,L,l)g(D,D,d)
#undef g
#undef h
#define h(x) {dex##x,add##x,sub##x,mul##x,dvd##x,mod##x,mnm##x,mxm##x,ltn##x,gtn##x,eql##x},
#define g(x) OV*ar##x[][11]={h(B##x)h(H##x)h(I##x)h(L##x)h(D##x)};
g(r)g(s)g(p)g(a)
#undef g
#undef h

C art(Iv,Ct)_(Q(c3(tc,t,td)||c3(tC,t,tD));Q(in(v,11));Y(t>tD,t+=tD-td)v>7&&t==tD?tI:t) //arithmetic op's result type
I sup(A*p,A*q)_(Ax=*p,y=*q;Ct=max(tH/*todo*/,min(tD,max(tT(xt),tT(yt))));A1*f=CH(t-tB,&gB,gH,gI,gL,gD);*p=x=Ny(f(x));*q=y=Nx(f(y));t)
S A v2(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 V*a=xtP?(V*)&x:xC,*b=ytP?(V*)&y:yC;int(*f)(V*,V*,V*,L)=arf[xt-(xtt?tb:tB)][v][k];Ct=art(v,xt);
 Y(!k,t+=tb-tB;P(_P(t),Iv;f(a,b,&v,1);x(y(AT(t,v)))))
 Au=xt==t&&xr==1?x:yt==t&&yr==1?y:atn(t,k-1?xn:yn);f(a,b,uC,un);x==u?y(u):y==u?x(u):x(y(u)))
A2(dex,mr(x);y)
A2(sub,add(x,Nx(neg(y))))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):v2(x,y,vi('=')))
S A ext(Ax,Ln)_(xtm?enl(x):xtt?rsh(az(n),x):x)
S A2(dct,x=ext(x,yN);y=ext(y,xN);El(xN-yN,x,y)am(x,y))
A2(mod,P(xtl&&gl_(x)==NL,out(x(y)))Xz(v2(x,y,vi('!')))dct(x,y))
A2(gtn,ltn(y,x))
#define h(c,s) A2(s,v2(x,y,vi(c)))
h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)
#undef h
