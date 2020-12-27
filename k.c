#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S A1(sam,x) //                                                                                                                  plc
OC vc[]={':','+','-','*','%','!','&','|','<','>','=','~',',','^','#','_','$','?','@','.','0','1','2','3','4','5','\'','/','\\','[',  0,  0};
OV*vf[]={sam,flp,neg,fir,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,len,flr,str,unq,typ,val,u0c,u1c,sam,sam,las,out,   0,  0, cmd,  0,  0,  0,
         dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql,mtc,cat,xpt,rsh,cut,cst,fnd,ap1,apn,v0c,v1c,dex,dex,com,dex, eac,rdc, scn,eap,ear,eal};
A1(mkn,P(xtmMA,ea1(mkn,x))Ay=mR(cn[xt]);xtt?dex(x,y):rsh(len(x),y)) //                                       mkl   '   /    \  ':   /:  \:
A2(id_/*x0y0*/,xtv&&xv<11?mR(ci[ytiI?0:ytdD?2:1][CH(xv,(C)4,0,0,1,1,2,2,3,3,2,4)]):mkn(fir(yR)))
A2(com,AK(yk,AT(tq,a2(x,y))))
AX(prj,XA(app(x,a,n))Ck=max(n,xk);F(n,k-=a[i]!=au_plc)Au=AK(k,atn(tp,n+1));ux=xR;mc(uA+1,a,8*n);u)
S A getM(Ax/*0*/,Lj)_(Q(xtM);Ay=xy,u=a0();F(yn,u=apd(u,get(ya,j)))am(mR(xx),u))
A get(Ax/*0*/,Li)_(XL(al(xl))XI(ai(xi))XA(mR(xa))XH(ah(xh))XS(as(xi))XC(ac(xc))XD(ad(xd))Xm(get(xy,i))XM(getM(x,i))xR)
A getr(Ax/*0*/,Li)_(Q(!xtt);in(i,xn)?get(x,i):xn?mkn(get(x,0)):mR(cn[xt]))
#define i_(T,U) SN V i##T##U(OV*RE a,L m,OV*RE b,V*RE c,Ln,Lv){O T*p=a;O U*q=b;T*r=c;F(n,U j=q[i];r[i]=in(j,m)?p[j]:v)}
i_(C,L)i_(H,L)i_(I,L)i_(L,L)i_(C,I)i_(H,I)i_(I,I)i_(L,I)
S A2(idx_/*x0y1*/,Er(xtt,y)P(y==au_plc,xR)YA(ear(cv('@'),A(xR,y),2))Ym(y=mut(y);yy=idx_(x,yy);y)Et(fun(y),y)Yt(getr(x,gl(y)))
 y=ytlL?y:N(gI(y));y=N(gL(y));L w=Zt[xt];Au=xtM?a0():atn(xt,yn);P(xtA||xtM,u=AN(0,u);F(yn,u=apd(u,getr(x,yl)))yr;u)
 A z=cn[xt];m2(y,CH(w+4*ytlL,&iCI,iHI,iII,iLI,iCL,iHL,iIL,iLL)(xC,xn,yC,uC,un,w==3?*zL:(I)z);0);u)
S AX(idxA,Ay=*a++;n--;YA(A b[8];*b=au_plc;mc(b+1,a,n);Az=prj(x,b,n+1);dex(z,eac(z,a-1,1)))
 P(ytT||y==au_plc,x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)K(".\\:",x,atnv(tA,n,a)))x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)Au=idxA(x,a,n);xr;u)
S A2(wrt,Xl(wrt(gI(x),y))Yc(wrt(x,enl(y)))Et(!xti||!ytC,y)write(gi(x),yC,yn);y)S A1(fnow,xr;al(now()))
AX(app,XT(xtA?idxA(x,a,n):n-1?ein(n,a):idx_(x,*a))P(xtil,n-1?ern(n,a):wrt(xR,*a))
 Xs(P(n>1,ern(n,a))SF(x,*a,"``j`k`p`t`x`e`hex`md5`sha1`sha256`sha3`aes`sin",
                      ser,jsw,kst,prs,fnow,frk,epr,hex,md5,sha1,sha256,sha3_256,aes0,sinx))
 Xm(Ay=N(idx_(xy,N(fnd(mR(xx),*a))));n-1?dex(y,app(y,a+1,n-1)):y)
 XM(Ay=*a;n>1?ern(n,a):ytilIL?idx_(x,y):app(AT(tm,x),a,n))
 P(n<xk,prj(x,a,n))Xv(n==2?((A2*)vf[32+xv])(*a,a[1]):x==cv('@')?amd(a,n):x==cv('.')?dmd(a,n):enn(n,a))Xr(((AX*)vf[58+xv])(xx,a,n))
 P(n>xk,ern(n,a))Xu(((A1*)vf[xv])(*a))Xw(Ay=*a;AK(0<xv&&xv<4&&yk==2?1:fun(y)?yk:1,AV(xv,atnv(tr,1,a))))Xo(run(x,a,n))
 Xp(P(n+xn>9,ern(n,a))I m=xn-1,j=0;A b[8];F(m,b[i]=xA[i+1]==au_plc&&j<n?a[j++]:mR(xA[i+1]))I l=max(0,n-j);mc(b+m,a+j,8*l);app(xx,b,m+l))
 Xq(app(xx,&(A){N(app(xy,a,n))},1))etn(n,a))
A1(val,XS(Ay=glb;F(xn,Et(!ytm,x)Az=yx,u=yy;Ed(!ztS||!utA,x)Ik=xi;Ij=fAI(z,k);Ev(j<0,x)y=uA[j])xr;yR)
 XA(P(!xn,x)P(xn==1,fir(x))Ez(xn>9,x)x=mut(x);Au=app(xx,&xy,xn-1);mr(AN(1,x));u)
 XC(x=N(cpl(N(prs(x))));dex(x,run(x,0,0)))P(xtc||xts,val(enl(x)))Xm(las(AT(tA,x)))Xr(cat(AT(tA,x),aw(xv)))
 P(c3(tu,xt,tw),al(xv))P(xto||xtp||xtq,AT(tA,x))Et(1,x);0)
A2(idx,dex(x,idx_(x,y)))
A2(ap1,dex(x,app(x,&y,1)))
A2(apn,y=enla(y);Ln=yn;P(!n,yr;x)Ez(n>8,x,y)y=mRa(Nx(blw(y)));Au=app(x,yA,n);xr;yr;u)
S A set(Ax,Li,Ay)_(Q(Ar(x)==1);Y(!xtA&&(!sim(y)||xt-tT(yt)),x=blw(x))
 XA(mr(xa);xa=y;sim(y)?sqz(x):x)xtC?xc=gc(y):xtI?xi=gi(y):xtL?xl=gl(y):xtD?xd=gd(y):xtS?xi=gs(y):0;x)
S I stp(Li,Ax/*0*/,A**pp)_(Ay=**pp;Ed(!ytm,x)**pp=y=mut(y);Az=yx;Ed(!ztS,x)Lj=fpI(&yx,xI[i+1]);Au=yy;Ed(!utA,x)
 yy=j==un?apd(u,aa0()):mut(u);Q(Ar(yy)==1);*pp=(A*)dat(yy)+j;1)
S A*pth(Ax/*1*/)_(x=enla(x);Ay=glb;Q(xtS&&Ar(y)==1&&ytm&&At(yx)==tS&&At(yy)==tA);Lj=fpI(&yx,*xI);
 Y(j==An(yy),yy=apd(yy,xn>1?aa0():au0))A*p=(A*)dat(yy)+j;F(xn-1,P(!stp(i,x,&p),(A*)0))xr;p)
S A mend(OA*a,In,AA*f)_(A*p=pth(*a);P(!p,mrn(n-1,a+1);0)A b[8];*b=*p;*p=au0;mc(b+1,a+1,(n-1)*8);*p=mR(N(f(b,n))))
AA(am1,Ax=*a,y=a[1],z=a[2];Xt(etn(n,a))
 Xm(x=mut(x);xx=unq(cat(xx,yR));xy=cat(xy,rsh(al(An(xx)-An(xy)),id_(z,xy)));
  A b[8];*b=xy;b[1]=fnd(mR(xx),y);mc(b+2,a+2,(n-2)*8);xy=am1(b,n);P(!xy,xy=au0;xr;0)x)
 Yt(x=mut(x);y=gL(y);P(!y,xr;mrn(n-2,a+2);0)
  Li=gl(y);P(!in(i,xn),xr;ein(n-2,a+2))A b[8];*b=get(x,i);mc(b+1,a+3,(n-3)*8);Au=app(z,b,n-2);zr;set(x,i,Nx(u)))
 P(n==4&&(xtIL||xtD)&&ytIL&&ztv&&zv<8&&xt==tT(At(a[3])),x=mut(x);Au=a[3];I d=utT;u=enla(u);Ei(d&&yn-un,x,y,u)y=gL(y);
  Ei(!m2(y,m2(u,x?((int(*)(V*,L,L*,L,V*,I))arf[xt-tI][zv][7])(xC,xn,yL,yn,uC,d):1)))x)
 P(n==4&&xtC&&ytL&&z==av0&&tT(At(a[3]))==tC,x=mut(x);Au=a[3];I d=utT;u=enla(u);El(d&&yn-un,x,y,u)
  x=m2(y,m2(u,F(yn,Lj=yl;Y(!in(j,xn),x=0;B)xC[j]=uC[d*i])x));Ei(!x)x)
 rdc(cv('@'),a,n))
AA(amd,Ax=*a;xts?mend(a,n,am1):am1(a,n))
AA(dm1,Ax=*a,y=a[1],z=a[2];L m=len_(y);P(!m||y==au0,yr;A b[8];*b=x;mc(b+1,a+3,(n-3)*8);dex(z,app(z,b,n-2)))
 P(m==1,A b[8];mc(b,a,n*8);b[1]=fir(y);am1(b,n))P(n-4,enn(n,a))K("{[x;y;z;u]@[x;*y;.[;1_y;z;];u]}",x,y,z,a[3]))
AA(dmd,Ax=*a,y=a[1],z=a[2];n==3&&fun(x)?try(x,y,z):xtsS?mend(a,n,dm1):dm1(a,n))
A K0(OC*s,In)_(L m=mu;Ax=val(aCn(s,n+1));mu=m;x)
OC Zt[]={Tz},ZT[]={TZ};
