#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S A1(sam,x)S A2(com,AK(yK,AT(tq,a2(x,y))))S AA(___,ern(n,a))
U(vc,{':','+','-','*','%','!','&','|','<','>','=','~',',','^','#','_','$','?','@','.','0','1','2','3','4','5'})
U(v1,{sam,flp,neg,fir,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,len,flr,str,unq,typ,val,u0c,u1c,sam,sam,las,out})
U(v2,{dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql,mtc,cat,exc,rsh,cut,cst,que,ap1,apn,v0c,v1c,dex,dex,com,dex})
U(vn,{___,___,___,___,___,___,___,___,___,___,___,___,___,___,___,___,___,___,amd,dmd,___,___,___,___,___,___})
A1(mkn,XmMA(eac1(x,mkn))Ay=_R(cn[xt]);Xt(x(y))rshN(xN,x(y)))I _K(Ax/*0*/)_(xtu||xtw?1:xtv?2:xtF?xk:0) //_K:arity
A2(id_,/*00*/x==CAT?_R(ce[ce[yt]?yt:tA]):xtv&&xv<11&&xv?_R(ci[ytdD][CH(xv,(C)4,0,0,1,1,2,2,3,3,2,4)]):mkn(fir(yR)))
AX(prj,XA(app(x,a,n))Ik=max(n,xK);i(n,k-=a[i]!=PLH)
 Ay=(xtp?val:a1)(xR);Ii=0,j=1;W(i<n&&j<yn,I(yA[j]==PLH,yA[j]=a[i++])j++)W(i<n,yq(a[i++]))AT(tp,AK(k,y)))
SN AAL(getM,/*0*/Q(xtM);Ay=xy,z=aA(yn);Q(ytA);j(zn,zA[j]=get(yA[j],i))am(_R(xx),sqz(z)))
AAL(get,/*0*/XA(_R(xa))XC(ac(xc))XB(ai(xb))XH(ai(xh))XI(ai(xi))XL(al(xl))XD(ad(xd))XS(as(xi))Xm(get(xy,i))XM(getM(x,i))xR)
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
S A2(idx_,/*01*/Er(xtt,y)P(y==PLH||y==au0,xR)YA(ear(AP1,xR,y))Ym(y=mut(y);yy=idx_(x,yy);y)YF(et1(y))Yt(getr(x,gl(y)))
 I(!ytL&&!ytI,y=N(cI(y)))Nn=yn;P(xtA||xtM,Az=oA;I(ytL,i(n,zq(getr(x,yl))))E(i(n,zq(getr(x,yi))))y(z))
 Az=xtL&&ytL&&yr==1?y:atn(xt,n);Lm=CH(xt-tB+7*ytL,&iBI,iHI,iII,jLI,iDI,iCI,iSI,iBL,iHL,iIL,jLL,iDL,iCL,iSL)(xC,xn,yC,zC,n);
 I(m<n,z=z(aL(n));CH(xt-tB+3*ytL,&jBI,jHI,jII,jBL,jHL,jIL)(xC,xn,yC,zC,n))y-z?y(z):z)
S AX(idxA,Ay=*a++;n--;P(ytT||y==PLH||y==au0,x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)K(".\\:",x,aV(tA,n,a)))
 x=idx_(x,y);P(!n,x)P(!x,mrn(n,a);0)x(idxA(x,a,n)))
S AX(idxm,Ay=N(idx_(xy,N(fnd(_R(xx),*a))));n-1?y(app(y,a+1,n-1)):y)
S A2(wrt,Xl(wrt(cI(x),y))Yc(wrt(x,enl(y)))Et(!xtz||!ytC,y)write(xv,yC,yn);y)
S A1(tme,x(al(now())))
S A1(err,e1(xtC?xC:(C*)"err",x))
S A1(argvf,Ay=oA;Q*p=argv;W(*p,yq(aCz(*p++)))ap1(y,x))
S A1(envf,Ay=oS,z=oA;Q*e=env;W(*e,Qp=*e++,q=p+si(p,'=');yq(cS(aCm(p,q)));zq(aCz(q+!!*q)))y=am(y,z);x-au0?ap1(y,x):y)
S A1(exitf,Xz(exit(gl(x));0)exit(1);0)
AX(app,XA(idxA(x,a,n))XT(n-1?ern(n,a):idx_(x,*a))Xz(n-1?ern(n,a):wrt(xR,*a))
 Xs(Ss("","k","j","p","cf","t","x","hex","md5","sha1","sha2","sha3","aes","sin","err","epr","argv","env","exit","e")
    Sf(x,*a,ser,kst,js1,prs,cf,tme,frk,hex,md5,sha1,sha256,sha3_256,aes0,sin,err,epr,argvf,envf,exitf,exp))
 XM(Ay=*a;YsS(idxm(x,a,n))x=idx_(x,y);P(n==1,x)x(app(x,a+1,n-1)))Xm(idxm(x,a,n))
 Ik=xK;P(n<k,prj(x,a,n))Xv(P(n==2,v2[xv](*a,a[1]))vn[xv](a,n))Xr(CH(xw,&w0,w1,w2,w3,w4,w5)(xx,a,n))
 P(n>k,ern(n,a))Xu(v1[xv](*a))Xw(Ay=*a;AK(0<xv&&xv<4&&yK==2?1:ytF?yK:1,AW(xv,aV(tr,1,a))))Xo(run(x,a,n))
 Xp(P(n+xn>8,ern(n,a))Im=xn-1,j=0;Ab8;i(m,b[i]=xA[i+1]==PLH&&j<n?a[j++]:_R(xA[i+1]))I l=max(0,n-j);Mc(b+m,a+j,8*l);app(xx,b,m+l))
 Xq(app(xx,&(A){N(app(xy,a,n))},1))Xe(P(n-1,ern(n,a))az(((A1*)(V*)xC)(gl(N(cL(*a))))))etn(n,a))
A1(val,XC(P(xn&&*xC=='\\',x=str0(x);x(evs(xC,xC+xn)))x=N(cpl(N(prs(x))));x(run(x,0,0)))P(xtc||xts,val(enl(x)))
 XS(Ay=glb;i(xn,Et(!ytm,x)Az=yx,u=yy;Ed(!ztS||!utA,x)Ik=xi;Lj=fAI(z,k);Ev(j<0,x)y=uA[j])x(yR))P(c3(tu,xt,tw),ai(xv))
 XA(P(!xn,x)P(xn==1,fir(x))Ez(xn>9,x)x=mut(x);Ay=app(xx,&xy,xn-1);AN(1,x);x(y))Xr(cat(AT(tA,mut(x)),aw0+xw))
 XmM(x(_R(xy)))P(xto||xtp||xtq,AT(tA,mut(x)))et1(x))
A2(idx,x(idx_(x,y)))
A2(ap1,x(app(x,&y,1)))
A2(apn,Ym(et2(x,y))Nn=yN;P(!n,y(x))Ez(n>8,x,y)y=mRa(Nx(blw(y)));x(y(app(x,yA,n))))
S I knd(Ax)_(Xz(ti)XZ(tI)xt)
S A set(Ax,Li,Ay)_(Q(xr==1);XA(Az=xa;xa=z(y);ytt&&!ytF?sqz(x):x)P(knd(x)-knd(y)-tC+tc,set(blw(x),i,y))
 I(xtZ,N(sup(&x,&y)))C w=Zt[xt];w==0?xb=yv:w==1?xh=yv:w==2?xi=yv:(xl=gl(y));x)
S I stp(Li,Ax/*0*/,A**p)_(Ay=**p;Ed(!ytm,x)**p=y=mut(y);Az=yx;Ed(!ztS,x)Lj=fpI(&yx,xI[i+1]);
 z=yy;Ed(!ztA,x)yy=j==zn?zq(aa0()):mut(z);Q(_r(yy)==1);*p=(A*)_V(yy)+j;1)
S A*pth(Ax/*1*/)_(x=enla(x);Ay=glb;Q(xtS&&yr==1&&ytm&&_t(yx)==tS&&_t(yy)==tA);Lj=fpI(&yx,*xI);
 I(j==_n(yy),_q(yy,xn>1?aa0():au0))A*p=(A*)_V(yy)+j;i(xn-1,P(!stp(i,x,&p),(A*)0))x(0);p)
S A mnd(OA*a,In,AA*f)_(A*p=pth(*a);P(!p,mrn(n-1,a+1);0)Ab8;*b=*p;*p=au0;Mc(b+1,a+1,(n-1)*8);*p=_R(N(f(b,n))))
AA(am1,Ax=*a,y=a[1];Xt(etn(n,a))
 Xm(Az=kv(&x),u=fnd(xR,yR);I(utlL,Q(ur==1);i(uN,I(ul==NL,ul=xN;xq(get(y,i));zq(id_(a[2],z)))))
  Ab8;Mc(b+2,a+2,(n-2)*SZ*a);*b=y(z);b[1]=u;am(x,Nx(am1(b,n))))
 P(y==au0,Ab8;Mc(b,a,n*8);b[1]=tilL(xN);am1(b,n))
 Yt(x=mut(x);y=cL(y);P(!y,mrn(n-2,a+2);x(0))Li=gl(y);P(!in(i,xn),x(ein(n-2,a+2)))
  Az=a[2],b[8];*b=get(x,i);Mc(b+1,a+3,(n-3)*8);set(x,i,Nx(z(app(z,b,n-2)))))
 I(n==4,Az=a[2],u=a[3];
  P(xtZ&&ytZ&&ztv&&zv<8&&utzZ,El(utT&&yn-un,x(y),u)x=mut(x);y=cL(y);Ny(sup(&x,&u));
   y2(u2(araT[xt-tB][zv](xC,xn,yL,yn,utP?&u:(V*)uC,utT)))+1?x:ei1(x))
  P(xtC&&ytZ&&z==av0&&utcC,x=mut(x);y=cL(y);I d=utT;u=enla(u);El(d&&yn-un,x(y),u)
   x=y2(u2(i(yn,Lj=yl;B(!in(j,xn),x=0)xC[j]=uC[d*i])x));Ei(!x)x))
 rdc(AP1,a,n))
AA(amd,Ax=*a;Xs(mnd(a,n,am1))am1(a,n))
AA(dm1,Ax=*a,y=a[1],z=a[2];Lm=yN;P(!m||y==au0,y(0);Ab8;*b=x;Mc(b+1,a+3,(n-3)*8);z(app(z,b,n-2)))
 P(m==1,Ab8;Mc(b,a,n*8);b[1]=fir(y);am1(b,n))
 P(n==4,K("{[x;y;z;u]@[x;*y;.[;1_y;z;];u]}",x,y,z,a[3]))P(n==3,K("{@[x;*y;.[;1_y;z]]}",x,y,z))enn(n,a))
AA(dmd,Ax=*a,y=a[1],z=a[2];n==3&&xtF?try(x,y,z):xtsS?mnd(a,n,dm1):dm1(a,n))
A K0(A*p,Qs,OA*a,In)_(Ax=*p;I(!x,x=*p=N(val(aCz(s)));cns=apd(cns,x))n?app(x,a,n):x)
OC Zt[]={Tz},ZT[]={TZ};
