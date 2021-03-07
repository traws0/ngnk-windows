#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
S L cD(Dd)_(Lv=*(L*)&d;v^(UL)(v>>63)>>1) //comparable double
#define hf(v,T,f) S T v(T x,T y)_(f)
#define hh(v,fb,fh,fi,fl,fd) hf(v##b,B,fb)hf(v##h,H,fh)hf(v##i,I,fi)hf(v##l,L,fl)hf(v##d,D,fd)
#define hd(v,f,g) hh(v,f,f,f,f,g)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hd(dvd,y?x/y:0,x/y)hd(mod,x>0?(y%x+x)%x:x?y/-x:y,y-(L)(y/x)*x)
h(mnm,min(x,y))h(mxm,max(x,y))hd(ltn,x<y,cD(x)<cD(y))hd(gtn,x>y,cD(x)>cD(y))hd(eql,x==y,*(L*)&x==*(L*)&y)
#undef h

#define ht0(v,t,T,R)\
 SN I v##T##s(R*RE a,T*RE b,R*RE r,UL n)_(R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))            0)\
 SN I v##T##p(T*RE a,T*RE b,R*RE r,UL n)_(T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)\
 SN I v##T##a(T*RE a,UL n,L*RE p,L m,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))0)
#define v0(v,rl,rd) ht0(v,b,B,B)ht0(v,h,H,H)ht0(v,i,I,I)ht0(v,l,L,rl)ht0(v,d,D,rd)
#define ht(v,t,T,Tt,R) ht0(v,t,T,R)\
 SN I v##t##t(T*RE a,T*RE b,R*RE r,UL n)_(*r=v##t(*a,*b);0)\
 SN I v##t##T(T*RE a,T*RE b,R*RE r,UL n)_(AL(b)AL(r)TY(*a)c=*a;i(PD(n,a),*r++=v##t(c,*b++))0)\
 SN I v##T##t(T*RE a,T*RE b,R*RE r,UL n)Tt\
 SN I v##T##T(T*RE a,T*RE b,R*RE r,UL n)_(AL(a)AL(b)AL(r)i(PD(n,a),*r++=v##t(*a++,*b++))0)
#define v(v,Bb,Hh,Ii,Ll,Dd,rl,rd) ht(v,b,B,Bb,B)ht(v,h,H,Hh,H)ht(v,i,I,Ii,I)ht(v,l,L,Ll,rl)ht(v,d,D,Dd,rd)
#define Tt(f) _(AL(a)AL(r)TY(*b)c=*b;i(PD(n,a),*r++=f(*a++,c))0)
#define s(x) _(x(b,a,r,n))
v0(dex,L,D)v0(add,L,D)v0(sub,L,D)v0(mul,L,D)v0(gtn,L,I)
//    Bb       Hh       Ii       Ll       Dd
v(dvd,Tt(dvdb),Tt(dvdh),Tt(dvdi),Tt(dvdl),Tt(dvdd),L,D) // % 4
v(mod,Tt(modb),Tt(modh),Tt(modi),Tt(modl),Tt(modd),L,D) // ! 5
v(mnm,s(mnmbB),s(mnmhH),s(mnmiI),s(mnmlL),s(mnmdD),L,D) // & 6
v(mxm,s(mxmbB),s(mxmhH),s(mxmiI),s(mxmlL),s(mxmdD),L,D) // | 7
v(ltn,Tt(ltnb),Tt(ltnh),Tt(ltni),Tt(ltnl),Tt(ltnd),L,I) // < 8
v(eql,s(eqlbB),s(eqlhH),s(eqliI),s(eqllL),s(eqldD),L,I) // = 10
#undef Tt

#define h(v,t,T) {v##t##t,v##t##T,v##T##t,v##T##T},
#define g(a...) {0},{0},{0},{0},h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a){0},h(eql,a)
OV*arf[][11][4]={{g(b,B)},{g(h,H)},{g(i,I)},{g(l,L)},{g(d,D)}};
#undef g
#undef h

#define h(v,T,R,Q) SN I v##T##r(R*RE a,T*RE b,UL n)_(R c=*a;i(n,c=v##Q(c,b[i]))*a=c;n)
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
A2(mod,P(xtl&&gl_(x)==NL,out(x(y)))P(xtz||xtd,v2(x,y,vi('!')))dct(x,y))
A2(gtn,ltn(y,x))
#define h(c,s) A2(s,v2(x,y,vi(c)))
h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)
#undef h
