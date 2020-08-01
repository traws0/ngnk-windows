#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S C em[32];S C en;S A es;S I eo;
NI A err0(O C*m)_(Y((UL)m<256,m=(C*[]){eM}[(I)m])en=min(strlen(m),Z(em)-1);mc(em,m,en);em[en]=0;0)
NI A err1(O C*m,A x)_(xr;err0(m))NI A err2(O C*m,A x,A y)_(yr;err1(m,x))NI A err3(O C*m,A x,A y,A z)_(zr;err2(m,x,y))
NI A errn(O C*m,I n,O A*a)_(mrn(n,a);err0(m))NI S I ecl()_(en=0;Y(es,mr(es);es=0)eo=0)NI I eso(A x/*1*/,I o)_(Y(!es,es=x;eo=o)0)
NI I epr()_(I h=64;C s0[3*h+Z(em)+6],*s=s0;*s++='\'';mc(s,em,en);s+=en;*s++=10;
 Y(es,A x=es;C*t=xc+eo,*p=t,*q=t+1;W(p>xc&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xc+xn&&q<=t+h&&*q&&*q-10,q++)
      mc(s,p,q-p);Y(p<=t-h,*s=s[1]='.')Y(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;F(t-p,*s++=32)*s++='^';*s++=10)
 ecl();write(1,s0,s-s0);0)
A3(try,x=ap2(x,y);P(x,zr;x)Y(fun(z),C k=zk;z=k==1?ap1(z,aCn(em,en)):k==2?ap2(z,a2(aCn(em,en),a2(es?mR(es):ac(0),al(eo)))):z)ecl();z)
