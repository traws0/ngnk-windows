#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))
A1(not,P(xtmMA,ea1(not,x))P(fun(x),I r=x==au0;xr;ai(r))eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtmMA,ea1(sqr,x))x=N(gD(x));Au=Ar(x)-1?atn(xt,xn):x;i(un,ud=__builtin_sqrt(xd))Y(xC-uC,xr)u)
A1(nul,P(xtmMA,ea1(nul,x))eql(x,mR(cn[xt])))
A1(flr,P(xtmMA,ea1(flr,x))P(xtilIL,x)P(xtc,fir(flr(enl(x))))P(xtC,Au=aC(xn);m2(x,i(un,Cc=xc;uc=c+32*c3('A',c,'Z'))u))
 x=N(gD(x));Au=atn(xtd?tl:tL,xn);m2(x,i(un,Dd=xd;ul=d<0?(L)d-(d<(L)d):(L)d)u))
//mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
S D sinD(D x)_(S O D pi=3.14159265358979323846,d=pi-8.742277657347586e-8,a[]={1.32913446369766718e-10,
  -2.33177897192836082e-8,2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sinD(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;i(6,v=v*q+a[i])(x-d)*(x+d)*v*x)
A1(sin,P(xtmMA,ea1(sin,x))x=N(gD(x));Au=Ar(x)-1?atn(xt,xn):x;i(un,ud=sinD(xd))Y(xC-uC,xr)u)

S L cD(Dd)_(Lv=*(L*)&d;v^(UL)(v>>63)>>1) //comparable double
#define h(v,fi,fl,fd) S I v##i(I x,I y)_(fi) S L v##l(L x,L y)_(fl) S D v##d(D x,D y)_(fd)
#define hh(v,f) h(v,f,f,f)
hh(dex,y)hh(add,x+y)hh(sub,x-y)hh(mul,x*y)h(dvd,y?x/y:(UI)NI+(x<0)-(x>0),y?x/y:(UL)NL+(x<0)-(x>0),x/y)
h(mod,x>0?(y%x+x)%x:x?y/-x:NI,x>0?(y%x+x)%x:x?y/-x:NL,ND)hh(mnm,min(x,y))hh(mxm,max(x,y))
h(ltn,x<y,x<y,cD(x)<cD(y))h(gtn,x>y,x>y,cD(x)>cD(y))h(eql,x==y,x==y,*(L*)&x==*(L*)&y)
#undef h

#define ht(v,t,T,xtT,xTt,xTT,rt)\
 SN V v##t##t(T*RE a,T*RE b,rt*r,UL n){*r=v##t(*a,*b);}\
 SN V v##t##T(T*RE a,T*RE b,rt*r,UL n)xtT\
 SN V v##T##t(T*RE a,T*RE b,rt*r,UL n)xTt\
 SN V v##T##T(T*RE a,T*RE b,rt*r,UL n)xTT\
 SN V v##rdc##T(T*RE a,T*RE b,UL n){T c=*a;i(n,c=v##t(c,b[i]))*a=c;}\
 SN V v##scn##T(T*RE a,T*RE b,T*RE r,UL n)_(T c=*a;i(PAD(n,b),r[i]=c=v##t(c,b[i])))\
 SN V v##eap##T(T*RE a,T*RE b,T*RE r,UL n)_(T c=*a;i(PAD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d))\
 SN I v##amd##T(T*RE a,UL n,L*RE p,L m,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))1)
#define v(v,iI,Ii,II,lL,Ll,LL,dD,Dd,DD,rl,rd) ht(v,i,I,iI,Ii,II,I)ht(v,l,L,lL,Ll,LL,rl)ht(v,d,D,dD,Dd,DD,rd)
#define tT(f) {ALN(b)ALN(r)TY(*a)c=*a;i(PAD(n,a),*r++=f(c,*b++))}
#define Tt(f) {ALN(a)ALN(r)TY(*b)c=*b;i(PAD(n,a),*r++=f(*a++,c))}
#define TT(f) {ALN(a)ALN(b)ALN(r)     i(PAD(n,a),*r++=f(*a++,*b++))}
#define s(x) {x(b,a,r,n);}
#define n(x) {TY(*b)c=-*b;x(a,&c,r,n);}
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

S A v2(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac(av(v),A(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));Ik=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 V*a=xti?(V*)&x:xC,*b=yti?(V*)&y:yC;V(*f)(V*,V*,V*,L)=arf[xt-(xtt?ti:tI)][v][k];Ct=xtiI?tI:xtlL?tL:v<8?tD:tI;
 Y(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);xr;yr;ai(r)))P(xt==t&&Ar(x)==1,m2(y,f(a,b,xC,xn);x))
 P(yt==t&&Ar(y)==1,m2(x,f(a,b,yC,yn);y))Au=atn(t,k-1?xn:yn);m2(x,m2(y,f(a,b,uC,un);u)))
A2(dex,xr;y)
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):v2(x,y,vi('=')))
A2(mod,P(xtl&&gl_(x)==NL,out(dex(x,y)))P(xtil,v2(x,y,vi('!')))
 Y(xtt||xtm,Y(xtm,x=enl(x))x=rsh(al(len_(y)),x))
 Y(ytt||ytm,Y(ytm,y=enl(y))y=rsh(al(len_(x)),y))
 El(len_(x)-len_(y),x,y)am(x,y))
A2(gtn,ltn(y,x))
#define h(c,s) A2(s,v2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)
#undef h
