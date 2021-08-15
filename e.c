#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S ST{C m[32];In,o;A s;}e; //message,length,offset,source
NI A e0(Qs)_(e.n=min(Sn(s),Z(e.m)-1);Mc(e.m,s,e.n);e.m[e.n]=0;0)
NI A e1(Qs,Ax)_(x(e0(s)))
NI A e2(Qs,Ax,Ay)_(y(e1(s,x)))
NI A eN(Qs,In,OA*a)_(mrn(n,a);e0(s))
SN I eC()_(e.n=0;I(e.s,mr(e.s);e.s=0)e.o=0)
NI I eS(Ax/*1*/,Ii)_(I(!e.s,e.s=x;e.o=i)E(x(0))0)
A3(try,x=apn(x,y);P(x,z(x))
 I(ztF,Ck=zK;z=k==1?ap1(z,aCn(e.m,e.n)):k==2?apn(z,a2(aCn(e.m,e.n),a2(e.s?_R(e.s):ac(0),az(e.o)))):z)eC();z)
A1(epr,I h=64;C s0[3*h+Z(e.m)+6],*s=s0;*s++='\'';Mc(s,e.m,e.n);s+=e.n;*s++=10;
 I(e.s,Ax=e.s;C*t=xC+e.o,*p=t,*q=t+1;W(p>xC&&p>t-h&&p[-1]&&p[-1]-10,p--)W(q<xC+xn&&q<=t+h&&*q&&*q-10,q++)
  Mc(s,p,q-p);I(p<=t-h,*s=s[1]='.')I(q>t+h,s[q-p-2]=s[q-p-1]='.')s+=q-p;*s++=10;Ms(s,32,t-p);s+=t-p;*s++='^';*s++=10)
 eC();write(1,s0,s-s0);x)
A die(Qs)_(write(1,s,Sn(s));exit(1);0)

#define g(t,m,n,a...) NI A##n(e##t##n,e##n(#m,##a))
#define h(a...) g(a,0)g(a,1,x)g(a,2,x,y)
EA
