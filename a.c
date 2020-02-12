#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A1(neg,sub(ai(0),x))A1(not,xtaAX?ea1(not,x):fun(x)?mtc(x,au0):eql(x,xtsS?as(0):ac(0)))
A1(sqr,P(xtaAX,ea1(sqr,x))x=N(gD(x));A u=Ar(x)-1?atn(xt,xn):x;F(un,udi=__builtin_sqrt(xdi))$(xc-uc,xr)u)
A1(nul,xtaAX?ea1(nul,x):eql(x,mR(cn[xt])))S C lwc(C c)_(c+32*C3('A',c,'Z'))S L fl1(D d)_(d<0?(L)d-(d<(L)d):(L)d)
A1(flr,P(xtlL||xtiI,x)P(xtc,ac(lwc(gc(x))))P(xtC,A u=aC(xn);mr2(x,F(un,uci=lwc(xci))u))P(xtaAX,ea1(flr,x))
 x=N(gD(x));A u=atn(xtd?tl:tL,xn);F(un,uli=fl1(xdi))xr;u)

#define divi(x,y) (y?x/y:!x?_0Ni:a>0?_0Wi:-_0Wi)
#define divl(x,y) (y?x/y:!x?_0N :a>0?_0W :-_0W )
#define divd(x,y) (x/y)
#define modi(x,y) (x>0?(y%x+x)%x:x?y/-x:_0Ni)
#define modl(x,y) (x>0?(y%x+x)%x:x?y/-x:_0N )
#define modd(x,y) ((V)x,(V)y,_0n)
SN V addiI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=v+b[i])}
SN V addlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=v+b[i])}
SN V adddD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=v+b[i])}
SN V addIi(I*a,I*b,I*r,L n){addiI(b,a,r,n);}
SN V addLl(L*a,L*b,L*r,L n){addlL(b,a,r,n);}
SN V addDd(D*a,D*b,D*r,L n){D v=*b;F(n,r[i]=a[i]+v)}
SN V addII(I*a,I*b,I*r,L n){F(n,r[i]=a[i]+b[i])}
SN V addLL(L*a,L*b,L*r,L n){F(n,r[i]=a[i]+b[i])}
SN V addDD(D*a,D*b,D*r,L n){F(n,r[i]=a[i]+b[i])}
SN V subiI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=v-b[i])}
SN V sublL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=v-b[i])}
SN V subdD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=v-b[i])}
SN V subIi(I*a,I*b,I*r,L n){I v=-*b;addIi(a,&v,r,n);}
SN V subLl(L*a,L*b,L*r,L n){L v=-*b;addLl(a,&v,r,n);}
SN V subDd(D*a,D*b,D*r,L n){D v=-*b;addDd(a,&v,r,n);}
SN V subII(I*a,I*b,I*r,L n){F(n,r[i]=a[i]-b[i])}
SN V subLL(L*a,L*b,L*r,L n){F(n,r[i]=a[i]-b[i])}
SN V subDD(D*a,D*b,D*r,L n){F(n,r[i]=a[i]-b[i])}
SN V muliI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=v*b[i])}
SN V mullL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=v*b[i])}
SN V muldD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=v*b[i])}
SN V mulIi(I*a,I*b,I*r,L n){muliI(b,a,r,n);}
SN V mulLl(L*a,L*b,L*r,L n){mullL(b,a,r,n);}
SN V mulDd(D*a,D*b,D*r,L n){muldD(b,a,r,n);}
SN V mulII(I*a,I*b,I*r,L n){F(n,r[i]=a[i]*b[i])}
SN V mulLL(L*a,L*b,L*r,L n){F(n,r[i]=a[i]*b[i])}
SN V mulDD(D*a,D*b,D*r,L n){F(n,r[i]=a[i]*b[i])}
SN V diviI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=divi(v,b[i]))}
SN V divlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=divl(v,b[i]))}
SN V divdD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=divd(v,b[i]))}
SN V divIi(I*a,I*b,I*r,L n){I v=*b;F(n,r[i]=divi(a[i],v))}
SN V divLl(L*a,L*b,L*r,L n){L v=*b;F(n,r[i]=divl(a[i],v))}
SN V divDd(D*a,D*b,D*r,L n){D v=*b;F(n,r[i]=divd(a[i],v))}
SN V divII(I*a,I*b,I*r,L n){F(n,r[i]=divi(a[i],b[i]))}
SN V divLL(L*a,L*b,L*r,L n){F(n,r[i]=divl(a[i],b[i]))}
SN V divDD(D*a,D*b,D*r,L n){F(n,r[i]=divd(a[i],b[i]))}
SN V modiI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=modi(v,b[i]))}
SN V modlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=modl(v,b[i]))}
SN V moddD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=modd(v,b[i]))}
SN V modIi(I*a,I*b,I*r,L n){I v=*b;F(n,r[i]=modi(a[i],v))}
SN V modLl(L*a,L*b,L*r,L n){L v=*b;F(n,r[i]=modl(a[i],v))}
SN V modDd(D*a,D*b,D*r,L n){D v=*b;F(n,r[i]=modd(a[i],v))}
SN V modII(I*a,I*b,I*r,L n){F(n,r[i]=modi(a[i],b[i]))}
SN V modLL(L*a,L*b,L*r,L n){F(n,r[i]=modl(a[i],b[i]))}
SN V modDD(D*a,D*b,D*r,L n){F(n,r[i]=modd(a[i],b[i]))}
SN V mnmiI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=min(v,b[i]))}
SN V mnmlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=min(v,b[i]))}
SN V mnmdD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=min(v,b[i]))}
SN V mnmIi(I*a,I*b,I*r,L n){mnmiI(b,a,r,n);}
SN V mnmLl(L*a,L*b,L*r,L n){mnmlL(b,a,r,n);}
SN V mnmDd(D*a,D*b,D*r,L n){mnmdD(b,a,r,n);}
SN V mnmII(I*a,I*b,I*r,L n){F(n,r[i]=min(a[i],b[i]))}
SN V mnmLL(L*a,L*b,L*r,L n){F(n,r[i]=min(a[i],b[i]))}
SN V mnmDD(D*a,D*b,D*r,L n){F(n,r[i]=min(a[i],b[i]))}
SN V mxmiI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=max(v,b[i]))}
SN V mxmlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=max(v,b[i]))}
SN V mxmdD(D*a,D*b,D*r,L n){D v=*a;F(n,r[i]=max(v,b[i]))}
SN V mxmIi(I*a,I*b,I*r,L n){mxmiI(b,a,r,n);}
SN V mxmLl(L*a,L*b,L*r,L n){mxmlL(b,a,r,n);}
SN V mxmDd(D*a,D*b,D*r,L n){mxmdD(b,a,r,n);}
SN V mxmII(I*a,I*b,I*r,L n){F(n,r[i]=max(a[i],b[i]))}
SN V mxmLL(L*a,L*b,L*r,L n){F(n,r[i]=max(a[i],b[i]))}
SN V mxmDD(D*a,D*b,D*r,L n){F(n,r[i]=max(a[i],b[i]))}
SN V ltniI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=v<b[i])}
SN V ltnlL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=v<b[i])}
SN V ltndD(D*a,D*b,L*r,L n){D v=*a;F(n,r[i]=v<b[i])}
SN V ltnIi(I*a,I*b,I*r,L n){I v=*b;F(n,r[i]=a[i]<v)}
SN V ltnLl(L*a,L*b,L*r,L n){L v=*b;F(n,r[i]=a[i]<v)}
SN V ltnDd(D*a,D*b,L*r,L n){D v=*b;F(n,r[i]=a[i]<v)}
SN V ltnII(I*a,I*b,I*r,L n){F(n,r[i]=a[i]<b[i])}
SN V ltnLL(L*a,L*b,L*r,L n){F(n,r[i]=a[i]<b[i])}
SN V ltnDD(D*a,D*b,L*r,L n){F(n,r[i]=a[i]<b[i])}
SN V gtniI(I*a,I*b,I*r,L n){ltnIi(b,a,r,n);}
SN V gtnlL(L*a,L*b,L*r,L n){ltnLl(b,a,r,n);}
SN V gtndD(D*a,D*b,L*r,L n){ltnDd(b,a,r,n);}
SN V gtnIi(I*a,I*b,I*r,L n){ltniI(b,a,r,n);}
SN V gtnLl(L*a,L*b,L*r,L n){ltnlL(b,a,r,n);}
SN V gtnDd(D*a,D*b,L*r,L n){ltndD(b,a,r,n);}
SN V gtnII(I*a,I*b,I*r,L n){ltnII(b,a,r,n);}
SN V gtnLL(L*a,L*b,L*r,L n){ltnLL(b,a,r,n);}
SN V gtnDD(D*a,D*b,L*r,L n){ltnDD(b,a,r,n);}
SN V eqliI(I*a,I*b,I*r,L n){I v=*a;F(n,r[i]=v==b[i])}
SN V eqllL(L*a,L*b,L*r,L n){L v=*a;F(n,r[i]=v==b[i])}
#define eqldD eqllL
SN V eqlIi(I*a,I*b,I*r,L n){I v=*b;F(n,r[i]=a[i]==v)}
SN V eqlLl(L*a,L*b,L*r,L n){L v=*b;F(n,r[i]=a[i]==v)}
#define eqlDd eqlLl
SN V eqlII(I*a,I*b,I*r,L n){F(n,r[i]=a[i]==b[i])}
SN V eqlLL(L*a,L*b,L*r,L n){F(n,r[i]=a[i]==b[i])}
#define eqlDD eqlLL
#define h(x) {{x##II,x##LL,x##DD},{x##iI,x##lL,x##dD},{x##Ii,x##Ll,x##Dd},{x##II,x##LL,x##DD}},
S O V*arf[11][4][3]={{},h(add)h(sub)h(mul)h(div)h(mod)h(mnm)h(mxm)h(ltn)h(gtn)h(eql)};
#undef h
S A pen2(A x,A y,I f)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(f),u),4))P(xtaAX||ytaAX,eac(av(f),A_(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));UC t=xtdD&&f<8?tD:xtiI?tI:tL;I k=xtT<<1|ytT;
 $(!k,t+=ti-tI;P(t==ti,I a=gi(x),b=gi(y),r;arI(f,1,r=);ai(r)))
 P(k==3&&xn-yn,el(x,y))
 V*a=xti?(V*)&x:xc;V*b=yti?(V*)&y:yc;void(*fn)(V*,V*,V*,L)=arf[f][k][xt-(xtt?ti:tI)];
 P(xt==t&&Ar(x)==1,mr2(y,fn(a,b,xc,xn);x))
 P(yt==t&&Ar(y)==1,mr2(x,fn(a,b,yc,yn);y))
 A u=atn(t,k==2?xn:yn);mr2(x,mr2(y,fn(a,b,uc,un);u)))
S A1(s2l,xts?al(gs(x)):AT(tL,x))A2(eql,$(xtsS&&ytsS,x=s2l(x);y=s2l(y))pen2(x,y,vi('=')))
A2(mod,P(xtl,xtl&&*xl==_0N?xr,out(y):pen2(x,y,vi('!')))$(xtt||xta,$(xta,x=enl(x))x=rsh(al(len_(y)),x))
                                                       $(ytt||yta,$(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
