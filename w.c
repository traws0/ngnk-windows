#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define AX2(f) AX2_(x,a,n,f)
S A AX2_(Ax,OA*a,In,A2*f)_(P(n>1,ern(n,a))f(xR,*a))
S A2(enc,x=Ny(gL(x));y=Nx(gL(y));Yt(Az=enc(x,enl(y));zn?fir(flp(z)):z(aL0))
 Xt(UL v=gl(x),r=0,m=0,b=1;i(yn,UL w=yl;Y(r<w,r=w))W(m<64&&b<=r,m++;b*=v)enc(rsh(az(m),az(v)),y))
 P(!xn,x(y(aA0)))Au=aA(xn);y=mut(y);Li=xn;W(--i>0,UL m=xl;m+=!m;Az=ua=aL(yn);i(yn,UL v=yl,w=yl=v/m;zl=v-w*m))
 UL m=gl(x);ux=y;Y(m,i(yn,yl%=m))u)
S A2(dec,K("{z+x*y}/[0;;]",x,y))S A2(bin,K("-1+/~>\\:",x,y))S A2(win,K("{y(!x)+/:!0|1-x-#y}",x,y))
A2(spl,Q(xtcC);Et(!ytC,x,y)C*s=xtc?(V*)&x:xC;Lm=xN;El(!m,x,y)Au=aA0;C*p=yC,*q=p,*t=p+yn,*r=t+1-xN;
 W(q<r,Y(mC(s,q,m),q++)E(uq(aCm(p,q));p=q+=m))Y(!xtc||gi(x)-10||p<t,uq(aCm(p,t)))x(y(u)))
A2(join,Q(xtcC);Et(!ytA,x,y)Nm=xN,n=yn,l=m*(n-!!n);i(n,Az=ya;Et(!ztcC,x,y)l+=zN)Au=aC(l);C*s=xtc?(V*)&x:xC,*p=uC;
 i(n,Y(i,mc(p,s,m);p+=m)Az=ya;Y(ztc,*p++=gi(z))E(mc(p,zC,zn);p+=zn))x(y(u)))
S L cfm(OA*a/*0*/,In)_(Lm=-1;i(n,Ax=a[i];Y(!xtt,N l=xN;P(m>=0&&m-l,-2)m=l))m)
S AX(eacm,Az=aS0,b[8];i(n,Ay=a[i];Y(ytm,z=cat(z,mR(yx))))z=unq(z);
 i(n,Ay=b[i]=a[i];Y(ytm,A u=kv(&y);uq(id_(x,u));b[i]=ap1(u,fil(ai(An(y)),fnd(y,zR)))))Au=eac(x,b,n);u?am(z,u):z(u))
AX(eac,Xz(AX2(win))P(xtT&&!xtA,n>1?ern(n,a):bin(xR,*a))A b[8];Ct[8];Lm=-1;
 i(n,Ay=b[i]=a[i];Ym(eacm(x,a,n))t[i]=ytP?0:ytt?1:ytA?2+(yr>1):4;Y(t[i]>1,L l=yN;P(m>=0&&m-l,eln(n,a))m=l))
 P(m<0,app(x,a,n))i(n,Y(t[i]==1,rfc(a[i])+=m)) //0:pkdatm,1:refatm,2:tA(r=1),3:tA,4:other
 Au=0;Y(!m,Y(x==cu('#'),u=aL0)EY(n==2&&xtv&&xv<11,u=a[!_N(a[1])];uR)E(u=aA0))
 j(m,i(n,Ay=a[i];Y(t[i]==2,b[i]=yA[j])Y(t[i]>2,b[i]=get(y,j)))Az=app(x,b,n);
     Y(!z,Y(u,u(0))i(n,Ay=a[i];Y(t[i]==1,yr-=m-j-1)Y(t[i]==2,mrn(m-j-1,yA+j+1)))BR)
     Y(!j,u=c3(tc,zt,ts)?AN(0,atn(tT(zt),m)):aA0)uq(z))
 i(n,mr(t[i]-2?a[i]:AN(0,a[i])))u)
A eac1(A1 f,Ax)_(Xt(f(x))Xm(x=mut(x);xy=eac1(f,xy);P(!xy,xy=au0;x(0))x)I b=xtA&&xr==1;Nn=xN;P(!n,x)Au=aA0;
 i(n,Ay=f(b?xa:get(x,i));Y(!y,Y(b,mrn(xn-i-1,xA+i+1))u=u(0);BR)uq(y))Y(b,x=AN(0,x))x(u))
AX(ear,XzZ(rdc(x,a,n))P(n-2,ern(n,a))x=prj(x,A(*a,PLH  ),n);x(eac(x,a+1,1)))
AX(eal,XzZ(scn(x,a,n))P(n-2,ern(n,a))x=prj(x,A(PLH,a[1]),n);x(eac(x,a  ,1)))
S AX(cvg,P(n==1,Ay=*a,z=yR,u;W(1,zR;u=N2(y,z,app(x,&z,1));P(mtc_(u,y)||mtc_(u,z),y(u(z)))z=z(u))y(z(u)))
 P(n==2,Ay=*a,u=a[1];Yz(i(gl(y),u=N(app(x,&u,1)))u)W(1,uR;Az=N2(y,u,app(y,&u,1));Y(!tru(z),BR)u=Ny(app(x,&u,1)))y(u))
 ern(n,a))
S AX(cvi,P(n>2,ern(n,a))Ay,z,u;Y(n==1,y=0;z=*a)E(y=*a;z=a[1])
 P(!y,A v=y=zR;u=enl(yR);W(1,z=yR;y=app(x,&y,1);P(!y,z(u(dex(v,0))))Im=mtc_(y,z)||mtc_(y,v);z(0);Y(m,BR)uq(yR))y(dex(v,u)))
 Yz(u=enl(zR);i(gl(y),z=Nu(app(x,&z,1));uq(zR))z(u))
 u=enl(zR);W(1,zR;A w=app(y,&z,1);P(!w,y(z(u(0))))Y(!tru(w),BR)z=app(x,&z,1);P(!z,y(u(0)))uq(zR))y(z(u)))
AX(rdc,XzZ(AX2(dec))XcC(AX2(join))P(xk<2,cvg(x,a,n))
 Ay=n>1?n--,*a++:0,z=*a;Lm=cfm(a,n);P(m==-1,y?app(x,a-1,n+1):*a)P(m<0,Y(y,y(0))eln(n,a))P(!m&&!y,Au=id_(x,z);mrn(n,a);u)
 P(n==1&&xtv&&xv<8&&(!y||ytt)&&c3(tC,zt,tD),Y(ztC,z=gH(z))Y(y&&(ytd||ztD),y=gD(y);z=gD(z))Ct=zt;
  Lv=gl(y?y:get(z,0));m2(z,((int(*)(V*,V*,N))arr[t-tB][xv])(&v,zC+ZT[t]*!y,m-!y));t==tD?atnv(td,1,&v):az(v))
 Li=!y;Y(i,y=get(z,0))A b[8];W(i<m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);Y(!y,BR)i++)mrn(n,a);y)
AX(scn,XzZ(AX2(enc))XcC(AX2(spl))P(xk<2,cvi(x,a,n))
 P(n==1,Az=a[n-1];P(ztt||!zn,z)P(ztm,Ay=kv(&z);y=Nz(scn(x,&y,1));am(z,y))P(x==cv(','),scn(x,A(aA0,z),2))
  P(xtv&&xv<8&&c3(tC,zt,tD)/*todo*/&&(xv-1&&xv-3||ztL||ztD),Y(ztC,z=N(gL(z)))
   I w=ZT[zt];Au=ax(z);mc(uC,zC,w);((int(*)(V*,V*,V*,N))ars[zt-tB][xv])(zC,zC+w,uC+w,zn-1);u)
  Ay=get(z,0),u=enl(yR);Li=0,n=zn;W(++i<n,y=N(app(x,A(y,get(z,i)),2));uq(yR))y(z(u)))
 Y(n==2,Au=a[1];P(utt,app(x,a,n))P(utm,u=mut(u);uy=scn(x,A(*a,uy),2);u)P(!un,mr(*a),u))
 Ay=*a++;n--;Lm=cfm(a,n);P(m==-2,y(eln(n,a)))Au=aA0,b[8];
 i(m,*b=y;j(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);P(!y,mrn(n,a);u(0))uq(yR))mrn(n,a);y(u))
AX(eap,XzZ(eac(x,a,n))P(n>2,ern(n,a))Az=a[n-1],y=n-1?*a:zt-tS?id_(x,*a):as(0);Et(!ztT,y,z)P(!zn,y(z))
 P(xtv&&xv<11&&c3(tc,yt,td)&&c3(tC,zt,tD)/*todo*/&&(xv-1&&xv-3||ztL||ztD),
  Y(ytz,y=az(gl(y)))N(sup(&y,&z));Lv=gl(y);Au=ax(z);((int(*)(V*,V*,V*,N))arp[zt-tB][xv])(&v,zC,uC,zn);u)
 Au=aA0;i(zn,y=app(x,A(get(z,i),y),2);P(!y,z(u(0)))uq(y);y=get(z,i))y(z(u)))
