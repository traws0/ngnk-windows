#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S struct{C m[32];I n,o;A s;}e; //message,length,offset,source
NI A err0(O C*m)_(Y((UL)m<256,m=(C*[]){eM}[(I)m])e.n=min(mn(m),Z(e.m)-1);mc(e.m,m,e.n);e.m[e.n]=0;0)
NI A err1(O C*m,A x)_(xr;err0(m))NI A err2(O C*m,A x,A y)_(yr;err1(m,x))NI A err3(O C*m,A x,A y,A z)_(zr;err2(m,x,y))
NI A errn(O C*m,I n,O A*a)_(mrn(n,a);err0(m))NI S I ecl()_(e.n=0;Y(e.s,mr(e.s);e.s=0)e.o=0)NI I eso(A x/*1*/,I o)_(Y(!e.s,e.s=x;e.o=o)0)
NI I epr()_(I h=64;C s0[3*h+Z(e.m)+6],*s=s0;*s++='\'';mc(s,e.m,e.n);s+=e.n;*s++=10;
 Y(e.s,A x=e.s;C*t=xc+e.o,*p=t,*q=t+1;W(p>xc&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xc+xn&&q<=t+h&&*q&&*q-10,q++)
      mc(s,p,q-p);Y(p<=t-h,*s=s[1]='.')Y(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;F(t-p,*s++=32)*s++='^';*s++=10)
 ecl();write(1,s0,s-s0);0)
A3(try,x=ap2(x,y);P(x,zr;x)Y(fun(z),C k=zk;z=k==1?ap1(z,aCn(e.m,e.n)):k==2?ap2(z,a2(aCn(e.m,e.n),a2(e.s?mR(e.s):ac(0),al(e.o)))):z)ecl();z)
