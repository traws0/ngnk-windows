#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
S A2(enc/*01*/,Q(xtzZ)P(x==ai(2)&&ytz&&gl_(y)<0,x=rshN(64,xR);x(enc(x,y)))
 Ii=ytt;x=K("{$[0>&/x;`err\"domain\"; `i~@x;|x!-1_![-x;]\\y; x!'|(,y),y{(-y)!x}\\|1_x]}",xR,y);!x||xN?x:x(i?oB:oA))
S A2(dec,/*01*/K("{z+x*y}/[0;;]",xR,y))S A2(win,/*01*/K("{y(!x)+/:!0|1-x-#y}",xR,y))
S A scC(Cc    ,C*p,Ln)_(           Ax=oA;C*q;W((q=MC(p,c,n  )),xq(aCm(p,q));n-=q-p+1;p=q+1)I(c-10||n,xq(aCn(p,n)))x)
S A sCC(C*s,Lm,C*p,Ln)_(P(!m,el0())Ax=oA;C*q;W((q=MM(p,n,s,m)),xq(aCm(p,q));n-=q+m-p;p=q+m)xq(aCn(p,n)))
S A sc(Cc    ,Ax)_(XC(x(scC(c,  xV,xn)))et1(x))A1(spl,sc(10,x))
S A sC(C*s,Lm,Ax)_(XC(x(sCC(s,m,xV,xn)))et1(x))
SN L jN(Lm,Ax/*0*/)_(P(!xtA,-1)Ln=(xn-!!xn)*m;i(xn,Ay=xa;P(!ytcC,-1)n+=yN)n)//total length or -1
A jc(Cc,   Ax)_(Ln=jN(1,x);P(n<0,et1(x))Ay=aC(n);C*p=yV;i(xn,I(i,*p++=c        )Az=xa;I(ztc,*p++=zv)E(Mc(p,zV,zn);p+=zn))x(y))
A jC(Qs,Nm,Ax)_(Ln=jN(m,x);P(n<0,et1(x))Ay=aC(n);C*p=yV;i(xn,I(i,Mc(p,s,m);p+=m)Az=xa;I(ztc,*p++=zv)E(Mc(p,zV,zn);p+=zn))x(y))
L cfm(OA*a/*0*/,In)_(Lm=-1;i(n,Ax=a[i];I(!xtt,Lv=xN;P(m>=0&&m-v,-2)m=v))m)
S AX(eacm,Az=oS;Ik=0;i(n,Ay=a[i];I(ytm,k++;z=cat(z,_R(yx))))I(k>1,z=unq(z))
 Ab8;i(n,Ay=b[i]=a[i];I(ytm,Au=kv(&y);uq(id_(x,u));b[i]=ap1(u,fil(ai(yn),fnd(y,zR)))))AX eac;x=eac(x,b,n);P(!x,z(x))dct(z,x))
A eac1f(Ax,A1 f)_(Xt(f(x))Xm(Ay=kv(&x);am(x,Nx(eac1f(y,f))))I b=xtA&&xr==1;Nn=xN;P(!n,f==len?x(oB):f==til?x(oA):x)
 Ay=oA;i(n,Az=f(b?xa:get(x,i));B(!z,I(b,mrn(xn-i-1,xA+i+1))y=y(0))yq(z))I(b,x=AN(0,x))x(y))
SN A atn0(Ax/*0*/,Nn)_(x?AN(0,atn(c3(ti,xt,ts)?TT[xt]:tA,n)):0)
S A2(eac1,/*10*/Yu(eac1f(x,v1[yv]))Xt(app1(y,x))Xm(eacm(y,&x,1))
 Ct=xtA?2+(xr>1):4;Nm=xN;P(!m,x(y==LEN?oB:oA))I(t==2,x=AN(0,x)) //2:tA(r=1),3:tA,4:other
 Au=0;i(m,Az=app1(y,t==2?xa:get(x,i));B(!z,I(u,u=u(0))I(t==2,mrn(m-i-1,xA+i+1)))I(!u,u=atn0(z,m))uq(z))x(u))
  A3(ear2,/*110*/z=prj(z,A(x,PLH),2);z(eac1(y,z)))
S A3(eal2,/*110*/z=prj(z,A(PLH,y),2);z(eac1(x,z)))
S AX(eal,Ab8;Mc(b,a,n*SZ x);*b=PLH;x=prj(x,b,n);x(eac1(*a,x)))
S A3(eac2,/*110*/P(ztv,eac2f(x,y,v2[zv]))A a[]={x,y};
 Xt(Yt(app2(*a,a[1],z))ear2(x,y,z))Yt(eal2(x,y,z))Xm(eacm(z,a,2))Ym(eacm(z,a,2))
 Nm=xN;P(m-yN,el2(x,y))P(!m,y(ztv&&zv<11?x:x(oA)))
 A b[2],u=0;Ct[2];i(2,Ay=a[i];t[i]=ytA?2+(yr>1):4) //2:tA(r=1),3:tA,4:other
 j(m,i(2,Ay=a[i];b[i]=t[i]==2?yA[j]:get(y,j))Ax=app2(*b,b[1],z);
  B(!x,I(u,u=u(0))i(2,Ay=a[i];I(t[i]==2,mrn(m-j-1,yA+j+1))))I(!u,u=atn0(x,m))uq(x))
 i(2,mr(t[i]-2?a[i]:AN(0,a[i])))u)
AX(eac,P(n==1,eac1(*a,x))P(n==2,eac2(*a,a[1],x))
 Ab8;Ct[8];Lm=-1;
 i(n,Ay=b[i]=a[i];Ym(eacm(x,a,n))t[i]=ytP?0:ytt?1:ytA?2+(yr>1):4;I(t[i]>1,L l=yN;P(m>=0&&m-l,eln(a,n))m=l))
 P(m<0,app(x,a,n))i(n,I(t[i]==1,_r(a[i])+=m)) //0:pkdatm,1:refatm,2:tA(r=1),3:tA,4:other
 Au=0;I(!m,u=x==LEN?oB:n==2&&xtv&&xv<11?_R(a[!_N(a[1])]):oA)
 j(m,i(n,Ay=a[i];I(t[i]==2,b[i]=yA[j])I(t[i]>2,b[i]=get(y,j)))Az=app(x,b,n);
  B(!z,I(u,u=u(0))i(n,Ay=a[i];I(t[i]==1,yr-=m-j-1)I(t[i]==2,mrn(m-j-1,yA+j+1))))
  I(!j,u=c3(ti,zt,ts)?AN(0,atn(TT[zt],m)):oA)uq(z))
 i(n,mr(t[i]-2?a[i]:AN(0,a[i])))u)
S I arf2(A2 f)_((SZ(V*)-8?fI:fL)(v2+1,10,(L)f)!=NL)
A eac2f(Ax,Ay,A2 f)_(Ik=2*xtt+ytt;P(k==3,f(x,y))
 P(xtm||ytm,P(xtm>ytm,Az=kv(&x);am(x,Nx(eac2f(z,y,f))))P(xtm<ytm,Az=kv(&y);am(y,Ny(eac2f(x,z,f))))
  Az=unq(cat(_R(xx),_R(yx)));x=ap1(x,zR);y=ap1(y,zR);I(arf2(f),Au=az(f==mul||f==dvd);x=fil(u,x);y=fil(u,y))am(z,Nz(eac2f(x,y,f))))
 P(!k&&xN-yN,el2(x,y))
 Nn=k<2?xN:yN;Az=f==mod?oB:oA;
 i(n,Au=f(get(x,i),get(y,i));B(!u,z=z(0))zq(u))
 x(y(z)))
S A nr(Ax,Ln,Ay/*0n1*/)_(      i(n,       y= N(app1(x,y)))   y )
S A ns(Ax,Ln,Ay/*0n1*/)_(Az=oC;i(n,zq(yR);y=Nz(app1(x,y)))zq(y))
S A3(wr,/*011*/           W(1,zR;A w=app1(y,z);B(!w,z=z(0))B(!tru(w))z=app1(x,z);Ny(z)              )y(z)   )
S A3(ws,/*011*/Au=enl(zR);W(1,zR;A w=app1(y,z);B(!w,u=u(0))B(!tru(w))z=app1(x,z);P(!z,y(u(0)))uq(zR))y(z(u)))
S A2(cr,/*01*/Az=yR,u;W(1,zR;u=app1(x,z);B(!u)P(mtc_(u,y)||mtc_(u,z),y(u(z)))z=z(u))y(z(u)))
S A2(cs,/*01*/Az=yR,v=yR,u=enl(y);W(1,z=yR;y=app1(x,y);P(!y,z(u(dex(v,0))))Im=mtc_(y,z)||mtc_(y,v);z(0);B(m)uq(yR))y(dex(v,u)))
S AX(lr,Ay=*a;P(n==1,cr(x,y))P(n==2,Yz(nr(x,gl(y),a[1]))wr(x,y,a[1]))ern(a,n))
S AX(ls,Ay=*a;P(n==1,cs(x,y))P(n==2,Yz(ns(x,gl(y),a[1]))ws(x,y,a[1]))ern(a,n))
A2(rdc1,/*10*/Lm=cfm(&x,1);P(m==-1,x)P(m<0,el1(x))P(!m,x(id_(y,x)))
 I(ytv&&yv&&yv<11&&xtZDC,XC(rdc1(cH(x),y))
  Ct=xt;V(f,arrT[t-tB][yv])P(f,Lv=gl(get(x,0));x2(f(&v,xV+xW,m-1));t-tD?az(v):ad(*(D*)&v)))
 Li=1;Az=get(x,0),b[2];W(i<m,*b=z;b[1]=get(x,i);z=app2(*b,b[1],y);B(!z)i++)x(z))
AX(rdc,P(n==1,rdc1(*a,x))n--;Ay=*a++,z=*a;Lm=cfm(a,n);
 P(m==-1,y?app(x,a-1,n+1):z)P(m<0,I(y,y(0))eln(a,n))P(!m&&!y,x=id_(x,z);mrn(n,a);x)
 Li=!y;I(i,y=get(z,0))Ab8;W(i<m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);B(!y)i++)mrn(n-1,a+1);z(y))
S AX scn;
S A2(scn1,/*10*/Xt(x)P(!xN,x)Xm(Az=kv(&x);am(x,Nx(scn1(z,y))))P(y==CAT,scn(y,A(oA,x),2))
 I(ytv&&yv&&yv<8&&xtZDC,I(xtC,x=N(cL(x)))V(f,arsT[xt-tB][yv])P(f,Au=ax(x);Mc(uV,xV,xW);f(xV,xV+xW,uV+xW,xN-1);u))
 Ni=0,n=xN;Az=get(x,0),u=enl(zR);W(++i<n,z=N(app2(z,get(x,i),y));uq(zR))z(x(u)))
S AX(scn,P(n==1,scn1(*a,x))I(n==2,Ay=a[1];Yt(app(x,a,n))Ym(y=mut(y);yy=scn(x,A(*a,yy),2);y)P(!yn,mr(*a),y))
 Ay=*a++;n--;Lm=cfm(a,n);P(m==-2,y(eln(a,n)))
 Az=oA,b[8];i(m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);P(!y,mrn(n,a);z(0))zq(yR))mrn(n,a);y(z))
S A3(eap2,/*110*/Ym(Au=kv(&y);am(y,Ny(eap2(x,u,z))))Yt(et2(x,y))P(!yN,x(y))P(ztv&&zv<11&&xtzc&&ytZC,arp[zv](x,y,z))
 Au=oA;i(yn,x=app2(get(y,i),x,z);P(!x,y(u(0)))uq(x);x=get(y,i))x(y(u)))
S A2(eap1,/*10*/eap2(id_(y,x),x,y))
SN A3(ste,/*110*/K("{z'x'y}",x,y,zR))
AX(w0, Xz(win(x,*a))XT(bin(xR,*a))                              eac(x,a,n))/* '  */
AX(w1,XzZ(dec(x,*a))Xc(jc(xv,*a))XC(jC(xV,xn,*a))xK<2?lr(x,a,n):rdc(x,a,n))/* /  */
AX(w2,XzZ(enc(x,*a))Xc(sc(xv,*a))XC(sC(xV,xn,*a))xK<2?ls(x,a,n):scn(x,a,n))/* \  */
AX(w3,n==1?eap1(*a,x):n==2?xK==1?ste(*a,a[1],x):eap2(*a,a[1],x):  ern(a,n))/* ': */
AX(w4,P(n==2,ear2(*a,a[1],x))                                     ern(a,n))/* /: */
AX(w5,P(n==2,eal2(*a,a[1],x))                                   eal(x,a,n))/* \: */
