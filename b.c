#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S O I mxl=16,mxc=128;enum{bu,bv=0x20,bg=0x40,bs=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br,bc=0x80,bC=0xff};S A f;S I lu[16],rhs(A);
#define fs A(f)[0] //src
#define fb A(f)[1] //bytecode
#define fl A(f)[2] //local symbols
#define fm A(f)[3] //srcmap
#define fc A(f)[4] //constants
#define h(b)({fb=apc(fb,(C)(b));fm=apc(fm,o);}) //add byte
#define hc(x)({I b=bc+fndpa(&fc,x);P(b>bC,err("mxc"))h(b);}) //add a "load constant" instruction
S I lhs(A x/*0*/,A y/*0*/)_(UH o=Ao(x);P(yts&&xx==cv0&&Ak(f),L i=fndpl(&fl,gs(y));i<mxl?(lu[i]=An(fb)),h(bs|i),1:err("mxl"))
 P(ytS&&!Av(xx),hc(cv0);hc(cu0);hc(yR);hc(cV('.'));h(ba);h(4);1)
 P(yts||(ytX&&At(yx)==ts),$(yts,hc(a0()))E(F(yn-1,N(rhs(ya[yn-1-i])))h(bl);h(yn-1))
  L k=gs(yts?y:yx),i=fndl(fl,k);$(i>=0,lu[i]=An(fb);h(bm);h(i))E(hc(as(k));h(bM))h(Av(xx));1)
 P(ytX&&yx==cv_mkl,h(bL);h(yn-1);F(yn-1,N(lhs(x,ya[i+1]));h(bp))1)en();eso(mR(fs),o);0)
S I rhs(A x/*0*/)_(UH o=Ao(x);$(xts,P(gs(x)==4,h(bo);1)L i=fndl(fl,gs(x));P(i>=0,lu[i]=An(fb);h(bg|i);1))P(xtS&&xn==1,hc(as(*xl));1)
 P(xtsS,hc(xR);h(bu|vi('.'));1)P(!xtX,hc(x==cv_plc?cu0:xR);1)L n=xn;P(!n,hc(xR);1)A u=xx;P(utS&&n==1,hc(uR);1)
 P((utu||u==cv0)&&n==3,N(rhs(xa[2]));N(lhs(x,xy)))
 P(u==cV('$')&&n>3,UC d[n];A*a=xa+1;n--;F(n&~1,N(rhs(a[i]));h(i&1?bj:bz);d[i]=An(fb);h(0))N(rhs(n&1?a[n-1]:cu0));
                   A z=fb;F(n&~1,zc[d[i]]=(i&1?zn:d[i+1])-d[i])1)
 $(u==cU('*')&&n==2,A z=xy;P(ztX&&zn==2&&zx==cU('|'),N(rhs(zy));h(bu|29);1))$(utw&&n==2,A z=xy;P(!ztX&&!zts&&!ztS,zR;hc(app(u,&z,1));1))
 I p=0;F(n-1,A z=xa[n-1-i];$(z==cv_plc,p=1;hc(zR))E(N(rhs(z))))P(p,N(rhs(xx));h(bP);h(n-1);1)P(u==cv0&&n==2,h(br);1)P(u==cv_mkl,h(bl);h(n-1);1)
 P(utu&&n==2,h(bu|Av(u));1)P(utv&&n==3,h(bv|Av(u));1)N(rhs(xx));h(ba);h(n-1);1)
A1(cpl,UC k=Ak(x);f=x=mut(x);A y=fb;fb=fm=mR(aC(0));fc=a1(cu0);C o=0;F(16,lu[i]=-1)F(yn,P(!rhs(yai),xr;yr;0)h(i==yn-1?br:bp))yr;
 y=fb;F(16,I j=lu[i];$(ycj==bg,asrt(Ar(y)==1);ycj=bd))AK(k,AT(to,x)))
S A sp0[0x10000],*sp=sp0+ZZ(sp0),*loc;S C*pc;
S A1(vm_/*x0*/,W(1,UC b=*pc++;$(b>=bc,*--sp=mR(A(xa[4])[b&(mxc-1)]))
 E$(b>=bm,$(b==bm,A*p=loc-*pc++;A y=*sp++;*sp=N(ap2(mR(*p=Ny(dm1(A_(*p,yR,cv(*pc++),*sp),4))),y)))
         E$(b==bM,A x=*sp++;    A y=*sp++;*sp=N(ap2(      Ny(dmd(A_(x ,yR,cv(*pc++),*sp),4)) ,y)))
         E$(b==bl,UC n=*pc++;A x=sqz(atnv(tX,n,sp));sp+=n-1;*sp=x)
         E$(b==bL,UC n=*pc++;A x=*sp;P(!xtt&&len_(x)-n,el())F(n,*--sp=get(x,n-1-i)))
         E$(b==ba||b==bP,L n=*pc++;A u=sp[n]=(b==ba?app:prj)(*sp,sp+1,n);mr(*sp);sp+=n;N(u))
         E$(b==bz,pc+=1+*pc*!tru(*sp++))E$(b==bj,pc+=*pc)E$(b==bo,*--sp=mR(loc[1]))E$(b==bp,mr(*sp++))E$(b==br,R*sp)E(UR))
 E$(b>=bd,A*p=loc-(b&(mxl-1));*--sp=*p;*p=cu0)E$(b>=bs,A*p=loc-(b&(mxl-1));mr(*p);*p=mR(*sp))E$(b>=bg,A*p=loc-(b&(mxl-1));*--sp=mR(*p))
 E$(b>=bv,sp++;N(*sp=((A2*)cf[b])(sp[-1],*sp)))E(N(*sp=((A1*)cf[b])(*sp))))UR;0)
AX(run,asrt(xto);asrt(n==Ak(x));xR;L m=An(xa[2]);P(sp<sp0+m+3,errn("stk",n,a))*--sp=(A)(V*)pc;*--sp=(A)(V*)loc;*--sp=x;pc=C(xy);loc=sp-1;
 F(n,*--sp=a[i])F(m-n,*--sp=cu0)A u=vm_(x);$(!u,eso(mR(xx),C(xa[3])[pc-1-C(xy)]);W(sp<loc-m,$(*sp,mr(*sp))sp++))
 asrt(sp==loc-m);A*p=loc+1;W(p>sp,mr(*p--))sp=loc+4;pc=(C*)sp[-1];loc=(V*)sp[-2];u)
