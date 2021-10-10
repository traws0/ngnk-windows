#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
C hx1(Ii)_(i+(i>9?'a'-10:'0'))I in(Li,UL n)_(i<n)I c3(Cc,Cv,Cd)_(c<=v&&v<=d)
I c09(Cc)_(c3('0',c,'9'))I caf(Cc)_(c3('a',c,'f'))I cAz(Cc)_(c3('a',c|32,'z'))I cA9(Cc)_(cAz(c)||c09(c))
I cAZ(Cc)_(c3('A',c,'Z'))I cAF(Cc)_(c3('A',c,'F'))I cAf(Cc)_(c3('a',c|32,'f'))
S I num(Qs)_(c09(s[*s=='-']))I si(Qs,Iv)_(SC0(s,v)-(char*)s)S D p10(In)_(Dv=1;i(n,v*=10)v)
L pu(Q*p)_(Qs=*p;Lv=0;Cc=*s;W(c09(c),v=10*v+c-'0';c=*++s)*p=s;v)L pl(Q*p)_(Im=**p=='-';*p+=m;(1-2*m)*pu(p))
S D pdu(Q*p)_(UL v=pu(p);Qs=*p;Cc=*s;P(c=='n'||c=='w',(*p)++;c=='n'?ND:WD)I e=0;
 I(c=='.',c=*++s;W(c09(c),I(v<(1ull<<63)/10,v=10*v+c-'0';e--)c=*++s))I(c=='e',s++;e+=pl(&s))*p=s;e<0?v/p10(-e):v*p10(e))
S D pd(Q*p)_(Im=**p=='-';(*p)+=m;(1-2*m)*pdu(p))
S Qs,s0;S I nx;
S Q p32(Qs)_(W(*s==32,s++)s)
S A0(pZ,Ax=oL;W(1,Lv=pl(&s);I(!v&&*s=='N',v=NL;s++)x=apv(x,&v);Qp=p32(s);B(p==s||!num(p))s=p)sqzZ(x))
S A0(pD,Ax=oD;W(1,x=apv(x,(D[]){pd(&s)});Qp=p32(s);B(p==s||!num(p))s=p)x)
S A0(pC,Ax=oC;Cc=*++s;W(c&&c-'"',I(c=='\\',c=*++s;Ii=si("tnr0",c);I(i<4,c="\t\n\r"[i]))x=apc(x,c);c=*++s)Ep(!c,x)c=*++s;x)
S C ph()_(Cc=*s;c09(c)?c-'0':caf(c)?c+10-'a':16)
S A0(p0x,Ax=oC;s+=2;W(1,Cc=ph();P(c>15,x)s++;Cd=ph();Ep(d>15,x)s++;x=apc(x,c<<4|d))x)
S A0(ps,Qp=s;Cc=*s;I(c>>7,W((c=*++s)>>6==2)s+=c==':')EI(cAz(c),W(cA9(c),c=*++s))aCm(p,s))
S A pS(Cc)_(Ax=oS;W(1,Ay=c-'`'||*s-'"'?ps():Nx(pC());y=str0(y);y(xq(syP(yV)));P(*s-c,x)++s)0)
S A lam(Ik,Ax,Ay,Az)_(AK(k,a3(x,y,z))) //x:src,y:bytecode,z:locals
S A1(shy,P(xn<2,x)Ay=xA[xn-1];I(ytA&&yn>2,Az=yx;I((z==av||ztu)&&_tsSA(yy),xq(au)))x) //if last is assignment, return ::
S A px(In)_(Q(in(n,4));Ax=aS(n);i(xn,xi='x'+i)x)S A1(p1,xn-1?x:fir(x))S A pb(A,C);
S A0(po,C nb=nx;nx=1;Q s1=s0,t=s0=s++;Ay;I(*s-'[',y=au)E(s++;y=sqz(N(pb(oA,']')));P(!ytS,ep1(y))P(yN>8,s--;ez1(y)))
 Az=pb(a1(PRG),'}');P(!z,s0=s1;y(0))I(y==au,y=px(nx))E(nx=yn)Ax=AK(nx,N(cpl(aCn(t,s-t),shy(z),y)));s0=s1;nx=nb;x)
S A pt(C*v)_(Ax;Cc=*s;P(c=='`',s++;x=N(pS(c));xn>1?enl(x):x)P(c=='{',po())P(c=='"',p1(N(pC())))
 P(c=='(',s++;P(*s==')',s++;oA)x=N(pb(enl(MKL),')'));xn-(C)xn?ez1(x):xn-2?x:las(x))P(c=='[',s++;pb(a1(PRG),']'))
 P(c09(c)&&s[1]==':',I u=s[2]==':';s+=2+u;Ii=20+c-'0';*v=1;AT(tv-u,i))P(c=='0'&&s[1]=='x',p1(N(p0x())))
 P(num(s)&&(c-'-'||(!cA9(s[-1])&&si(")]}\"",s[-1])==4)),L d=0;Qp=s;c=*p;
  W(1,p+=*p==32;B(!num(p))p+=*p=='-';c=*p;B(!cA9(c))W(cA9(c)||c=='.'||c==':',d|=si(".nwe",c)<4;c=*++p))p1(N(d?pD():pZ())))
 P(cAz(c),Qp=s;x=pS('.');I(s-p==1&&c3('y',c,'z'),nx=max(nx,c-'w'))AO(p-s0,p1(x)))P(c>127,Qp=s;x=pS('.');*v=1;AO(p-s0,p1(x)))
 Ii=si("'/\\",c);P(i<3,c=*++s;I h=c==':';s+=h;*v=1;aw+i+3*h)i=si(vc,c);P(i>19,PLH)I u=*++s==':';s+=u;*v=1;AT(tv-u,i))
S A1(mon,Xv(x^au^av)XA(I(xn==2&&xx==aw||xn==3&&xx==COM,x=mut(x);xA[xn-1]=mon(xA[xn-1]))x)
 Xs(Lv=xv;Qs=syp(&v);Nn;P(*s>>7&&s[(n=Sn(s))-1]-':',Cb[8];Mc(b,s,n);b[n]=':';b[n+1]=0;syP(b))x)x)
S A pT(C*v)_(Ax=N(pt(v));
 W(1,Cc=*s;Ii=si("'/\\[",c);P(i>3,x)s++;
  I(i>2,x=AO(s-1-s0,N(pb(a1(x),']')));I(xn==2,I(xy==PLH,xy=au)E(xx=mon(xx)))*v=0)
  E(I u=*s==':';s+=u;x=a2(aw+i+3*u,x);*v=1))x)
S V pw()_(s=p32(s);Cc=*s;P(c-'/')c=s[-1];P(s>s0&&c-32&&c-10)W((c=*++s)&&c-10))
S A pe(Ax,C*v)_(pw();P(s>s0&&*s=='\\'&&s[-1]==32,s++;Ay=pe(0,v);P(!y,x?x(0):0);*v=0;y=a2(OUT,y);I(x,y=a2(mon(x),y))y)
 UH o=s-s0;Cb=0;Ay=pT(&b);P(!y,x?x(0):0)P(y==PLH,x?x:y)P(!b,Az=pe(y,v);P(!x,z)Nx(z);*v?a3(COM,x,z):AO(o,a2(mon(x),z)))
 Az=pe(0,v);P(!z,y(x?x(0):0))P(z==PLH,*v=1;P(!x,y)Ep(ytu,x,y)AO(o,a3(y,x,z)))
 *v&=y!=av;I(!x,y=mon(y))*v?a3(COM,x?AO(o,a3(y,x,PLH)):y,z):AO(o,x?a3(y,x,z):a2(mon(y),z)))
S A pb(Ax,Cc)_(W(1,Cv=0;Ay=Nx(pe(0,&v));I(y==PLH&&c-']',Ep(c==')',x,y)y=au)xq(y);B(*s-';'&&*s-10)s++)Ep(*s-c,x)s++;x)
A pk(Qp)_(s0=s=p;Ax=pb(a1(PRG),0);P(!x,eS(aCz(s0),s-s0);0)x=shy(x);xn-2?x:las(x))
A1(prs,Et(!xtC,x)x=str0(x);x(pk(xV)))
