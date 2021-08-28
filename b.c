#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,bc=0x80,bC=0xff};S A2 cr;
#define fs xx    //src            BYTECODE                               ba:apply n-adic      f[x;y;z]
#define fb xy    //ast|bytecode   bu,bv:apply unary|binary verb   +x*y   bP:make projection   f[x;;z]
#define fm xz    //srcmap         bs,bg,bd:set|get|delete local    a:b   bz:branch if falsey  $[x;y;z]
#define fl xA[3] //local syms     bm,bM:l|glb modified assign  a[i]+:b   bj,bp:jmp|pop        $[x;:y;]
#define fc xA[4] //constants      bl,bL:make|unmake list   (a;b):(c;d)   bc:load constant     12;`a;""
#define fu ((I*)_V(xA[5])) //last usages of locals
#define h(a) ({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add instruction
#define hc(a) ({Iv=bc+fpA(&fc,a);Ez(v>bC)h(v);}) //add a "load constant" instruction
#define l(a...) N(cl(a)) //compile left-hand side of assignment
#define r(a...) N(cr(a)) //right
S A3(cl,/*0*/I o=yo;
 P(zts&&yx==av&&xK,Li=fpI(&fl,zv);Ez(i>15)fu[i]=_n(fb);h(bs|i);x)
 P(zts||(ztA&&_t(zx)==ts),I(zts,hc(oA))E(i(zn-1,r(x,zA[zn-1-i]))h(bl);h(zn-1))
  Ik=_v(zts?z:zx);Li=fAI(fl,k);I(i<0,hc(as(k));h(bM))E(fu[i]=_n(fb);h(bm);h(i))h(_v(yx));x)
 P(ztS&&!_v(yx),hc(av);hc(au);hc(zR);hc(APN);h(ba);h(4);x)
 P(ztA&&zx==MKL,h(bL);h(zn-1);i(zn-1,l(x,y,zA[i+1]);h(bp))1)
 eS(_R(fs),o);ec0())
I asg(Ax)_(xtA||xtsS) //is lhs of assignment?
S A2(cr,/*0*/I o=yo;
 Ys(Li=fAI(fl,yv);P(i>=0,fu[i]=_n(fb);h(bg|i);x)P(yv=='o',h(bo);x)hc(AO(0,yR));h(bu|APN-av);x)
 YS(P(yn-1,hc(AO(0,yR));h(bu|APN-av);x)hc(get(y,0));x)
 P(!ytA||!yn,hc(y-PLH?yR:au);x)
 Nn=yn;Au=yx;
 P(u==PRG,i(n-1,I(i,h(bp))r(x,yA[i+1]))x)
 P(n<2,hc(uR);x)
 P(n==3&&(utu||u==av)&&asg(yy),r(x,yz);l(x,y,yy))
 P(n>3&&u==CST,n--;I p[n];A*a=yA;i(n&~1,r(x,*++a);h(i&1?bj:bz);p[i]=_n(fb);h(0))r(x,n&1?*++a:au);Az=fb;
  i(n&~1,I d=(i&1?zn:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))Ez(d>255)zC[p[i]]=d)x)
 I(n==2&&u==FIR,Az=yy;P(ztA&&zn==2&&zx==REV,r(x,zy);h(bu|LAS-au);x))
 I(n==2&&utw,Az=yy;P(!ztA&&!ztsS,zR;hc(app(u,&z,1));x))
 I p=0;i(n-1,Az=yA[n-1-i];z==PLH?(p=1),hc(PLH):r(x,z))
 P(p,r(x,yx);h(bP);h(n-1);x)
 P(u==MKL,h(bl);h(n-1);x)
 P(n==2&&utu,h(bu|uv);x)
 P(n==3&&utv,h(bv|uv);x)
 r(x,yx);h(ba);h(n-1);x)
S A2(f2,/*0*/P(xtw&&!ytA&&!ytsS,x)/*P(x==TIL&&ytL&&yn<4,i(yn,P(!in(yl,101),0))x)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,x)0)
S A1(wrp,/*1*/!x?x:xtA||xtsS?enl(x):x)
A1(cf,XA(I o=xo;P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,wrp(val(x)))AO(o,blw(eac1(x,cf))))x)
A1(cpl,x=AK(xk,AT(to,mut(x)));Ay=fb;fb=oC;fm=oC;fc=a1(au);xA[5]=aI(16);I o=0;Ms(fu,-1,64);y=cf(y);
 P(!cr(x,y),y(x(dex(xA[5],0))))h(bu);y=y(fb);Q(yr==1);j(16,Ii=fu[j];I(i>=0&&yc==bg,yc=bd))dex(xA[5],x))

S A s0[65536],*s=s0+ZZ(s0),*l;S C*c;S A1(p,*--s=x)S A0(q,*s++) //s:stack,l:locals,c:current instruction,p:push,q:pop
S A1(vm,/*0*/W(1,Cb=*c++;
 I(b>=bm,I(b>=bc,Ay=fc;p(_R(yA[b-bc])))
        EI(b==bm,A*v=l-*c++,x=*v,y=q(),z=*s;*v=au;*s=au;N(*s=apn(_R(*v=Ny(dmn(A(x,yR,av+*c++,z),4))),y)))
        EI(b==bM,Ax=q()         ,y=q(),z=*s;      *s=au;N(*s=apn(      Ny(dmd(A(x,yR,av+*c++,z),4)) ,y)))
        EI(b==bl,Nn=*c++;s+=n;p(sqz(aV(tA,n,s-n))))
        EI(b==bL,Nn=*c++;Ax=*s;El(!xtt&&xN-n)i(n,p(get(x,n-1-i))))
        EI(b==ba||b==bP,Nn=*c++;Ax=s[n]=(b==ba?app:prj)(*s,s+1,n);mr(*s);s+=n;N(x))
        EI(b==bz,c+=1+*c*!tru(q()))EI(b==bj,c+=(C)*c)EI(b==bo,p(_R(l[1])))EI(b==bp,mr(q())))
 EI(b>=bs,A*v=l-b%16,x=*v;I(b>=bd,p(x);*v=au)EI(b>=bg,p(xR))E(x=x(*v=_R(*s))))
 EI(b>=bv,Ax=q();N(*s=v2[b-bv](x,*s)))EI(b,N(*s=v1[b](*s)))E(_(*s)))0)
AX(run,Q(xto);Q(n==xk);P(s<s0+16,esn(n,a))p((A)c);p((A)l);p(x);c=_V(fb);l=s-1;Im=_n(fl);i(n,p(a[i]))i(m-n,p(au))
 Au=vm(x);I(!u,Ay=fb,z=fm;eS(_R(fs),zC[c-1-yC]);W(s<l-m,Ax=q();I(x,x(0))))Q(s==l-m);mrn(m,s+1);s=l+2;l=(V*)q();c=(V*)q();u)
