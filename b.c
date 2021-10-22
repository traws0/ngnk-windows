#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
//bu,bv:apply unary|binary verb;bs,bg,bd:set|get|delete local;bm,bM:l|glb modified assign;bl:list,bL:unlist
//ba:n-adic apply;bP:projection;bz:branch if falsey;bj:jmp,bp:pop;b4:tetradic dot;bc:load constant
enum{bu,bv=32,bs=64,bg=80,bd=96,bm=112,bM,bl,bL,ba,bP,bz,bj,bo,bp,b4,bc=128,bC=255};
#define h(a) {m[nb]=o;b[nb]=a;nb+=nb<SZ b-1;}       //add instruction
#define hc(a) {Ij=bc+fpA(&fc,a);P(j>bC,ez0())h(j);} //add a "load constant" instruction
#define OK 1
#define Nr(a...) {I r=cr(a);P(r-OK,r);}
#define Nl(a...) {I r=cl(a);P(r-OK,r);}
S UC b[2048],m[SZ b];S A fl,fc;S I nb,ns,ms,fu[16];S A1 cr;
S A2(cl,/*0*/I o=xo;Q(xx==av||_t(xx)==tu);Iv=_v(xx);
 Ys(P(xx==av&&_n(fl),Li=fpI(&fl,yv);P(i>15,ez0())fu[i]=nb;h(bs|i);OK)
  hc(oA);Ik=yv;Li=fAI(fl,k);I(i<0,hc(as(k));h(bM))E(fu[i]=nb;h(bm);h(i))h(v);OK)
 YS(hc(av+v);hc(au);hc(yR);h(b4);OK)
 YA(In=yn-1;P(n-(UC)n,o)Az=yx;P(zt==tS,hc(av+v);i(n,Nr(yA[n-i]))h(bl);h(n);hc(zR);h(b4);OK)
  P(zt==ts,i(n,Nr(yA[n-i]))h(bl);h(n);Li=fAI(fl,zv);I(i<0,hc(z);h(bM))E(fu[i]=nb;h(bm);h(i))h(v);OK)
  P(z==MKL&&xx==av,h(bL);h(n);i(n,Nl(x,yA[i+1]);h(bp))OK)o)o)
S A1(cr,/*0*/I o=xo;
 Xs(Li=fAI(fl,xv);P(i>=0,fu[i]=nb;h(bg|i);OK)P(xv=='o',h(bo);OK)hc(AO(0,xR));h(bu|APN-av);OK)
 XS(P(xn-1,hc(AO(0,xR));h(bu|APN-av);OK)hc(get(x,0));OK)
 P(!xtA||!xn,hc(x-PLH?xR:au);OK)
 Nn=xn;Ay=xx;
 P(y==PRG,i(n-1,I(i,h(bp))Nr(xA[i+1]))OK)
 P(n<2,hc(yR);OK)
 P(n==3&&(ytu||y==av)&&_tsSA(xy),Nr(xz);Nl(x,xy);OK)
 P(n>3&&y==CST,n--;I p[n];A*a=xA;i(n&~1,Nr(*++a);h(i&1?bj:bz);p[i]=nb;h(0))Nr(n&1?*++a:au);
  i(n&~1,I d=(i&1?nb:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,ez0())b[p[i]]=d)OK)
 I(n==2&&y==FIR,Az=xy;P(ztA&&zn==2&&zx==REV,Nr(zy);h(bu|LAS-au);OK))
 I p=0;i(n-1,Az=xA[n-1-i];I(z==PLH,p=1;hc(PLH))E(Nr(z)))
 P(p,Nr(xx);h(bP);h(n-1);OK)
 P(y==MKL,n--;P(n-(UC)n,o);h(bl);h(n);OK)
 P(n==2&&ytu,h(bu|yv);OK)
 P(n==3&&ytv,h(bv|yv);OK)
 Nr(xx);h(ba);h(n-1);OK)
S A2(f2,/*0*/P(xtw&&!ytsSA,1)/*P(x==TIL&&ytZ&&yn<4,i(yn,P(!in(gl(get(y,i)),101),0))1)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,1)0)
S A1(qt,/*1*/xtsSA?enl(x):x)
A1(cf,XA(P(xx==MKL,i(xn,Ay=xa;YsSA(x))a1(drp(1,x)))
         P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,qt(N(val(x))))
         AO(xo,blw(eac1(x,cf))))x)
A3(cpl,/*src,ast,loc*/y=cf(y);P(!y,x(z(0)))
 nb=ns=ms=0;fl=z;fc=a1(au);Ms(fu,-1,SZ fu);I r=cr(y);y(0);I o=0;h(bu);P(r-OK,eS(xR,r);ec0())
 P(nb>=SZ b-1,eS(xR,r);ez0())i(16,Ij=fu[i];I(j>=0&&b[j]==bg,b[j]=bd))AK(0,aV(to,5,A(x,aCn(b,nb),aCn(m,nb),fl,fc))))

S A s0[65536],*s=s0+ZZ(s0);
S V mrn0(A*a,Nn){i(n,Ax=a[i];I(x,x(0)))}
AX(run,Q(xto);Q(n==xk);S I d;P(++d>1024,esn(a,n))
 UC*p=_V(xy);Im=_n(xA[3]);A*t=s,l[m],r;Mc(l,a,n*SZ x);i(m-n,l[n+i]=au)
 W(1,UC b=*p++;
  I(b>=bc,*--s=_R(_A(xA[4])[b-bc]))
  EI(b>=bm,
   I(b==bm,A*v=l+*p++,x=*v,y=*s++,z=*s;*v=*s=au;*v=dmn(A(x,yR,av+*p++,z),4);B(!*v,r=y(0))*s=apn(_R(*v),y);B(!*s,r=0))
   EI(b==bM,Ax=*s++,y=*s++,z=*s;*s=au;A w=mnd(A(x,yR,av+*p++,z),4,dmn);B(!w,r=y(0))*s=apn(w,y);B(!*s,r=0))
   EI(b==bl,Nn=*p++;s+=n;Ax=sqz(aV(tA,n,s-n));*--s=x)
   EI(b==bL,Nn=*p++;Ax=*s;B(!xtt&&xN-n,r=el0())i(n,*--s=get(x,n-1-i)))
   EI(b==ba||b==bP,Nn=*p++;Ax=s[n]=(b-ba?prj:app)(*s,s+1,n);mr(*s);s+=n;B(!x,r=0))
   EI(b==bz,p+=1+*p*!tru(*s++))
   EI(b==bj,p+=*p)
   EI(b==bo,*--s=xR)
   EI(b==bp,mr(*s++))
   EI(b==b4,s+=3;*s=dmd(aV(tA,4,s-3));B(!x,r=0)))
  EI(b>=bs,A*v=l+b%16,x=*v;I(b>=bd,*--s=x;*v=au)EI(b>=bg,*--s=xR)E(x=x(*v=_R(*s))))
  EI(b>=bv,Ax=*s++;*s=v2[b-bv](x,*s);B(!*s,r=0))
  EI(b,*s=v1[b](*s);B(!*s,r=0))
  E(B(1,r=*s++)))
 I(!r,eS(_R(xx),_C(xz)[p-1-_C(xy)]);mrn0(s,t-s);s=t)
 mrn0(l,m);d--;r)
