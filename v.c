#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#define til_(T)   V til##T(V*p,L n)_(T*a=p;ALN(a)F(PAD(n,a),a[i]=i))
#define r_(T)     S V r##T(V*p,L n)_(T*a=p,*b=a+n-1;W(a<b,SWP(*a,*b);a++;b--))
#define c_(T,R,p) S V c##T##R(OV*RE v,V*RE w,UL n)_(O T*RE a=v;R*RE r=w;F(PAD(n,p),r[i]=a[i]))
#define cN(T,R,p) S V c##T##R(OV*RE v,V*RE w,UL n)_(O T*RE a=v;R*RE r=w;F(PAD(n,p),r[i]=a[i]==N##T?N##R:a[i]))
til_(H)til_(I)til_(L)r_(C)r_(H)r_(I)r_(L)
c_(C,I,r)c_(I,C,a)c_(L,C,a)cN(H,I,r)cN(I,H,a)cN(H,L,r)cN(L,H,a)cN(I,L,r)cN(L,I,a)cN(L,D,a)cN(D,L,a)
A1(flp,P(xtmM,Y(xtm,Ay=xy;Er(!ytA||!yn,x)F(yn,Az=ya;En(!ztT,x))L m=An(*yA);F(yn,Az=ya;El(zn-m,x)))AT(xt^tm^tM,x))
 Xtt(enl(enl(x)))P(!xtA||!xn,enl(x))K("{(,/n#'x)(n*!#x)+/:!n:|/#'x}",x))
A1(til,P(xth||xtil,Ln=gl_(x);Im=n<0;n*=1-2*m;Au=atn(tT(xt),n);CH(xt-th,&tilH,tilI,tilL)(uC,n);(m?add:dex)(x,u))
 P(xtIL,K("{x((*a)#&#)'1_a:|*\\|x,1}",x))Xtm(fir(AT(tA,x)))Xto(val(x))Et(!xtA||xn,x)x)
A1(whr,Et(xtM||xtA,x)Xtm(Ay=gkv(&x);idx(x,Nx(whr(y))))x=N(gL(enla(x)));Ln=0;F(xn,Ed(xl<0,x)n+=xl)
 Au=aL(n);m2(x,n=0;F(xn,Fj(xl,uL[n++]=i))u))
A1(rev,Xtt(x)Xtm(AT(tm,N(ea1(rev,AT(tA,x)))))XtM(Ay=gkv(&x);aM(x,Nx(ea1(rev,y))))
 x=mut(x);CH(Zt[xt],&rC,rH,rI,rL,rL)(xC,xn);x)
A1(typ,Ct=xt;xr;as(syC(TS[t])))
A1(len,dex(x,al(len_(x))))L len_(Ax/*0*/)_(xtT?xn:xtm?len_(xy):!xtM?1:An(xy)?len_(*(A*)dat(xy)):1)
A1(unq,Et(!xtT,x)xn<2?x:K("{x@&@[&#x;i;:;]@[;0;:;a=a:*a]@a:~$[`A=@x;~;=]':x@i:<x}",x))
S A2(fil,ytmMA?eac(cv('^'),A(x,y),2):ytt?fir(xpt(x,enl(y))):K("{@[y;&^y;:;x]}",x,y))
A2(xpt,Xtt(fil(x,y))En(xtmM||ytmM,x,y)y=enla(y);Y(xtA,y=blw(y))K("{x@&^y?x}",x,y))
A2(cut,P(ytil,Et(!xtT,x,y)Li=gl(y);P(!in(i,xn),x)
              Au=atn(xt,xn-1);L w=ZT[xt];mc(uC,xC,i*w);mc(uC+i*w,xC+i*w+w,(xn-i-1)*w);Y(xtA,u=sqz(mRa(u)))xr;u)
 Ytm(rsh(xpt(mR(yx),x),y))Et(ytt,x,y)x=Ny(gL(x));K("{n:#y;y$[`l=@x;$[n<x|-x;!0;x<0;!n+x;x+!n-x];x+!'1_-':x,#y]}",x,y))
S A gt(Ax,A1*f)_(fir(N(f(enl(x)))))
A1(gC,P(xtcC,x)Xtt(gt(x,gC))x=N(gI(x));Au=aC(xn);m2(x,cIC(xC,uC,un);u))
A1(gH,P(xthH,x)Xtt(gt(x,gH))x=N(gI(x));Au=aH(xn);m2(x,cIH(xC,uC,un);u))
A1(gI,P(xtiI,x)P(xtdD,gI(N(gL(x))))Xtl(gt(x,gI))XtL(Au=aI(xn);m2(x,cLI(xC,uC,un);u))Xtc(ai(gc(x)))Xth(ai(gh(x)))
 XtC(Au=aI(xn);m2(x,cCI(xC,uC,un);u))XtH(Au=aI(xn);m2(x,cHI(xC,uC,un);u))Et(1,x);0)
A1(gL,P(xtlL,x)Xtt(gt(x,gL))XtD(Au=aL(xn);m2(x,cDL(xC,uC,un);u))x=N(gI(x));Au=aL(xn);m2(x,cIL(xC,uC,un);u))
A1(gD,P(xtdD,x)Xtt(gt(x,gD))x=N(gL(x));Au=aD(xn);m2(x,cLD(xC,uC,un);u))
A1(gS,P(xtsS,x)XtC(x=str0(x);dex(x,as(syP(xC))))Et(!xtc,x)as(syC(gc(x))))
A2(cst,P(ytmMA,eac(cv('$'),A(x,y),2))P(xtil&&ytC,ap1(y,Ny(til(x))))En(!xts,x,y)SF(x,y,"``s`c`h`i`l`d",gS,gS,gC,gH,gI,gL,gD))
A1(sqz,P(!xtA||!xn,x)Ay=xx;Ct=yt;P(!sim(y)&&t-tm,x)Ln=xn;F(n,Ay=xa;P(t-yt,x))
 P(t==tm,Az=yx;F(n,Ay=xa;P(!mtc_(yx,z),x))aM(zR,flp(ea1(val,x))))En(t==tM,x)
 t=tT(t);Au=atn(t,n);P(Zt[t]<3,m2(x,CH(Zt[t],&cLC,cLH,cLI)(xL,uC,n);u))F(n,Ay=xa;ul=*yL);xr;u)
A1(blw,XtA(x)Xtt(a1(x))Et(xtm,x)Ln=len_(x);Au=aA(n);F(n,ua=get(x,i))xr;u)
L tru(Ax/*1*/)_(Lv=sim(x)?gl_(x):fun(x)?!xtu||xv:xn;xr;v)A2(dex,xr;y)A1(fir,xtt?x:dex(x,getr(x,0)))A1(las,xtt?x:dex(x,getr(x,xn-1)))
I mtc_(Ax,Ay/*x0y0*/)_(P(x==y,1)P(xt-yt||pkd(x)||xn-yn||(xtr&&xv-yv),0)P(!ref(x),F(xn*ZT[xt],P(xc-yc,0))1)F(xn,P(!mtc_(xa,ya),0))1)
S I cmpL(Li,Lj)_(i<j?-1:i>j)
S I cmp_(Ax,Ay/*x0y0*/)_(P(x==y,0)Iv=xt-yt;P(v,v)P(xtc||xth||xti,gi(x)-gi(y))Xtl(cmpL(gl_(x),gl_(y)))
 Xtd(D u=gd_(x),v=gd_(y);u<v?-1:u>v?1:0)Xts(strcmp(syp(gs(x)),syp(gs(y))))
 Y(!pkd(x),Iv=cmpL(xn,yn);XtT(F(min(xn,yn),Az=get(x,i),u=get(y,i);I d=cmp_(z,u);zr;ur;P(d,d))v))cmpL(x,y))
A2(mtc,Iv=mtc_(x,y);xr;yr;ai(v))
S I bef(A*a,Ii,Ij)_(Iv=cmp_(a[i],a[j]);v?v<0:i<j)
S V sft(A*a,I*l,Ii,Ij)_(W(1,Lk=1+2*i;Y(k>j,B)Y(k+1<=j&&bef(a,l[k],l[k+1]),k++)Y(!bef(a,l[i],l[k]),B)SWP(l[i],l[k])i=k))
S A1(asci,Ez(xn>WI,x)x=N(K("{x-&/x}",x));I w=ZT[xt];UI n=xn;Ay=aC(n),z=aI(n),u=aI(n);C*a=dat(y);UI c[257];tilI(uI,n);
 m2(x,m2(y,Fj(w,ms(c,0,Z c);F(n,a[i]=xC[w*ui+j])F(n,c[a[i]+1]++)Y(c[1+*a]-n,F(255,c[i+1]+=c[i])F(n,zI[c[a[i]]++]=ui)SWP(z,u)))zr;u)))
A1(asc,XtA(Ez(xn>WI,x)A*a=xA,u=til(ai(xn));In=xn,i=n/2;W(i-->0,sft(a,uI,i,n-1))i=n-1;W(i>0,SWP(ui,*uI)sft(a,uI,0,--i))xr;u)
 Xtm(Ay=gkv(&x);idx(x,N(asc(y))))P(xtIL||xtC,asci(x))XtS(asc(N(ea1(str,x))))XtD(asc(blw(x)))Et(!(xts||xti),x)hop(x))
A1(dsc,Xti(hcl(x))Xtm(Ay=gkv(&x);idx(x,Nx(dsc(y))))Et(!xtT,x)sub(ai(len_(x)-1),rev(asc(rev(x)))))
A1(grp,Xtt(Et(!xtil)K("{(2#x)#1i,`i$&x}",x))Xtm(Au=grp(gkv(&x));Q(Ar(u)==1);uy=idx(x,uy);u)Ay=atn(xt,0),u=a0();C w=Zt[xt];
 F(xn,Lj=!w?fpC(&y,xc):w==2?fpI(&y,xi):w==3?fpL(&y,xl):fpA(&y,mR(xa));Y(j==un,u=apd(u,aL(0)))uA[j]=apv(uA[j],&i))xr;am(y,u))
