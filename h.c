#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A rsh_(A x/*0*/,L m,L*pj,L*s,L r)_(L n=llabs(*s);P(r>1,A y=aX(n);F(n,yai=rsh_(x,m,pj,s+1,r-1))y)
 UC t=t_lst(xt);$(t&&!xn,x=cn[t])L j=*s>=0?*pj:(m-n%m)%m,w=tZ(t),q=min(m-j,n);*pj=(j+n)%m;A y=atn(t,n);mc(yc,xc+j*w,q*w);mc(yc+q*w,xc,min(j,n-q)*w);
 W(2*m<=n,mc(yc+m*w,yc,m*w);m*=2)mc(yc+m*w,yc,(n-m)*w);$(t==tX,y=sqz(mRa(y)))y)
SN A2(flt,P(!ytT,er(x,y))A u=atn(yt,0);F(yn,A z=get(y,i);z=app(x,&z,1);$(!z,ur;u=0;B)z=gL(z);P(!z,xr;yr;ur;0)Fj(gl(z),u=apd(u,get(y,i))))xr;yr;u)
S A2(rsh0N,asrt(xtL);asrt(xn==2);asrt(ytT);P((*xl<=0&&xl[1]<=0)||!yn,ed(x,y))K("{n:1+(-m:|/x)!-1+l:#y;$[^*x;m*!n;0|l+n*!-m]_y}",x,y))
A2(rsh,P(fun(x),flt(x,y))P(yta&&!xtl,x=enla(x);xR;aa(x,ap1(y,x)))P(ytA,y=mut(y);yy=ear(cV('#'),A_(x,yy),2);y)
 y=!ytT?enl(y):!yn?enl(fir(y)):y;x=enla(Ny(gL(x)));P(!xn,xr;fir(y))
 F(xn,L v=xli;$(v<0,P(xn>2||(xn==2&&v!=_0N)||(xn==1&&v==_0N),ed(x,y))P(xn==2,rsh0N(x,y))))L j=0;A u=rsh_(y,yn,&j,xl,xn);xr;yr;u)
A1(enl,P(sim(x),atv(t_lst(xt),gl(x)))P(xta,A y=gkv(&x);aA(x,ea1(enl,y)))a1(x))A1(enla,xtt||xta?enl(x):x)
A2(cat,P(xtaA&&ytaA,P(!mtc_(xx,yx),ed(x,y))A u=eac(cV(','),A_(mR(xy),mR(yy)),2);$(u,u=aA(mR(xx),u))xr;yr;u)
 x=enla(x);y=enla(y);$(!xn,swp(x,y))P(!yn,yr;x)$(xt-yt,x=Ny(blw(x));y=Nx(blw(y)))L w=tZ(xt),m=xn,n=yn;
 A u;$(Ar(x)==1&&ZA+(m+n)*w<=1<<Ab(x),u=AN(m+n,x))E(u=atn(xt,m+n);mc(uc,xc,m*w);$(xtX,$(Ar(x)==1,mr(AN(0,x)))E(mRa(x);xr))E(xr))
 mc(uc+m*w,yc,n*w);$(ytX,mRa(y))yr;u)
A apv(A x,O V*v)_(asrt(xtT);L n=xn,w=tZ(xt);
 $(Ar(x)==1&&ZA+w+n*w<=1L<<xb,x=AN(n+1,x))E(A y=atn(xt,n+1);$(Ar(x)>1&&xtX,mRa(x))E(x=AT(tL,x);asrt(ZV==8))xr;mc(yc,xc,n*w);x=y)
 V*p=xc+n*w;$(w==1,*(C*)p=*(C*)v)$(w==2,*(H*)p=*(H*)v)$(w==4,*(I*)p=*(I*)v)$(w==8,*(L*)p=*(L*)v)x)
A2(apd,asrt(xtT||xtA);P(xtA,P(!yta||!mtc_(xx,yx),apd(Ny(blw(x)),y))x=mut(x);A z=xy=mut(xy);F(An(z),zai=apd(zai,get(yy,i)))yr;x)
 $(!xtX&&(!ytt||xt-t_lst(yt)),x=blw(x))P(!xn,xr;enl(y))L v=xtX?(L)y:gl(y);apv(x,&v))
A room(A x,L l)_(asrt(xtC);L n=xn;P(Ar(x)==1&&ZA+n+l<=1L<<xb,x)xr;AN(n,atnv(tC,n+l,xc)))
A apc(A x,C c)_(asrt(xtC);x=room(x,1);xc[xn]=c;AN(xn+1,x))A catc(A x,O C*s,L l)_(asrt(xtC);x=room(x,l);mc(xc+xn,s,l);AN(xn+l,x))
