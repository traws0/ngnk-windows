#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
S L c(Dd)_(Lv=*(L*)&d;v^(UL)(v>>63)>>1) //comparable double
#define hf(v,T,f) S T v(T x,T y)_(f)
#define hd(v,f,g) hf(v##b,B,f)hf(v##h,H,f)hf(v##i,I,f)hf(v##l,L,f)hf(v##d,D,g)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hd(dvd,y?x/y:0,x/y)hd(mod,x>0?(y%x+x)%x:x?y/-x:y,y-(L)(y/x)*x)
h(mnm,min(x,y))h(mxm,max(x,y))hd(ltn,x<y,c(x)<c(y))hd(gtn,x>y,c(x)>c(y))hd(eql,x==y,*(L*)&x==*(L*)&y)
#undef h
#undef hd
#undef hf

#define hF(f,T,R,e...) SN I f(O T*RE a,O T*RE b,R*RE r,Nn)_(e)
#define h0(v,t,T,R) SN I v##T##a(T*RE a,Nn,L*RE p,Nm,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))0)\
                                hF(v##T##s,T,R,R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))0)\
                                hF(v##T##p,T,R,T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)
#define ht(v,t,T,R) h0(v,t,T,R) hF(v##t##t,T,R,*r=v##t(*a,*b);0)\
                                hF(v##T##T,T,R,AL(a)AL(b)AL(r)      i(PD(n,a),*r++=v##t(*a++,*b++))0)\
                                hF(v##t##T,T,R,AL(b)AL(r)TY(*a)c=*a;i(PD(n,a),*r++=v##t(   c,*b++))0)
#define h1(v,t,T,R) ht(v,t,T,R) hF(v##T##t,T,R,AL(a)AL(r)TY(*b)c=*b;i(PD(n,a),*r++=v##t(*a++,   c))0)
#define h2(v,t,T,R) ht(v,t,T,R) hF(v##T##t,T,R,v##t##T(b,a,r,n))
#define v0(v)    h0(v,b,B,B)h0(v,h,H,H)h0(v,i,I,I)h0(v,l,L,L)h0(v,d,D,D)  //impl provided elsewhere
#define v1(v,RD) h1(v,b,B,B)h1(v,h,H,H)h1(v,i,I,I)h1(v,l,L,L)h1(v,d,D,RD) //standard Tt
#define v2(v,RD) h2(v,b,B,B)h2(v,h,H,H)h2(v,i,I,I)h2(v,l,L,L)h2(v,d,D,RD) //Tt swaps args and delegates to tT
v0(dex)v0(add)v0(sub)v0(mul)v1(dvd,D)v1(mod,D)v2(mnm,D)v2(mxm,D)v1(ltn,I)v0(gtn)v2(eql,I)

#define h(v,t,T) {v##t##t,v##t##T,v##T##t,v##T##T},
#define g(a...) {h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a){0},h(eql,a)},
S OV*arf[][7][5]={g(b,B)g(h,H)g(i,I)g(l,L)g(d,D)};
#undef g
#undef h

#define h(v,T,R,Q) SN I v##T##r(R*RE a,T*RE b,Nn)_(R c=*a;i(n,c=v##Q(c,b[i]))*a=c;n)
#define g(a...) h(dex,a)h(add,a)h(sub,a)h(mul,a)h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a)h(gtn,a)h(eql,a)
g(B,L,l)g(H,L,l)g(I,L,l)g(L,L,l)g(D,D,d)
#undef g
#undef h
#define h(x) {dex##x,add##x,sub##x,mul##x,dvd##x,mod##x,mnm##x,mxm##x,ltn##x,gtn##x,eql##x},
#define g(x) OV*ar##x[][11]={h(B##x)h(H##x)h(I##x)h(L##x)h(D##x)};
g(r)g(s)g(p)g(a)
#undef g
#undef h

S C art(Iv,Ct)_(Q(c3(tc,t,td)||c3(tC,t,tD));Q(in(v,11));Y(t>tD,t+=tD-td)v>7&&t==tD?tI:t) //arithmetic op's result type
S C tZx(Ax)_(xtdD?tD:xtlL?tL:xtcC?tH:xtZ?xt:xtz?tZ(gi(x)):tB)
I sup(A*p,A*q)_(Ax=*p,y=*q;A1*f=CH(max(tZx(x),tZx(y))-tB,&gB,gH,gI,gL,gD);*p=x=Ny(f(x));*q=y=Nx(f(y));1)
S A vv(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v),A(x,y),2))N(sup(&x,&y));Ik=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 V*a=xtP?(V*)&x:xC,*b=ytP?(V*)&y:yC;int(*f)(V*,V*,V*,N)=arf[xt-(xtt?tb:tB)][v-4][k];Ct=art(v,xt);
 Y(!k,t+=tb-tB;P(_P(t),Iv;f(a,b,&v,1);x(y(AT(t,v)))))
 Au=xt==t&&xr==1?x:yt==t&&yr==1?y:atn(t,k-1?xn:yn);f(a,b,uC,un);x==u?y(u):y==u?x(u):x(y(u)))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):vv(x,y,vi('=')))
S A ext(Ax,Nn)_(xtm?enl(x):xtt?rsh(az(n),x):x)S A2(dct,x=ext(x,yN);y=ext(y,xN);El(xN-yN,x,y)am(x,y))
A2(mod,P(xtl&&gl_(x)==NL,out(x(y)))P(xtz||xtd,vv(x,y,vi('!')))dct(x,y))
#define h(c,s) A2(s,vv(x,y,vi(c)))
A2(dex,mr(x);y)A2(sub,add(x,Nx(neg(y))))A2(gtn,ltn(y,x))h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)
#undef h
