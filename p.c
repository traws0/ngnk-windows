#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
S I ltr(Cc)_(c3('a',c|32,'z'))S I ldg(Cc)_(ltr(c)||dgt(c))S I num(C*s)_(dgt(s[*s=='-']))S A pb(A,C);
I si(OC*s,I c)_(OC*t=s;W(*t&&*t-c,t++)t-s)S A1(p1,xn-1?x:fir(x))S D p10(In)_(Dd=1;i(n,d*=10)d)
L pu(C**p)_(C*s=*p;Lv=0;Cc=*s;W(dgt(c),v=10*v+c-'0';c=*++s)*p=s;v)L pl(C**p)_(Im=**p=='-';*p+=m;(1-2*m)*pu(p))
S D pdu(C**p)_(UL v=pu(p);C*s=*p,c=*s;P(c=='n'||c=='w',(*p)++;c=='n'?ND:WD)I e=0;
 Y(c=='.',c=*++s;W(dgt(c),Y(v<(1ull<<63)/10,v=10*v+c-'0';e--)c=*++s))Y(c=='e',s++;e+=pl(&s))*p=s;e<0?v/p10(-e):v*p10(e))
S D pd(C**p)_(Im=**p=='-';(*p)+=m;(1-2*m)*pdu(p))
S C*s0,*s,na;
S A pLm(L*m)_(Ax=aL0;Cc;
 W(1,Lv=pl(&s);c=*s;Y(!v&&c=='N',v=NL;c=*++s)*m=min(*m,v);m[1]=max(m[1],v);x=apv(x,&v);Y(c-32||!num(s+1),BR)c=*++s)x)
S A0(pZ,Lm[2]={};Ax=pLm(m);ct[max(tZ(*m),tZ(m[1]))](x))
S A0(pD,Ax=aD0;W(1,x=apv(x,(D[]){pd(&s)});Y(*s-32||!num(s+1),BR)s++)x)
S A0(pC,Ax=aC0;Cc=*++s;W(c&&c-'"',Y(c=='\\',c=*++s;Ii=si("tnr0",c);Y(i<4,c="\t\n\r"[i]))x=apc(x,c);c=*++s)Ep(!c,x)c=*++s;x)
S C ph()_(Cc=*s;dgt(c)?c-'0':c3('a',c,'f')?c+10-'a':16)
S A0(p0x,Ax=aC0;s+=2;W(1,Cc=ph();P(c>15,x)s++;Cd=ph();Ep(d>15,x)s++;x=apc(x,c<<4|d))x)
S A0(ps,C*t=s,c=*s;Y(c&128,W((c=*++s)>>6==2)s+=c==':')EY(c==':',W(ldg(c=*++s)||si("./:",c)<3))E(W(ldg(c),c=*++s))aCm(t,s))
S A pS(Cc)_(Ax=aS0;W(1,Ay=c-'`'||*s-'"'?ps():Nx(pC());y=str0(y);x=y(apv(x,(I[]){syP(yC)}));P(*s-c,x)++s)0)
S A lam(Ck,Ax,Ay,Az)_(AK(k,atnv(tA,5,A(x,y,au0,z,au0)))) //x:src,y:bytecode,z:locals
S A1(shy,P(xn<2,x)Ay=xA[xn-1];Y(ytA&&yn>2,Az=yx;Y(z==av0||ztu,xq(au0)))x) //if last expr is assignment, make it return ::
S A px(In)_(Q(in(n,4));Au=aS(n);iui('x'+i))
S A0(po,C nb=na;na=1;C*s1=s0,*t=s0=s++;Ay;Y(*s-'[',y=au0)E(s++;y=sqz(N(pb(aA0,']')));Ep(!ytS||yn>8,y))
 Az=pb(a1(PRG),'}');P(!z,s0=s1;y(0))Y(y==au0,y=px(na))E(na=yn)Ax=cpl(lam(na,aCn(t,s-t),shy(z),y));s0=s1;na=nb;x)
S A pt(C*v)_(Ax;Cc=*s;P(c=='`',s++;x=N(pS(c));xn>1?enl(x):x)P(c=='{',po())P(c=='"',p1(N(pC())))
 P(c=='(',s++;P(*s==')',s++;aA0)x=N(pb(enl(MKL),')'));xn-2?x:las(x))
 P(dgt(c)&&s[1]==':',I u=s[2]==':';s+=2+u;Ii=20+c-'0';*v=1;u?au(i):av(i))P(c=='0'&&s[1]=='x',p1(N(p0x())))
 P(num(s)&&(c-'-'||(!ldg(s[-1])&&si(")]}\"",s[-1])==4)),L d=0;C*p=s;c=*p;
  W(1,p+=*p==32;p+=*p=='-';c=*p;Y(!ldg(c),BR)W(ldg(c)||c=='.'||c==':',d|=si(".nwe",c)<4;c=*++p))p1(N(d?pD():pZ())))
 P(ltr(c),C*t=s;x=pS('.');Y(s-t==1&&c3('y',c,'z'),na=max(na,c-'w'))AO(t-s0,p1(x)))
 P(c>127,C*t=s;x=pS('.');*v=1;AO(t-s0,p1(x)))
 Ii=si(vc,c);P(25<i&&i<30,c=*++s;I h=c==':';s+=h;*v=1;aw(i-26+3*h))P(i>19,PLH)I u=*++s==':';s+=u;*v=1;u?au(i):av(i))
S A1(mon,P(xtv&&x-av0,au(xv))
 Y(xts,C*s=syp((V*)&x);Nn=mn(s);P((*s&128)&&s[n-1]-':',Cb[8];mc(b,s,n);b[n]=':';b[n+1]=0;as(syP(b))))
 P(!xtA,x)P(xn==2&&xx==aw(0)||xn==3&&xx==COM,x=mut(x);xA[xn-1]=mon(xA[xn-1]);x)x)
S A pT(C*v)_(Ax=N(pt(v));W(1,Cc=*s;Ii=si(vc+26,c);P(i>3,x)s++;
 Y(i>2,x=AO(s-1-s0,N(pb(a1(x),']')));Y(xn==2,Y(xy==PLH,xy=au0)E(xx=mon(xx)))*v=0)E(I u=*s==':';s+=u;x=a2(aw(i+3*u),x);*v=1))x)
S V pw()_(Cc=*s;W(c==32,c=*++s)P(c-'/')c=s[-1];P(s>s0&&c-32&&c-10)W((c=*++s)&&c-10))
S A pe(Ax,C*v)_(pw();P(s>s0&&*s=='\\'&&s[-1]==32,s++;Au=pe(0,v);P(!u,x?x(0):0);*v=0;u=a2(OUT,u);Y(x,u=a2(mon(x),u))u)
 UH o=s-s0;Cb=0;Ay=pT(&b);P(!y,x?x(0):0)P(y==PLH,x?x:y)
 P(!b,Az=pe(y,v);P(!x,z)Nx(z);*v?a3(COM,x,z):AO(o,a2(mon(x),z)))
 Az=pe(0,v);P(!z,y(x?x(0):0))P(z==PLH,*v=1;P(!x,y)Ep(ytu,x,y)AO(o,a3(y,x,z)))
 *v&=y!=av0;Y(!x,y=mon(y))*v?a3(COM,x?AO(o,a3(y,x,PLH)):y,z):AO(o,x?a3(y,x,z):a2(mon(y),z)))
S A pb(Ax,Cc)_(W(1,Cv=0;Ay=Nx(pe(0,&v));Y(y==PLH&&c-']',Ep(c==')',x,y)y=au0)xq(y);Y(*s-';'&&*s-10,BR)s++)Ep(*s-c,x)s++;x)
A1(prs,Et(!xtC,x)x=str0(x);s=s0=xC;Ay=*s=='\\'?a2(PRG,AO(0,a2(CMD,aCz(s+1)))):pb(a1(PRG),0);
 !y?eS(x,s-s0),0:lam(0,x,shy(y),aS0))
