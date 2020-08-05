#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))A1(not,xtaAX?ea1(not,x):fun(x)?ai(x==au0):eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtaAX,ea1(sqr,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=__builtin_sqrt(xdi))Y(xc-uc,xr)u)A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))
A1(flr,P(xtilIL,x)P(xtc,fir(flr(enl(x))))P(xtC,A u=aC(xn);m2(x,F(un,C c=xci;uci=c+32*c3('A',c,'Z'))u))P(xtaAX,ea1(flr,x))
 x=N(gD(x));A u=atn(xtd?tl:tL,xn);m2(x,F(un,D d=xdi;uli=d<0?(L)d-(d<(L)d):(L)d)u))

D sind(D x)_(S O D pi=3.1415927410125732,d=pi-8.742277657347586e-8, //mooooo.ooo/chebyshev-sine-approximation (public domain: /about)
 a[]={1.32913446369766718e-10,-2.33177897192836082e-8,2.52229235749396866e-6,-1.7350505791248e-4,0.00662087952180793,-0.10132118334670907};
 P(x<0,-sind(-x))Y(x>pi,x-=pi*(L)(x/pi))D q=x*x,v=0;F(6,v=v*q+a[i])(x-d)*(x+d)*v*x)
A1(sinx,P(xtaAX,ea1(sinx,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=sind(xdi))Y(xc-uc,xr)u)

S L cmpd(D x)_(L a=*(L*)&x;a^(UL)(a>>63)>>1) //comparable double
#define h(v,fi,fl,fd) S I v##i(I x,I y)_(fi) S L v##l(L x,L y)_(fl) S D v##d(D x,D y)_(fd)
#define hh(v,f) h(v,f,f,f)
hh(dex,y)hh(add,x+y)hh(sub,x-y)hh(mul,x*y)
h(dvd,y?x/y:(UI)_0Ni+(x<0)-(x>0),y?x/y:(UL)_0Nl+(x<0)-(x>0),x/y)h(mod,x>0?(y%x+x)%x:x?y/-x:_0Ni,x>0?(y%x+x)%x:x?y/-x:_0Nl,_0n)
hh(mnm,min(x,y))hh(mxm,max(x,y))h(ltn,x<y,x<y,cmpd(x)<cmpd(y))h(gtn,x>y,x>y,cmpd(x)>cmpd(y))h(eql,x==y,x==y,*(L*)&x==*(L*)&y)
#undef hh
#undef h

#define ht(v,t,T,xtT,xTt,xTT,rt)\
 S NI V v##t##t(T*RE a,T*RE b,rt*r,UL n){*r=v##t(*a,*b);}\
 S NI V v##t##T(T*RE a,T*RE b,rt*r,UL n)xtT\
 S NI V v##T##t(T*RE a,T*RE b,rt*r,UL n)xTt\
 S NI V v##T##T(T*RE a,T*RE b,rt*r,UL n)xTT\
 S NI V v##rdc##T(T*RE a,T*RE b,UL n){T c=*a;F(n,c=v##t(c,b[i]))*a=c;}\
 S NI V v##scn##T(T*RE a,T*RE b,T*RE r,UL n)_(T c=*a;F(PAD(n,b),r[i]=c=v##t(c,b[i])))\
 S NI V v##eap##T(T*RE a,T*RE b,T*RE r,UL n)_(T c=*a;F(PAD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d))\
 S NI I v##amd##T(T*RE a,UL n,L*RE p,L m,T*RE b,I d)_(F(m,L j=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))1)
#define ha(v,xiI,xIi,xII,xlL,xLl,xLL,xdD,xDd,xDD,rl,rd) ht(v,i,I,xiI,xIi,xII,I)ht(v,l,L,xlL,xLl,xLL,rl)ht(v,d,D,xdD,xDd,xDD,rd)
#define htT(f) {ALN(b)ALN(r)__typeof__(*a)c=*a;F(PAD(n,a),*r++=f(c,*b++))}
#define hTt(f) {ALN(a)ALN(r)__typeof__(*b)c=*b;F(PAD(n,a),*r++=f(*a++,c))}
#define hTT(f) {ALN(a)ALN(b)ALN(r)             F(PAD(n,a),*r++=f(*a++,*b++))}
#define hs(x) {x(b,a,r,n);}
#define h2(x) {x((V*)a,(V*)b,(V*)r,2*n);}
#define hn(x) {__typeof__(*b)c=-*b;x(a,&c,r,n);}
//     iI        Ii        II        lL        Ll        LL        dD        Dd        DD
ha(dex,htT(dexi),hTt(dexi),;        ,h2(dexiI),hTt(dexl),;        ,;        ,;        ,;        ,L,D) // : 0
ha(add,htT(addi),hs(addiI),hTT(addi),htT(addl),hs(addlL),hTT(addl),htT(addd),hs(adddD),hTT(addd),L,D) // + 1
ha(sub,htT(subi),hn(addIi),hTT(subi),htT(subl),hn(addLl),hTT(subl),htT(subd),hn(addDd),hTT(subd),L,D) // - 2
ha(mul,htT(muli),hs(muliI),hTT(muli),htT(mull),hs(mullL),hTT(mull),htT(muld),hs(muldD),hTT(muld),L,D) // * 3
ha(dvd,htT(dvdi),hTt(dvdi),hTT(dvdi),htT(dvdl),hTt(dvdl),hTT(dvdl),htT(dvdd),hTt(dvdd),hTT(dvdd),L,D) // % 4
ha(mod,htT(modi),hTt(modi),hTT(modi),htT(modl),hTt(modl),hTT(modl),htT(modd),hTt(modd),hTT(modd),L,D) // ! 5
ha(mnm,htT(mnmi),hs(mnmiI),hTT(mnmi),htT(mnml),hs(mnmlL),hTT(mnml),htT(mnmd),hs(mnmdD),hTT(mnmd),L,D) // & 6
ha(mxm,htT(mxmi),hs(mxmiI),hTT(mxmi),htT(mxml),hs(mxmlL),hTT(mxml),htT(mxmd),hs(mxmdD),hTT(mxmd),L,D) // | 7
ha(ltn,htT(ltni),hTt(ltni),hTT(ltni),htT(ltnl),hTt(ltnl),hTT(ltnl),htT(ltnd),hTt(ltnd),hTT(ltnd),L,I) // < 8
ha(gtn,hs(ltnIi),hs(ltniI),hs(ltnII),hs(ltnLl),hs(ltnlL),hs(ltnLL),hs(ltnDd),hs(ltndD),hs(ltnDD),L,I) // > 9
ha(eql,htT(eqli),hs(eqliI),hTT(eqli),htT(eqll),hs(eqllL),hTT(eqll),htT(eqld),hs(eqldD),hTT(eqld),L,I) // = 10
#undef hn
#undef h2
#undef hs
#undef hTT
#undef hTt
#undef htT
#undef ha
#undef ht

#define dexLL dexlL
#define dexII dexiI
#define dexDd dexLl
#define dexdD dexlL
#define dexDD dexLL
#define h(v,t,T) {v##t##t,v##t##T,v##T##t,v##T##T,v##rdc##T,v##scn##T,v##eap##T,v##amd##T},
O V*arf[3][11][8]={{ariths(h,i,I)},{ariths(h,l,L)},{ariths(h,d,D)}};
#undef h
#undef dexDD
#undef dexdD
#undef dexDd
#undef dexLL
#undef dexII

S A pen2(A x,A y,I v)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(v),u),4))P(xtaAX||ytaAX,eac(av(v),A_(x,y),2)) //dyadic penetrate
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));I k=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 V*a=xti?(V*)&x:xc,*b=yti?(V*)&y:yc;V(*f)(V*,V*,V*,L)=arf[xt-(xtt?ti:tI)][v][k];C t=xtiI?tI:xtlL?tL:v<8?tD:tI;
 Y(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);xr;yr;ai(r)))P(xt==t&&Ar(x)==1,m2(y,f(a,b,xc,xn);x))P(yt==t&&Ar(y)==1,m2(x,f(a,b,yc,yn);y))
 A u=atn(t,k-1?xn:yn);m2(x,m2(y,f(a,b,uc,un);u)))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):pen2(x,y,vi('=')))
A2(mod,P(xtl&&gl_(x)==_0Nl,out(dex(x,y)))P(xtil,pen2(x,y,vi('!')))
 Y(xtt||xta,Y(xta,x=enl(x))x=rsh(al(len_(y)),x))Y(ytt||yta,Y(yta,y=enl(y))y=rsh(al(len_(x)),y))El(len_(x)-len_(y),x,y)aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
