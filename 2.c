#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define XYmMA(a...) P((1<<xt|1<<yt)&(1<<tm|1<<tM|1<<tA),a)

//{dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql}x{o0123fspa}x{BHILD} =
// = {:+-*%!&|<>=}x{op,a+a,a+l,l+a,l+l,f/,f\,f':,@}x{byte,short,int,long,double}
#define hv(v,T,R,f) S R v##o##T(T x,T y)_(f)
#define hd(v,f,g) hv(v,B,B,f)hv(v,H,H,f)hv(v,I,I,f)hv(v,L,L,f)hv(v,D,D,g)
#define hc(v,f,g) hv(v,B,B,f)hv(v,H,B,f)hv(v,I,B,f)hv(v,L,B,f)hv(v,D,B,g)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hv(dvd,D,D,x/y)hd(mod,x>0?(y%x+x)%x:!x?y:y<0?-1-(-1-y)/-x:y/-x,x>0?y-(L)(y/x)*x:dvdoD(y,-x))
h(mnm,min(x,y))h(mxm,max(x,y))hc(ltn,x<y,qD(x,y)<0)hc(gtn,x>y,ltn(y,x))hc(eql,x==y,*(L*)&x==*(L*)&y)
#undef h
#define hV(f,T,R,e...) SN I f(OV*RE p,OV*RE q,V*RE s,Nn)_(O T*a=p,*b=q;R*r=s;e)
#define h0(v,T,R) hV(v##0##T,T,R,*r=v##o##T(*a,*b);0)
#define h1(v,T,R) hV(v##1##T,T,R,LN(b)LN(r)TY(*a)c=*a;i(PD(n,a),*r++=v##o##T(   c,*b++))0)
#define h2(v,T,R) hV(v##2##T,T,R,LN(a)LN(r)TY(*b)c=*b;i(PD(n,a),*r++=v##o##T(*a++,   c))0)
#define h3(v,T,R) hV(v##3##T,T,R,LN(a)LN(b)LN(r)      i(PD(n,a),*r++=v##o##T(*a++,*b++))0)
#define hS(v,T,R) hV(v##2##T,T,R,v##1##T(b,a,r,n))
#define h0123(a...) h0(a)h1(a)h2(a)h3(a)
#define h01S3(a...) h0(a)h1(a)hS(a)h3(a)
                                                        h0123(dvd,D,D)
h0123(mod,B,B)h0123(mod,H,H)h0123(mod,I,I)h0123(mod,L,L)h0123(mod,D,D)
h01S3(mnm,B,B)h01S3(mnm,H,H)h01S3(mnm,I,I)h01S3(mnm,L,L)h01S3(mnm,D,D)
h01S3(mxm,B,B)h01S3(mxm,H,H)h01S3(mxm,I,I)h01S3(mxm,L,L)h01S3(mxm,D,D)
h0123(ltn,B,B)h0123(ltn,H,B)h0123(ltn,I,B)h0123(ltn,L,B)h0123(ltn,D,B)
h01S3(eql,B,B)h01S3(eql,H,B)h01S3(eql,I,B)h01S3(eql,L,B)h01S3(eql,D,B)
TY(&mod0B)aro[][5][7]={
 {{    0,mod0B,mnm0B,mxm0B,ltn0B,0,eql0B},//a+a
  {    0,mod0H,mnm0H,mxm0H,ltn0H,0,eql0H},
  {    0,mod0I,mnm0I,mxm0I,ltn0I,0,eql0I},
  {    0,mod0L,mnm0L,mxm0L,ltn0L,0,eql0L},
  {dvd0D,mod0D,mnm0D,mxm0D,ltn0D,0,eql0D}},
 {{    0,mod1B,mnm1B,mxm1B,ltn1B,0,eql1B},//a+l
  {    0,mod1H,mnm1H,mxm1H,ltn1H,0,eql1H},
  {    0,mod1I,mnm1I,mxm1I,ltn1I,0,eql1I},
  {    0,mod1L,mnm1L,mxm1L,ltn1L,0,eql1L},
  {dvd1D,mod1D,mnm1D,mxm1D,ltn1D,0,eql1D}},
 {{    0,mod2B,mnm2B,mxm2B,ltn2B,0,eql2B},//l+a
  {    0,mod2H,mnm2H,mxm2H,ltn2H,0,eql2H},
  {    0,mod2I,mnm2I,mxm2I,ltn2I,0,eql2I},
  {    0,mod2L,mnm2L,mxm2L,ltn2L,0,eql2L},
  {dvd2D,mod2D,mnm2D,mxm2D,ltn2D,0,eql2D}},
 {{    0,mod3B,mnm3B,mxm3B,ltn3B,0,eql3B},//l+l
  {    0,mod3H,mnm3H,mxm3H,ltn3H,0,eql3H},
  {    0,mod3I,mnm3I,mxm3I,ltn3I,0,eql3I},
  {    0,mod3L,mnm3L,mxm3L,ltn3L,0,eql3L},
  {dvd3D,mod3D,mnm3D,mxm3D,ltn3D,0,eql3D}}};
S C tZx(Ax)_(Ct=TX[xt];P(t,t)Xl(tZ(gl_(x)))tZ(xv))
C sup(A*p,A*q)_(Ax=*p,y=*q;Ct=max(tZx(x),tZx(y));*p=x=Ny(cT[t](x));*q=y=Nx(cT[t](y));t)
S A3(ar2,Q(ztv)XYmMA(eac2f(x,y,v2[zv]))N(sup(&x,&y));Ik=xtT<<1|ytT;P(k==3&&xn-yn,el2(x,y))
 Ct=k?min(xt,yt):max(xt,yt);V*a=xtP?(V*)&x:xV,*b=ytP?(V*)&y:yV;t=TT[t];V(f,aro[k][t-tB][zv-4]);I(z>MXM,t=tB)
 I(!k,t=max(ti,t+tc-tC);P(TP(t),Ii=0;f(a,b,&i,1);x(y(az(i)))))
 Az=xt==t&&xr==1?x:yt==t&&yr==1?y:an(t,k-1?xn:yn);f(a,b,zV,zn);x-z?x(y-z?y(z):z):y(z))
S ALA(ext,XMT(x)rsh(n,xtm?enl(x):x))
A2(dct,P(rnk(x)<0,ed2(x,y))x=ext(yN,x);y=ext(xN,y);(xN-yN?el2:am)(x,y))
A2(dex,mr(x);y)
A2(add,adm(x,y,0))
A2(sub,add(x,Nx(neg(y))))
A2(mul,adm(x,y,1))
A2(dvd,XYmMA(eac2f(x,y,dvd))ar2(Ny(cD(x)),Nx(cD(y)),DVD))
A2(mod,Xzc(ar2(x,y,MOD))dct(x,y))
A2(mnm,ar2(x,y,MNM))
A2(mxm,ar2(x,y,MXM))
A2(ltn,ar2(x,y,LTN))
A2(gtn,ltn(y,x))
A2(eql,XYmMA(eac2f(x,y,eql))P(xtsS-ytsS,et2(x,y))P(xtsS,eql(AT(xt+ti-ts,mut(x)),AT(yt+ti-ts,mut(y))))ar2(x,y,EQL))

#define hf(v,T)S L v##f##T(L a,O V*b,Nn)_(O T*p=b;i(n,a=v##oL(a,p[i]))a)
#define hfD(v) S D v##f##D(D a,O D*b,Nn)_(i(n,a=v##oD(a,b[i]))a)
hf(add,B)hf(add,H)hf(add,I)hf(add,L)hfD(add) hf(mul,B)hf(mul,H)hf(mul,I)hf(mul,L)hfD(mul)
hf(mnm,B)hf(mnm,H)hf(mnm,I)hf(mnm,L)hfD(mnm) hf(mxm,B)hf(mxm,H)hf(mxm,I)hf(mxm,L)hfD(mxm)
S A3(___f,Nn=yn,i=!x;I(i,x=ii(y,0))W(i<n,x=z2(x,ii(y,i++));B(!x))y(x))
S A3 dexs;S A3(dexf,las(dexs(x,y,z)))
S A3(ammf,Q(ztv)I(ytC,y=cH(y))I(ytD||(x&&xtd),I(x,x=cD(x))y=cD(y))
 Ii=T((C)9,0,9,1,9,9,2,3)[zv];YD(ad(ye(T(&addfD,mulfD,mnmfD,mxmfD)[i](x?gd(x):T(0.0,1,WD,-WD)[i],yV,yn))))
 V(f,T(&addfB,addfH,addfI,addfL,mulfB,mulfH,mulfI,mulfL,mnmfB,mnmfH,mnmfI,mnmfL,mxmfB,mxmfH,mxmfI,mxmfL)[i<<2|yt-tB])
 az(ye(f(x?gl(x):T(0ll,1,WL,-WL)[i],yV,yn))))
S A3(subf,neg(ammf(x?neg(x):yn?mul(ai(-2),ii(y,0)):0,y,ADD)))
A3(arf,Q(ztv)Q(zv<11)Q(!x||xtzdc)Q(ytZDC)T(&dexf,ammf,subf,ammf,___f,___f,ammf,ammf,___f,___f,___f)[zv](x,y,z))

#define hs(v,T) S V v##s##T(L a,V*RE q,V*RE s,Nn){T*b=q,*r=s,c=a;i(PD(n,b),c=r[i]=v##o##T(c,b[i]));}
hs(mxm,B)hs(mxm,H)hs(mxm,I)hs(mxm,L)
S A3(___s,Ni=!x;Au=i?x=ii(y,0),enl(xR):oA;Nn=yn;W(i<n,x=z2(x,ii(y,i++));P(!x,y(u))uq(xR))x(y(u)))
S A3(dexs,x?x(y):y)
S A3(adds,L w=x?gl(x):0;Nn=yn;
 W(1,I b=1;Lv=w;Ct=yt;Au=an(t,n);
  I(t==tB,i(n,ub=v+=yb;B(v-(B)v,b=0)))
  J(t==tH,i(n,uh=v+=yh;B(v-(H)v,b=0)))
  J(t==tI,i(n,ui=v+=yi;B(v-(I)v,b=0)))
  E(i(n,ul=v+=yl))
  P(b,y(u))y=cT[t+1](u(y)))0)
S A3(muls,L w=x?gl(x):1;Nn=yn;
 W(1,I b=1;Lv=w;Ct=yt;Au=an(t,n);I(t==tL,i(n,ul=v*=yl))J(t==tI,i(n,ui=v*=yi;B(v-(I)v,b=0)))
  J(t==tH,i(n,uh=v*=yh;B(v-(H)v,b=0)))J(t==tB,i(n,ub=v*=yb;B(v-(B)v,b=0)))E(Q(0))P(b,y(u))y=cT[t+1](u(y)))0)
S A3(subs,neg(adds(neg(x?x:mul(ai(2),ii(y,0))),y,0)))
S A3(mxms,P((!x||xtz)&&ytZ,Lv=x?gl(x):-WL,l=-1ll<<8*yW-1,h=~l;I(v<=l||h<=v,P(v>=0,y(rsh(yn,az(v))))v=v<0?l:h)
            Au=yr==1?y:an(yt,yn);T(&mxmsB,mxmsH,mxmsI,mxmsL)[yt-tB](v,yV,uV,un);y-u?y(u):u)___s(x,y,z))
SN A1(inv,x=mut(x);Nn=xn*xW;i(PD(n,xC),xc^=-1)x)
S A3(mnms,P((!x||xtz)&&ytZ,inv(mxms(x?az(-1-gl(x)):0,inv(y),MXM)))___s(x,y,z))
A3(ars,Q(ztv)Q(zv<11)Q(!x||xtzdc)Q(ytZDC)T(&dexs,adds,subs,muls,___s,___s,mnms,mxms,___s,___s,___s)[zv](x,y,z))

#define hp(v,T,R) S I v##p##T(OV*RE p,OV*RE q,V*RE s,Nn)_(O T*a=p,*b=q;R*r=s;T c=*a;i(PD(n,b),T d=b[i];r[i]=v##o##T(b[i],c);c=d);0)
hp(mnm,B,B)hp(mnm,H,H)hp(mnm,I,I)hp(mnm,L,L) hp(ltn,B,B)hp(ltn,H,B)hp(ltn,I,B)hp(ltn,L,B)
hp(mxm,B,B)hp(mxm,H,H)hp(mxm,I,I)hp(mxm,L,L) hp(gtn,B,B)hp(gtn,H,B)hp(gtn,I,B)hp(gtn,L,B)
S A3(dexp,cat(x,drp(-1,y)))                  hp(eql,B,B)hp(eql,H,B)hp(eql,I,B)hp(eql,L,B)
S A3(___p,v2[zv](y,dexp(x,yR,av)))
S A3(modp,eac2f(y,dexp(x,yR,av),mod))
S A3(mmmp,N(sup(&x,&y));Lv=gl(x);Ii=(z-MNM)<<2|Tz[yt];x=ax(y);T(&mnmpB,mnmpH,mnmpI,mnmpL,mxmpB,mxmpH,mxmpI,mxmpL)[i](&v,yV,xV,yn);x)
S A3(cmpp,Ii=z-LTN,j=Tz[yt];Lv=gl(x);x=aB(yn);Cc=tZ(v)-tB<=j?2:!i?v>0:i==1?v<0:0;
 ye(T(&ltnpB,ltnpH,ltnpI,ltnpL,gtnpB,gtnpH,gtnpI,gtnpL,eqlpB,eqlpH,eqlpI,eqlpL)[i<<2|j](&v,yV,xV,yn);I(c-2,*xB=c)x))
A3(arp,Q(ztv)Q(zv<11)Q(xtzc)Q(ytZC)T(&dexp,___p,___p,___p,___p,modp,mmmp,mmmp,cmpp,cmpp,cmpp)[zv](x,y,z))

#define ha(v,T)\
 S V v##a##T##L(V*RE p,Nn,OV*RE q,Nm,O V*RE r,N d){T*a=p;O L*b=q;O T*c=r;i(m,Lj=b[i];a[j]=v##o##T(a[j],c[d*i]))}\
 S V v##a##T##I(V*RE p,Nn,OV*RE q,Nm,O V*RE r,N d){T*a=p;O I*b=q;O T*c=r;i(m,Ij=b[i];a[j]=v##o##T(a[j],c[d*i]))}
ha(dex,B)ha(dex,H)ha(dex,I)ha(dex,L)
                           ha(add,L)
                           ha(sub,L)
                           ha(mul,L)
ha(mnm,B)ha(mnm,H)ha(mnm,I)ha(mnm,L)
ha(mxm,B)ha(mxm,H)ha(mxm,I)ha(mxm,L)
S TY(&mxmaBL)araT[][11][2]={
 {{dexaBI,dexaBL},{             },{             },{             },{},{},{mnmaBI,mnmaBL},{mxmaBI,mxmaBL}},
 {{dexaHI,dexaHL},{             },{             },{             },{},{},{mnmaHI,mnmaHL},{mxmaHI,mxmaHL}},
 {{dexaII,dexaIL},{             },{             },{             },{},{},{mnmaII,mnmaIL},{mxmaII,mxmaIL}},
 {{dexaLI,dexaLL},{addaLI,addaLL},{subaLI,subaLL},{mulaLI,mulaLL},{},{},{mnmaLI,mnmaLL},{mxmaLI,mxmaLL}}};
A4(ara,/*1111*/Q(xtZ)Q(ytZ)Q(ztv)Q(zv<11)Q(utzZ)P(utT&&yn-un,el2(x(y),u))I(ADD<=z&&z<=MUL,/*todo*/x=cL(x))
 x=mut(x);Ny(sup(&x,&u));Nn=xn;
 I(ytL,    i(yn,P(yl>=n,ei2(x(y),u))))
 E(y=cI(y);i(yn,P(yi>=n,ei2(x(y),u))))
 ye(ue(araT[xt-tB][zv][ytL](xV,xn,yV,yn,utP?&u:uV,utT);x)))
