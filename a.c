#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A1(not,P(xtt,al(!tru(x)))P(xtaAX,ea1(not,x))$(tZ(xt)-ZL,x=N(gL(x)))xr;A u=aL(xn);F(un,uli=!xli)u)A1(neg,sub(ai(0),x))
A1(sqr,P(xtaAX,ea1(sqr,x))x=gD(x);P(xtt,ad(__builtin_sqrt(gd(x))))A u=ax(x);F(xn,udi=__builtin_sqrt(xdi))u)
S C lwc(C c)_(c+32*C3('A',c,'Z'))S L fl1(D d)_(d<0?(L)d-(d<(L)d):(L)d)A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))
A1(flr,P(xtlL||xtiI,x)P(xtc,ac(lwc(gc(x))))P(xtC,A u=ax(x);F(un,uci=lwc(xci))u)P(xtaAX,ea1(flr,x))
 x=N(gD(x));P(xtt,al(fl1(gd(x))))xr;A u=aL(xn);F(xn,uli=fl1(xdi))u)
S A pen2(A x,A y,I f)_(P(xta&&yta,A u=gkv(&y);amd(A_(x,y,cv(f),u),4))P(xtaAX||ytaAX,eac(cv(f),A_(x,y),2))I d=xtdD||ytdD,k=xtt<<1|ytt;
 P(k==3,P(d,x=Ny(gD(x));y=Nx(gD(y));D a=gd(x),b=gd(y),r;arD(f,1,r=);f<8?ad(r):al(d2l(r)))
            x=Ny(gL(x));y=Nx(gL(y));L a=gl(x),b=gl(y),r;arL(f,1,r=);al(r))
 A1*g=d?gD:gL;x=Ny(g(x));y=Nx(g(y));xr;yr;P(!k&&xn-yn,el())A u=atn(d&&f<8?tD:tL,k==1?xn:yn);
 Y(k*2+d,UR,Q(0,arL(f,un,L a=xli;L b=yli;uli=))Q(2,L b=gl_(y);arL(f,un,L a=xli;uli=))Q(4,L a=gl_(x);arL(f,un,L b=yli;uli=))
            Q(1,arD(f,un,D a=xdi;D b=ydi;udi=))Q(3,D b=gd_(y);arD(f,un,D a=xdi;udi=))Q(5,D a=gd_(x);arD(f,un,D b=ydi;udi=)))u)
S A1(s2l,xts?al(gs(x)):AT(tL,x))A2(eql,$(xtsS&&ytsS,x=s2l(x);y=s2l(y))pen2(x,y,vi('=')))
A2(mod,P(xtl,xt==tlx&&*xl==_0N?xr,out(y):pen2(x,y,vi('!')))$(xtt||xta,$(xta,x=enl(x))x=rsh(al(len_(y)),x))
                                                           $(ytt||yta,$(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
