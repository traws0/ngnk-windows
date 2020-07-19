#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
A rsh_(A x/*0*/,L m,L*pj,L*s,L r)_(L n=absL(*s);P(r>1,A y=aX(n);F(n,yai=rsh_(x,m,pj,s+1,r-1))y)
 C t=t_lst(xt);Y(t&&!xn,x=cn[t])L j=*s>=0?*pj:(m-n%m)%m,w=tZ[t],q=min(m-j,n);*pj=(j+n)%m;A y=atn(t,n);mc(yc,xc+j*w,q*w);mc(yc+q*w,xc,min(j,n-q)*w);
 W(2*m<=n,mc(yc+m*w,yc,m*w);m*=2)mc(yc+m*w,yc,(n-m)*w);Y(t==tX,y=sqz(mRa(y)))y)
A2(flt,Er(!ytT,x,y)A u=atn(yt,0);F(yn,A z=get(y,i);z=app(x,&z,1);Y(!z,ur;u=0;B)z=gL(z);P(!z,xr;yr;ur;0)Fj(gl(z),u=apd(u,get(y,i))))xr;yr;u)
A2(rsh,P(fun(x),flt(x,y))P(yta&&!xtl,x=enla(x);xR;aa(x,ap1(y,x)))P(ytA,y=mut(y);yy=ear(cv('#'),A_(x,yy),2);y)
 y=!ytT?enl(y):!yn?enl(fir(y)):y;x=enla(Ny(gL(x)));P(!xn,xr;fir(y))
 F(xn,L v=xli;Y(v<0,Ed(xn>2||xn==2&&v-_0Nl||xn==1&&v==_0Nl,x,y)
                    P(xn==2,Ed(*xl<=0&&xl[1]<=0||!yn,x,y)K("{n:1+(-m:|/x)!-1+l:#y;$[^*x;m*!n;0|l+n*!-m]_y}",x,y))))
 L j=0;A u=rsh_(y,yn,&j,xl,xn);xr;yr;u)
A1(enl,P(sim(x),atv(t_lst(xt),gl(x)))P(xta,A y=gkv(&x);aA(x,ea1(enl,y)))a1(x))A1(enla,xtt||xta?enl(x):x)
A2(cat,P(xtaA&&ytaA,P(xta&&yta,A z=gkv(&y);amd(A_(x,y,av0,z),4))Ed(!mtc_(xx,yx),x,y)A u=eac(cv(','),A_(mR(xy),mR(yy)),2);Y(u,u=aA(mR(xx),u))xr;yr;u)
 x=enla(x);y=enla(y);Y(!xn,SWP(x,y))P(!yn,yr;x)Y(xt-yt,x=Ny(blw(x));y=Nx(blw(y)))L w=tZ[xt],m=xn,n=yn;
 A u;Y(Ar(x)==1&&ZA+(m+n)*w<=1<<xb,u=AN(m+n,x))E(u=atn(xt,m+n);mc(uc,xc,m*w);Y(xtX,Y(Ar(x)==1,mr(AN(0,x)))E(mRa(x);xr))E(xr))
 mc(uc+m*w,yc,n*w);Y(ytX,mRa(y))yr;u)
A apv(A x,O V*v)_(asrt(xtT);L n=xn,w=tZ[xt];
 Y(Ar(x)==1&&ZA+w+n*w<=1L<<xb,x=AN(n+1,x))E(A y=atn(xt,n+1);Y(Ar(x)>1&&xtX,mRa(x))EY(ref(x),x=AT(tL,x);asrt(ZV==8))m2(x,mc(yc,xc,n*w));x=y)
 V*p=xc+n*w;Y(w==1,*(C*)p=*(C*)v)Y(w==2,*(H*)p=*(H*)v)Y(w==4,*(I*)p=*(I*)v)Y(w==8,*(L*)p=*(L*)v)x)
A2(apd,asrt(xtT||xtA);P(xtA,P(!yta||!mtc_(xx,yx),apd(Ny(blw(x)),y))x=mut(x);A z=xy=mut(xy);F(An(z),zai=apd(zai,get(yy,i)))yr;x)
 Y(!xtX&&(!ytt||xt-t_lst(yt)),x=blw(x))P(!xn,xr;enl(y))L v=xtX?(L)y:gl(y);apv(x,&v))
A apc(A x,C c)_(asrt(xtC);x=room(x,1);xc[xn]=c;AN(xn+1,x))A catc(A x,O C*s,L l)_(asrt(xtC);x=room(x,l);mc(xc+xn,s,l);AN(xn+l,x))
