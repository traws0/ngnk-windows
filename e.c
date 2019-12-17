#include"k.h" // ngn/k, (c) ngn 2019, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S C em[32];S UC en;S A es;S UH eo;S O C eM[][3]={"nyi","len","typ","dom","rnk","idx","prs"};
cold A err0(O C*m)_($((UL)m<128,*(I*)(V*)em=*(I*)(V*)eM[(UL)m];en=3)E(en=min(strlen(m),Z(em)-1);mc(em,m,en+1))0)
cold A err1(O C*m,A x)_(xr;err0(m))cold A err2(O C*m,A x,A y)_(yr;err1(m,x))cold A err3(O C*m,A x,A y,A z)_(zr;err2(m,x,y))
cold A errn(O C*m,I n,O A*a)_(mrn(n,a);err0(m))cold I ecl()_(en=0;$(es,mr(es);es=0)eo=0;0)cold I eso(A x/*1*/,L o)_($(!es,es=x;eo=o)0)
cold I epr()_(C s0[0x1000],*s=s0;*s++='\'';mc(s,em,en);s+=en;*s++=10;A x=es;
 $(x,C*p=xc+eo,*q=p+1;W(p>xc&&p[-1]&&p[-1]-10,p--)W(*q&&*q-10&&q<xc+xn,q++)mc(s,p,q-p);s+=q-p;*s++=10;F(xc+eo-p,*s++=32)*s++='^';*s++=10)
 ecl();write(1,s0,s-s0);0)
A3(try,x=ap2(x,y);P(x,zr;x)$(fun(z),UC k=Ak(z);z=k==1?ap1(z,aCn(em,en)):k==2?ap2(z,a2(aCn(em,en),a2(es?mR(es):ac(0),al(eo)))):z)ecl();z)
