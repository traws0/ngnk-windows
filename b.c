#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br=0x7f,bc=0x80,bC=0xff};S I lu[16];S A2 rhs;
#define fs xx    //src          BYTECODE                                ba:apply n-adic      f[x;y;z]
#define fb xy    //bytecode     bu,bv:apply unary|binary verb    +x*y   bP:make projection   f[x;;z]
#define fm xz    //srcmap       bs,bg,bd:set|get|delete local     a:b   bz:branch if falsey  $[x;y;z]
#define fl xa[3] //local syms   bm,bM:loc|glb modified assign a[i]+:b   bj,bp,br:jmp|pop|ret $[x;:y;]
#define fc xa[4] //constants    bl,bL:make|unmake list    (a;b):(c;d)   bc:load constant     12;`a;""
#define h(a)({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add byte
#define hc(a)({I b=bc+fpa(&fc,a);P(b>bC,err("mxc"))h(b);}) //add a "load constant" instruction
S A3(lhs,/*0*/UH o=yo;P(zts&&yx==av0&&xk,L i=fpi(&fl,gs(z));P(i>15,err("mxl"))lu[i]=An(fb);h(bs|i);x)
 P(ztS&&!Av(yx),hc(av0);hc(au0);hc(zR);hc(cv('.'));h(ba);h(4);x)
 P(zts||(ztX&&At(zx)==ts),Y(zts,hc(a0()))E(F(zn-1,N(rhs(x,za[zn-1-i])))h(bl);h(zn-1))
  I k=gs(zts?z:zx);L i=fndi(fl,k);Y(i<0,hc(as(k));h(bM))E(lu[i]=An(fb);h(bm);h(i))h(Av(yx));x)
 P(ztX&&zx==av_mkl,h(bL);h(zn-1);F(zn-1,N(lhs(x,y,za[i+1]));h(bp))1)en();eso(mR(fs),o);0)
S A2(rhs,/*0*/UH o=yo;Y(yts,P(gs(y)==syC('o'),h(bo);x)L i=fndi(fl,gs(y));P(i>=0,lu[i]=An(fb);h(bg|i);x))P(ytS&&yn==1,hc(as(*yl));x)
 P(ytsS,hc(AO(0,yR));h(bu|vi('.'));x)P(!ytX,hc(y==au_plc?au0:yR);x)L n=yn;P(!n,hc(yR);x)A u=yx;P(utS&&n==1,hc(uR);x)
 P((utu||u==av0)&&n==3,N(rhs(x,yz));N(lhs(x,y,yy)))
 P(u==cv('$')&&n>3,n--;I p[n];A*a=ya;F(n&~1,N(rhs(x,*++a));h(i&1?bj:bz);p[i]=An(fb);h(0))N(rhs(x,n&1?*++a:au0));
  A z=fb;F(n&~1,I d=(i&1?zn:p[i+1])-p[i];Y(i&1,I j=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,err("mxj");0)zc[p[i]]=d)1)
 Y(u==cu('*')&&n==2,A z=yy;P(ztX&&zn==2&&zx==cu('|'),N(rhs(x,zy));h(bu|24);x))Y(utw&&n==2,A z=yy;P(!ztX&&!ztsS,zR;hc(app(u,&z,1));x))
 I p=0;F(n-1,A z=ya[n-1-i];z==au_plc?(p=1),hc(zR):N(rhs(x,z)))P(p,N(rhs(x,yx));h(bP);h(n-1);x)P(u==av0&&n==2,h(br);x)P(u==av_mkl,h(bl);h(n-1);x)
 P(utu&&n==2,h(bu|uv);x)P(utv&&n==3,h(bv|uv);x)N(rhs(x,yx));h(ba);h(n-1);x)
A1(cpl,UC k=xk;x=mut(x);A y=fb;fb=fm=mR(aC(0));fc=a1(au0);C o=0;ms(lu,-1,Z lu);F(yn,P(!rhs(x,yai),xr;yr;0)h(i==yn-1?br:bp))yr;
 y=fb;asrt(Ar(y)==1);F(16,I j=lu[i];Y(ycj==bg,ycj=bd))AK(k,AT(to,x)))

S A stk[65536],*sp=stk+ZZ(stk),*loc;S C*ip;
S A1(vm,/*0*/W(1,UC b=*ip++;Y(b>=bc,*--sp=mR(((A*)dat(fc))[b&127]))
 EY(b>=bm,Y(b==bm,A*p=loc-*ip++,y=*sp++;*sp=N(ap2(mR(*p=Ny(dm1(A_(*p,yR,av(*ip++),*sp),4))),y)))
         EY(b==bM,A x=*sp++    ,y=*sp++;*sp=N(ap2(      Ny(dmd(A_(x ,yR,av(*ip++),*sp),4)) ,y)))
         EY(b==bl,UC n=*ip++;A x=sqz(atnv(tX,n,sp));sp+=n-1;*sp=x)
         EY(b==bL,UC n=*ip++;A x=*sp;P(!xtt&&len_(x)-n,el())F(n,*--sp=get(x,n-1-i)))
         EY(b==ba||b==bP,L n=*ip++;A u=sp[n]=(b==ba?app:prj)(*sp,sp+1,n);mr(*sp);sp+=n;N(u))
         EY(b==bz,ip+=1+(UC)*ip*!tru(*sp++))EY(b==bj,ip+=(UC)*ip)EY(b==bo,*--sp=mR(loc[1]))EY(b==bp,mr(*sp++))E(asrt(b==br);_(*sp)))
 EY(b>=bs,A*p=loc-(b&15);Y(b>=bd,*--sp=*p;*p=au0)EY(b>=bg,*--sp=mR(*p))E(mr(*p);*p=mR(*sp)))
 EY(b>=bv,sp++;N(*sp=((A2*)vf[b])(sp[-1],*sp)))E(N(*sp=((A1*)vf[b])(*sp))))UR;0)
AX(run,asrt(xto);asrt(n==xk);xR;I m=An(fl);P(sp<stk+m+3,esn(n,a))*--sp=(A)(V*)ip;*--sp=(A)(V*)loc;*--sp=x;ip=dat(fb);loc=sp-1;
 F(n,*--sp=a[i])F(m-n,*--sp=au0)A u=vm(x);Y(!u,eso(mR(fs),((C*)dat(fm))[ip-1-(C*)dat(fb)]);W(sp<loc-m,Y(*sp,mr(*sp))sp++))
 asrt(sp==loc-m);A*p=loc+1;W(p>sp,mr(*p--))sp=loc+4;ip=(C*)sp[-1];loc=(V*)sp[-2];u)

#undef fs
#undef fb
#undef fm
#undef fl
#undef fc
#undef h
#undef hc
