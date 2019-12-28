#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S C em[32];S UC en;S A es;S UH eo;S O C*eM[]={"nyi","len","typ","dom","rnk","idx","prs"};
cold A err0(O C*m)_($((UL)m<128,m=eM[(L)m])en=min(strlen(m),Z(em)-1);mc(em,m,en);em[en]=0;0)
cold A err1(O C*m,A x)_(xr;err0(m))cold A err2(O C*m,A x,A y)_(yr;err1(m,x))cold A err3(O C*m,A x,A y,A z)_(zr;err2(m,x,y))
cold A errn(O C*m,I n,O A*a)_(mrn(n,a);err0(m))cold S I ecl()_(en=0;$(es,mr(es);es=0)eo=0)cold I eso(A x/*1*/,L o)_($(!es,es=x;eo=o)0)
cold I epr()_(I h=64;C s0[3*h+Z(em)+6],*s=s0;*s++='\'';mc(s,em,en);s+=en;*s++=10;
 $(es,A x=es;C*t=xc+eo,*p=t,*q=t+1;W(p>xc&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xc+xn&&q<=t+h&&*q&&*q-10,q++)
      mc(s,p,q-p);$(p<=t-h,*s=s[1]='.')$(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;F(t-p,*s++=32)*s++='^';*s++=10)
 ecl();write(1,s0,s-s0);0)
A3(try,x=ap2(x,y);P(x,zr;x)$(fun(z),UC k=Ak(z);z=k==1?ap1(z,aCn(em,en)):k==2?ap2(z,a2(aCn(em,en),a2(es?mR(es):ac(0),al(eo)))):z)ecl();z)
