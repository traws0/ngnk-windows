#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
A1(rs0,rsz(0,x))
ZN A flt(A x,A y,B b/*01b*/)_(P(xK-1,er(y))Ym(K("{(!y)[i]!(.y)i:&z~/:x@.y}",xR,y,ai(b)))Yt(flt(x,enl(y),b))
 x=Ny(x1(yR));x=xN?x:x(emp(tG));P(!xtzZ,et(y(x)))I(xtt,x=rsz(yN,x))E(P(xN-yN,el(x(y))))I(!b,x=not(x))x=Ny(whr(x));y(y1(x)))
V cyc(V*a,W m,W n){Q(m);W(2*m<=n,MC(a+m,a,m);m*=2)I(n>m,MC(a+m,a,n-m))}
Z V cpyB(W*x,U j,CO W*y,U k,U n) {P(!n)x+=j>>6;y+=k>>6;j&=63;k&=63; // x[j..j+n] = y[k..k+n]
 I(j,W a=*y>>k;I(k&&n>64-k,a|=y[1]<<64-k);*x=(*x&(1ULL<<j)-1)|a<<j;P(n<=64-j)++x;k+=64-j;y+=k>>6;k&=63;n-=64-j) // align x
 I(!k,MC(x,y,n+7>>3))E(W a=*y++>>k,b;F(n>>6,b=*y++;*x++=a|b<<64-k;a=b>>k);I(n&63,b=(n&63)>64-k?*y:0;*x++=a|b<<64-k))}
Z V cycB(W*x,CO W*y,U k,U m,U n){ // cycle n bits from y[0..m] starting at k
 cpyB(x,0  ,y,k,MIN(m-k,n));P(n<=m-k);n-=m-k;
 cpyB(x,m-k,y,0,MIN(k  ,n));P(n<=k  );n-=k;
 W(n>m,cpyB(x,m,x,0,m);n-=m;m*=2)cpyB(x,m,x,0,n);}
A rsz(L n,A x/*1*/)_(
 X(Rt(rsz(n,enl(x)))
   RM(A y=kv(&x),z=az(n);aM(x,Nx(z(r2(RSH,z,y)))))
   Rm(A y=kv(&x);x=Ny(rsz(n,x));y=Nx(rsz(n,y));am(x,y))
   RE(Lij P(n>j-i||n<i-j,rsz(n,gZ(x)))x(0);n>=0?aE(i,i+n):aE(j+n,j))
   R_(P(n==NL,x)P(!xn,rsz(n,enl(fir(x))))
      I r=n<0;n*=1-2*r;P((W)n-(U)n,ez(x))A y=an(n,xt);N w=MAX(0,xw-3),m=xn<<w,h=m,k=n%xn<<w,l=n<<w;
      XB(cycB(yV,xV,r?m-k:0,m,l);x(y))
      I(!r,MC(yV,xV,MIN(m,l)))J(l<=m,MC(yV,xV+m-l,l))E(MC(yV,xV+m-k,k);MC(yV+k,xV,m-k))
      I(m,cyc(yV,m,l));I(!n&&ytA,A u=yx=mkn(_R(xx));I(!utP,ur--))x(ytA?sqz(mRa(y)):y)))0)
A slc(A x/*0*/,U i,U j)_(Q(xtT&&i<=j&&j<=xN)N n=j-i;
 XB(A y=an(j-i,tB);cpyB(yV,0,xV,i,j-i);y)
 XE(I v=*xL;aE(v+i,v+j))A y=an(n,xt);U w=xw-3;MC(yV,xV+((W)i<<w),(W)n<<w);XA(P(!n,yx=mkn(_R(xx));y)sqz(mRa(y)))y)
Z A chp(L n,A x/*1*/)_(P(n<0,ed(x))XmM(en(x))L m=(xn+n-1)/n;A y=aA(m);F(m|!m,ya=slc(x,n*i,MIN(xn,n*i+n)))x(0);I(!m,yx=mkn(yx))y)
Z A2(rsh,/*01*/XE(x=gZ(xR);x(rsh(x,y)))YE(rsh(x,gZ(y)))YmM(en(y))Yt(rsh(x,enl(y)))Q(xtZ);N r=xn;P(!r,fir(y))P(r>256,ez(y))x=Ny(cL(xR));L s[r];MC(s,xV,r<<3);x(0);
 I(r==2,P(*s==NL,chp(s[1],y))P(s[1]==NL,A u=az(*s);u(K2("{$[(0<x)&~x!#y;(x;(-x)!#y)#y;((-x)!(#y)*!x)_y]}",u,y))))P(r==1&&*s==NL,y)I(!yn,y=enl(fir(y)))
 L p[r],m=1;F(r,L d=s[r-1-i];P(d<0||m*d<0,ed(y))p[i]=m*=MAX(1,d))y=N(rsz(m,y));F(r-1,L d=s[r-1-i];I(d,y=N(chp(MAX(1,d),y)))E(y=N(e1f(rs0,N(chp(1,y))))))rsz(*s,y))
X2(hsh,/*01*/Ril(rsz(gl_(x),y))RU(flt(x,y,1))RT(P(ytm||ytM&&xtS,P(urnk(yx)-urnk(x)==1,en(y))A u=N(y1(xR),x(y(0)));y(aV(yt,2,A(xR,u))))XZ(rsh(x,y))et(y))R_(et(y)))
A drp(L n,A x/*1*/)_(X(Rm(A y=kv(&x);am(Ny(drp(n,x)),Nx(drp(n,y))))RM(A y=kv(&x);aM(x,Nx(e2f(und,az(n),y))))Rt(er(x))RE(Lij x(0);aE(MAX(i,MIN(j,i+n)),MAX(i,MIN(j,j+n))))
 R_(P(n==NL,rs0(x))L m=xn;n=MAX(-m,MIN(m,n));P(-n<(W)m&&MINE(x),I(xtA,mrn(-n,xA+m+n))AN(m+n,x))x(slc(x,MAX(0,n),m+MIN(0,n)))))0)
Z A rmv(A x/*1*/,L i)_(XB(rmv(cG(x),i))X(RT_E(P(i>=(W)xn,x)A y=an(xn-1,xt);U w=xw-3;MC(yV,xV,i<<w);MC(yV+(i<<w),xV+(i+1<<w),xn-i-1<<w);I(xtA,I(!yn,A u=yx=mkn(_R(xx));I(!utP,ur--))y=sqz(mRa(y)))x(y))
 RM(A y=kv(&x);y=Nx(y(l2f(und,y,az(i))));aM(x,y))RE(rmv(gZ(x),i))R_(et(x)))0)
Z A2(cut,/*01*/Q(xtZ)Q(ytMT)K2("{y$[|/0<':x,#y;`err\"domain\";x+!'1_-':x,#y]}",x,y))
A2(und,/*01*/
 Xz(drp(gl_(x),y))
 XU(flt(x,y,0))
 Xm(A z=N(fnd(xx,yR));Zz(y(0);y=Nz(und(xx,zR));z=Ny(und(xy,z));am(y,z))ZZ(z(0);K2("_/",x,y))z(en(y)))
 P(xtZ&&ytMT,cut(x,y))
 P(xtMT&&ytz,rmv(xR,gl(y)))
 Ym(K2("{((!y)^x)#y}",x,y))
 YM(flp(N(und(x,flp(y)))))
 et(y))
X1(enl,Rl(x=mut(x);xT=tL;x)Ri(aV(tZ(xv),1,&x))R3(tf,tc,ts,x(aV(TT[xt],1,TP(xt)?&x:xV)))Rm(A y=kv(&x);aM(x,e1f(enl,y)))R_(aA1(x)))
Z A psh_(A,A,B);
Z A cat11_(A,A,B);
A cat10_(A x,A y,B c)_(
 XE(cat10(gZ(c?x:xR),y))
 YE(y=gZ(yR);y(cat10_(x,y,c)))
 C b=xtB|ytB<<1;P(b==3,U m=xn,n=yn;x=aa_(m+n,x,c);cpyB(xV,m,yV,0,n);x)
 I(b&&(xtz|ytz),W v=(W)gl_(b==2?x:y);P(v<2,A u=aV(tB,1,&v);P(b==1,cat11_(x,u,c))u=cat10(u,y);c?x(u):u))
 P(xtT&&ytT,P(!yn,c?x:xR)P(!xn,c?x(yR):yR)P(xt-yt,P(xtZ&&ytZ,A u=x;B s=1;yR;N(sup_(&x,&y,c));I(!c&&u==x,mr(x);s=0)cat11_(x,y,s))cat11(blw(c?x:xR),blw(yR)))
  U m=xn,n=yn,w=xw-3;x=aa_(m+n,x,c);
  MC(xV+((W)m<<w),yV,(W)n<<w);I(ytA,mRa(y))x)
 P(xtm&&ytm,a4(c?x:xR,yx,av,yy))
 Xmt(cat10(enl(c?x:xR),y))
 Ymt(P(xN,psh_(x,yR,c))y=enl(yR);c?x(y):y)
 P(xtM||ytM,P(!yN,c?x:xR)P(!xN,c?x(yR):yR)P(xtT||ytT||xt==yt&&!mtc_(xx,yx),x=N(blw(c?x:xR));y=Nx(blw(yR));cat11(x,y))P(!xtM||!ytM,et(c?x:xR))P(!mtc_(xx,yx),ed(c?x:xR))A z=e2f(cat,xy,_R(yy));y=z?aM(_R(xx),z):0;c?x(y):y)Q(0);0)
A2(cat10,cat10_(x,y,1))
Z A cat11_(A x,A y,B c)_(y(cat10_(x,y,c)))
A2(cat11,y(cat10(x,y)))
A2(cat,/*01*/cat11_(x,y,0))
Z A psh_(A x,A y,B c)_(/*?1*/Q(xtMT|xtq);C ty=yt,tx=xt;U n=xtq?xn:xN;I(xtZFSC,S(tx,
 C(tG,P(ty==ti&&yv==(G)yv, x=aa_(n+1,x,c);xG[n]=yv;x))
 C(tH,P(ty==ti&&yv==(H)yv, x=aa_(n+1,x,c);xH[n]=yv;x))
 C(tI,P(ty==ti,            x=aa_(n+1,x,c);xI[n]=yv;x))
 C(tL,P(ty==ti,            x=aa_(n+1,x,c);xL[n]=yv;x)
      P(ty==tl,            x=aa_(n+1,x,c);xL[n]=gl(y);x))
 C(tC,P(ty==tc,            x=aa_(n+1,x,c);xG[n]=yv;x))
 C(tS,P(ty==ts,            x=aa_(n+1,x,c);xI[n]=yv;x))
 C(tF,P(ty==tf,            x=aa_(n+1,x,c);xL[n]=gl(y);x))
 C(tB,P(ty==ti&&yv==(1&yv),x=aa_(n+1,x,c);xG[n>>3]|=yv<<(n&7);x)))
 P(xtE,psh(gZ(c?x:xR),y)))
 P(!n&&(x==ce[tA]||!ytt||xt-TT[ty]),enl(c?x(y):y))
 P(xtZ&&ytz,A u=x;B s=1;N(sup_(&x,&y,c));I(!c&&u==x,mr(x);s=0)psh_(x,y,s))
 XM(P(!ytm||!mtc_(xx,yx),psh(Ny(blw(c?x:xR)),y))x=mut_(x,c);A z=xy=mut(xy);F(zn|!zn,N(PSH(za,ii(yy,i)),za=au;x(0)))I(!zn,zx=mkn(zx))y(x))
 B xtA_=xtA;P(!xtA_&&(!ytt||xt-TT[yt]),psh(Ny(blw(c?x:xR)),y))
 L v=(xtq||xtA)?(L)y:gl(y);C k=xtq?xK:0;x=AK(k,aa_(n+1,x,c));I(!n&&xtA&&x!=ce[tA],mr(xx))
 U w=xw-3;MC(xV+((W)n<<w),&v,1<<w);x)
A2(psh,/*11*/psh_(x,y,1))
Z A apc_(A x/*_cl*/,C c,B l)_(Q(xtC||xtG);U n=xn;x=aa_(n+1,x,l);xC[n]=c;x)
A apc(A x/*1c*/,C c   )_(apc_(x,c,1))
A cts(A x/*1*/,S s,U m)_(Q(xtC);     U n=xn;x=aa(n+m,x);MC(xV+n,s,m);x)
Z A insL(A x,L i,L j,A y/*1ij0*/)_(
 I n=xN,k=yN,m=n-j+i+k;P(i>=(W)(j+1)||j>=(W)(n+1),ei(x))U w=xw-3;P(!m,P(!n,x)A z=an(0,xt);zx=emp(tC);x(z))
 P(MINE(x),I(m>n,x=aa(m,x));A z=0;I(j<n,z=aV(xt,n-j,xV+(j<<w)))I(xtR,mrn(j-i,xA+i))
   MC(xV+(i<<w),yV,(W)k<<w);I(ytR,I(MINE(y),AZ(y))E(mRa(y)))I(z,MC(xV+(i+k<<w),zV,(W)zn<<w))I(z,AZ(z);z(0))sqz(AN(m,x)))
 A z=an(m,xt);MC(zV,xV,(W)i<<w);MC(zV+(i<<w),yV,(W)k<<w);MC(zV+(i+k<<w),xV+((W)j<<w),(W)(n-j)<<w);
 I(xtR,mRn(i,xA);mRn(n-j,xA+j);I(MINE(y),AZ(y))E(mRa(y))z=sqz(z))
 x(z))
A3(ins3,/*100*/
 Xmt(et(x))
 Zmt(z=enl(zR);z(ins3(x,y,z)))
 XM(P(!ztM,et(x))P(!mtc_(xx,zx),ed(x))y=prj(QUE,A8((A)GAP,yR,GAP),3);A u=Nx(y(e2(y,xy,_R(zy))));x(aM(_R(xx),u)))
 P(xtZ&&ztZ&&xt-zt,zR;N(sup(&x,&z));z(ins3(x,y,z)))
 P(xt-zt,z=blw(zR);z(ins3(blw(x),y,z)))
 Y(Ril(L i=gl_(y);insL(x,i,i,z))REGHIL(P(yn-2,el(x))insL(x,gl_(ii(y,0)),gl_(ii(y,1)),z))R_(et(x)))0)
AA(ins,/*10..0*/P(n==3,ins3(*a,a[1],a[2]))en(*a))
