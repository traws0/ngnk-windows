#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
//bu,bv:apply unary|binary verb;bs,bg,bd:set|get|delete local;bm,bM:l|glb modified assign;bl:list,bL:unlist
//ba:n-adic apply;bP:projection;bz:branch if falsey;bj:jmp,bp:pop;b4:tetradic dot;bc:load constant
enum{bu,bv=32,bs=64,bg=80,bd=96,bm=112,bM,bl,bL,ba,bP,bz,bj,bo,bp,b4,bc=128,bC=255};
#define h(a) {m[nb]=o;b[nb]=a;nb+=nb<SZ b-1;} //add instruction
#define hc(a) {Ij=bc+fpA(&fc,a);Ez(j>bC)h(j);} //add a "load constant" instruction
#define OK -1
#define Nr(a...) {I r=cr(a);P(r-OK,r);}
#define Nl(a...) {I r=cl(a);P(r-OK,r);}
S UC b[2048],m[SZ b];S A fl,fc;S I nb,fu[16];S A1 cr;
S A2(cl,/*0*/I o=xo;Q(xx==av||_t(xx)==tu);Iv=_v(xx);YS(hc(av+v);hc(au);hc(yR);h(b4);OK)
 Ys(P(xx==av&&_n(fl),Li=fpI(&fl,yv);Ez(i>15)fu[i]=nb;h(bs|i);OK)
  hc(oA);Ik=yv;Li=fAI(fl,k);I(i<0,hc(as(k));h(bM))E(fu[i]=nb;h(bm);h(i))h(v);OK)
 YA(In=yn-1;P(n-(UC)n,o)Az=yx;P(zt==tS,hc(av+v);i(n,Nr(yA[n-i]))h(bl);h(n);hc(zR);h(b4);OK)
  P(zt==ts,i(n,Nr(yA[n-i]))h(bl);h(n);Li=fAI(fl,zv);I(i<0,hc(z);h(bM))E(fu[i]=nb;h(bm);h(i))h(v);OK)
  P(z==MKL&&xx==av,h(bL);h(n);i(n,Nl(x,yA[i+1]);h(bp))OK)o)o)
S A1(cr,/*0*/I o=xo;Xs(Li=fAI(fl,xv);P(i>=0,fu[i]=nb;h(bg|i);OK)P(xv=='o',h(bo);OK)hc(AO(0,xR));h(bu|APN-av);OK)
 XS(P(xn-1,hc(AO(0,xR));h(bu|APN-av);OK)hc(get(x,0));OK)P(!xtA||!xn,hc(x-PLH?xR:au);OK)Nn=xn;Ay=xx;
 P(y==PRG,i(n-1,I(i,h(bp))Nr(xA[i+1]))OK)P(n<2,hc(yR);OK)P(n==3&&(ytu||y==av)&&_tsSA(xy),Nr(xz);Nl(x,xy);OK)
 P(n>3&&y==CST,n--;I p[n];A*a=xA;i(n&~1,Nr(*++a);h(i&1?bj:bz);p[i]=nb;h(0))Nr(n&1?*++a:au);
  i(n&~1,I d=(i&1?nb:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))Ez(d>255)b[p[i]]=d)OK)
 I(n==2&&y==FIR,Az=xy;P(ztA&&zn==2&&zx==REV,Nr(zy);h(bu|LAS-au);OK))
 I p=0;i(n-1,Az=xA[n-1-i];I(z==PLH,p=1;hc(PLH))E(Nr(z)))
 P(p,Nr(xx);h(bP);h(n-1);OK)P(y==MKL,h(bl);h(n-1);OK)P(n==2&&ytu,h(bu|yv);OK)P(n==3&&ytv,h(bv|yv);OK)
 Nr(xx);h(ba);h(n-1);OK)
S A2(f2,/*0*/P(xtw&&!ytsSA,1)/*P(x==TIL&&ytZ&&yn<4,i(yn,P(!in(gl(get(y,i)),101),0))1)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,1)0)
S A1(qt,/*1*/xtsSA?enl(x):x)
A1(cf,XA(I o=xo;P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,qt(N(val(x))))AO(o,blw(eac1(x,cf))))x)
A3(cpl,/*src,ast,loc*/nb=0;fl=z;fc=a1(au);Ms(fu,-1,SZ fu);y=cf(y);I r=cr(y);y(0);I o=0;h(bu);P(r-OK,eS(xR,r);ec0())
 P(nb>=SZ b-1,eS(xR,r);ez0())i(16,Ij=fu[i];I(j>=0&&b[j]==bg,b[j]=bd))AK(0,aV(to,5,A(x,aCn(b,nb),aCn(m,nb),fl,fc))))

S A s0[65536],*s=s0+ZZ(s0),*l;S C*c;S A1(p,*--s=x)S A0(q,*s++) //s:stack,l:locals,c:current instruction,p:push,q:pop
SN V rne(Ax/*0*/){Ay=xy,z=xz;Im=_n(xA[3]);eS(_R(xx),zC[c-1-yC]);W(s<l-m,Ax=q();I(x,x(0)))}
S A1(vm,/*0*/W(1,UC b=*c++;
 I(b>=bc,Ay=xA[4]/*fc*/;p(_R(yA[b-bc])))
 EI(b>=bm,I(b==bm,A*v=l-*c++,x=*v,y=q(),z=*s;*v=au;*s=au;N(*s=apn(_R(*v=Ny(dmn(A(x,yR,av+*c++,z),4))),y)))
         EI(b==bM,Ax=q()         ,y=q(),z=*s;      *s=au;N(*s=apn(      Ny(dmd(A(x,yR,av+*c++,z),4)) ,y)))
         EI(b==bl,Nn=*c++;s+=n;p(sqz(aV(tA,n,s-n))))
         EI(b==bL,Nn=*c++;Ax=*s;El(!xtt&&xN-n)i(n,p(get(x,n-1-i))))
         EI(b==ba||b==bP,Nn=*c++;Ax=s[n]=(b-ba?prj:app)(*s,s+1,n);mr(*s);s+=n;N(x))
         EI(b==bz,c+=1+*c*!tru(q()))EI(b==bj,c+=(UC)*c)EI(b==bo,p(_R(l[1])))EI(b==bp,mr(q()))
         EI(b==b4,s+=3;N(*s=dmd(s-3,4))))
 EI(b>=bs,A*v=l-b%16,x=*v;I(b>=bd,p(x);*v=au)EI(b>=bg,p(xR))E(x=x(*v=_R(*s))))
 EI(b>=bv,Ax=q();N(*s=v2[b-bv](x,*s)))EI(b,N(*s=v1[b](*s)))E(_(*s)))0)
AX(run,Q(xto);Q(n==xk);P(s<s0+16,esn(a,n))p((A)c);p((A)l);p(x);c=_V(xy);l=s-1;i(n,p(a[i]))Im=_n(xA[3]);i(m-n,p(au))
 Ay=vm(x);I(!y,rne(x))Q(s==l-m);mrn(m,s+1);s=l+2;l=(V*)q();c=(V*)q();y)
