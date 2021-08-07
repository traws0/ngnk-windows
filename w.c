#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
S A2(enc,x=Ny(gL(x));y=Nx(gL(y));Yt(Az=enc(x,enl(y));zn?fir(flp(z)):z(oL))
 Xt(UL v=gl(x),r=0,m=0,b=1;i(yn,UL w=yl;Y(r<w,r=w))W(m<64&&b<=r,m++;b*=v)enc(rshL(m,az(v)),y))
 P(!xn,x(y(oA)))Au=aA(xn);y=mut(y);Li=xn;W(--i>0,UL m=xl;m+=!m;Az=ua=aL(yn);i(yn,UL v=yl,w=yl=v/m;zl=v-w*m))
 UL m=gl(x);ux=y;Y(m,i(yn,yl%=m))u)
S A2(dec,K("{z+x*y}/[0;;]",x,y))S A2(win,K("{y(!x)+/:!0|1-x-#y}",x,y))
A splcC(Cc    ,C*p,Ln)_(      Ax=oA;C*q;W((q=MC(p,c,n  )),xq(aCm(p,q));n-=q-p+1;p=q+1)Y(c-10||n,xq(aCn(p,n)))x)
A splCC(C*s,Lm,C*p,Ln)_(El(!m)Ax=oA;C*q;W((q=MM(p,n,s,m)),xq(aCm(p,q));n-=q+m-p;p=q+m)xq(aCn(p,n)))
A splc(Cc    ,Ax)_(XC(x(splcC(c,  xC,xn)))et1(x))
A splC(C*s,Lm,Ax)_(XC(x(splCC(s,m,xC,xn)))et1(x))
NI L jn(Lm,Ax/*0*/)_(P(!xtA,-1)Ln=(xn-!!xn)*m;i(xn,Ay=xa;P(!ytcC,-1)n+=yN)n)//total length or -1
A jc(Cc,   Ax)_(Ln=jn(1,x);Et(n<0,x)Ay=aC(n);C*p=yC;i(xn,Y(i,*p++=c        )Az=xa;Y(ztc,*p++=zv)E(Mc(p,zC,zn);p+=zn))x(y))
A jC(Qs,Nm,Ax)_(Ln=jn(m,x);Et(n<0,x)Ay=aC(n);C*p=yC;i(xn,Y(i,Mc(p,s,m);p+=m)Az=xa;Y(ztc,*p++=zv)E(Mc(p,zC,zn);p+=zn))x(y))
S L cfm(OA*a/*0*/,In)_(Lm=-1;i(n,Ax=a[i];Y(!xtt,Lv=xN;P(m>=0&&m-v,-2)m=v))m)
S AX(eacm,Az=oS,b[8];i(n,Ay=a[i];Y(ytm,z=cat(z,_R(yx))))z=unq(z);
 i(n,Ay=b[i]=a[i];Y(ytm,Au=kv(&y);uq(id_(x,u));b[i]=ap1(u,fil(ai(yn),fnd(y,zR)))))Au=eac(x,b,n);u?am(z,u):z(u))
AX(eac,A b[8];Ct[8];Lm=-1;
 i(n,Ay=b[i]=a[i];Ym(eacm(x,a,n))t[i]=ytP?0:ytt?1:ytA?2+(yr>1):4;Y(t[i]>1,L l=yN;P(m>=0&&m-l,eln(n,a))m=l))
 P(m<0,app(x,a,n))i(n,Y(t[i]==1,_r(a[i])+=m)) //0:pkdatm,1:refatm,2:tA(r=1),3:tA,4:other
 Au=0;Y(!m,Y(x==cu('#'),u=oL)EY(n==2&&xtv&&xv<11,u=a[!_N(a[1])];uR)E(u=oA))
 j(m,i(n,Ay=a[i];Y(t[i]==2,b[i]=yA[j])Y(t[i]>2,b[i]=get(y,j)))Az=app(x,b,n);
     B(!z,Y(u,u=u(0))i(n,Ay=a[i];Y(t[i]==1,yr-=m-j-1)Y(t[i]==2,mrn(m-j-1,yA+j+1))))
     Y(!j,u=c3(ti,zt,ts)?AN(0,atn(tT(zt),m)):oA)uq(z))
 i(n,mr(t[i]-2?a[i]:AN(0,a[i])))u)
A eac1(Ax,A1 f)_(Xt(f(x))Xm(Ay=kv(&x);am(x,Nx(eac1(y,f))))
 I b=xtA&&xr==1;Nn=xN;P(!n,x)Ay=oA;i(n,Az=f(b?xa:get(x,i));B(!z,Y(b,mrn(xn-i-1,xA+i+1))y=y(0))yq(z))Y(b,x=AN(0,x))x(y))
A3(eac2,/*110*/eac(z,A(x,y),2))
AX(ear,P(n-2,ern(n,a))x=prj(x,A(*a,PLH  ),n);x(eac(x,a+1,1)))
AX(eal,P(n-2,ern(n,a))x=prj(x,A(PLH,a[1]),n);x(eac(x,a  ,1)))
S AX(cvg,P(n==1,Ay=*a,z=yR,u;W(1,zR;u=N2(y,z,app(x,&z,1));P(mtc_(u,y)||mtc_(u,z),y(u(z)))z=z(u))y(z(u)))
 P(n==2,Ay=*a,u=a[1];Yz(i(gl(y),u=N(app(x,&u,1)))u)W(1,uR;Az=N2(y,u,app(y,&u,1));B(!tru(z))u=Ny(app(x,&u,1)))y(u))
 ern(n,a))
S AX(cvi,P(n>2,ern(n,a))Ay,z,u;Y(n==1,y=0;z=*a)E(y=*a;z=a[1])
 P(!y,A v=y=zR;u=enl(yR);W(1,z=yR;y=app(x,&y,1);P(!y,z(u(dex(v,0))))Im=mtc_(y,z)||mtc_(y,v);z(0);B(m)uq(yR))y(dex(v,u)))
 Yz(u=enl(zR);i(gl(y),z=Nu(app(x,&z,1));uq(zR))z(u))
 u=enl(zR);W(1,zR;A w=app(y,&z,1);P(!w,y(z(u(0))))B(!tru(w))z=app(x,&z,1);P(!z,y(u(0)))uq(zR))y(z(u)))
AX(rdc,
 Ay=n>1?n--,*a++:0,z=*a;Lm=cfm(a,n);P(m==-1,y?app(x,a-1,n+1):*a)P(m<0,Y(y,y(0))eln(n,a))P(!m&&!y,Au=id_(x,z);mrn(n,a);u)
 Y(n==1&&xtv&&xv<8&&(!y||ytt)&&ztZDC,Y(ztC,z=gH(z))Y(y&&(ytd||ztD),y=gD(y);z=gD(z))Ct=zt;
  int(*f)(V*,V*,N)=arrT[t-tB][xv];P(f,Lv=gl(y?y:get(z,0));z2(f(&v,zC+ZT[t]*!y,m-!y));t==tD?atnv(td,1,&v):az(v)))
 Li=!y;Y(i,y=get(z,0))A b[8];W(i<m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);B(!y)i++)mrn(n-1,a+1);z(y))
AX(scn,
 P(n==1,Az=a[n-1];P(ztt||!zN,z)P(ztm,Ay=kv(&z);y=Nz(scn(x,&y,1));am(z,y))P(x==cv(','),scn(x,A(oA,z),2))
  Y(xtv&&xv&&xv<8&&ztZDC/*todo*/&&(xv-1&&xv-2&&xv-3||ztL||ztD),Y(ztC,z=N(gL(z)))
   int(*f)(V*,V*,V*,N)=arsT[zt-tB][xv];P(f,I w=ZT[zt];Au=ax(z);Mc(uC,zC,w);f(zC,zC+w,uC+w,zN-1);u))
  Ay=get(z,0),u=enl(yR);Li=0,n=zN;W(++i<n,y=N(app(x,A(y,get(z,i)),2));uq(yR))y(z(u)))
 Y(n==2,Au=a[1];P(utt,app(x,a,n))P(utm,u=mut(u);uy=scn(x,A(*a,uy),2);u)P(!un,mr(*a),u))
 Ay=*a++;n--;Lm=cfm(a,n);P(m==-2,y(eln(n,a)))Au=oA,b[8];
 i(m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);P(!y,mrn(n,a);u(0))uq(yR))mrn(n,a);y(u))
AX(eap,P(n>2,ern(n,a))Az=a[n-1],y=n-1?*a:zt-tS?id_(x,*a):as(0);Et(!ztT,y,z)P(!zn,y(z))
 Y(xtv&&xv<11&&ytZC&&ztZC/*todo*/&&(xv-1&&xv-2&&xv-3||ztL),Y(ytz,y=az(gl(y)))N(sup(&y,&z));Lv=gl(y);
  int(*f)(V*,V*,V*,N)=arpT[zt-tB][xv];P(f,Au=ax(z);f(&v,zC,uC,zn);u))
 Au=oA;i(zn,y=app(x,A(get(z,i),y),2);P(!y,z(u(0)))uq(y);y=get(z,i))y(z(u)))
AX(w0,Y(n==1, Xz(win(xR,*a)))P(xtT&&!xtA,n>1?ern(n,a):bin(xR,*a))eac(x,a,n))                   /* '  */
AX(w1,Y(n==1,XzZ(dec(xR,*a))Xc(  jc(xv,*a))XC(  jC(xC,xn,*a)))P(np(x)<2,cvg(x,a,n))rdc(x,a,n)) /* /  */
AX(w2,Y(n==1,XzZ(enc(xR,*a))Xc(splc(xv,*a))XC(splC(xC,xn,*a)))P(np(x)<2,cvi(x,a,n))scn(x,a,n)) /* \  */
AX(w3,XzZ(w0(x,a,n))eap(x,a,n))                                                                /* ': */
AX(w4,XzZ(w1(x,a,n))ear(x,a,n))                                                                /* /: */
AX(w5,XzZ(w2(x,a,n))eal(x,a,n))                                                                /* \: */
