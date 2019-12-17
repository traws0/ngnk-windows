#include"k.h" // ngn/k, (c) ngn 2019, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S O I mxl=16,mxg=16,mxc=128;enum{bu,bv=0x20,bg=0x40,bs=0x50,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br,bc=0x80,bC=0xff};S A2 rhs;
#define h(b)({xy=apc(xy,(C)(b));xa[4]=apc(xa[4],o);})
#define hc(v)({I b=bc+fndpa(xa+5,v);P(b>bC,err("mxc",x))h(b);})
#define hr(y)({x=N(rhs(x,y));})
S A3(lhs/*x1y0z0*/,asrt(Ar(x)==1);UH o=pkd(y)&&!yts?0:Ao(y);
 P(zts&&yx==cv0&&Ak(x),L i=fndpl(xa+2,gs(z));i<mxl?h(bs|i),x:err("mxl",x))
 P(ztS&&!Av(yx),hc(cv0);hc(cu0);hc(zR);hc(cV('.'));h(ba);h(4);x)
 P(zts||(ztX&&At(zx)==ts),$(zts,hc(aX(0)))E(F(zn-1,hr(za[zn-1-i]))h(bl);h(zn-1))
  L k=gs(zts?z:zx),i=fndl(xa[2],k);$(i>=0,h(bm);h(i))E(i=fndpl(xa+3,k);P(i>=mxg,err("mxg",x))h(bM);h(i))h(Av(yx));x)
 P(ztX&&zx==cv_mkl,h(bL);h(zn-1);F(zn-1,x=N(lhs(x,y,za[i+1]));h(bp))x)en();eso(fir(x),o);0)
S A2(rhs/*x1y0*/,asrt(Ar(x)==1);UH o=pkd(y)&&!yts?0:Ao(y);$(yts,P(gs(y)==4,h(bo);x)L i=fndl(xa[2],gs(y));P(i>=0,h(bg|i);x))P(ytS&&yn==1,hc(as(*yl));x)
 P(ytsS,hc(yR);h(bu|vi('.'));x)P(!ytX,hc(y==cv_plc?cu0:yR);x)L n=yn;P(!n,hc(yR);x)A u=yx;P(utS&&n==1,hc(uR);x)P((utu||u==cv0)&&n==3,hr(ya[2]);lhs(x,y,yy))
 P(u==cV('$')&&n>3,UC d[n];A*a=ya+1;n--;F(n&~1,hr(a[i]);h(i&1?bj:bz);d[i]=An(xy);h(0))hr(n&1?a[n-1]:cu0);A z=xy;F(n&~1,zc[d[i]]=(i&1?zn:d[i+1])-d[i])x)
 $(u==cU('*')&&n==2,A z=yy;P(ztX&&zn==2&&zx==cU('|'),hr(zy);h(bu|29);x))$(utw&&n==2,A z=yy;P(!ztX&&!zts&&!ztS,zR;hc(app(u,&z,1));x))
 I p=0;F(n-1,A z=ya[n-1-i];$(z==cv_plc,p=1;hc(zR))E(hr(z)))P(p,hr(yx);h(bP);h(n-1);x)P(u==cv0&&n==2,h(br);x)P(u==cv_mkl,h(bl);h(n-1);x)
 P(utu&&n==2,h(bu|Av(u));x)P(utv&&n==3,h(bv|Av(u));x)hr(yx);h(ba);h(n-1);x)
A1(cpl,UC k=Ak(x);x=mut(x);A y=xy;xy=aC(0);xa[3]=aS(0);xa[4]=aC(1);xa[5]=a1(cu0);C o=0;F(yn,x=Ny(rhs(x,yai));h(i==yn-1?br:bp))yr;AK(k,AT(to,x))) //sblgmc
S A sp0[0x10000],*sp=sp0+ZZ(sp0);S A*loc;S C*pc;
S A1(vm_/*x0*/,W(1,UC b=*pc++;$(b<0x20,N(*sp=((A1*)cf[b])(*sp)))E$(b<0x40,sp++;N(*sp=((A2*)cf[b])(sp[-1],*sp)))
 E$(b<0x50,A*p=loc-(b&(mxl-1));*--sp=mR(*p))E$(b<0x60,A*p=loc-(b&(mxl-1));mr(*p);*p=mR(*sp))E$(b>=bc,*--sp=mR(A(xa[5])[b&(mxc-1)]))
 E$(b==bm,A*p=loc-*pc;          sp++;*p =N(dm1(A_(*p,mR(sp[-1]),cv(pc[1]),*sp),4));*sp=N(ap2(mR(*p),sp[-1]));pc+=2)
 E$(b==bM,A y=as(L(xa[3])[*pc]);sp++;A h=N(dmd(A_(y ,mR(sp[-1]),cv(pc[1]),*sp),4));*sp=N(ap2(    h ,sp[-1]));pc+=2)
 E$(b==bl,UC n=*pc++;A x=sqz(atnv(tX,n,sp));sp+=n-1;*sp=x)E$(b==bL,UC n=*pc++;A x=*sp;P(!xtt&&len_(x)-n,el())F(n,*--sp=get(x,n-1-i)))
 E$(b==ba||b==bP,L n=*pc++;A u=sp[n]=(b==ba?app:prj)(*sp,sp+1,n);mr(*sp);sp+=n;N(u))
 E$(b==bz,pc+=1+*pc*!tru(*sp++))E$(b==bj,pc+=*pc)E$(b==bo,*--sp=mR(loc[1]))E$(b==bp,mr(*sp++))E$(b==br,R*sp)E(UR))0)
AX(run,asrt(xto);asrt(n==Ak(x));xR;L m=An(xa[2]);P(sp<sp0+m+3,errn("stk",n,a))*--sp=(A)(V*)pc;*--sp=(A)(V*)loc;*--sp=x;pc=C(xy);loc=sp-1;
 F(n,*--sp=a[i])F(m-n,*--sp=cu0)A u=vm_(x);$(!u,eso(mR(xx),C(xa[4])[pc-C(xy)]);W(sp<loc-m,$(*sp,mr(*sp))sp++))
 asrt(sp==loc-m);A*p=loc+1;W(p>sp,mr(*p--))sp=loc+4;pc=(C*)sp[-1];loc=(V*)sp[-2];u)
