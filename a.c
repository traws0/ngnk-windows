#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
A1(neg,sub(ai(0),x))
#define R1(f,a...) A1(f,P(xtmMA,ea1(f,x))a)
R1(not,P(fun(x),I r=x==au0;x(ai(r)))eql(x,xtsS?as(0):ac(0)))
R1(sqr,x=N(gD(x));Au=Ar(x)-1?atn(xt,xn):x;i(un,ud=__builtin_sqrt(xd))xC==uC?u:x(u))
R1(nul,eql(x,mR(cn[xt])))
R1(flr,Xc(fir(flr(enl(x))))XC(Au=aC(xn);m2(x,i(un,uc=xc+32*c3('A',xc,'Z'))u))P(xtilIL,x)
 x=N(gD(x));Au=atn(xtd?tl:tL,xn);m2(x,i(un,ul=xd<0?(L)xd-(xd<(L)xd):(L)xd)u))
//mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
S D sinD(D x)_(S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,
  -2.33177897192836082e-8,2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sinD(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)
R1(sin,x=N(gD(x));Au=Ar(x)-1?atn(xt,xn):x;i(un,ud=sinD(xd))xC==uC?u:x(u))

S L cD(Dd)_(Lv=*(L*)&d;v^(UL)(v>>63)>>1) //comparable double
#define hh(v,fi,fl,fd) S I v##i(I x,I y)_(fi) S L v##l(L x,L y)_(fl) S D v##d(D x,D y)_(fd)
#define hd(v,f_,fd) hh(v,f_,f_,fd)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hd(dvd,y?x/y:0,x/y)hd(mod,x>0?(y%x+x)%x:x?y/-x:y,ND)
h(mnm,min(x,y))h(mxm,max(x,y))hd(ltn,x<y,cD(x)<cD(y))hd(gtn,x>y,cD(x)>cD(y))hd(eql,x==y,*(L*)&x==*(L*)&y)
#undef h

#define ht(v,t,T,tT,Tt,TT,R)\
 SN I v##t##t(T*RE a,T*RE b,R*r,UL n)_(*r=v##t(*a,*b);0)\
 SN I v##t##T(T*RE a,T*RE b,R*r,UL n)tT\
 SN I v##T##t(T*RE a,T*RE b,R*r,UL n)Tt\
 SN I v##T##T(T*RE a,T*RE b,R*r,UL n)TT\
 SN I v##rdc##T(R*RE a,T*RE b,       UL n)_(R c=*a;i(n      ,     c=v##t(c,b[i]))       *a=c;0)\
 SN I v##scn##T(R*RE a,T*RE b,R*RE r,UL n)_(R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))            0)\
 SN I v##eap##T(T*RE a,T*RE b,R*RE r,UL n)_(T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)\
 SN I v##amd##T(T*RE a,UL n,L*RE p,L m,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))0)
#define v(v,iI,Ii,II,lL,Ll,LL,dD,Dd,DD,rl,rd) ht(v,i,I,iI,Ii,II,I)ht(v,l,L,lL,Ll,LL,rl)ht(v,d,D,dD,Dd,DD,rd)
#define tT(f) _(LN(b)LN(r)TY(*a)c=*a;i(PD(n,a),*r++=f(c,*b++))0)
#define Tt(f) _(LN(a)LN(r)TY(*b)c=*b;i(PD(n,a),*r++=f(*a++,c))0)
#define TT(f) _(LN(a)LN(b)LN(r)      i(PD(n,a),*r++=f(*a++,*b++))0)
#define s(x) _(x(b,a,r,n))
#define n(x) _(TY(*b)c=-*b;x(a,&c,r,n))
//    iI       Ii       II       lL       Ll       LL       dD       Dd       DD
v(dex,;       ,;       ,;       ,;       ,;       ,;       ,;       ,;       ,;       ,L,D) // : 0
v(add,tT(addi),s(addiI),TT(addi),tT(addl),s(addlL),TT(addl),tT(addd),s(adddD),TT(addd),L,D) // + 1
v(sub,tT(subi),n(addIi),TT(subi),tT(subl),n(addLl),TT(subl),tT(subd),n(addDd),TT(subd),L,D) // - 2
v(mul,tT(muli),s(muliI),TT(muli),tT(mull),s(mullL),TT(mull),tT(muld),s(muldD),TT(muld),L,D) // * 3
v(dvd,tT(dvdi),Tt(dvdi),TT(dvdi),tT(dvdl),Tt(dvdl),TT(dvdl),tT(dvdd),Tt(dvdd),TT(dvdd),L,D) // % 4
v(mod,tT(modi),Tt(modi),TT(modi),tT(modl),Tt(modl),TT(modl),tT(modd),Tt(modd),TT(modd),L,D) // ! 5
v(mnm,tT(mnmi),s(mnmiI),TT(mnmi),tT(mnml),s(mnmlL),TT(mnml),tT(mnmd),s(mnmdD),TT(mnmd),L,D) // & 6
v(mxm,tT(mxmi),s(mxmiI),TT(mxmi),tT(mxml),s(mxmlL),TT(mxml),tT(mxmd),s(mxmdD),TT(mxmd),L,D) // | 7
v(ltn,tT(ltni),Tt(ltni),TT(ltni),tT(ltnl),Tt(ltnl),TT(ltnl),tT(ltnd),Tt(ltnd),TT(ltnd),L,I) // < 8
v(gtn,;       ,;       ,;       ,;       ,;       ,;       ,;       ,;       ,;       ,L,I) // > 9
v(eql,tT(eqli),s(eqliI),TT(eqli),tT(eqll),s(eqllL),TT(eqll),tT(eqld),s(eqldD),TT(eqld),L,I) // = 10

#define  h(v,t,T) {v##t##t,v##t##T,v##T##t,v##T##T,v##rdc##T,v##scn##T,v##eap##T,v##amd##T},
#define h0(v,t,T) {0      ,0      ,0      ,0      ,v##rdc##T,v##scn##T,v##eap##T,v##amd##T},
#define hA(a...)  h0(dex,a)h(add,a)h(sub,a)h(mul,a)h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a)h0(gtn,a)h(eql,a)
OV*arf[3][11][8]={{hA(i,I)},{hA(l,L)},{hA(d,D)}};
#undef h

C art(Iv,Ct)_(Q(c3(tc,t,td)||c3(tC,t,tD));Q(in(v,11));Y(t>tD,t+=tD-td)v>7&&t==tD?tI:t) //arithmetic op's result type
S A v2(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v),A(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));Ik=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 V*a=xti?(V*)&x:xC,*b=yti?(V*)&y:yC;int(*f)(V*,V*,V*,L)=arf[xt-(xtt?ti:tI)][v][k];Ct=art(v,xt);
 Y(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);x(y(ai(r)))))P(xt==t&&Ar(x)==1,m2(y,f(a,b,xC,xn);x))
 P(yt==t&&Ar(y)==1,m2(x,f(a,b,yC,yn);y))Au=atn(t,k-1?xn:yn);m2(x,m2(y,f(a,b,uC,un);u)))
A2(dex,mr(x);y)
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):v2(x,y,vi('=')))
S A ext(Ax,Ln)_(xtm?enl(x):xtt?rsh(al(n),x):x)
S A2(dct,x=ext(x,len_(y));y=ext(y,len_(x));El(len_(x)-len_(y),x,y)am(x,y))
A2(mod,P(xtl&&gl_(x)==NL,out(x(y)))P(c3(tc,xt,tl),v2(x,y,vi('!')))dct(x,y))
A2(gtn,ltn(y,x))
#define h(c,s) A2(s,v2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)
#undef h
