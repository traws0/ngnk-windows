#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
//bu,bv:apply unary|binary verb;bs,bg,bd:set|get|delete local;bm,bM:l|glb modified assign;bl:list,bL:unlist
//ba:n-adic apply;bP:projection;bz:branch if falsey;bj:jmp,bp:pop;b4:tetradic dot;bc:load constant
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,b4,bc=0x80,bC=0xff};
#define h(a) ({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add instruction
#define hc(a) ({Iv=bc+fpA(&fc,a);Ez(v>bC)h(v);}) //add a "load constant" instruction
S A fs,fb,fm,fl,fc;S I fu[16];S A1 cr;I asg(Ax)_(xtA||xtsS)
S A2(cl,/*0*/I o=xo;
 P(yts&&xx==av&&_n(fl),Li=fpI(&fl,yv);Ez(i>15)fu[i]=_n(fb);h(bs|i);x)
 P(yts,hc(oA);Ik=yv;Li=fAI(fl,k);I(i<0,hc(as(k));h(bM))E(fu[i]=_n(fb);h(bm);h(i))h(_v(xx));x)
 P(ytS&&(xx==av||_t(xx)==tu),hc(av+_v(xx));hc(au);hc(yR);h(b4);x)
 P(ytA&&(xx==av||_t(xx)==tu)&&_t(yx)==ts,i(yn-1,N(cr(yA[yn-1-i])))h(bl);h(yn-1);
  Ik=_v(yx);Li=fAI(fl,k);I(i<0,hc(as(k));h(bM))E(fu[i]=_n(fb);h(bm);h(i))h(_v(xx));x)
 P(ytA&&(xx==av||_t(xx)==tu)&&_t(yx)==tS,hc(av+_v(xx));i(yn-1,N(cr(yA[yn-1-i])))h(bl);h(yn-1);hc(_R(yx));h(b4);x)
 P(ytA&&yx==MKL,h(bL);h(yn-1);i(yn-1,N(cl(x,yA[i+1]));h(bp))x)
 eS(_R(fs),o);ec0())
S A1(cr,/*0*/I o=xo;
 Xs(Li=fAI(fl,xv);P(i>=0,fu[i]=_n(fb);h(bg|i);x)P(xv=='o',h(bo);x)hc(AO(0,xR));h(bu|APN-av);x)
 XS(P(xn-1,hc(AO(0,xR));h(bu|APN-av);x)hc(get(x,0));x)
 P(!xtA||!xn,hc(x-PLH?xR:au);x)
 Nn=xn;Ay=xx;
 P(y==PRG,i(n-1,I(i,h(bp))N(cr(xA[i+1])))x)
 P(n<2,hc(yR);x)
 P(n==3&&(ytu||y==av)&&asg(xy),N(cr(xz));N(cl(x,xy)))
 P(n>3&&y==CST,n--;I p[n];A*a=xA;i(n&~1,N(cr(*++a));h(i&1?bj:bz);p[i]=_n(fb);h(0))N(cr(n&1?*++a:au));Az=fb;
  i(n&~1,I d=(i&1?zn:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))Ez(d>255)zC[p[i]]=d)x)
 I(n==2&&y==FIR,Az=xy;P(ztA&&zn==2&&zx==REV,N(cr(zy));h(bu|LAS-au);x))
 I(n==2&&ytw,Az=xy;P(!ztA&&!ztsS,zR;hc(app(y,&z,1));x))
 I p=0;i(n-1,Az=xA[n-1-i];z==PLH?(p=1),hc(PLH):N(cr(z)))
 P(p,N(cr(xx));h(bP);h(n-1);x)
 P(y==MKL,h(bl);h(n-1);x)
 P(n==2&&ytu,h(bu|yv);x)
 P(n==3&&ytv,h(bv|yv);x)
 N(cr(xx));h(ba);h(n-1);x)
S A2(f2,/*0*/P(xtw&&!ytA&&!ytsS,x)/*P(x==TIL&&ytL&&yn<4,i(yn,P(!in(yl,101),0))x)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,x)0)
S A1(wrp,/*1*/!x?x:xtA||xtsS?enl(x):x)
A1(cf,XA(I o=xo;P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,wrp(val(x)))AO(o,blw(eac1(x,cf))))x)
A1(cpl,Ik=xk;Ay=get(x,1)/*ast*/;fs=get(x,0);fb=oC;fm=oC;fl=las(x);fc=a1(au);Ms(fu,-1,SZ fu);
 y=cf(y);I r=!!cr(y);I o=0;h(bu);y=y(fb);j(16,Ii=fu[j];I(i>=0&&yc==bg,yc=bd))r?AK(k,aV(to,5,A(fs,fb,fm,fl,fc))):0)

S A s0[65536],*s=s0+ZZ(s0),*l;S C*c;S A1(p,*--s=x)S A0(q,*s++) //s:stack,l:locals,c:current instruction,p:push,q:pop
SN V rne(Ax/*0*/){Ay=xy,z=xz;Im=_n(xA[3]);eS(_R(xx),zC[c-1-yC]);W(s<l-m,Ax=q();I(x,x(0)))}
S A1(vm,/*0*/W(1,UC b=*c++;
 I(b>=bm,I(b>=bc,Ay=xA[4]/*fc*/;p(_R(yA[b-bc])))
        EI(b==bm,A*v=l-*c++,x=*v,y=q(),z=*s;*v=au;*s=au;N(*s=apn(_R(*v=Ny(dmn(A(x,yR,av+*c++,z),4))),y)))
        EI(b==bM,Ax=q()         ,y=q(),z=*s;      *s=au;N(*s=apn(      Ny(dmd(A(x,yR,av+*c++,z),4)) ,y)))
        EI(b==bl,Nn=*c++;s+=n;p(sqz(aV(tA,n,s-n))))
        EI(b==bL,Nn=*c++;Ax=*s;El(!xtt&&xN-n)i(n,p(get(x,n-1-i))))
        EI(b==ba||b==bP,Nn=*c++;Ax=s[n]=(b-ba?prj:app)(*s,s+1,n);mr(*s);s+=n;N(x))
        EI(b==bz,c+=1+*c*!tru(q()))EI(b==bj,c+=(UC)*c)EI(b==bo,p(_R(l[1])))EI(b==bp,mr(q()))
        EI(b==b4,s+=3;N(*s=dmd(s-3,4))))
 EI(b>=bs,A*v=l-b%16,x=*v;I(b>=bd,p(x);*v=au)EI(b>=bg,p(xR))E(x=x(*v=_R(*s))))
 EI(b>=bv,Ax=q();N(*s=v2[b-bv](x,*s)))EI(b,N(*s=v1[b](*s)))E(_(*s)))0)
AX(run,Q(xto);Q(n==xk);P(s<s0+16,esn(n,a))p((A)c);p((A)l);p(x);c=_V(xy);l=s-1;i(n,p(a[i]))Im=_n(xA[3]);i(m-n,p(au))
 Ay=vm(x);I(!y,rne(x))Q(s==l-m);mrn(m,s+1);s=l+2;l=(V*)q();c=(V*)q();y)
