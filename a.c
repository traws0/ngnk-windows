#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))A1(not,xtaAX?ea1(not,x):fun(x)?mtc(x,au0):eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtaAX,ea1(sqr,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=__builtin_sqrt(xdi))$(xc-uc,xr)u)
A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))S C lwc(C c)_(c+32*C3('A',c,'Z'))S L fl1(D d)_(d<0?(L)d-(d<(L)d):(L)d)
A1(flr,P(xtlL||xtiI,x)P(xtc,ac(lwc(gc(x))))P(xtC,A u=aC(xn);mr2(x,F(un,uci=lwc(xci))u))P(xtaAX,ea1(flr,x))
 x=N(gD(x));A u=atn(xtd?tl:tL,xn);F(un,uli=fl1(xdi))xr;u)
S I divi(I x,I y)_(y?x/y:(UI)_0Ni+(x<0)-(x>0))S I modi(I x,I y)_(x>0?(y%x+x)%x:x?y/-x:_0Ni)
S L divl(L x,L y)_(y?x/y:(UL)_0N +(x<0)-(x>0))S L modl(L x,L y)_(x>0?(y%x+x)%x:x?y/-x:_0N )S D modd(D x,D y)_(_0n)
S L cmpd(L x)_(x^((UL)(x>>63)>>1))S I ltnd(D x,D y)_(L a=*(L*)&x,b=*(L*)&y;cmpd(a)<cmpd(b))
#define hf(x,t,rt,c)SN V x(t*a,t*b,rt*r,L n)c
#define ha(x,xiI,xIi,xII,xlL,xLl,xLL,xdD,xDd,xDD,ri,rl,rd)\
 hf(x##iI,I,ri,xiI)hf(x##Ii,I,ri,xIi)hf(x##II,I,ri,xII)\
 hf(x##lL,L,rl,xlL)hf(x##Ll,L,rl,xLl)hf(x##LL,L,rl,xLL)\
 hf(x##dD,D,rd,xdD)hf(x##Dd,D,rd,xDd)hf(x##DD,D,rd,xDD)
#define htTo(o){__typeof__(*a)v=*a;F(n,r[i]=v o b[i] )}
#define htT(f) {__typeof__(*a)v=*a;F(n,r[i]=f(v,b[i]))}
#define hTto(o){__typeof__(*b)v=*b;F(n,r[i]=a[i]o v  )}
#define hTt(f) {__typeof__(*b)v=*b;F(n,r[i]=f(a[i],v))}
#define hTTo(o){F(n,r[i]=a[i]o b[i]  )}
#define hTT(f) {F(n,r[i]=f(a[i],b[i]))}
#define hs(x)  {x(b,a,r,n);}
#define hv(x)  {x((V*)a,(V*)b,r,n);}
#define hn(x)  {__typeof__(*b)v=-*b;x(a,&v,r,n);}
//     iI        Ii        II        lL        Ll        LL        dD        Dd        DD
ha(add,htTo(+)  ,hs(addiI),hTTo(+)  ,htTo(+)  ,hs(addlL),hTTo(+)  ,htTo(+)  ,hTto(+)  ,hTTo(+)  ,I,L,D)
ha(sub,htTo(-)  ,hn(addIi),hTTo(-)  ,htTo(-)  ,hn(addLl),hTTo(-)  ,htTo(-)  ,hn(addDd),hTTo(-)  ,I,L,D)
ha(mul,htTo(*)  ,hs(muliI),hTTo(*)  ,htTo(*)  ,hs(mullL),hTTo(*)  ,htTo(*)  ,hs(muldD),hTTo(*)  ,I,L,D)
ha(div,htT(divi),hTt(divi),hTT(divi),htT(divl),hTt(divl),hTT(divl),htTo(/)  ,hTto(/)  ,hTTo(/)  ,I,L,D)
ha(mod,htT(modi),hTt(modi),hTT(modi),htT(modl),hTt(modl),hTT(modl),htT(modd),hTt(modd),hTT(modd),I,L,D)
ha(mnm,htT(min) ,hs(mnmiI),hTT(min) ,htT(min) ,hs(mnmlL),hTT(min) ,htT(min) ,hs(mnmdD),hTT(min) ,I,L,D)
ha(mxm,htT(max) ,hs(mxmiI),hTT(max) ,htT(max) ,hs(mxmlL),hTT(max) ,htT(max) ,hs(mxmdD),hTT(max) ,I,L,D)
ha(ltn,htTo(<)  ,hTto(<)  ,hTTo(<)  ,htTo(<)  ,hTto(<)  ,hTTo(<)  ,htT(ltnd),hTt(ltnd),hTT(ltnd),I,L,I)
ha(gtn,hs(ltnIi),hs(ltniI),hs(ltnII),hs(ltnLl),hs(ltnlL),hs(ltnLL),hs(ltnDd),hs(ltndD),hs(ltnDD),I,L,I)
ha(eql,htTo(==) ,hs(eqliI),hTTo(==) ,htTo(==) ,hs(eqllL),hTTo(==) ,hv(eqllL),hv(eqlLl),hv(eqlLL),I,L,L)
#undef hn
#undef hv
#undef hs
#undef hTT
#undef hTTo
#undef hTt
#undef hTto
#undef htT
#undef htTo
#undef ha
#undef hf

#define h(x,y,z){x##y##z,x##z##y,x##z##z},
#define h1(a...){h(add,a)h(sub,a)h(mul,a)h(div,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a)h(gtn,a)h(eql,a)},
O V*arf[3][10][3]={h1(i,I)h1(l,L)h1(d,D)};
#undef h1
#undef h
S A pen2(A x,A y,I v)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(v),u),4))P(xtaAX||ytaAX,eac(av(v),A_(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));I k=xtT<<1|ytT;P(k==3&&xn-yn,el(x,y))
 V*a=xti?(V*)&x:xc,*b=yti?(V*)&y:yc;void(*f)(V*,V*,V*,L)=arf[xt-(xtt?ti:tI)][v-1][k-!!k];UC t=xtiI?tI:xtlL?tL:v<8?tD:v==vi('=')?tL:tI;
 $(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);xr;yr;ai(r)))P(xt==t&&Ar(x)==1,mr2(y,f(a,b,xc,xn);x))P(yt==t&&Ar(y)==1,mr2(x,f(a,b,yc,yn);y))
 A u=atn(t,k-1?xn:yn);mr2(x,mr2(y,f(a,b,uc,un);u)))
S A1(s2i,xts?ai(gs(x)):AT(tI,x))A2(eql,$(xtsS&&ytsS,x=s2i(x);y=s2i(y))pen2(x,y,vi('=')))
A2(mod,P(xtil,gl_(x)==_0N||gi(x)==_0Ni?out(dex(x,y)):pen2(x,y,vi('!')))
 $(xtt||xta,$(xta,x=enl(x))x=rsh(al(len_(y)),x))$(ytt||yta,$(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
