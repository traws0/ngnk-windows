#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br=0x7f,bc=0x80,bC=0xff};S A2 rhs;
#define fs xx    //src          BYTECODE                                ba:apply n-adic      f[x;y;z]
#define fb xy    //bytecode     bu,bv:apply unary|binary verb    +x*y   bP:make projection   f[x;;z]
#define fm xz    //srcmap       bs,bg,bd:set|get|delete local     a:b   bz:branch if falsey  $[x;y;z]
#define fl xa[3] //local syms   bm,bM:loc|glb modified assign a[i]+:b   bj,bp,br:jmp|pop|ret $[x;:y;]
#define fc xa[4] //constants    bl,bL:make|unmake list    (a;b):(c;d)   bc:load constant     12;`a;""
#define h(a) ({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add byte
#define hc(a) ({I b=bc+fpa(&fc,a);P(b>bC,err("mxc"))h(b);}) //add a "load constant" instruction
#define lu ((I*)dat(xa[5])) //last usages of locals
S A3(lhs,/*0*/UH o=yo;P(zts&&yx==av0&&xk,L i=fpi(&fl,gs(z));P(i>15,err("mxl"))lu[i]=An(fb);h(bs|i);x)
 P(ztS&&!Av(yx),hc(av0);hc(au0);hc(zR);hc(cv('.'));h(ba);h(4);x)
 P(zts||(ztX&&At(zx)==ts),Y(zts,hc(a0()))E(F(zn-1,N(rhs(x,za[zn-1-i])))h(bl);h(zn-1))
  I k=gs(zts?z:zx);L i=fndi(fl,k);Y(i<0,hc(as(k));h(bM))E(lu[i]=An(fb);h(bm);h(i))h(Av(yx));x)
 P(ztX&&zx==av_mkl,h(bL);h(zn-1);F(zn-1,N(lhs(x,y,za[i+1]));h(bp))1)en();eso(mR(fs),o);0)
S A2(rhs,/*0*/UH o=yo;Y(yts,P(gs(y)==So,h(bo);x)L i=fndi(fl,gs(y));P(i>=0,lu[i]=An(fb);h(bg|i);x))P(ytS&&yn==1,hc(as(*yl));x)
 P(ytsS,hc(AO(0,yR));h(bu|vi('.'));x)P(!ytX,hc(y==au_plc?au0:yR);x)L n=yn;P(!n,hc(yR);x)A u=yx;P(utS&&n==1,hc(uR);x)
 P((utu||u==av0)&&n==3,N(rhs(x,yz));N(lhs(x,y,yy)))
 P(u==cv('$')&&n>3,n--;I p[n];A*a=ya;F(n&~1,N(rhs(x,*++a));h(i&1?bj:bz);p[i]=An(fb);h(0))N(rhs(x,n&1?*++a:au0));
  A z=fb;F(n&~1,I d=(i&1?zn:p[i+1])-p[i];Y(i&1,I j=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,err("mxj");0)zc[p[i]]=d)1)
 Y(u==cu('*')&&n==2,A z=yy;P(ztX&&zn==2&&zx==cu('|'),N(rhs(x,zy));h(bu|24);x))Y(utw&&n==2,A z=yy;P(!ztX&&!ztsS,zR;hc(app(u,&z,1));x))
 I p=0;F(n-1,A z=ya[n-1-i];z==au_plc?(p=1),hc(zR):N(rhs(x,z)))P(p,N(rhs(x,yx));h(bP);h(n-1);x)P(u==av0&&n==2,h(br);x)P(u==av_mkl,h(bl);h(n-1);x)
 P(utu&&n==2,h(bu|uv);x)P(utv&&n==3,h(bv|uv);x)N(rhs(x,yx));h(ba);h(n-1);x)
A1(cpl,C k=xk;x=mut(x);A y=fb;fb=fm=mR(aC(0));fc=a1(au0);xa[5]=aI(16);C o=0;ms(lu,-1,16*Z(I));F(yn,P(!rhs(x,yai),xr;yr;0)h(i==yn-1?br:bp))yr;
 y=fb;asrt(Ar(y)==1);F(16,I j=lu[i];Y(j>=0&&ycj==bg,ycj=bd))mr(xa[5]);AK(k,AT(to,x)))

S A stk[65536],*sp=stk+ZZ(stk),*loc;S C*ip;S A1(psh,*--sp=x)S A0(pop,*sp++)
S A1(vm,/*0*/W(1,C b=*ip++;
 Y(b>=bm,Y(b>=bc,A y=fc;psh(mR(ya[b-bc])))
        EY(b==bm,A*p=loc-*ip++,y=pop();N(*sp=ap2(mR(*p=Ny(dm1(A_(*p,yR,av(*ip++),*sp),4))),y)))
        EY(b==bM,A x=pop()    ,y=pop();N(*sp=ap2(      Ny(dmd(A_(x ,yR,av(*ip++),*sp),4)) ,y)))
        EY(b==bl,C n=*ip++;A x=sqz(atnv(tX,n,sp));sp+=n;psh(x))
        EY(b==bL,C n=*ip++;A x=*sp;El(!xtt&&len_(x)-n)F(n,psh(get(x,n-1-i))))
        EY(b==ba||b==bP,C n=*ip++;A u=sp[n]=(b==ba?app:prj)(*sp,sp+1,n);mr(*sp);sp+=n;N(u))
        EY(b==bz,ip+=1+*ip*!tru(pop()))EY(b==bj,ip+=(C)*ip)EY(b==bo,psh(mR(loc[1])))EY(b==bp,mr(pop()))E(asrt(b==br);_(*sp)))
 EY(b>=bs,A*p=loc-(b&15);Y(b>=bd,psh(*p);*p=au0)EY(b>=bg,psh(mR(*p)))E(mr(*p);*p=mR(*sp)))
 EY(b>=bv,A x=pop();N(*sp=((A2*)vf[b])(x,*sp)))E(N(*sp=((A1*)vf[b])(*sp))))0)
AX(run,asrt(xto);asrt(n==xk);P(sp<stk+16,esn(n,a))psh((A)(V*)ip);psh((A)(V*)loc);psh(x);ip=dat(fb);loc=sp-1;I m=An(fl);F(n,psh(a[i]))F(m-n,psh(au0))
 A u=vm(x);Y(!u,A y=fb,z=fm;eso(mR(fs),zc[ip-1-yc]);W(sp<loc-m,A x=pop();Y(x,mr(x))))asrt(sp==loc-m);mrn(m,sp+1);sp=loc+2;loc=(V*)pop();ip=(V*)pop();u)

#undef fs
#undef fb
#undef fm
#undef fl
#undef fc
#undef h
#undef hc
