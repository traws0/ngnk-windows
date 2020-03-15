#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S A2(f,
 y=apc(y,xt);
 P(xtc||xti,catc(y,(V*)&x,8))
 P(xtl||xtd,mr2(x,catc(y,xc,xn*tZ(xt))))
 P(xtC||xtI||xtL||xtD,mr2(x,catc(y,xc-8,8+xn*tZ(xt))))
 en(x,y))
A1(ser,f(x,aC(0)))

S C*s;
S A g()_(
 UC t=*s++;
 P(t==tc||t==ti,*(A*)(V*)s)
 P(t==tl||t==td,C*v=s;s+=tZ(t);atnv(t,1,v))
 P(t==tC||t==tI||t==tL||t==tD,L n=*(L*)(V*)s;s+=8;C*v=s;s+=n*tZ(t);atnv(t,n,v))
 en())
A1(des,P(!xtC,ed(x))s=xc;dex(x,g()))
