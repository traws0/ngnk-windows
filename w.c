#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S AX(enc,P(!xtiIlL,etn(n,a));P(n>1,ern(n,a))A y=N(gL(*a));P(sim(y),A z=enc(x,A_(enl(y)),1);zn?fir(flp(z)):dex(z,aL(0)))
 P(sim(x),UL v=gl_(x),r=0,m=0,b=1;F(yn,UL w=yli;$(r<w,r=w))W(m<64&&b<=r,m++;b*=v)x=aL(m);F(m,xli=v)dex(x,enc(x,&y,1)))
 P(!xn,yr;a0())A u=aX(xn);y=mut(y);for(L i=xn-1;i>0;i--){UL m=xli;m+=!m;A z=uai=aL(yn);Fj(yn,UL v=ylj,w=ylj=v/m;zlj=v-w*m)}
 UL m=*xl;ux=y;$(m,Fj(yn,ylj%=m))u)
S AX(dec,n>1?ern(n,a):K("{z+x*y}/[0;;]",xR,*a))
S AX(spl,asrt(xtcC);P(n>1,ern(n,a))A y=*a;P(!ytC,et(y))C*s=xtc?(V*)&x:xc;L l=len_(x);P(!l,el(y))A u=a0();C*p=yc,*q=yc,*q2=yc+yn,*q1=q2+1-len_(x);
 W(q<q1,C m=1;F(l,m&=s[i]==q[i])$(m,u=apd(u,aCm(p,q));p=q+=l)E(q++))$(x-ac(10)||p<q2,u=apd(u,aCm(p,q2)))yr;u)
S AX(join,asrt(xtcC);P(n>1,ern(n,a))A y=*a;P(!ytX,et(y))C*s=xtc?(V*)&x:xc;L m=len_(x),k=yn,l=m*(k-!!k);F(k,A z=yai;P(!ztcC,et(y))l+=len_(z))
 A u=aC(l);C*p=uc;F(k-1,A z=yai;$(ztc,*p++=gc(z))E(mc(p,zc,zn);p+=zn)mc(p,s,m);p+=m)$(k,A z=ya[k-1];$(ztc,*p=gc(z))E(mc(p,zc,zn)))yr;u)
A ea1(A1 f,A x)_(P(xtt,f(x))P(xta,x=mut(x);xy=ea1(f,xy);P(!xy,xy=cu0;xr;0)x)
 I b=xtX&&Ar(x)==1;L n=len_(x);P(!n,x)A u=a0();F(n,A y=f(b?xai:get(x,i));$(!y,$(b,mrn(xn-i-1,xa+i+1))xr;ur;u=0;B)u=apd(u,y))$(b,x=AN(0,x))xr;u)
S AX(sld,P(n>1,ern(n,a))L k=gl_(x);x=*a;P(!xtT,et(x))P(k<=0,ed(x))A u=aX(max(0,xn-k+1));
 $(xtX&&un,I l=min(k,xn-k+1);F(xn,A y=xai;$(!pkd(y),Ar(y)+=min(l,min(1+i,xn-i)))))L w=tZ(xt);F(un,uai=sqz(atnv(xt,k,xc+i*w)))xr;u)
S L cfm(O A*a/*0*/,L n)_(L m=-1;F(n,A x=a[i];$(!xtt,L l=len_(x);P(m>=0&&m-l,-2)m=l))m)
S AX(eaca,A z,b[8];F(n,A y=a[i];$(yta,z=yx;B))zR;F(n,A y=b[i]=a[i];$(yta,P(!mtc_(z,yx),zr,edn(n,b))b[i]=val(y)))A u=eac(x,b,n);(u?aa:dex)(z,u))
AX(eac,P(xtil,sld(x,a,n)) //0:pkdatm,1:refatm,2:tX(r=1),3:tX(r>1),4:other
 A b[8];C t[8];L m=-1;F(n,A y=a[i];P(yta,eaca(x,a,n))t[i]=pkd(y)?0:ytt?1:ytX?2+(Ar(y)>1):4;$(t[i]>1,L l=len_(y);P(m>=0&&m-l,eln(n,a))m=l))
 P(m<0,app(x,a,n))
 F(n,A y=b[i]=a[i];$(t[i]==1,Ar(y)+=m))
 A u=a0();L j=0;
 W(j<m,F(n,A y=a[i];$(t[i]==2,b[i]=yaj)$(t[i]>2,b[i]=get(y,j)))
       A z=app(x,b,n);$(!z,ur;u=0;F(n,A y=a[i];$(t[i]==1,Ar(y)-=m-j-1)$(t[i]==2,mrn(m-j-1,ya+j+1)))B)u=apd(u,z);j++)
 F(n,mr(t[i]-2?a[i]:AN(0,a[i])))u)
S AX(cvg,P(n==2,A y=*a,u=a[1];P(ytil,F(gl(y),u=N(app(x,&u,1)))u)W(1,uR;A z=N2(y,u,app(y,&u,1));$(!tru(z),B)u=Ny(app(x,&u,1)))yr;u)
 P(n==1,A y=*a,z=yR,u;W(1,zR;u=N2(y,z,app(x,&z,1));$(mtc_(u,y)||mtc_(u,z),B)zr;z=u)yr;zr;u)ern(n,a))
AX(rdc,P(xtiIlL,dec(x,a,n))P(xtcC,join(x,a,n))P(Ak(x)<=1,cvg(x,a,n))
 A y=n>1?n--,*a++:0,z=*a;L m=cfm(a,n);P(m==-1,y?app(x,a-1,n+1):*a)P(m<0,$(y,yr)eln(n,a))P(!m&&!y,A u=id_(x,z);mrn(n,a);u)
 $(ari(x)&&(!y||ytt)&&n==1,$(ztC,z=gL(z);P(!z,$(y,yr);0))$(y&&ytdD||ztdD,$(y,y=gD(y))z=gD(z))
  P(ztI,I*p=zi,a=!y?m--,*p++:gi(y);zr;arI(Av(x),m,I b=p[i];a=)ai(a))
  P(ztL,L*p=zl,a=!y?m--,*p++:gl(y);zr;arL(Av(x),m,L b=p[i];a=)al(a))
  P(ztD,D*p=zd,a=!y?m--,*p++:gd(y);zr;arD(Av(x),m,D b=p[i];a=)ad(a)))
 L i=!y;$(i,y=get(z,0))A b[8];W(i<m,*b=y;Fj(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);$(!y,B)i++)mrn(n,a);y)
S AX(cvi,A y,z,u;$(n==1,y=0;z=*a)E$(n==2,y=*a;z=a[1])E(R ern(n,a))
 P(!y,A y0=y=zR;u=enl(yR);W(1,z=yR;y=app(x,&y,1);P(!y,zr;ur;mr(y0);0)I m=mtc_(y,z)||mtc_(y,y0);zr;$(m,B)u=apd(u,yR))mr(y0);yr;u)
 P(ytil,u=enl(zR);F(gl(y),z=Nu(app(x,&z,1));u=apd(u,zR))zr;u)
 u=enl(zR);W(1,zR;A w=app(y,&z,1);P(!w,yr;zr;ur;0)$(!tru(w),B)z=app(x,&z,1);P(!z,yr;ur;0)u=apd(u,zR))yr;zr;u)
AX(scn,P(xtiIlL,enc(x,a,n))P(xtcC,spl(x,a,n))P(Ak(x)<=1,cvi(x,a,n))
 P(n==1,A z=*a;P(ztt||!zn,z)P(zta,z=mut(z);zy=scn(x,&zy,1);z)P(x==cV(','),scn(x,A_(a0(),z),2))
  $(ari(x),L n=zn-1,f=Av(x);P(ztL||ztC,A u=ax(N(gL(z)));L a=*ul=*zl;arL(f,n,L b=zl[i+1];ul[i+1]=a=)u)
                            P(ztI,     A u=ax(z);       I a=*ui=*zi;arI(f,n,I b=zi[i+1];ui[i+1]=a=)u)
                            P(ztD,     A u=ax(z);       D a=*ud=*zd;arD(f,n,D b=zd[i+1];ud[i+1]=a=)u))
  A y=get(z,0),u=enl(yR);L i=0,n=zn;W(++i<n,y=N(app(x,A_(y,get(z,i)),2));u=apd(u,yR))yr;zr;u)
 $(n==2,A u=a[1];P(uta,u=mut(u);uy=scn(x,A_(*a,uy),2);u)P(!un,mr(*a),u))
 A y=*a++;n--;L m=cfm(a,n);P(m==-2,yr;eln(n,a))A u=a0(),b[8];
 F(m,*b=y;Fj(n,b[j+1]=get(a[j],i))y=app(x,b,n+1);P(!y,mrn(n,a);ur;0)u=apd(u,yR))mrn(n,a);yr;u)
AX(eap,P(n>2,ern(n,a))A y=n==1?id_(x,*a):*a,z=a[n-1];P(!ztT,et(y,z))P(!zn,yr;z)
 $(ari(x),L f=Av(x),n=zn;P(yti&&(ztI||ztC) ,I a=gi(gI(y));z=N(gI(z));A u=ax(z);arI(f,n,I b=a;a=zii;uii=)u)
                         P(ytil&&(ztL||ztC),L a=gl(gL(y));z=N(gL(z));A u=ax(z);arL(f,n,L b=a;a=zli;uli=)u)
                         P(yt==tdx||ztD    ,D a=gd(gD(y));z=N(gD(z));A u=ax(z);arD(f,n,D b=a;a=zdi;udi=)u))
 A u=a0();F(zn,y=app(x,A_(get(z,i),y),2);P(!y,zr;ur;0)u=apd(u,y);y=get(z,i))yr;zr;u)
AX(ear,P(n==1,dec(x,a,n))P(n-2,enn(n,a))x=prj(x,A_(*a,cv_plc  ),n);dex(x,eac(x,a+1,1)))
AX(eal,P(n==1,enc(x,a,n))P(n-2,enn(n,a))x=prj(x,A_(cv_plc,a[1]),n);dex(x,eac(x,a  ,1)))
