#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
TD ST {S s0;S s;S sr;U k;} P;Z A pb(P*,A,C);                                                        //parser state (s:current pointer, s0:start of source, sr:start of last statement, k:implicit arg counter)
U si(S s,C v)_(strchrnul(s,v)-(C*)s)                                                                //find char (string index)
B id0(UC c)_(CAz(c)|(c|1)==0xd1)                                                                    //is identifier start char?
Z B id1(C c)_(id0(c)|C09(c))                                                                        //is identifier char?
Z B num(S s)_(C09(s[*s=='-']))                                                                      //is number start?
Z S pw(S s)_(W(*s==32,s++)s)                                                                        //skip whitespace
Z A p1(P*w,A x)_(x&&xn==1?fir(x):x)                                                                 //singleton list to atom
S pID(S s)_(W(id1(*s),s+=0xe555>>((UC)*s>>4&-2)&3)s)                                                //parse identifier
W pu(S*p)_(S s=*p;W v=0;C c=*s;W(C09(c),v=10*v+c-'0';c=*++s)*p-s?*p=s,v:NL)                         //parse unsigned long
L pl(S*p)_(B m=**p=='-';*p+=m;(1-2*m)*pu(p))                                                        //parse long
Z L plN(S*p)_(S s=*p;L v=pl(&s);P((*s)&&!!strchr(".nwef",*s),NL)
 I(*s=='b'&&s-*p-1,S r=*p;F(s-*p,B(*r-'0'>=2u);++r)P(r==s,NL))*p=s;!v&&**p=='N'?(*p)++,NL:v)        //parse long (with support for nulls)
Z L pfu(S*p)_(L v=pu(p);S s=*p;C c=*s;P(c=='w',(*p)++;WFL)P(c=='n',(*p)++;v^NFL)I e=0;              //parse float unsigned
 I(c=='.',c=*++s;W(C09(c),I(v<(1ull<<63)/10,v=10*v+c-'0';e--)c=*++s))
 I(c=='e',s++;e+=pl(&s);P(e<-308,0)P(e>308,WFL))
 Z F t[309];I(!*t,*t=1;F(308,t[i+1]=10*t[i]))
 *p=s;*(L*)A(e<0?v/t[-e]:v*t[e]))
L pf(S*p)_(B m=**p=='-';(*p)+=m;L v=(L)m<<63|pfu(p);(*p)+=**p=='f';v)                               //parse float
Z A pV(P*w,C t,TY(pl)*f)_(L a[1<<9];U n=0;S p=w->s,m;B d=1;A x=an(0,t);                             //parse ints or floats
 W(d,n=0;W(n<L(a),m=p;L v=f(&p);B(p==m,d=0)w->s=p;a[n++]=v;p=pw(w->s);B(p==w->s||!num(p),d=0))x=cat11(x,aV(t,n,a)))x)
Z A pZ(P*w)_(S p=w->s;W(*p-'0'<2u,p++)                                                              //parse ints
 P(*p=='B',S t=w->s;w->s=p+1;cB(aV(tG,p-t,t)))//todo
 P(*p=='b',S t=w->s;w->s=p+1;cG(cB(aV(tG,p-t,t))))
 sqzZ(N(pV(w,tL,plN))))
Z A pF(P*w)_(pV(w,tF,pf))                                                                           //parse floats
Z A pC(P*w)_(C a[1<<9];U n;C c=*++w->s;A x=an(0,tC);B d=1;                                          //parse "string"
 W(c&&d,n=0;W(c&&c-'"'&&n<L(a),I(c=='\\',c=*++w->s;U i=fG("tnr0",4,c);I(i<4,c="\t\n\r"[i]))a[n++]=c;c=*++w->s)
 x=cat11(x,aV(tC,n,a));B(c=='"',d=0))P(!c,x(0);ep0())w->s++;x)
Z A p0x(P*w)_(S p=w->s;W(CA9(*p),p++)A x=N(unhC(w->s,p-w->s));w->s=p;x)                             //parse 0x string
Z A ps(P*w)_(S p=w->s;C c=*w->s;I(id0(c),w->s=pID(w->s))J(c>>7,W(*++w->s<-64)w->s+=*w->s==':')aCm(p,w->s))     //parse symbol
Z A pS(P*w,C c)_(I a[256];U n=0;I m=w->s-w->sr;                                                     //parse symbols
 W(1,P(n>=L(a),ez0())A y=*++w->s-'"'?ps(w):N(pC(w));y=str0(y);a[n++]=us(yC);y(0);S p=pw(w->s);B(*p-c)w->s=p)AO(m,aV(tS,n,a)))
Z A pP(P*w)_(I a[8];U n=0;I m=w->s-w->sr;                                                           //parse dot-separated path of identifiers
 W(1,P(n>=L(a),ez0())A y=str0(ps(w));a[n++]=us(yV);y(0);B(*(w->s)-'.'||!id0((w->s)[1]))++w->s)
 AO(m,aV(tS,n,a)))
Z A pp(P*w)_(P(*(w->s)-'[',au)A x=N(pS(w,';'));P(*(w->s)-']'||!xn,ep(x))P(xN>8,ez(x))w->s++;x)      //parse parameter list
Z A pt(P*w,C*b)_(C c=*w->s;                                                                         //parse term
 P(c=='`',A x=p1(w,N(pS(w,'`')));I m=xo;AO(m,qte(x)))
 P(c=='"',p1(w,pC(w)))
 P(c=='[',w->s++;AO(-1,N(pb(w,GAP,']'))))
 P(c=='(',w->s++;I m=w->s-w->sr;A x=N(pb(w,MKL,')'));xn-2?(xn?AO(m,x):x):las(x))
 P(c=='{',P w0;MC(&w0,w,SZ(w0));w0.k=1;S t=w0.sr=w0.s++;w->s=w0.s;A y=N(pp(&w0)),z=pb(&w0,GAP,'}');P(!z,y(0))I(y==au,y=aS(w0.k);F(3,yi='x'+i))A x=N(cpl(aCn(t,w0.s-t),z,y));w->s=w0.s;x)
 P(id0(c),S p=w->s;A x=N(pP(w));I(w->s-p==1&&c-'y'<2u,w->k=MAX(w->k,c-'w'))AO(p-w->sr,x))
 P(C09(c)&&(w->s)[1]==':',B u=(w->s)[2]==':';w->s+=2+u;U i=20+c-'0';P(i>25,ep0())*b=1;Lt(tv-u)|i)
 P(c=='0'&&w->s[1]=='x',w->s+=2;p1(w,p0x(w)))
 P(num(w->s)&&(c-'-'||w->s==w->s0||(!id1((w->s)[-1])&&!strchr(")]}\"",(w->s)[-1]))),
  B d;S p=w->s;A x=an(0,tL);W(1,d=xtF;p+=*p=='-';c=*p;B(!CA9(c))W(CA9(c)||c=='.'||c==':',d|=!!strchr(".nwef",c);c=*++p)x=cat11(d-xtF?cF(x):x,d?pF(w):pZ(w));p=pw(w->s);B(p==w->s||!num(p))w->s=p)p1(w,x))
 P(c>>7,S p=w->s;A x=pP(w);*b=1;AO(p-w->sr,x))
 U i=si("'/\\",c);P(i<3,c=*++w->s;B h=c==':';w->s+=h;*b=1;aw+i+3*h)i=si(vc,c);P(i>19,GAP)
 B u=*++w->s==':';w->s+=u;*b=1;Lt(tv-u)|i)
Z X1(pm,                                                                                            //monadify
 Rv(x^au^av)
 RA(I(xx==aw,x=mut(x);xA[xn-1]=pm(xA[xn-1]))x)
 Rs(S s=su(xv);U n;P(*s>>7&&s[(n=SL(s))-1]-':',C b[n+2];MC(b,s,n);b[n]=':';b[n+1]=0;sym(b))x)
 RS(I o=xo;xn==1?AO(o,enl(pm(fir(x)))):x)
 R_(x))
A pT(P*w,C*b)_(I m=w->s-w->sr;A x=N(pt(w,b));                                                       //parse term and the adverbs or square brackets after it (v:verb?)
  W(1,C c=*w->s;U i=si("'/\\[",c);P(i>3,x)w->s++;
  I(i>2,x=AO(m,N(pb(w,x,']')));I(xn==2,I(xy==GAP,xy=au)E(xx=pm(xx)))*b=0)
  E(I c=*(w->s)==':';w->s+=c;x=AO(m,aA2(aw+i+3*c,x));*b=1))x)
Z A pe(P*w,A x,C*v)_(w->s=pw(w->s);C c=*w->s;                                                       //parse expression
  I(c=='/'&&(w->s==w->s0||(w->s)[-1]==32||(w->s)[-1]==10),
 I((w->s)[1]==10,C*e=(C*)strstr(w->s+1,"\n\\\n");w->s=e?e+2:w->s+SL(w->s))
  E(W((c=*++w->s)&&c-10)))
 P(w->s>w->s0&&*w->s=='\\'&&(w->s)[-1]==32,w->s++;A y=pe(w,0,v);P(!y,x?x(0):0);*v=0;I o=yo;y=AO(o,aA2(OUT,y));I(x,y=aA2(pm(x),y))y)
  UH o=w->s-w->sr;C b=0;A y=pT(w,&b);P(!y,x?x(0):0)P(y==GAP,x?x:y)
 P(!b,A z=pe(w,y,v);P(!x,z)Nx(z);*v?AO(o,aA3(aw,x,z)):AO(o,aA2(pm(x),z)))
 A z=pe(w,0,v);P(!z,y(x?x(0):0))P(z==GAP,*v=1;P(!x,y)Yu(ep(x))AO(o,aA3(y,x,z)))
 *v&=y!=av&y!=au;I(!x,y=pm(y))*v?AO(o,aA3(aw,x?AO(o,aA3(y,x,GAP)):y,z)):AO(o,x?aA3(y,x,z):aA2(pm(y),z)))
Z A pb(P*w,A x,C c)_(x=x?aA1(x):emp(tA);B st=!!strchr("\n}",c);                                     //parse body (sequence of ;-separated expressions)
 W(1,C v=0;I m=w->s-w->s0;A y=Nx(pe(w,0,&v));A z=c-']'&&y==GAP?au:y;P(y==GAP&&c==')'&&*w->s==c&&xn==1,++w->s;x(emp(tA)))PSH(x,z);B(*w->s-';'&&*w->s-10)B(c==10&&*w->s==10)w->s++)
 P(c==10&&!*w->s,x)P(*w->s-c,ep(x))w->s++;AO(1,x))
A pk(S*p,C c)_(P w={.sr=*p,.s0=*p,.s=*p};A x=pb(&w,GAP,c);*p=w.s;P(x,xn==2?las(x):AO(0,x))eQ(w.s0,SL(w.s0),w.s-w.s0);0)  //parse either a group of lines (c='\n') or til '\0' (c='\0')
