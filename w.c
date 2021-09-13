#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S A2(enc,x=Ny(cL(x));y=Nx(cL(y));Yt(Az=enc(x,enl(y));zn?fir(flp(z)):z(oL))
 Xt(UL v=gl(x),r=0,m=0,b=1;i(yn,UL w=yl;I(r<w,r=w))W(m<64&&b<=r,m++;b*=v)enc(rshN(m,az(v)),y))
 P(!xn,x(y(oA)))Au=aA(xn);y=mut(y);Li=xn;W(--i>0,UL m=xl;m+=!m;Az=ua=aL(yn);i(yn,UL v=yl,w=yl=v/m;zl=v-w*m))
 UL m=gl(x);ux=y;I(m,i(yn,yl%=m))u)
S A2(dec,K("{z+x*y}/[0;;]",x,y))S A2(win,K("{y(!x)+/:!0|1-x-#y}",x,y))
S A scC(Cc    ,C*p,Ln)_(      Ax=oA;C*q;W((q=MC(p,c,n  )),xq(aCm(p,q));n-=q-p+1;p=q+1)I(c-10||n,xq(aCn(p,n)))x)
S A sCC(C*s,Lm,C*p,Ln)_(El(!m)Ax=oA;C*q;W((q=MM(p,n,s,m)),xq(aCm(p,q));n-=q+m-p;p=q+m)xq(aCn(p,n)))
S A sc(Cc    ,Ax)_(XC(x(scC(c,  xV,xn)))et1(x))A1(spl,sc(10,x))
S A sC(C*s,Lm,Ax)_(XC(x(sCC(s,m,xV,xn)))et1(x))
SN L jN(Lm,Ax/*0*/)_(P(!xtA,-1)Ln=(xn-!!xn)*m;i(xn,Ay=xa;P(!ytcC,-1)n+=yN)n)//total length or -1
A jc(Cc,   Ax)_(Ln=jN(1,x);Et(n<0,x)Ay=aC(n);C*p=yV;i(xn,I(i,*p++=c        )Az=xa;I(ztc,*p++=zv)E(Mc(p,zV,zn);p+=zn))x(y))
A jC(Qs,Nm,Ax)_(Ln=jN(m,x);Et(n<0,x)Ay=aC(n);C*p=yV;i(xn,I(i,Mc(p,s,m);p+=m)Az=xa;I(ztc,*p++=zv)E(Mc(p,zV,zn);p+=zn))x(y))
L cfm(OA*a/*0*/,In)_(Lm=-1;i(n,Ax=a[i];I(!xtt,Lv=xN;P(m>=0&&m-v,-2)m=v))m)
S AX(eacm,Az=oS,b[8];i(n,Ay=a[i];I(ytm,z=cat(z,_R(yx))))z=unq(z);
 i(n,Ay=b[i]=a[i];I(ytm,Au=kv(&y);uq(id_(x,u));b[i]=ap1(u,fil(ai(yn),fnd(y,zR)))))x=eac(x,b,n);x?am(z,x):z(x))
AX(eac,Ab8;Ct[8];Lm=-1;
 i(n,Ay=b[i]=a[i];Ym(eacm(x,a,n))t[i]=ytP?0:ytt?1:ytA?2+(yr>1):4;I(t[i]>1,L l=yN;P(m>=0&&m-l,eln(n,a))m=l))
 P(m<0,app(x,a,n))i(n,I(t[i]==1,_r(a[i])+=m)) //0:pkdatm,1:refatm,2:tA(r=1),3:tA,4:other
 Au=0;I(!m,I(x==LEN,u=oL)EI(n==2&&xtv&&xv<11,u=a[!_N(a[1])];uR)E(u=oA))
 j(m,i(n,Ay=a[i];I(t[i]==2,b[i]=yA[j])I(t[i]>2,b[i]=get(y,j)))Az=app(x,b,n);
     B(!z,I(u,u=u(0))i(n,Ay=a[i];I(t[i]==1,yr-=m-j-1)I(t[i]==2,mrn(m-j-1,yA+j+1))))
     I(!j,u=c3(ti,zt,ts)?AN(0,atn(TT[zt],m)):oA)uq(z))
 i(n,mr(t[i]-2?a[i]:AN(0,a[i])))u)
A eac1(Ax,A1 f)_(Xt(f(x))Xm(Ay=kv(&x);am(x,Nx(eac1(y,f))))
 I b=xtA&&xr==1;Nn=xN;P(!n,x)Ay=oA;i(n,Az=f(b?xa:get(x,i));B(!z,I(b,mrn(xn-i-1,xA+i+1))y=y(0))yq(z))I(b,x=AN(0,x))x(y))
A3(eac2,/*110*/eac(z,A(x,y),2))
S A nr(Ax/*0*/,Ln,Ay/*1*/)_(      i(n,       y= N(app(x,&y,1)))   y )
S A ns(Ax/*0*/,Ln,Ay/*1*/)_(Az=oC;i(n,zq(yR);y=Nz(app(x,&y,1)))zq(y))
S A3(wr,/*011*/           W(1,zR;A w=app(y,&z,1);B(!w,z=z(0))B(!tru(w))z=app(x,&z,1);Ny(z)              )y(z)   )
S A3(ws,/*011*/Au=enl(zR);W(1,zR;A w=app(y,&z,1);B(!w,u=u(0))B(!tru(w))z=app(x,&z,1);P(!z,y(u(0)))uq(zR))y(z(u)))
S A2(cr,/*01*/Az=yR,u;W(1,zR;u=app(x,&z,1);B(!u)P(mtc_(u,y)||mtc_(u,z),y(u(z)))z=z(u))y(z(u)))
S A2(cs,/*01*/Az=yR,v=yR,u=enl(y);W(1,z=yR;y=app(x,&y,1);P(!y,z(u(dex(v,0))))Im=mtc_(y,z)||mtc_(y,v);z(0);B(m)uq(yR))y(dex(v,u)))
S AX(lr,Ay=*a;P(n==1,cr(x,y))P(n==2,Yz(nr(x,gl(y),a[1]))wr(x,y,a[1]))ern(n,a))
S AX(ls,Ay=*a;P(n==1,cs(x,y))P(n==2,Yz(ns(x,gl(y),a[1]))ws(x,y,a[1]))ern(n,a))
AX(rdc,Ay=n>1?n--,*a++:0,z=*a;Lm=cfm(a,n);P(m==-1,y?app(x,a-1,n+1):z)P(m<0,I(y,y(0))eln(n,a))P(!m&&!y,x=id_(x,z);mrn(n,a);x)
 I(n==1&&xtv&&xv<11&&(!y||ytz||ytd||ytc)&&ztZDC,I(ztC,z=cH(z))I(y&&(ytd||ztD),y=cD(y);z=cD(z))Ct=zt;
  V(f,arrT[t-tB][xv])P(f,Lv=gl(y?y:get(z,0));z2(f(&v,zV+!y*zW,m-!y));t-tD?az(v):ad(*(D*)&v)))
 Li=!y;I(i,y=get(z,0))Ab8;W(i<m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);B(!y)i++)mrn(n-1,a+1);z(y))
S AX(scn,
 P(n==1,Az=a[n-1];P(ztt||!zN,z)P(ztm,Ay=kv(&z);y=Nz(scn(x,&y,1));am(z,y))P(x==CAT,scn(x,A(oA,z),2))
  I(xtv&&xv&&xv<8&&ztZDC,I(ztC,z=N(cL(z)))V(f,arsT[zt-tB][xv])P(f,Au=ax(z);Mc(uV,zV,zW);f(zV,zV+zW,uV+zW,zN-1);u))
  Ay=get(z,0),u=enl(yR);Li=0,n=zN;W(++i<n,y=N(app(x,A(y,get(z,i)),2));uq(yR))y(z(u)))
 I(n==2,Ay=a[1];Yt(app(x,a,n))Ym(y=mut(y);yy=scn(x,A(*a,yy),2);y)P(!yn,mr(*a),y))
 Ay=*a++;n--;Lm=cfm(a,n);P(m==-2,y(eln(n,a)))
 Az=oA,b[8];i(m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);P(!y,mrn(n,a);z(0))zq(yR))mrn(n,a);y(z))
S A3(eap2,/*011*/Et(!ztT,y,z)P(!zn,y(z))
 I(xtv&&xv<11&&ytZC&&ztZC,I(ytz,y=az(gl(y)))N(sup(&y,&z));Lv=gl(y);V(f,arpT[zt-tB][xv])P(f,x=ax(z);f(&v,zV,xV,zn);x))
 Au=oA;i(zn,y=app(x,A(get(z,i),y),2);P(!y,z(u(0)))uq(y);y=get(z,i))y(z(u)))
S A2(eap1,/*01*/eap2(x,id_(x,y),y))
AX(w0,I(n==1, Xz(win(xR,*a))XT(bin(xR,*a)))                              eac(x,a,n)) /* '  */
AX(w1,I(n==1,XzZ(dec(xR,*a))Xc(jc(xv,*a))XC(jC(xV,xn,*a)))xK<2?lr(x,a,n):rdc(x,a,n)) /* /  */
AX(w2,I(n==1,XzZ(enc(xR,*a))Xc(sc(xv,*a))XC(sC(xV,xn,*a)))xK<2?ls(x,a,n):scn(x,a,n)) /* \  */
AX(w3,n==1?eap1(x,*a):n==2?eap2(x,*a,a[1]):ern(n,a))                                 /* ': */
AX(w4,n-2?ern(n,a):ear(x,*a,a[1]))A3(ear,/*011*/x=prj(x,A(y,PLH),2);x(eac(x,&z,1)))  /* /: */
AX(w5,n-2?ern(n,a):eal(x,*a,a[1]))A3(eal,/*011*/x=prj(x,A(PLH,z),2);x(eac(x,&y,1)))  /* \: */
