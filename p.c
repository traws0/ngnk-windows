#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S I ltr(UC c)_(c|=32;c3('a',c,'z')||c>127)S I ldg(C c)_(ltr(c)||dgt(c))S I unh(C c)_((c&15)+9*(c>'9'))S D p10(I n)_(D d=1;F(n,d*=10)d)
S C*s,*s0,na;S A pb(A,C);S I num(C*s)_(dgt(s[*s=='-']))I Ci(O C*s,C c)_(O C*t=s;W(*t&&*t-c,t++)t-s)S A1(p1,xn-1?x:fir(x))
L pu(C**p)_(C*s=*p;L v=0;C c=*s;W(dgt(c),v=10*v+c-'0';c=*++s)*p=s;v)
L pl(C**p)_(I m=**p=='-';*p+=m;(1-2*m)*pu(p))
S D pdu(C**p)_(UL v=pu(p);C*s=*p,c=*s;P(c=='n'||c=='w',(*p)++;c=='n'?_0n:_0w)I e=0;Y(c=='.',c=*++s;W(dgt(c),Y(v<(1ull<<63)/10,v=10*v+c-'0';e--)c=*++s))
 Y(c=='e',s++;e+=pl(&s))*p=s;e<0?v/p10(-e):v*p10(e))
S D pd(C**p)_(I m=**p=='-';(*p)+=m;(m?-1:1)*pdu(p))
S A0(pIL,A x=aL(0);C c;I b=0;W(1,L l=pl(&s);c=*s;Y(!l&&c=='N',l=_0Nl;c=*++s)E(b|=l<_0Ni||l>_0Wi)x=apv(x,&l);Y(c-32||!num(s+1),B)c=*++s)
 P(c=='j'||c=='l',s++;x)P(c=='i',!b?s++,gI(x):ep(x))x)
S A0(pD,A x=aD(0);C c;W(1,D d=pd(&s);x=apv(x,&d);c=*s;Y(c-32||!num(s+1),B)c=*++s)x)
S A0(pC,A x=aC(0);C c=*++s;W(c&&c-'"',Y(c=='\\',c=*++s;I i=Ci("tnr0",c);Y(i<4,c="\t\n\r"[i]))x=apc(x,c);c=*++s)P(!c,ep())c=*++s;x)
S A0(p0x,s+=2;C*p=s;W(ldg(*p),p++)L m=(p-s)/2;A x=aC(m);F(m,xci=unh(*s)<<4|unh(s[1]);s+=2)x)
S A ps(C**p)_(C*s=*p,c=*s;Y(c&0x80,W(((c=*++s)&0xc0)==0x80))EY(c==':',W(ldg(c=*++s)||Ci("./:",c)<3))E(W(ldg(c),c=*++s))A u=aCm(*p,s);*p=s;u)
S A pS(C d)_(A x=aS(0);W(1,I v=sym(d-'`'||*s-'"'?ps(&s):pC());x=apv(x,&v);P(*s-d,x)++s)0)
S A lam(C k,A s,A b,A l)_(AK(k,atnv(tX,5,A_(s,b,au0,l,au0))))
S A1(shy,P(!xn,x)A y=xa[xn-1];Y(ytX&&yn,A z=yx;P(z==av0||ztu&&yn>2,apd(x,au0)))x)
S A0(po,C nb=na;na=1;C*s1=s0,*t=s0=s++;A y;Y(*s-'[',y=au0)E(s++;y=sqz(N(pb(a0(),']')));P(!ytS||yn>8,ep(y)))
 A z=pb(a0(),'}');P(!z,yr;s0=s1;0)Y(y==au0,y=atnv(tS,na,(I[]){1,2,3}))E(na=yn)A x=cpl(lam(na,aCn(t,s-t),shy(z),y));s0=s1;na=nb;x)
S A pt(C*v)_(A x;C c=*s;P(c=='`',s++;x=pS(c);xn>1?enl(x):x)P(c=='(',s++;x=N(pb(enl(av_mkl),')'));xn-2?x:xy==au_plc?xr,a0():las(x))P(c=='{',po())
 P(c=='"',p1(N(pC())))P(ltr(c),C*t=s;x=pS('.');Y(s-t==1&&c3('y',c,'z'),na=max(na,c-'w'))AO(t-s0,p1(x)))
 P(c3('0',c,'9')&&s[1]==':',I u=s[2]==':';s+=2+u;I i=20+c-'0';*v=1;u?au(i):av(i))P(c=='0'&&s[1]=='x',p1(p0x()))
 P(num(s)&&(c-'-'||(!ldg(s[-1])&&Ci(")]}\"",s[-1])==4)),
  L d=0;C*p=s;c=*p;W(1,p+=*p==32;p+=*p=='-';c=*p;Y(!ldg(c),B)W(ldg(c)||c=='.'||c==':',d|=Ci(".nwe",c)<4;c=*++p))p1(d?pD():pIL()))
 I i=Ci(vc,c);P(i>25&&i<30,c=*++s;I h=c==':';s+=h;*v=1;aw(i-26+3*h))P(i>19,au_plc)I u=*++s==':';s+=u;*v=1;u?au(i):av(i))
S A pT(C*v)_(A x=N(pt(v));W(1,C c=*s;I i=Ci(vc+26,c);P(i>3,x)s++;Y(i>2,x=AO(s-1-s0,N(pb(a1(x),']')));Y(xn==2&&xy==au_plc,xy=au0)*v=0)
                                                                 E(I u=*s==':';s+=u;x=a2(aw(i+3*u),x);*v=1))x)
S A1(mon,P(xtv&&x-av0,au(Av(x)))P(!xtX,x)P(xn==2&&xx==aw(0)||xn==3&&xx==av_com,x=mut(x);xa[xn-1]=mon(xa[xn-1]);x)x)
S V pw()_(C c=*s;W(c==32,c=*++s)P(c-'/')c=s[-1];P(s>s0&&c-32&&c-10)W((c=*++s)&&c-10))
S A pe(A x,C*v)_(pw();P(s>s0&&*s=='\\'&&s[-1]==32,s++;A u=pe(0,v);P(!u,Y(x,xr)0);*v=0;u=a2(au_out,u);Y(x,u=a2(mon(x),u))u)
 UH o=s-s0;C w=0;A y=pT(&w);P(!y,Y(x,xr)0)P(y==au_plc,x?x:y)P(!w,A z=pe(y,v);P(!x,z)Nx(z);*v?a3(av_com,x,z):AO(o,a2(mon(x),z)))
 A z=pe(0,v);P(!z,Y(x,xr)yr;0)P(z==au_plc,*v=1;!x?y:!ytu?AO(o,a3(y,x,z)):ep(x,y))
 *v&=y!=av0;Y(!x,y=mon(y))*v?a3(av_com,x?AO(o,a3(y,x,au_plc)):y,z):AO(o,x?a3(y,x,z):a2(mon(y),z)))
S A pb(A x,C e)_(W(1,C v=0;A y=Nx(pe(0,&v));Y(y==au_plc&&(!e||e=='}'),y=au0)x=apv(x,&y);Y(*s-';'&&*s-10,B)s++)P(*s-e,ep(x))s++;x)
A1(prs,P(!xtC,et(x))s=s0=C(x=str0(x));A y=*s=='\\'?a1(AO(0,a2(au_cmd,aCz(s+1)))):pb(a0(),0);!y?eso(x,s-s0),0:lam(0,x,shy(y),aS(0)))
