#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S A1(sam,x)S A2(com,AK(yK,AT(tq,a2(x,y))))VS
A1(mkn,XmMA(eac1(x,mkn))Ay=_R(cn[xt]);Xt(x(y))rshN(xN,x(y)))I _K(Ax/*0*/)_(xtu||xtw||xte?1:xtv?2:xtF?xk:0) //_K:arity
A2(id_,/*00*/x==CAT?_R(ce[ce[yt]?yt:tA]):xtv&&xv<11&&xv?_R(ci[ytdD][CH(xv,(C)4,0,0,1,1,2,2,3,3,2,4)]):mkn(fir(yR)))
AX(prj,XA(app(x,a,n))Ik=max(n,xK);i(n,k-=a[i]!=PLH)
 x=(xtp?val:a1)(xR);Ii=0,j=1;W(i<n&&j<xn,I(xA[j]==PLH,xA[j]=a[i++])j++)W(i<n,xq(a[i++]))P(xn>9,ez1(x))AT(tp,AK(k,x)))
AAL(get,/*0*/XA(_R(xa))XC(ac(xc))XB(ai(xb))XH(ai(xh))XI(ai(xi))XL(al(xl))XD(ad(xd))XS(as(xi))Xm(get(xy,i))
 XM(Ay=xy,z=aA(yn);Q(ytA);j(zn,zA[j]=get(yA[j],i))am(_R(xx),sqz(z)))xR)
S AAL(getr,/*0*/xtt||in(i,xN)?get(x,i):xN?mkn(get(x,0)):xtm?getr(xy,i):_R(cn[xt]))A1(fir,x(getr(x,0)))A1(las,x(getr(x,xN-1)))
#define G(T,U) (32/(SZ(T)>SZ(U)?SZ(T):SZ(U)))
#define iF(f,T,U,R,e...) S L f(OV*RE a,Lm,OV*RE b,V*RE c,Nn)_(O T*p=a;O U*q=b;R*r=c;LN(p)LN(q)LN(r)e;n)
#define iC_(U) iF(  iC##U,C,U,C,i(PD(n,q),r[i]=in(q[i],m)?p[q[i]]:32))
#define iS_(U) iF(  iS##U,I,U,I,i(PD(n,q),Iv=in(q[i],m);r[i]=v*p[v*q[i]]))
#define iD_(U) iF(  iD##U,D,U,D,i(n,r[i]=in(q[i],m)?p[q[i]]:ND))
#define j_(T,U)iF(j##T##U,T,U,L,i(n,r[i]=in(q[i],m)?p[q[i]]:NL))
#define i_(T,U)iF(i##T##U,T,U,T,UI g=G(T,U);U k[g];\
 i(n/g,j(g,k[j]=q[j])U o=0;j(g,o|=!in(k[j],m))P(o,i*g)j(g,r[j]=p[k[j]])q+=g;r+=g)\
 L l=n/g*g;j(n-l,P(!in(q[j],m),l))j(n-l,r[j]=p[q[j]]))
iC_(I)iC_(L)i_(B,I)j_(B,I)i_(B,L)j_(B,L)i_(H,I)j_(H,I)i_(H,L)j_(H,L)i_(I,I)j_(I,I)i_(I,L)j_(I,L)j_(L,I)j_(L,L)
iD_(I)iD_(L)iS_(I)iS_(L)
S A2(idx_,/*01*/Xt(er1(y))P(y==PLH||y==au,xR)YA(ear(AP1,xR,y))Ym(y=mut(y);yy=idx_(x,yy);y)YF(et1(y))Yt(getr(x,gl(y)))
 I(!ytL&&!ytI,y=N(cI(y)))Nn=yn;P(xtA||xtM,Az=oA;I(ytL,i(n,zq(getr(x,yl))))E(i(n,zq(getr(x,yi))))y(z))
 Az=xtL&&ytL&&yr==1?y:atn(xt,n);Lm=CH(xt-tB+7*ytL,&iBI,iHI,iII,jLI,iDI,iCI,iSI,iBL,iHL,iIL,jLL,iDL,iCL,iSL)(xV,xn,yV,zV,n);
 I(m<n,z=z(aL(n));CH(xt-tB+3*ytL,&jBI,jHI,jII,jBL,jHL,jIL)(xV,xn,yV,zV,n))y-z?y(z):z)
S AX(idxA,Ay=*a++;n--;Cb=ytT||y==PLH||y==au;x=idx_(x,y);P(!n||!x,mrn(n,a);x)b?K(".\\:",x,aV(tA,n,a)):x(idxA(x,a,n)))
AX(idxm,Ay=N(idx_(xy,N(fnd(_R(xx),*a))));n-1?y(app(y,a+1,n-1)):y)
S A2(wrt,Xl(wrt(cI(x),y))Yc(wrt(x,enl(y)))P(!xtz||!ytC,et1(y))write(xv,yV,yn);y)
S A1(tme,x(al(now())))
S A1(e1f,e1(x,xtC?xV:"err"))
S A1(avf,Ay=oA;Q*p=argv;W(*p,yq(aCz(*p++)))ap1(y,x))
S A1(enf,Ay=oS,z=oA;Q*e=env;W(*e,Qp=*e++,q=p+si(p,'=');yq(cS(aCm(p,q)));zq(aCz(q+!!*q)))y=am(y,z);x-au?ap1(y,x):y)
S A1(exf,exit(xtz?gl(x):1);0)
S A1(jsf,XC(WASM(Cb[4096];I js_eval(C*,I,C*,I);In=js_eval(xC,xn,b,SZ b);x(0);aCn(b,n))NWASM(en1(x)))XA(eac1(x,jsf))et1(x))
AX(app,
 XA(idxA(x,a,n))
 XT(n-1?ern(a,n):idx_(x,*a))
 Xz(n-1?ern(a,n):wrt(xR,*a))
 Xs(Ss("","k","j","p","cf","t","x","hex","err","epr","argv","env","exit","js","prng","sin","exp","ln")
  Sf(x,*a,ser,kst,js1,prs,cf,tme,frk,hex,e1f,epr,avf,enf,exf,jsf,prng,sinx,expx,logx))
 XM(Ay=*a;YsS(idxm(x,a,n))x=idx_(x,y);P(!x,mrn(n-1,a+1);0)n-1?x(app(x,a+1,n-1)):x)
 Xm(idxm(x,a,n))
 Ik=xK;P(n<k,prj(x,a,n))
 Xv(n-2?vn[xv](aV(tA,n,a)):v2[xv](*a,a[1]))
 Xr(CH(xw,&w0,w1,w2,w3,w4,w5)(xx,a,n))
 Xp(P(xn+k>9,ern(a,n))Im=xn-1,j=0;Ab8;i(m,b[i]=xA[i+1]==PLH&&j<n?a[j++]:_R(xA[i+1]))I l=max(0,n-j);Mc(b+m,a+j,8*l);app(xx,b,m+l))
 Xq(app(xx,&(A){N(app(xy,a,n))},1))
 P(n>k,ern(a,n))
 Xu(v1[xv](*a))
 Xw(Ay=*a;AK(0<xv&&xv<4&&yK==2?1:ytF?yK:1,AW(xv,aV(tr,1,a))))
 Xo(run(x,a,n))
 Xe(P(n-1,ern(a,n))az(((A1*)(x<<8>>8))(gl(N(cL(*a))))))
 etn(a,n))
A1(val,P(xtc||xts,val(enl(x)))
 XS(Ay=glb;i(xn,P(!ytm,et1(x))Az=yx,u=yy;P(!ztS||!utA,ed1(x))Ik=xi;Lj=fAI(z,k);P(j<0,ev1(x))y=uA[j])x(yR))
 XC(x=str0(x);x(evs(xV)))XA(P(!xn,x)P(xn==1,fir(x))P(xn>9,ez1(x))x=mut(x);Ay=app(xx,&xy,xn-1);AN(1,x);x(y))
 XmM(x(_R(xy)))Xr(cat(AT(tA,mut(x)),aw+xw))P(c3(tu,xt,tw),ai(xv))P(c3(to,xt,tq),AT(tA,mut(x)))et1(x))
A2(idx,x(idx_(x,y)))
A2(ap1,x(app(x,&y,1)))
A2(apn,Ym(et2(x,y))Nn=yN;P(!n,y(x))P(n>8,ez2(x,y))y=mRa(Nx(blw(y)));x(y(app(x,yA,n))))
S I knd(Ax)_(Xz(ti)XZ(tI)xt)
S A set(Ax/*1*/,Li,Ay/*1*/)_(Q(xr==1);XA(Az=xa;xa=z(y);ytt&&!ytF?sqz(x):x)
 XM(Az=kv(&x);z=mut(z);Q(ztA);I(ytT&&yN-zn,x(el2(y,z)))Ij=i;i(zn,za=set(mut(za),j,get(y,i));P(!za,za=au;x(y(z(0)))))y(aM(x,z)))
 P(knd(x)-knd(y)-tC+tc,set(blw(x),i,y))
 I(xtZ,N(sup(&x,&y)))C w=Tz[xt];w==0?xb=yv:w==1?xh=yv:w==2?xi=yv:(xl=gl(y));x)
S I stp(Li,Ax/*0*/,A**p)_(Ay=**p;P(!ytm,ed1(x))**p=y=mut(y);Az=yx;P(!ztS,ed1(x))Lj=fpI(&yx,xI[i+1]);
 z=yy;P(!ztA,ed1(x))yy=j==zn?zq(aa0()):mut(z);Q(_r(yy)==1);*p=(A*)_V(yy)+j;1)
S A*pth(Ax/*1*/)_(x=enla(x);Ay=glb;Q(xtS&&yr==1&&ytm&&_t(yx)==tS&&_t(yy)==tA);Lj=fpI(&yx,*xI);
 I(j==_n(yy),_q(yy,xn>1?aa0():au))A*p=(A*)_V(yy)+j;i(xn-1,P(!stp(i,x,&p),(A*)0))x(0);p)
A mnd(OA*a,In,AA*f)_(A*p=pth(*a);P(!p,mrn(n-1,a+1);0)Ab8;*b=*p;Mc(b+1,a+1,(n-1)*8);*p=au;*p=_R(N(f(b,n))))
AA(amn,Ax=*a,y=a[1];Xt(etn(a,n))
 Xm(Az=kv(&x),u=fnd(xR,yR);I(utlL,Q(ur==1);i(uN,I(ul==NL,ul=xN;xq(get(y,i));zq(id_(a[2],z)))))
  Ab8;Mc(b+2,a+2,(n-2)*SZ*a);*b=y(z);b[1]=u;am(x,Nx(amn(b,n))))
 P(y==au,Ab8;Mc(b,a,n*8);b[1]=tilL(xN);amn(b,n))
 Yt(x=mut(x);y=cL(y);P(!y,mrn(n-2,a+2);x(0))Li=gl(y);P(!in(i,xn),x(ein(a+2,n-2)))
  Az=a[2],b[8];*b=get(x,i);Mc(b+1,a+3,(n-3)*8);set(x,i,Nx(z(app(z,b,n-2)))))
 I(n==4,Az=a[2],u=a[3];
  P(xtZ&&ytZ&&ztv&&utzZ&&zv<11,P(utT&&yn-un,el2(x(y),u))I(ADD<=z&&z<=MUL,/*todo*/x=cL(x))x=mut(x);y=cL(y);Ny(sup(&x,&u));
   y2(u2(araT[xt-tB][zv](xV,xn,yL,yn,utP?&u:_V(u),utT)))+1?x:ei1(x))
  P(xtC&&ytZ&&z==av&&utcC,x=mut(x);y=cL(y);I d=utT;u=enla(u);P(d&&yn-un,el2(x(y),u))
   x=y2(u2(i(yn,Lj=yl;B(!in(j,xn),x=0)xC[j]=uC[d*i])x));P(!x,ei0())x))
 rdc(AP1,a,n))
A1(amd,Nn=xn;Ay=xx;
 Ys(x=AN(0,mut(x));x(mnd(xA,n,amn)))
 YF(x=AN(1,mut(x));x(app(xx,xA+1,n-1)))
 x=AN(0,mut(x));x(amn(xA,n)))
AA(dmn,Ax=*a,y=a[1];
 P(y==au||!yN,Ab8;*b=y(x);Mc(b+1,a+3,(n-3)*8);Az=a[2];z(app(z,b,n-2)))
 P(yN==1,Ab8;Mc(b,a,n*8);b[1]=fir(y);amn(b,n))
 P(n==4,K("{[x;y;z;u]@[x;*y;.[;1_y;z;];u]}",x,y,a[2],a[3]))
 P(n==3,K("{         @[x;*y;.[;1_y;z;]  ]}",x,y,a[2]     ))
 enn(a,n))
A1(dmd,Nn=xn;Ay=xx;
 YF(P(n-3,er1(x))x=AN(0,mut(x));x(try(xx,xy,xz)))
 YsS(x=AN(0,mut(x));x(mnd(xA,n,dmn)))
 x=AN(0,mut(x));x(dmn(xV,n)))
A K0(A*p,Qs,OA*a,In)_(I(!*p,cns=apd(cns,*p=N(val(aCz(s)))))n?app(*p,a,n):*p)
OC Tz[]={Tzv},TZ[]={TZv},TT[]={TTv};
