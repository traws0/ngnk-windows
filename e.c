#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S struct{C m[32];I n,o;A s;}e; //message,length,offset,source
NO A e0(O C*m)_(Y((UL)m<256,m=(C*[]){eM}[(I)m])e.n=min(mn(m),Z(e.m)-1);mc(e.m,m,e.n);e.m[e.n]=0;0)
NO A e1(O C*m,A x        )_(dex(x,e0(m    )))
NO A e2(O C*m,A x,A y    )_(dex(y,e1(m,x  )))
NO A e3(O C*m,A x,A y,A z)_(dex(z,e2(m,x,y)))
NO A eN(O C*m,I n,O A*a)_(mrn(n,a);e0(m))
SN I ecl()_(e.n=0;Y(e.s,mr(e.s);e.s=0)e.o=0)
NO I eso(A x/*1*/,I o)_(Y(!e.s,e.s=x;e.o=o)0)
A3(try,x=apn(x,y);P(x,zr;x)Y(fun(z),C k=zk;z=k==1?ap1(z,aCn(e.m,e.n)):k==2?apn(z,a2(aCn(e.m,e.n),a2(e.s?mR(e.s):ac(0),al(e.o)))):z)ecl();z)
A1(epr,I h=64;C s0[3*h+Z(e.m)+6],*s=s0;*s++='\'';mc(s,e.m,e.n);s+=e.n;*s++=10;
 Y(e.s,A x=e.s;C*t=xc+e.o,*p=t,*q=t+1;W(p>xc&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xc+xn&&q<=t+h&&*q&&*q-10,q++)
       mc(s,p,q-p);Y(p<=t-h,*s=s[1]='.')Y(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;F(t-p,*s++=32)*s++='^';*s++=10)
 ecl();write(1,s0,s-s0);x)
