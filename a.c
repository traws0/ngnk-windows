#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))A1(not,xtaAX?ea1(not,x):fun(x)?x==au0:eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtaAX,ea1(sqr,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=__builtin_sqrt(xdi))Y(xc-uc,xr)u)
A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))S C lwc(C c)_(c+32*c3('A',c,'Z'))S L fl1(D d)_(d<0?(L)d-(d<(L)d):(L)d)
A1(flr,P(xtilIL,x)P(xtc,ac(lwc(gc(x))))P(xtC,A u=aC(xn);mr2(x,F(un,uci=lwc(xci))u))P(xtaAX,ea1(flr,x))
 x=N(gD(x));A u=atn(xtd?tl:tL,xn);mr2(x,F(un,uli=fl1(xdi))u))

S L cmpd(D x)_(L a=*(L*)&x;a^((UL)(a>>63)>>1)) //comparable double
#define h(v,fi,fl,fd) S I v##i(I x,I y)_(fi) S L v##l(L x,L y)_(fl) S D v##d(D x,D y)_(fd)
#define hh(v,f) h(v,f,f,f)
hh(dex,y)hh(add,x+y)hh(sub,x-y)hh(mul,x*y)
h(dvd,y?x/y:(UI)_0Ni+(x<0)-(x>0),y?x/y:(UL)_0Nl+(x<0)-(x>0),x/y)h(mod,x>0?(y%x+x)%x:x?y/-x:_0Ni,x>0?(y%x+x)%x:x?y/-x:_0Nl,_0n)
hh(mnm,min(x,y))hh(mxm,max(x,y))h(ltn,x<y,x<y,cmpd(x)<cmpd(y))h(gtn,x>y,x>y,cmpd(x)>cmpd(y))h(eql,x==y,x==y,*(L*)&x==*(L*)&y)
#undef hh
#undef h

#define hf(x,t,rt,c) V x(t*a,t*b,rt*r,L n)c
#define ht(v,t,T,xtT,xTt,xTT,rt)\
 hf(v##t##T,T,rt,xtT)hf(v##T##t,T,rt,xTt)hf(v##T##T,T,rt,xTT)\
 V v##rdc##T(T*a,T*b,L n){T c=*a;F(n,c=v##t(c,b[i]))*a=c;}\
 V v##scn##T(T*a,T*b,T*r,L n)_(T c=*a;F(n,r[i]=c=v##t(c,b[i])))\
 V v##eap##T(T*a,T*b,T*r,L n)_(T c=*a;F(n,T d=b[i];r[i]=v##t(b[i],c);c=d))\
 I v##amd##T(T*a,L n,L*p,L m,T*b,I d)_(F(m,L j=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))1)
#define ha(v,xiI,xIi,xII,xlL,xLl,xLL,xdD,xDd,xDD,rl,rd) ht(v,i,I,xiI,xIi,xII,I)ht(v,l,L,xlL,xLl,xLL,rl)ht(v,d,D,xdD,xDd,xDD,rd)
#define htT(f) {__typeof__(*a)c=*a;F(n,r[i]=f(c,b[i]))}
#define hTt(f) {__typeof__(*b)c=*b;F(n,r[i]=f(a[i],c))}
#define hTT(f) {F(n,r[i]=f(a[i],b[i]))}
#define hs(x) {x(b,a,r,n);}
#define hn(x) {__typeof__(*b)c=-*b;x(a,&c,r,n);}
//     iI        Ii        II        lL        Ll        LL        dD        Dd        DD
ha(dex,htT(dexi),hTt(dexi),hTT(dexi),htT(dexl),hTt(dexl),hTT(dexl),htT(dexd),hTt(dexd),hTT(dexd),L,D) // : 0
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
#undef hs
#undef hTT
#undef hTt
#undef htT
#undef ha
#undef ht
#undef hf

#define h(v,t,T) {v##t##T,v##T##t,v##T##T,v##rdc##T,v##scn##T,v##eap##T,v##amd##T},
O V*arf[3][11][7]={{ariths(h,i,I)},{ariths(h,l,L)},{ariths(h,d,D)}};
#undef h
S A pen2(A x,A y,I v)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(v),u),4))P(xtaAX||ytaAX,eac(av(v),A_(x,y),2)) //dyadic penetrate
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));I k=xtT<<1|ytT;P(k==3&&xn-yn,el(x,y))
 V*a=xti?(V*)&x:xc,*b=yti?(V*)&y:yc;V(*f)(V*,V*,V*,L)=arf[xt-(xtt?ti:tI)][v][k-!!k];UC t=xtiI?tI:xtlL?tL:v<8?tD:tI;
 Y(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);xr;yr;ai(r)))P(xt==t&&Ar(x)==1,mr2(y,f(a,b,xc,xn);x))P(yt==t&&Ar(y)==1,mr2(x,f(a,b,yc,yn);y))
 A u=atn(t,k-1?xn:yn);mr2(x,mr2(y,f(a,b,uc,un);u)))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,x),AT(yt+ti-ts,y)):pen2(x,y,vi('=')))
A2(mod,P(xtl&&gl_(x)==_0Nl,out(dex(x,y)))P(xtil,pen2(x,y,vi('!')))
 Y(xtt||xta,Y(xta,x=enl(x))x=rsh(al(len_(y)),x))Y(ytt||yta,Y(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
