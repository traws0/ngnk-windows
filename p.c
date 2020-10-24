#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S I ltr(Cc)_(c3('a',c|32,'z')||c>127)S I ldg(Cc)_(ltr(c)||dgt(c))S I num(C*s)_(dgt(s[*s=='-']))S A pb(A,C);
O C*sc0(O C*s,I c)_(W(*s&&*s-c,s++)s)I si(O C*s,I c)_(sc0(s,c)-s)S A1(p1,xn-1?x:fir(x))S D p10(In)_(Dd=1;F(n,d*=10)d)
L pu(C**p)_(C*s=*p;Lv=0;Cc=*s;W(dgt(c),v=10*v+c-'0';c=*++s)*p=s;v)L pl(C**p)_(I m=**p=='-';*p+=m;(1-2*m)*pu(p))
S D pdu(C**p)_(UL v=pu(p);C*s=*p,c=*s;P(c=='n'||c=='w',(*p)++;c=='n'?ND:WD)I e=0;
 Y(c=='.',c=*++s;W(dgt(c),Y(v<(1ull<<63)/10,v=10*v+c-'0';e--)c=*++s))Y(c=='e',s++;e+=pl(&s))*p=s;e<0?v/p10(-e):v*p10(e))
S D pd(C**p)_(I m=**p=='-';(*p)+=m;(1-2*m)*pdu(p))
S C*s0,*s,na;
S A0(pIL,Ax=aL(0);Cc;I b=0;W(1,L l=pl(&s);c=*s;Y(!l&&c=='N',l=NL;c=*++s)E(b|=l<NI||l>WI)x=apv(x,&l);Y(c-32||!num(s+1),B)c=*++s)
 P(c=='j'||c=='l',s++;x)P(c=='i',ep(b,x)s++;gI(x))x)
S A0(pD,Ax=aD(0);W(1,x=apv(x,D(pd(&s)));Y(*s-32||!num(s+1),B)s++)x)
S A0(pC,Ax=aC(0);Cc=*++s;W(c&&c-'"',Y(c=='\\',c=*++s;Ii=si("tnr0",c);Y(i<4,c="\t\n\r"[i]))x=apc(x,c);c=*++s)ep(!c)c=*++s;x)
S C ph()_(Cc=*s;dgt(c)?c-'0':c3('a',c,'f')?c+10-'a':16)
S A0(p0x,Ax=aC(0);s+=2;W(1,Cc=ph();P(c>15,x)s++;C d=ph();ep(d>15,x)s++;x=apc(x,c<<4|d))x)
S A ps()_(C*t=s,c=*s;Y(c&128,W((c=*++s)>>6==2))EY(c==':',W(ldg(c=*++s)||si("./:",c)<3))E(W(ldg(c),c=*++s))aCm(t,s))
S A pS(Cc)_(Ax=aS(0);W(1,Ay=c-'`'||*s-'"'?ps():pC();y=str0(y);x=apv(x,I(syP(yc)));yr;P(*s-c,x)++s)0)
S A lam(C k,Ax,Ay,Az)_(AK(k,atnv(tA,5,A(x,y,au0,z,au0)))) //x:src,y:bytecode,z:locals
S A1(shy,P(!xn,x)Ay=xa[xn-1];Y(ytA&&yn,Az=yx;P(z==av0||ztu&&yn>2,apd(x,au0)))x) //if last expr is assignment, make it return ::
S A px(In)_(asrt(in(n,4));Ax=aS(n);F(n,xii=syC('x'+i))x)
S A0(po,C nb=na;na=1;C*s1=s0,*t=s0=s++;Ay;Y(*s-'[',y=au0)E(s++;y=sqz(N(pb(a0(),']')));ep(!ytS||yn>8,y))
 Az=pb(a0(),'}');P(!z,yr;s0=s1;0)Y(y==au0,y=px(na))E(na=yn)Ax=cpl(lam(na,aCn(t,s-t),shy(z),y));s0=s1;na=nb;x)
S A pt(C*v)_(Ax;Cc=*s;P(c=='`',s++;x=pS(c);xn>1?enl(x):x)P(c=='(',s++;x=N(pb(enl(av_mkl),')'));xn-2?x:xy==au_plc?xr,a0():las(x))P(c=='{',po())
 P(c=='"',p1(N(pC())))P(ltr(c),C*t=s;x=pS('.');Y(s-t==1&&c3('y',c,'z'),na=max(na,c-'w'))AO(t-s0,p1(x)))
 P(dgt(c)&&s[1]==':',I u=s[2]==':';s+=2+u;Ii=20+c-'0';*v=1;u?au(i):av(i))P(c=='0'&&s[1]=='x',p1(N(p0x())))
 P(num(s)&&(c-'-'||(!ldg(s[-1])&&si(")]}\"",s[-1])==4)),
  L d=0;C*p=s;c=*p;W(1,p+=*p==32;p+=*p=='-';c=*p;Y(!ldg(c),B)W(ldg(c)||c=='.'||c==':',d|=si(".nwe",c)<4;c=*++p))p1(N(d?pD():pIL())))
 Ii=si(vc,c);P(25<i&&i<30,c=*++s;I h=c==':';s+=h;*v=1;aw(i-26+3*h))P(i>19,au_plc)I u=*++s==':';s+=u;*v=1;u?au(i):av(i))
S A pT(C*v)_(Ax=N(pt(v));W(1,Cc=*s;Ii=si(vc+26,c);P(i>3,x)s++;Y(i>2,x=AO(s-1-s0,N(pb(a1(x),']')));Y(xn==2&&xy==au_plc,xy=au0)*v=0)
                                                              E(I u=*s==':';s+=u;x=a2(aw(i+3*u),x);*v=1))x)
S A1(mon,P(xtv&&x-av0,au(xv))P(!xtA,x)P(xn==2&&xx==aw(0)||xn==3&&xx==av_com,x=mut(x);xa[xn-1]=mon(xa[xn-1]);x)x)
S V pw()_(Cc=*s;W(c==32,c=*++s)P(c-'/')c=s[-1];P(s>s0&&c-32&&c-10)W((c=*++s)&&c-10))
S A pe(Ax,C*v)_(pw();P(s>s0&&*s=='\\'&&s[-1]==32,s++;Au=pe(0,v);P(!u,Y(x,xr)0);*v=0;u=a2(au_out,u);Y(x,u=a2(mon(x),u))u)
 UH o=s-s0;C w=0;Ay=pT(&w);P(!y,Y(x,xr)0)P(y==au_plc,x?x:y)P(!w,Az=pe(y,v);P(!x,z)Nx(z);*v?a3(av_com,x,z):AO(o,a2(mon(x),z)))
 Az=pe(0,v);P(!z,Y(x,xr)yr;0)P(z==au_plc,*v=1;P(!x,y)ep(ytu,x,y)AO(o,a3(y,x,z)))
 *v&=y!=av0;Y(!x,y=mon(y))*v?a3(av_com,x?AO(o,a3(y,x,au_plc)):y,z):AO(o,x?a3(y,x,z):a2(mon(y),z)))
S A pb(Ax,Cc)_(W(1,Cv=0;Ay=Nx(pe(0,&v));Y(y==au_plc&&(!c||c=='}'),y=au0)x=apv(x,&y);Y(*s-';'&&*s-10,B)s++)ep(*s-c,x)s++;x)
A1(prs,et(!xtC,x)s=s0=dat(x=str0(x));Ay=*s=='\\'?a1(AO(0,a2(au_cmd,aCz(s+1)))):pb(a0(),0);!y?eso(x,s-s0),0:lam(0,x,shy(y),aS(0)))
