#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S C m[32];S I n,o;A src; //message,length,offset,source
NI A e0(Qs)_(n=min(Sn(s),SZ m-1);Mc(m,s,n);m[n]=0;0)
NI A e1(Qs,Ax)_(x(e0(s)))
NI A e2(Qs,Ax,Ay)_(y(e1(s,x)))
SN A eN(OA*a,In,Qs)_(mrn(n,a);e0(s))
SN I eC()_(n=0;I(src,mr(src);src=0)o=0)
NI I eS(Ax/*1*/,Ii)_(P(src,x(0))src=x;o=i;0)
A3(try,x=apn(x,y);P(x,z(x))I(ztF&&zK<3,Ay=aCn(m,n);z=zK<2?ap1(z,y):apn(z,a2(y,a2(src?_R(src):oC,az(o)))))eC();z)
A1(epr,I h=64;Cb[3*h+6+SZ m],*r=b;*r++='\'';Mc(r,m,n);r+=n;*r++=10;
 I(src,Ax=src;C*t=xV+o,*p=t,*q=t;W(p>xC&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xC+xn&&q<=t+h&&*q&&*q-10,q++)
  Mc(r,p,q-p);I(p<=t-h,*r=r[1]='.')I(q>t+h,r[q-p-2]=r[q-p-1]='.')r+=q-p;*r++=10;Ms(r,32,t-p);r+=t-p;*r++='^';*r++=10)
 eC();write(1,b,r-b);x)
A die(Qs)_(write(1,s,Sn(s));exit(1);0)

#define f(t,m,n,a...) NI A##n(e##t##n,e##n(#m,##a))
#define g(t,m) AA(e##t##n,eN(a,n,#m))
#define h(a...) f(a,0)f(a,1,x)f(a,2,x,y)g(a)
EA
