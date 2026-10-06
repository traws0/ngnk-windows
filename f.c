#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
I rnk(A x/*0*/){X(RA(I v=rnk(xx);P(v<0,v)F(xn,P(v-rnk(xa),-1))v+1)RmM(rnk(xy))RT_A(1)R_(0))}//-1 for mixed rank
U urnk(A x/*0*/){X(RA(urnk(xx)+1)RmM(urnk(xy))RT_A(1)R_(0))}//assuming unirank

  U fG(CO G*a,U n,G v)_(U i=0;W(i<n&&a[i]!=v,i++)i)
Z U fH(CO H*a,U n,H v)_(U i=0;W(i<n&&a[i]!=v,i++)i)
  U fI(CO I*a,U n,I v)_(U i=0;W(i<n&&a[i]!=v,i++)i)
  U fL(CO L*a,U n,L v)_(U i=0;W(i<n&&a[i]!=v,i++)i)

Z A1(fN,A y=_R(cn[tl]);x(xtt?y:rsz(xN,y)))

Z CO W msk[]={0x8080808080808080ll,0x8000800080008000ll,0x8000000080000000ll,0x8000000000000000ll};
A2(fndl,YmMA(r2f(fndl,x,y))YE(fndl(x,gZ(y)))YB(fndl(x,cG(y)))Yzfs(fir(N(fndl(x,enl(y)))))Yt(y(_R(cn[tl])))
  P(xt==TT[yt]||xtZ&&ytZ,C w=xw-3;A z=aL(yn);F_(k,yn,L v;
  S4(yw-3,v=yG[k],v=yH[k],v=yI[k],v=yL[k])I(Tw[tZ(v)]>xw,zL[k]=NL;continue)S4(w,v=(UC)v,v=(UH)v,v=(U)v,v=(W)v)
  I(w==3,U i=fL(xV,xn,v);zL[k]=i<xn?i:NL)E(CO W m=msk[w],u=v*(m>>(-1+(1<<w+3)));B b=false;
  F(xn-1+(1<<5-w)>>5-w,W h=0,r[4];Fj(4,W e=~(xL[4*i+j]^u);L s=(m&e)>>-1+(1<<w+3);h|=r[j]=m&(s+(e&~m)))
   B(h,b=true;Fj(4,B(r[j],v=(4*i+j<<3-w)+(CTZ(r[j])>>w+3);zL[k]=v<xn?v:NL))))I(!b,zL[k]=NL)))y(sqzZ(z)))
 fN(y))
Z X2(fndGx,
 R_(y(fN(xR)))
 RmMA(l2f(fndGx,x,y))
 Rilc(L v=gl_(x);y(az(v==(C)v?yL[(UC)v]:NL)))
 RE(x=gZ(xR);x(fndGx(x,y)))
 RB(x=cG(xR);x(fndGx(x,y)))
 RGHILC(U m=xn;A z=aL(m);
  S4(xw-3,F(m,zl=yL[(UC)xc]),
   F(m,H v=xh;zl=v==(C)v?yL[(UC)v]:NL),
   F(m,I v=xi;zl=v==(C)v?yL[(UC)v]:NL),
   F(m,L v=xl;zl=v==(C)v?yL[(UC)v]:NL))
  y(sqzZ(z))))

W hc0(W x)_(x^=x>>33;x*=0xff51afd7ed558ccdUL;x^=x>>33;x*=0xc4ceb9fe1a85ec53UL;x^=x>>33;x) // murmur64
Z A tbl(U n)_(W m=1ULL<<64-CLZ((W)n*9/8);A x=an(MIN(m,~0U),tI);MS(xV,-1,(4*(W)xn+31)&~31ULL);xn=m;x) // xn=0 means UINT32_MAX+1
Z W hc(A x/*0*/)_(XP(hc0(x))XB(x=cG(xR);x(hc(x)))XE(x=gZ(xR);x(hc(x)))x=sqz(xR);I(LH(tG,xt,tL),x=sqzZ(x));W s=hc0(Lt(xt)|xn);
 XR(F(xn|!xn,s=hc0(s^hc(xa)));x(s))W n=xn<<xw-3;F(n>>3,s=hc0(s^xl))I(n&7,s=hc0(s^(xL[n>>3]&(1ULL<<8*(n&7))-1)));x(s))
W fndA_(A x,A y,A z)_(U h=hc(y),d=0,n=MAX(zn,1),i;W((i=zI[h&(n-1)])!=~0U,P(mtc_(xA[i],y),h&(n-1));h+=++d);h&(n-1))
A2(fndA,Z A z=0;Z U k;U l=urnk(y);
 P(z,P(l>k-1,r2f(fndA,x,y))P(l<k-1,er(y))U j=y(fndA_(x,y,z));(U)zI[j]<xn?az((L)(U)zI[j]):al(NL))
 k=urnk(x);P(l+1<k,er(y))
 P(l>=k,z=tbl(xn);F(xn,U j=fndA_(x,xa,z);I(zI[j]==-1,zI[j]=i));y=z(fndA(x,y)),z=0;y)
 F(xn,P(mtc_(y,xa),y(al(i))))y(al(NL)))
A2(fndZFS,Z A z=0;
 P(z,YmMA(r2f(fndZFS,x,y))YE(fndZFS(x,gZ(y)))YB(fndZFS(x,cG(y)))Yz(fir(N(fndZFS(x,enl(y)))))Yt(ed(y))
  P(xt==TT[yt]||ytZ&&LH(tG,xt,tL),U wx=xw-3,wy=yw-3,n=zn;A u=an(yn,tL);
   F(yn,L l,m;ul=NL;S4(wy,l=yg,l=yh,l=yi,l=yl)S4(wx,,I(l-(H)l,continue),I(l-(I)l,continue),)U h=hc0(l),d=0,j;
    W((j=zI[h&(n-1)])!=~0U,S4(wx,,m=xH[j],m=xI[j],m=xL[j]);B(l==m,ul=j);h+=++d))y(u))
  fN(y))
 Yt(P(xt==TT[yt]||ytz&&xtZ,L v=gl(y);S4(xw-3,,F(xn,P(v==xh,ai(i))),F(xn,P(v==xi,ai(i))),F(xn,P(v==xl,ai(i))))al(NL))y(al(NL)))
 z=tbl(xn);U wx=xw-3,n=zn;
 F(xn,L l,m;S4(wx,,l=xh,l=xi,l=xl);U h=hc0(l),d=0,j;W((j=zI[h&(n-1)])!=~0U,S4(wx,,m=xH[j],m=xI[j],m=xL[j]);B(l==m);h+=++d)I(zI[h&(n-1)]==-1,zI[h&(n-1)]=i))
 y=z(fndZFS(x,y));z=0;y)
X2(fnd,
 R_(et(y))
 Rm(i1(xx,N(fnd(xy,y))))
 RM(en(y))
 RE(x=gZ(xR);x(fnd(x,y)))
 RA(fndA(x,y))
 RB(x=cG(xR);x(fnd(x,y)))
 RGC(A z=aL(256);F(256,zl=NL);UC*a=xV;U n=xn;F(n,zL[a[n-1-i]]=n-1-i)y(fndGx(y,z)))
 R5(tH,tI,tL,tF,tS,P(xn>=10,fndZFS(x,y))fndl(x,y)))
X2(que,Rs(Z CO C s[][4]={"","j","k","hex"};G(&des,js0,val,unh,ed)[fI((V*)s,L(s),xv)](y))Ril(rnd(gl_(x),y))R_(fnd(x,y)))

Z A2 binF;
Z Y2(binZ,
 R_(et(y))
 RF(x=cF(xR);x(binF(x,y)))
 Rt(YU(ed(y))fir(N(binZ(x,enl(y)))))
 RmMA(r2f(binZ,x,y))
 RE(binZ(x,gZ(y)))
 RB(binZ(x,cG(y)))
 RGHILC(
  XE(x=gZ(xR);x(binZ(x,y)))
  A z=an(yn,tZ(xn-1));U wx=xw-3,wy=yw-3,wz=zw-3;
  P(!wx,L t[257]={[0]=-1};F(xn,t[129+xg]++)F(256,t[i+1]+=t[i])
   F(yn,L v,j;S4(wy,v=yg,v=yh,v=yi,v=yl);j=t[129+MIN(127,MAX(-128,v))];S4(wz,zg=j,zh=j,zi=j,zl=j))y(z))L k[2];
  F(yn,L v;S4(wy,v=yg,v=yh,v=yi,v=yl)*k=-1;k[1]=xn;S4(wx,,W(*k+1<k[1],L i=*k+k[1]>>1;k[v<xh]=i),W(*k+1<k[1],L i=*k+k[1]>>1;k[v<xi]=i),W(*k+1<k[1],L i=*k+k[1]>>1;k[v<xl]=i))
       S4(wz,zg=*k,zh=*k,zi=*k,zl=*k))y(z)))
Z Y2(binF,RF(x=of1(xR);x(binZ(x,of1(y))))REBGHILC(binF(x,N(cF(y))))Rt(YU(ed(y))fir(N(binF(x,enl(y)))))RmMA(r2f(binF,x,y))R_(ed(y)))
X2(bin,REGHILC(binZ(x,y))RF(binF(x,y))Rm(_1(xx,N(bin(xy,y))))RB(binZ(cG(xR),y))R_(et(y)))
