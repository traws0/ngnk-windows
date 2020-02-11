#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))A1(not,xtaAX?ea1(not,x):fun(x)?mtc(x,au0):eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtaAX,ea1(sqr,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=__builtin_sqrt(xdi))$(xc-uc,xr)u)
A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))S C lwc(C c)_(c+32*C3('A',c,'Z'))S L fl1(D d)_(d<0?(L)d-(d<(L)d):(L)d)
A1(flr,P(xtlL||xtiI,x)P(xtc,ac(lwc(gc(x))))P(xtC,A u=aC(xn);mr2(x,F(un,uci=lwc(xci))u))P(xtaAX,ea1(flr,x))
 x=N(gD(x));A u=atn(xtd?tl:tL,xn);F(un,uli=fl1(xdi))xr;u)
S A pen2_(A x,A y,I f,I k,A u)_(
 P(xtdD,P(k==1,D a=gd_(x);arD(f,un,D b=ydi;udi=)u)P(k==2,D b=gd_(y);arD(f,un,D a=xdi;udi=)u)arD(f,un,D a=xdi;D b=ydi;udi=)u)
 P(xtlL,P(k==1,L a=gl_(x);arL(f,un,L b=yli;uli=)u)P(k==2,L b=gl_(y);arL(f,un,L a=xli;uli=)u)arL(f,un,L a=xli;L b=yli;uli=)u)
        P(k==1,I a=gi (x);arI(f,un,I b=yii;uii=)u)P(k==2,I b=gi (y);arI(f,un,I a=xii;uii=)u)arI(f,un,I a=xii;I b=yii;uii=)u)
S A pen2(A x,A y,I f)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(f),u),4))P(xtaAX||ytaAX,eac(av(f),A_(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));UC t=xtdD&&f<8?tD:xtiI?tI:tL;I k=xtT<<1|ytT;
 $(!k,t+=ti-tI;P(t==ti,I a=gi(x),b=gi(y),r;arI(f,1,r=);ai(r)))
 P(k==3&&xn-yn,el(x,y))
 P(xt==t&&Ar(x)==1,mr2(y,pen2_(x,y,f,k,x)))
 P(yt==t&&Ar(y)==1,mr2(x,pen2_(x,y,f,k,y)))
 A u=atn(t,k==2?xn:yn);mr2(x,mr2(y,pen2_(x,y,f,k,u))))
S A1(s2l,xts?al(gs(x)):AT(tL,x))A2(eql,$(xtsS&&ytsS,x=s2l(x);y=s2l(y))pen2(x,y,vi('=')))
A2(mod,P(xtl,xtl&&*xl==_0N?xr,out(y):pen2(x,y,vi('!')))$(xtt||xta,$(xta,x=enl(x))x=rsh(al(len_(y)),x))
                                                       $(ytt||yta,$(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
