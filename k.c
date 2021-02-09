#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
S A1(sam,x) //                                                                                                                  plc prg
OC vc[]={':','+','-','*','%','!','&','|','<','>','=','~',',','^','#','_','$','?','@','.','0','1','2','3','4','5','\'','/','\\','[',  0,  0};
OV*vf[]={sam,flp,neg,fir,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,len,flr,str,unq,typ,val,u0c,u1c,sam,sam,las,out,   0,  0, cmd,  0,  0,  0,
         dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql,mtc,cat,xpt,rsh,cut,cst,fnd,ap1,apn,v0c,v1c,dex,dex,com,dex, eac,rdc, scn,eap,ear,eal};
A1(mkn,XmMA(ea1(mkn,x))Ay=mR(cn[xt]);xtt?x(y):rsh(len(x),y)) //                                       mkl   '   /    \  ':   /:  \:
S A emp(Ct)_(Ax=ce[t];x?xR:aA0)
A2(id_,/*00*/x==cv(',')?emp(yt):xtv&&xv<11?mR(ci[2+ytdD][CH(xv,(C)4,0,0,1,1,2,2,3,3,2,4)]):mkn(fir(yR)))
A2(com,AK(yk,AT(tq,a2(x,y))))
AX(prj,XA(app(x,a,n))Ck=max(n,xk);i(n,k-=a[i]!=PLH)Au=AK(k,atn(tp,n+1));ux=xR;mc(uA+1,a,8*n);u)
SN A getM(Ax/*0*/,Li)_(Q(xtM);K("{x!y@\\:z}",mR(xx),mR(xy),al(i)))
A get(Ax/*0*/,Li)_(XA(mR(xa))XC(ac(xc))XH(ah(xh))XI(ai(xi))XL(al(xl))XD(ad(xd))XS(as(xi))XM(getM(x,i))Xm(get(xy,i))xR)
A getr(Ax/*0*/,Li)_(Q(!xtt);in(i,xN)?get(x,i):xn?mkn(get(x,0)):mR(cn[xt]))
#define G(T,U) (32/Z(T))
#define iF(f,T,U,R,e...) SN L f(OV*RE a,Lm,OV*RE b,V*RE c,UL n)_(O T*p=a;O U*q=b;R*r=c;AL(p)AL(q)AL(r)e;n)
#define iC_(U) iF(iC##U,C,U,C,i(n,r[i]=in(q[i],m)?p[q[i]]:32))
#define iS_(U) iF(iS##U,I,U,I,i(n,r[i]=in(q[i],m)?p[q[i]]: 0))
#define j_(T,U)iF(j##T##U,T,U,L,i(n,r[i]=in(q[i],m)?p[q[i]]:NL))
#define i_(T,U)iF(i##T##U,T,U,T,UL i=0,l=n/G(T,U)*G(T,U);\
                W(i<l,j(G(T,U),P(!in(q[j],m),i))j(G(T,U),r[j]=p[q[j]])i+=G(T,U);q+=G(T,U);r+=G(T,U))\
                j(n-l,P(!in(q[j],m),l))j(n-l,r[j]=p[q[j]]))
iC_(I)iC_(L)i_(H,I)j_(H,I)i_(H,L)j_(H,L)i_(I,I)j_(I,I)i_(I,L)j_(I,L)j_(L,I)j_(L,L)iS_(I)iS_(L) //iII
S A2(idx_,/*01*/Er(xtt,y)P(y==PLH,xR)YA(ear(cv('@'),A(xR,y),2))Ym(y=mut(y);yy=idx_(x,yy);y)Et(ytF,y)Yt(getr(x,gl(y)))
 Y(!ytL&&!ytI,y=N(gI(y)))Ln=yn;Au=xtM?aA0:atn(xt,n);
 P(xtA||xtM,u=AN(0,u);Y(ytL,i(n,uq(getr(x,yl))))E(i(n,uq(getr(x,yi))))y(u))
 Lm=CH(xt-tC+6*ytL,&iCI,iHI,iII,jLI,jLI,iSI,iCL,iHL,iIL,jLL,jLL,iSL)(xC,xn,yC,uC,n);
 Y(m<n,u=u(aL(n));CH(xt-tH+2*ytL,&jHI,jII,jHL,jIL)(xC,xn,yC,uC,n))y(u))
S AX(idxA,Ay=*a++;n--;P(ytT||y==PLH,x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)K(".\\:",x,atnv(tA,n,a)))
 x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)x(idxA(x,a,n)))
S A2(wrt,Xl(wrt(gI(x),y))Yc(wrt(x,enl(y)))Et(!xti||!ytC,y)write(gi(x),yC,yn);y)S A1(tme,x(al(now())))
AX(app,XA(idxA(x,a,n))XT(n-1?ern(n,a):idx_(x,*a))Xz(n-1?ern(n,a):wrt(xR,*a))
 Xs(P(n>1,ern(n,a))SF(x,*a,"``j`k`p`cf`t`x`e`hex`md5`sha1`sha256`sha3`aes`sin",
                      ser,jsw,kst,prs,cf,tme,frk,epr,hex,md5,sha1,sha256,sha3_256,aes0,sin))
 Xm(Ay=N(idx_(xy,N(fnd(mR(xx),*a))));n-1?y(app(y,a+1,n-1)):y)XM(Ay=*a;n>1?ern(n,a):ytzZ?idx_(x,y):app(AT(tm,x),a,n))
 P(n<xk,prj(x,a,n))Xv(n==2?((A2*)vf[32+xv])(*a,a[1]):x==cv('@')?amd(a,n):x==cv('.')?dmd(a,n):enn(n,a))Xr(((AX*)vf[58+xv])(xx,a,n))
 P(n>xk,ern(n,a))Xu(((A1*)vf[xv])(*a))Xw(Ay=*a;AK(0<xv&&xv<4&&yk==2?1:ytF?yk:1,AV(xv,atnv(tr,1,a))))Xo(run(x,a,n))
 Xp(P(n+xn>9,ern(n,a))I m=xn-1,j=0;A b[8];i(m,b[i]=xA[i+1]==PLH&&j<n?a[j++]:mR(xA[i+1]))I l=max(0,n-j);mc(b+m,a+j,8*l);app(xx,b,m+l))
 Xq(app(xx,&(A){N(app(xy,a,n))},1))etn(n,a))
A1(val,XS(Ay=glb;i(xn,Et(!ytm,x)Az=yx,u=yy;Ed(!ztS||!utA,x)Ik=xi;Ij=fAI(z,k);Ev(j<0,x)y=uA[j])x(yR))
 XA(P(!xn,x)P(xn==1,fir(x))Ez(xn>9,x)x=mut(x);Au=app(xx,&xy,xn-1);AN(1,x);x(u))
 XC(x=N(cpl(N(prs(x))));x(run(x,0,0)))P(xtc||xts,val(enl(x)))Xm(las(AT(tA,x)))Xr(cat(AT(tA,x),aw(xv)))
 P(c3(tu,xt,tw),al(xv))P(xto||xtp||xtq,AT(tA,x))et1(x))
A2(idx,x(idx_(x,y)))
A2(ap1,x(app(x,&y,1)))
A2(apn,y=enla(y);Ln=yn;P(!n,y(x))Ez(n>8,x,y)y=mRa(Nx(blw(y)));x(y(app(x,yA,n))))
S A set(Ax,Li,Ay)_(Q(xr==1);Y(!xtA&&(!ytQ||xt-tT(yt)),x=blw(x))
 XA(mr(xa);xa=y;YQ(sqz(x))x)xtC?xc=gc(y):xtH?xh=gh(y):xtI?xi=gi(y):xtL?xl=gl(y):xtD?xd=gd(y):xtS?xi=gs(y):0;x)
S I stp(Li,Ax/*0*/,A**p)_(Ay=**p;Ed(!ytm,x)**p=y=mut(y);Az=yx;Ed(!ztS,x)Lj=fpI(&yx,xI[i+1]);Au=yy;Ed(!utA,x)
 yy=j==un?uq(aa0()):mut(u);Q(Ar(yy)==1);*p=(A*)dat(yy)+j;1)
S A*pth(Ax/*1*/)_(x=enla(x);Ay=glb;Q(xtS&&yr==1&&ytm&&At(yx)==tS&&At(yy)==tA);Lj=fpI(&yx,*xI);
 Y(j==An(yy),_q(yy,xn>1?aa0():au0))A*p=(A*)dat(yy)+j;i(xn-1,P(!stp(i,x,&p),(A*)0))x(0);p)
S A mend(OA*a,In,AA*f)_(A*p=pth(*a);P(!p,mrn(n-1,a+1);0)A b[8];*b=*p;*p=au0;mc(b+1,a+1,(n-1)*8);*p=mR(N(f(b,n))))
AA(am1,Ax=*a,y=a[1],z=a[2];Xt(etn(n,a))
 Xm(x=mut(x);xx=unq(cat(xx,yR));xy=cat(xy,rsh(al(An(xx)-An(xy)),id_(z,xy)));
  A b[8];*b=xy;b[1]=fnd(mR(xx),y);mc(b+2,a+2,(n-2)*8);xy=am1(b,n);P(!xy,xy=au0;x(0))x)
 Yt(x=mut(x);y=gL(y);P(!y,mrn(n-2,a+2);x(0))Li=gl(y);P(!in(i,xn),x(ein(n-2,a+2)))
  A b[8];*b=get(x,i);mc(b+1,a+3,(n-3)*8);set(x,i,Nx(z(app(z,b,n-2)))))
 Y(n==4,Au=a[3];
  P(xtZ&&ytZ&&ztv&&zv<8&&utzZ,Ei(utT&&yn-un,x(y),u)x=mut(x);y=gL(y);Ny(sup(&x,&u));
   Ei(m2(y,m2(u,x?((int(*)(V*,L,L*,L,V*,I))ara[xt-tH][zv])(xC,xn,yL,yn,utP?&u:(V*)uC,utT):0)))x)
  P(xtC&&ytZ&&z==av0&&utcC,x=mut(x);y=gL(y);I d=utT;u=enla(u);El(d&&yn-un,x(y),u)
   x=m2(y,m2(u,i(yn,Lj=yl;Y(!in(j,xn),x=0;B)xC[j]=uC[d*i])x));Ei(!x)x))
 rdc(cv('@'),a,n))
AA(amd,Ax=*a;Xs(mend(a,n,am1))am1(a,n))
AA(dm1,Ax=*a,y=a[1],z=a[2];Lm=yN;P(!m||y==au0,y(0);A b[8];*b=x;mc(b+1,a+3,(n-3)*8);z(app(z,b,n-2)))
 P(m==1,A b[8];mc(b,a,n*8);b[1]=fir(y);am1(b,n))P(n-4,enn(n,a))K("{[x;y;z;u]@[x;*y;.[;1_y;z;];u]}",x,y,z,a[3]))
AA(dmd,Ax=*a,y=a[1],z=a[2];n==3&&xtF?try(x,y,z):xtsS?mend(a,n,dm1):dm1(a,n))
A K0(OC*s,In)_(Lm=mu;Ax=val(aCn(s,n+1));mu=m;x)
OC Zt[]={Tz},ZT[]={TZ};
