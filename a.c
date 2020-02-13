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
#define AR1(x,t,rt,c) SN V x(t*a,t*b,rt*r,L n){c;}
#define ARF(x,xiI,xIi,xII,xlL,xLl,xLL,xdD,xDd,xDD) AR1(x##iI,I,I,xiI)AR1(x##Ii,I,I,xIi)AR1(x##II,I,I,xII)\
                                                   AR1(x##lL,L,L,xlL)AR1(x##Ll,L,L,xLl)AR1(x##LL,L,L,xLL)\
                                                   AR1(x##dD,D,D,xdD)AR1(x##Dd,D,D,xDd)AR1(x##DD,D,D,xDD)
#define CMF(x,xiI,xIi,xII,xlL,xLl,xLL,xdD,xDd,xDD) AR1(x##iI,I,I,xiI)AR1(x##Ii,I,I,xIi)AR1(x##II,I,I,xII)\
                                                   AR1(x##lL,L,L,xlL)AR1(x##Ll,L,L,xLl)AR1(x##LL,L,L,xLL)\
                                                   AR1(x##dD,D,L,xdD)AR1(x##Dd,D,L,xDd)AR1(x##DD,D,L,xDD)
ARF(add,{I v=*a;F(n,r[i]=     v+b[i] )},{addiI(b,a,r,n);              },{F(n,r[i]=     a[i]+b[i] )},
        {L v=*a;F(n,r[i]=     v+b[i] )},{addlL(b,a,r,n);              },{F(n,r[i]=     a[i]+b[i] )},
        {D v=*a;F(n,r[i]=     v+b[i] )},{D v=*b;F(n,r[i]=a[i]+v)      },{F(n,r[i]=     a[i]+b[i] )})
ARF(sub,{I v=*a;F(n,r[i]=     v-b[i] )},{I v=-*b;addIi(a,&v,r,n);     },{F(n,r[i]=     a[i]-b[i] )},
        {L v=*a;F(n,r[i]=     v-b[i] )},{L v=-*b;addLl(a,&v,r,n);     },{F(n,r[i]=     a[i]-b[i] )},
        {D v=*a;F(n,r[i]=     v-b[i] )},{D v=-*b;addDd(a,&v,r,n);     },{F(n,r[i]=     a[i]-b[i] )})
ARF(mul,{I v=*a;F(n,r[i]=     v*b[i] )},{muliI(b,a,r,n);              },{F(n,r[i]=     a[i]*b[i] )},
        {L v=*a;F(n,r[i]=     v*b[i] )},{mullL(b,a,r,n);              },{F(n,r[i]=     a[i]*b[i] )},
        {D v=*a;F(n,r[i]=     v*b[i] )},{muldD(b,a,r,n);              },{F(n,r[i]=     a[i]*b[i] )})
ARF(div,{I v=*a;F(n,r[i]=divi(v,b[i]))},{I v=*b;F(n,r[i]=divi(a[i],v))},{F(n,r[i]=divi(a[i],b[i]))},
        {L v=*a;F(n,r[i]=divl(v,b[i]))},{L v=*b;F(n,r[i]=divl(a[i],v))},{F(n,r[i]=divl(a[i],b[i]))},
        {D v=*a;F(n,r[i]=divd(v,b[i]))},{D v=*b;F(n,r[i]=divd(a[i],v))},{F(n,r[i]=divd(a[i],b[i]))})
ARF(mod,{I v=*a;F(n,r[i]=modi(v,b[i]))},{I v=*b;F(n,r[i]=modi(a[i],v))},{F(n,r[i]=modi(a[i],b[i]))},
        {L v=*a;F(n,r[i]=modl(v,b[i]))},{L v=*b;F(n,r[i]=modl(a[i],v))},{F(n,r[i]=modl(a[i],b[i]))},
        {D v=*a;F(n,r[i]=modd(v,b[i]))},{D v=*b;F(n,r[i]=modd(a[i],v))},{F(n,r[i]=modd(a[i],b[i]))})
ARF(mnm,{I v=*a;F(n,r[i]= min(v,b[i]))},{mnmiI(b,a,r,n);              },{F(n,r[i]= min(a[i],b[i]))},
        {L v=*a;F(n,r[i]= min(v,b[i]))},{mnmlL(b,a,r,n);              },{F(n,r[i]= min(a[i],b[i]))},
        {D v=*a;F(n,r[i]= min(v,b[i]))},{mnmdD(b,a,r,n);              },{F(n,r[i]= min(a[i],b[i]))})
ARF(mxm,{I v=*a;F(n,r[i]= max(v,b[i]))},{mxmiI(b,a,r,n);              },{F(n,r[i]= max(a[i],b[i]))},
        {L v=*a;F(n,r[i]= max(v,b[i]))},{mxmlL(b,a,r,n);              },{F(n,r[i]= max(a[i],b[i]))},
        {D v=*a;F(n,r[i]= max(v,b[i]))},{mxmdD(b,a,r,n);              },{F(n,r[i]= max(a[i],b[i]))})
CMF(ltn,{I v=*a;F(n,r[i]=     v<b[i] )},{I v=*b;F(n,r[i]=a[i]<v)      },{F(n,r[i]=     a[i]<b[i] )},
        {L v=*a;F(n,r[i]=     v<b[i] )},{L v=*b;F(n,r[i]=a[i]<v)      },{F(n,r[i]=     a[i]<b[i] )},
        {D v=*a;F(n,r[i]=     v<b[i] )},{D v=*b;F(n,r[i]=a[i]<v)      },{F(n,r[i]=     a[i]<b[i] )})
CMF(gtn,{ltnIi(b,a,r,n);              },{ltniI(b,a,r,n);              },{ltnII(b,a,r,n);          },
        {ltnLl(b,a,r,n);              },{ltnlL(b,a,r,n);              },{ltnLL(b,a,r,n);          },
        {ltnDd(b,a,r,n);              },{ltndD(b,a,r,n);              },{ltnDD(b,a,r,n);          })
CMF(eql,{I v=*a;F(n,r[i]=    v==b[i] )},{eqliI(b,a,r,n);              },{F(n,r[i]=     a[i]==b[i])},
        {L v=*a;F(n,r[i]=    v==b[i] )},{eqllL(b,a,r,n);              },{F(n,r[i]=     a[i]==b[i])},
        {eqllL((V*)a,(V*)b,r,n);      },{eqllL((V*)b,(V*)a,r,n);      },{eqlLL((V*)a,(V*)b,r,n);  })
#define h(x) {{x##iI,x##lL,x##dD},{x##Ii,x##Ll,x##Dd},{x##II,x##LL,x##DD}},
S O V*arf[10][3][3]={h(add)h(sub)h(mul)h(div)h(mod)h(mnm)h(mxm)h(ltn)h(gtn)h(eql)};
#undef h
S A pen2(A x,A y,I v)_(P(xta&&yta,A u=gkv(&y);am1(A_(x,y,av(v),u),4))P(xtaAX||ytaAX,eac(av(v),A_(x,y),2))
 A1*g=xtdD||ytdD?gD:xtlL||ytlL?gL:gI;x=Ny(g(x));y=Nx(g(y));I k=xtT<<1|ytT;P(k==3&&xn-yn,el(x,y))
 V*a=xti?(V*)&x:xc,*b=yti?(V*)&y:yc;void(*f)(V*,V*,V*,L)=arf[v-1][k-!!k][xt-(xtt?ti:tI)];UC t=xtdD&&v<8?tD:xtiI?tI:tL;
 $(!k,t+=ti-tI;P(t==ti,I r;f(a,b,&r,1);ai(r)))
 P(xt==t&&Ar(x)==1,mr2(y,f(a,b,xc,xn);x))
 P(yt==t&&Ar(y)==1,mr2(x,f(a,b,yc,yn);y))
 A u=atn(t,k-1?xn:yn);mr2(x,mr2(y,f(a,b,uc,un);u)))
S A1(s2l,xts?al(gs(x)):AT(tL,x))A2(eql,$(xtsS&&ytsS,x=s2l(x);y=s2l(y))pen2(x,y,vi('=')))
A2(mod,P(xtl,xtl&&*xl==_0N?xr,out(y):pen2(x,y,vi('!')))$(xtt||xta,$(xta,x=enl(x))x=rsh(al(len_(y)),x))
                                                       $(ytt||yta,$(yta,y=enl(y))y=rsh(al(len_(x)),y))len_(x)-len_(y)?el(x,y):aa(x,y))
#define h(c,s) A2(s,pen2(x,y,vi(c)))
h('+',add)h('-',sub)h('*',mul)h('%',dvd)h('&',mnm)h('|',mxm)h('<',ltn)h('>',gtn)
#undef h
