#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br=0x7f,bc=0x80,bC=0xff};S A2 cr;
#define fs xx    //src            BYTECODE                               ba:apply n-adic      f[x;y;z]
#define fb xy    //ast|bytecode   bu,bv:apply unary|binary verb   +x*y   bP:make projection   f[x;;z]
#define fm xz    //srcmap         bs,bg,bd:set|get|delete local    a:b   bz:branch if falsey  $[x;y;z]
#define fl xA[3] //local syms     bm,bM:l|glb modified assign  a[i]+:b   bj,bp,br:jmp|pop|ret $[x;:y;]
#define fc xA[4] //constants      bl,bL:make|unmake list   (a;b):(c;d)   bc:load constant     12;`a;""
#define fu ((I*)_V(xA[5])) //last usages of locals
#define h(a) ({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add byte
#define hc(a) ({Iv=bc+fpA(&fc,a);Ez(v>bC)h(v);}) //add a "load constant" instruction
#define l(a...) N(cl(a)) //compile left-hand side of assignment
#define r(a...) N(cr(a)) //right
S A3(cl,/*0*/Co=yo;P(zts&&yx==av0&&xk,Li=fpI(&fl,gi(z));Ez(i>15)fu[i]=_n(fb);h(bs|i);x)
 P(ztS&&!_v(yx),hc(av0);hc(au0);hc(zR);hc(cv('.'));h(ba);h(4);x)
 P(zts||(ztA&&_t(zx)==ts),Y(zts,hc(oA))E(i(zn-1,r(x,zA[zn-1-i]))h(bl);h(zn-1))
  Ik=gi(zts?z:zx);Li=fAI(fl,k);Y(i<0,hc(as(k));h(bM))E(fu[i]=_n(fb);h(bm);h(i))h(_v(yx));x)
 P(ztA&&zx==MKL,h(bL);h(zn-1);i(zn-1,l(x,y,zA[i+1]);h(bp))1)
 eS(_R(fs),o);ec0())
I asg(Ax)_(xtA||xts||(xtS&&xn>1)) //is lhs of assignment?
S A2(cr,/*0*/Co=yo;Li;P(yts&&(i=fAI(fl,gi(y)))>=0,fu[i]=_n(fb);h(bg|i);x)P(yts&&gi(y)=='o',h(bo);x)
 P(ytS&&yn==1,hc(get(y,0));x)YsS(hc(AO(0,yR));h(bu|vi('.'));x)P(!ytA||!yn,hc(y==PLH?au0:yR);x)Nn=yn;Au=yx;
 P(u==PRG,i(n-1,r(x,yA[i+1]);h(i==n-2?br:bp))x)
 P(n<2,hc(uR);x)P(n==3&&(utu||u==av0)&&asg(yy),r(x,yz);l(x,y,yy))
 P(n>3&&u==cv('$'),n--;I p[n];A*a=yA;i(n&~1,r(x,*++a);h(i&1?bj:bz);p[i]=_n(fb);h(0))r(x,n&1?*++a:au0);Az=fb;
  i(n&~1,I d=(i&1?zn:p[i+1])-p[i];Y(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))Ez(d>255)zC[p[i]]=d)x)
 Y(n==2&&u==cu('*'),Az=yy;P(ztA&&zn==2&&zx==cu('|'),r(x,zy);h(bu|24);x))
 Y(n==2&&utw,Az=yy;P(!ztA&&!ztsS,zR;hc(app(u,&z,1));x))
 I p=0;i(n-1,Az=yA[n-1-i];z==PLH?(p=1),hc(PLH):r(x,z))P(p,r(x,yx);h(bP);h(n-1);x)
 P(n==2&&u==av0,h(br);x)P(u==MKL,h(bl);h(n-1);x)P(n==2&&utu,h(bu|uv);x)P(n==3&&utv,h(bv|uv);x)r(x,yx);h(ba);h(n-1);x)
S A2(f2,/*0*/P(xtw&&!ytA&&!ytsS,x)/*P(x==cu('!')&&ytL&&yn<4,i(yn,P(!in(yl,101),0))x)*/0)
S A3(f3,/*0*/P(xtv&&c3(vi('+'),xv,vi('*'))&&ytL&&ztL&&yn==zn&&yn<101,x)0)
S A1(wrp,/*1*/!x?x:xtA||xtsS?enl(x):x)
A1(cf,XA(Co=xo;Nn=xn;P(n==2?f2(xx,xy):n==3?f3(xx,xy,xz):0,wrp(val(x)))x=mut(x);i(xn,xa=cf(xa))AO(o,x))x)
A1(cpl,x=AK(xk,AT(to,mut(x)));Ay=fb;fb=oC;fm=oC;fc=a1(au0);xA[5]=aI(16);Co=0;Ms(fu,-1,64);y=cf(y);Q(*yA==PRG);
 P(!cr(x,y),mr(xA[5]);x(y(0)))y=y(fb);Q(yr==1);j(16,Ii=fu[j];Y(i>=0&&yc==bg,yc=bd))mr(xA[5]);x)

S A s0[65536],*s=s0+ZZ(s0),*l;S C*c;S A1(p,*--s=x)S A0(q,*s++) //s:stack,l:locals,c:current instruction,p:push,q:pop
S A1(vm,/*0*/W(1,Cb=*c++;
 Y(b>=bm,Y(b>=bc,Ay=fc;p(_R(yA[b-bc])))
        EY(b==bm,A*v=l-*c++,x=*v,y=q(),z=*s;*v=au0;*s=au0;N(*s=apn(_R(*v=Ny(dm1(A(x,yR,av(*c++),z),4))),y)))
        EY(b==bM,Ax=q()         ,y=q(),z=*s;       *s=au0;N(*s=apn(      Ny(dmd(A(x,yR,av(*c++),z),4)) ,y)))
        EY(b==bl,Cn=*c++;s+=n;p(sqz(atnv(tA,n,s-n))))
        EY(b==bL,Cn=*c++;Ax=*s;El(!xtt&&xN-n)i(n,p(get(x,n-1-i))))
        EY(b==ba||b==bP,Cn=*c++;Ax=s[n]=(b==ba?app:prj)(*s,s+1,n);mr(*s);s+=n;N(x))
        EY(b==bz,c+=1+*c*!tru(q()))EY(b==bj,c+=(C)*c)EY(b==bo,p(_R(l[1])))EY(b==bp,mr(q()))E(Q(b==br);_(*s)))
 EY(b>=bs,A*v=l-b%16,x=*v;Y(b>=bd,p(x);*v=au0)EY(b>=bg,p(xR))E(x=x(*v=_R(*s))))
 EY(b>=bv,Ax=q();N(*s=v2[b-bv](x,*s)))E(N(*s=v1[b](*s))))0)
AX(run,Q(xto);Q(n==xk);P(s<s0+16,esn(n,a))p((A)c);p((A)l);p(x);c=_V(fb);l=s-1;Im=_n(fl);i(n,p(a[i]))i(m-n,p(au0))
 Au=vm(x);Y(!u,Ay=fb,z=fm;eS(_R(fs),zC[c-1-yC]);W(s<l-m,Ax=q();Y(x,x(0))))Q(s==l-m);mrn(m,s+1);s=l+2;l=(V*)q();c=(V*)q();u)
