#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br=0x7f,bc=0x80,bC=0xff};S A f;S I lu[16],rhs(A);
#define fs ((A*)dat(f))[0] //src                  BYTECODE                                              ba:apply n-adic
#define fb ((A*)dat(f))[1] //bytecode             bu,bv:apply unary|binary verb                         bP:make projection
#define fm ((A*)dat(f))[2] //srcmap               bs,bg,bd:set|get|delete local                         bz:branch if falsey
#define fl ((A*)dat(f))[3] //local symbols        bm,bM:local|global modified assign (a[i]+:b)          bj,bp,br:jump|pop|return
#define fc ((A*)dat(f))[4] //constants            bl,bL:make|destroy list, the latter used for (a;b):c  bc:load constant
#define h(b)({fb=apc(fb,(C)(b));fm=apc(fm,o);}) //add byte
#define hc(x)({I b=bc+fpa(&fc,x);P(b>bC,err("mxc"))h(b);}) //add a "load constant" instruction
S I lhs(A x/*0*/,A y/*0*/)_(UH o=Ao(x);P(yts&&xx==av0&&Ak(f),L i=fpi(&fl,gs(y));i<16?(lu[i]=An(fb)),h(bs|i),1:err("mxl"))
 P(ytS&&!Av(xx),hc(av0);hc(au0);hc(yR);hc(cv('.'));h(ba);h(4);1)
 P(yts||(ytX&&At(yx)==ts),Y(yts,hc(a0()))E(F(yn-1,N(rhs(ya[yn-1-i])))h(bl);h(yn-1))
  I k=gs(yts?y:yx);L i=fndi(fl,k);Y(i<0,hc(as(k));h(bM))E(lu[i]=An(fb);h(bm);h(i))h(Av(xx));1)
 P(ytX&&yx==av_mkl,h(bL);h(yn-1);F(yn-1,N(lhs(x,ya[i+1]));h(bp))1)en();eso(mR(fs),o);0)
S I rhs(A x/*0*/)_(UH o=Ao(x);Y(xts,P(gs(x)==syC('o'),h(bo);1)L i=fndi(fl,gs(x));P(i>=0,lu[i]=An(fb);h(bg|i);1))P(xtS&&xn==1,hc(as(*xl));1)
 P(xtsS,hc(AO(0,xR));h(bu|vi('.'));1)P(!xtX,hc(x==au_plc?au0:xR);1)L n=xn;P(!n,hc(xR);1)A u=xx;P(utS&&n==1,hc(uR);1)
 P((utu||u==av0)&&n==3,N(rhs(xz));N(lhs(x,xy)))
 P(u==cv('$')&&n>3,n--;I p[n];A*a=xa;F(n&~1,N(rhs(*++a));h(i&1?bj:bz);p[i]=An(fb);h(0))N(rhs(n&1?*++a:au0));
  A y=fb;F(n&~1,I d=(i&1?yn:p[i+1])-p[i];Y(i&1,I j=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,err("mxj");0)yc[p[i]]=d)1)
 Y(u==cu('*')&&n==2,A y=xy;P(ytX&&yn==2&&yx==cu('|'),N(rhs(yy));h(bu|24);1))Y(utw&&n==2,A y=xy;P(!ytX&&!ytsS,yR;hc(app(u,&y,1));1))
 I p=0;F(n-1,A y=xa[n-1-i];y==au_plc?(p=1),hc(yR):N(rhs(y)))P(p,N(rhs(xx));h(bP);h(n-1);1)P(u==av0&&n==2,h(br);1)P(u==av_mkl,h(bl);h(n-1);1)
 P(utu&&n==2,h(bu|Av(u));1)P(utv&&n==3,h(bv|Av(u));1)N(rhs(xx));h(ba);h(n-1);1)
A1(cpl,UC k=Ak(x);f=x=mut(x);A y=fb;fb=fm=mR(aC(0));fc=a1(au0);C o=0;ms(lu,Z lu,-1);F(yn,P(!rhs(yai),xr;yr;0)h(i==yn-1?br:bp))yr;
 y=fb;F(16,I j=lu[i];Y(ycj==bg,asrt(Ar(y)==1);ycj=bd))AK(k,AT(to,x)))

S A stk[65536],*sp=stk+ZZ(stk),*loc;S C*ip;
S A vm_(A f/*0*/)_(W(1,UC b=*ip++;Y(b>=bc,*--sp=mR(((A*)dat(fc))[b&127]))
 EY(b>=bm,Y(b==bm,A*p=loc-*ip++,y=*sp++;*sp=N(ap2(mR(*p=Ny(dm1(A_(*p,yR,av(*ip++),*sp),4))),y)))
         EY(b==bM,A x=*sp++    ,y=*sp++;*sp=N(ap2(      Ny(dmd(A_(x ,yR,av(*ip++),*sp),4)) ,y)))
         EY(b==bl,UC n=*ip++;A x=sqz(atnv(tX,n,sp));sp+=n-1;*sp=x)
         EY(b==bL,UC n=*ip++;A x=*sp;P(!xtt&&len_(x)-n,el())F(n,*--sp=get(x,n-1-i)))
         EY(b==ba||b==bP,L n=*ip++;A u=sp[n]=(b==ba?app:prj)(*sp,sp+1,n);mr(*sp);sp+=n;N(u))
         EY(b==bz,ip+=1+(UC)*ip*!tru(*sp++))EY(b==bj,ip+=(UC)*ip)EY(b==bo,*--sp=mR(loc[1]))EY(b==bp,mr(*sp++))E(asrt(b==br);_(*sp)))
 EY(b>=bs,A*p=loc-(b&15);Y(b>=bd,*--sp=*p;*p=au0)EY(b>=bg,*--sp=mR(*p))E(mr(*p);*p=mR(*sp)))
 EY(b>=bv,sp++;N(*sp=((A2*)vf[b])(sp[-1],*sp)))E(N(*sp=((A1*)vf[b])(*sp))))UR;0)
AX(run,asrt(xto);asrt(n==Ak(x));A f=xR;I m=An(fl);P(sp<stk+m+3,esn(n,a))*--sp=(A)(V*)ip;*--sp=(A)(V*)loc;*--sp=f;ip=dat(fb);loc=sp-1;
 F(n,*--sp=a[i])F(m-n,*--sp=au0)A u=vm_(f);Y(!u,eso(mR(fs),((C*)dat(fm))[ip-1-(C*)dat(fb)]);W(sp<loc-m,Y(*sp,mr(*sp))sp++))
 asrt(sp==loc-m);A*p=loc+1;W(p>sp,mr(*p--))sp=loc+4;ip=(C*)sp[-1];loc=(V*)sp[-2];u)

#undef fs
#undef fb
#undef fm
#undef fl
#undef fc
#undef h
#undef hc
