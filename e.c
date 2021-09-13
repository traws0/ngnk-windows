#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S ST{C m[32];In,o;A s;}e; //message,length,offset,source
NI A e0(Qs)_(e.n=min(Sn(s),SZ e.m-1);Mc(e.m,s,e.n);e.m[e.n]=0;0)
NI A e1(Qs,Ax)_(x(e0(s)))
NI A e2(Qs,Ax,Ay)_(y(e1(s,x)))
SN A eN(OA*a,In,Qs)_(mrn(n,a);e0(s))
SN I eC()_(e.n=0;I(e.s,mr(e.s);e.s=0)e.o=0)
NI I eS(Ax/*1*/,Ii)_(P(e.s,x(0))e.s=x;e.o=i;0)
A3(try,x=apn(x,y);P(x,z(x))I(ztF&&zK<3,Ay=aCn(e.m,e.n);z=zK<2?ap1(z,y):apn(z,a2(y,a2(e.s?_R(e.s):oC,az(e.o)))))eC();z)
A1(epr,I h=64;Cb[3*h+6+SZ e.m],*s=b;*s++='\'';Mc(s,e.m,e.n);s+=e.n;*s++=10;
 I(e.s,Ax=e.s;C*t=xV+e.o,*p=t,*q=t+1;W(p>xC&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xC+xn&&q<=t+h&&*q&&*q-10,q++)
  Mc(s,p,q-p);I(p<=t-h,*s=s[1]='.')I(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;Ms(s,32,t-p);s+=t-p;*s++='^';*s++=10)
 eC();write(1,b,s-b);x)
A die(Qs)_(write(1,s,Sn(s));exit(1);0)

#define f(t,m,n,a...) NI A##n(e##t##n,e##n(#m,##a))
#define g(t,m) AA(e##t##n,eN(a,n,#m))
#define h(a...) f(a,0)f(a,1,x)f(a,2,x,y)g(a)
EA
