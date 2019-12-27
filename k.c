#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S O L cil[]={_0N,0,0,1,1,_0W,_0W,-_0W,-_0W,_0W,_0N};S O I cii[]={_0Ni,0,0,1,1,_0Wi,_0Wi,-_0Wi,-_0Wi,_0Wi,_0Ni};
S O D cid[]={_0n,0,0,1,1,_0w,_0w,-_0w,-_0w,_0w,_0n};S A1(__1,en(x))S A2(__2,en(x,y))S A1(sam,x)
O C vc[]={':','+','-','*','%','!','&','|','<','>','=','~',',','^','#','_','$','?','@','.',0};//1:  2:  3:  4:  5:  6:  7:  8:  9: 10: 11:
O V*cf[]={sam,flp,neg,fir,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,len,flr,str,unq,typ,val,u0c,u1c,__1,__1,__1,__1,__1,__1,out,las,__1,cmd,
          dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql,mtc,cat,xpt,rsh,cut,cst,fnd,ap1,ap2,v0c,v1c,__2,__2,__2,__2,__2,__2,__2,__2,__2,com,
          eac,rdc,scn,eap,ear,eal}; // ' / \ ': /: \:
A2(id_/*x0y0*/,!ari(x)?a0():ytdD?ad(cid[Av(x)]):ytiI?ai(cii[Av(x)]):al(cil[Av(x)]))A1(mkn,P(xtaAX,ea1(mkn,x))A y=mR(cn[xt]);xtt?dex(x,y):rsh(len(x),y))
A2(com,AK(Ak(y),AT(tq,a2(x,y))))AX(prj,P(xtX,app(x,a,n))UC k=max(n,Ak(x));F(n,k-=a[i]!=cv_plc)A u=AK(k,atn(tp,n+1));ux=xR;mc(ua+1,a,n*ZV);u)
SN A getA(A x/*0*/,L i)_(asrt(xtA);A y=xy,u=a0();Fj(yn,u=apd(u,get(yaj,i)))aa(mR(xx),u))
A get(A x/*0*/,L i)_(xtX?mR(xai):xtI?ai(xii):xtL?al(xli):xtS?as(xli):xtC?ac(xci):xtD?ad(xdi):xta?get(xy,i):xtA?getA(x,i):xR)
A getr(A x/*0*/,L i)_(asrt(!xtt);0<=i&&i<xn?get(x,i):xn?mkn(get(x,0)):mR(cn[xt]))
S A2(idx_/*x0y1*/,asrt(xtT||xtaA);P(y==cv_plc,flp(xR))P(ytX,eac(x,&y,1))P(yta,y=mut(y);yy=idx_(x,yy);y)P(fun(y),et(x,y))P(ytt,getr(x,gl(y)))
 y=N(gL(y));L w=tz(xt);A u=atn(xt,yn);P(xtX,u=AN(0,u);F(yn,u=apd(u,getr(x,yli)))yr;u)
 L h=gl_(cn[xt]);yr;P(w==0,F(un,L j=yli;uci=0<=j&&j<xn?xcj:h)u)
                    P(w==2,F(un,L j=yli;uii=0<=j&&j<xn?xij:h)u)
                    P(w==3,F(un,L j=yli;uli=0<=j&&j<xn?xlj:h)u)en(y,u))
AX(app,P(xtT,P(xtX,L c=1;F(n,A y=a[i];L c0=c;c=ytt;x=N(!c0?eal(cV('@'),A_(x,y),2):i?idx(x,y):idx_(x,y)))x)n==1?idx_(x,*a):ein(n,a))
 P(xts,C*s=C(symstr(gs(x))),c=*s;A y=*a;s[1]?enn(n,a):n>1?ern(n,a):c=='j'?json(y):c=='k'?kst(y,aC(0)):c=='p'?prs(y):c=='t'?dex(y,al(time())):
  c=='x'?sys(y):c=='e'?yr,epr(),cu0:enn(n,a))
 P(xta,A y=N(idx_(xy,N(fnd(mR(xx),*a))));P(n==1,y)dex(y,app(y,a+1,n-1)))P(xtA,P(n>1,ern(n,a))A y=*a;P(ytil,idx_(x,y))app(AT(ta,x),a,n))
 P(xtil,P(n>1,ern(n,a))A y=*a;$(ytc,y=enl(y))E(P(!ytC,et(y)))write(gl_(x),yc,yn);y)
 P(n<Ak(x),prj(x,a,n))P(xtv,n==2?((A2*)cf[32+Av(x)])(*a,a[1]):x==cV('@')?amd(a,n):x==cV('.')?dmd(a,n):enn(n,a))P(xtr,((AX*)cf[64+Av(x)])(xx,a,n))
 P(n>Ak(x),ern(n,a))P(xtu,((A1*)cf[Av(x)])(*a))P(xtw,C v=Av(x);AK(0<v&&v<4?1:fun(*a)?Ak(*a):1,AV(v,atnv(tr,1,a))))P(xto,run(x,a,n))
 P(xtp,L m=xn-1,j=0;A b[m+n];F(xn-1,b[i]=xa[i+1]==cv_plc&&j<n?a[j++]:mR(xa[i+1]))W(j<n,b[m++]=a[j++])app(xx,b,m))
 P(xtq,app(xx,&(A){N(app(xy,a,n))},1))etn(n,a))
A1(val,P(xtS,A y=glb;xr;F(xn,P(!yta,et())A z=yx,u=yy;P(!ztS||!utX,ed())L k=xli,j=fndl(z,k);P(j<0,err(C(symstr(k))))y=uaj)yR)
 P(xtX,P(!xn,x)P(xn==1,fir(x))P(xn>9,err("mxa",x))x=mut(x);A u=app(xx,&xy,xn-1);mr(AN(1,x));u)
 P(xtC,x=N(cpl(N(prs(x))));dex(x,run(x,0,0)))xtc||xts?val(enl(x)):xta||xtr?las(AT(tX,x)):C3(tu,xt,tw)?al(Av(x)):xto||xtp||xtq?AT(tX,x):et(x))
A2(idx,dex(x,idx_(x,y)))A2(ap1,dex(x,app(x,&y,1)))A2(ap2,y=enla(y);L n=yn;P(!n,yr;x)P(n>8,err("mxa",x,y))y=mRa(Nx(blw(y)));A u=app(x,ya,n);xr;yr;u)
S A set(A x,L i,A y)_(asrt(Ar(x)==1);$(!xtX&&(!sim(y)||xt-t_lst(yt)),x=blw(x))
 P(xtX,mr(xai);xai=y;x)P(xtC,xci=gc(y);x)P(xtI,xii=gi(y);x)P(xtL,xli=gl(y);x)P(xtD,xdi=gd(y);x)P(xtS,xli=gs(y);x)en(x,y))
#define cki(i,n,a...) P((i)<0||(n)<=(i),ei(a))
AA(amd,asrt(n>2);A x=*a,y=a[1],z=a[2];P(xtt,etn(n,a))P(n==3&&!fun(z),amd(A_(x,y,cv0,z),4))
 P(xta,x=mut(x);xx=unq(cat(xx,yR));xy=cat(xy,rsh(al(An(xx)-An(xy)),id_(z,xy)));
  A b[8];*b=xy;b[1]=fnd(mR(xx),y);mc(b+2,a+2,(n-2)*ZV);xy=amd(b,n);P(!xy,xy=cu0;xr;0)x)
 P(ytt,x=mut(x);L i=gl(gL(y));P(i<0||i>=xn,xr;ein(n-2,a+2))A b[8];*b=get(x,i);mc(b+1,a+3,(n-3)*ZV);A u=app(z,b,n-2);zr;Nx(u);set(x,i,u))
 P(n==4&&(xtIL||xtD)&&ytIL&&ari(z)&&xt==t_lst(At(a[3])),x=mut(x);A u=a[3];L f=Av(z),d=utT;u=enla(u);y=gL(y);yr;ur;$(d&&yn-un,el(x))
  $( xtD,arD(f,yn,L j=yli;cki(j,xn,x)D a=xdj;D b=ud[d*i];xdj=))
  E$(xtI,arI(f,yn,L j=yii;cki(j,xn,x)I a=xij;I b=ui[d*i];xij=))
  E$(xtL,arL(f,yn,L j=yli;cki(j,xn,x)L a=xlj;L b=ul[d*i];xlj=))x)
 P(n==4&&xtC&&ytL&&z==cv0&&t_lst(At(a[3]))==tC,x=mut(x);A u=a[3];L d=utT;u=enla(u);yr;ur;$(d&&yn-un,el(x))F(yn,L j=yli;cki(j,xn,x)xcj=uc[d*i])x)
 rdc(cV('@'),a,n))
S A*pth(A x/*1*/)_(x=enla(x);A y=glb;asrt(xtS&&Ar(y)==1&&yta&&At(yx)==tS&&At(yy)==tX);L j=fpl(&yx,*xl);$(j==An(yy),yy=apd(yy,xn>1?aa0():cu0))A*p=A(yy)+j;
 F(xn-1,A y=*p;P(!yta,(A*)ed(x))*p=y=mut(y);A z=yx;P(!ztS,(A*)ed(x))L j=fpl(&yx,xl[i+1]);A u=yy;P(!utX,(A*)ed(x))yy=j==un?apd(u,aa0()):mut(u);
  asrt(Ar(yy)==1);p=A(yy)+j)
 xr;p)
AA(dm1,A x=*a,y=a[1],z=a[2];P(y==cu0||ytT&&!yn,yr;A b[8];*b=x;mc(b+1,a+3,(n-3)*ZV);dex(z,app(z,b,n-2)))y=enla(y);P(yn>8,eln(n,a))
 A t[8];*t=x;F(yn-1,t[i+1]=app(t[i],A_(get(y,i)),1))
 A b[8];*b=t[yn-1];b[1]=get(y,yn-1);b[2]=z;mc(b+3,a+3,(n-3)*ZV);A u=N(amd(b,n));F(yn-1,u=N(amd(A_(t[yn-2-i],get(y,yn-2-i),cv0,u),4)))yr;u)
AA(dmd,A x=*a,y=a[1],z=a[2];P(n==3&&fun(x),try(x,y,z))P(n==3&&!fun(z),dmd(A_(x,y,cv0,z),4))
 P(xtsS,A*p=pth(x);P(!p,mrn(n-1,a+1);0)A b[8];*b=*p;*p=cu0;mc(b+1,a+1,(n-1)*ZV);*p=mR(N(dm1(b,n))))dm1(a,n))
