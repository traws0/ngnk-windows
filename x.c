#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE

S A ser8(L v,A y)_(catc(y,(V*)&v,8))
S A2(serx,y=Nx(apc(y,xt));
 P(xts,O C*s=syp(gs(x));catc(y,s,strlen(s)+1))
 P(pkd(x),ser8(x,y))
 P(xtX||xtS,y=Nx(ser8(xn,y));F(xn,y=Nx(serx(get(x,i),y)))xr;y)
 P(fun(x),serx(AT(tX,x),Nx(apc(y,xv<<3|xk))))
 I l=8*xtT;A u=catc(y,xc-l,l+xn*tZ[xt]);xr;u)
A1(ser,serx(x,aC(0)))

S L des8(C**p)_(L r=*(L*)*p;*p+=8;r)
S A desx(C**p)_(C t=*(*p)++;
 P(t==ts,O C*s=*p;*p+=strlen(s)+1;as(syP(s)))
 P(pkdt(t),des8(p))
 P(t==tX||t==tS,L n=des8(p);A x=AN(0,atn(t,n));F(n,x=apd(x,Nx(desx(p))))x)
 P(funt(t),C vk=*(*p)++;AT(t,AK(vk&7,AV(vk>>3,N(desx(p))))))
 L n=t<ta?des8(p):1;C*v=*p;(*p)+=n*tZ[t];atnv(t,n,v))
A1(des,Ed(!xtC,x)C*s=xc;dex(x,desx(&s)))
