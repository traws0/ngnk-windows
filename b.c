#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
//bu,bv:apply unary|binary verb;bs,bg,bd:set|get|delete local;bm,bM:l|glb modified assign;bl:list,bL:unlist
//ba:n-adic apply;bP:projection;bz:branch if falsey;bj:jmp,bp:pop;b4:tetradic dot;bc:load constant
enum{bu,bv=32,bs=64,bg=80,bd=96,bm=112,bM,bG,bS,bl,bL,ba,bP,bz,bj,bo,bp,b4,bc=128};
#define h(a) {m[nb]=o;b[nb]=a;nb+=nb<SZ b-1;}        //add instruction
#define hc(a) {Ij=bc+fpA(&fc,a);P(j>255,ez0())h(j);} //add a "load constant" instruction
#define OK -1
#define Nr(a...) {I r=cr(a);P(r-OK,r);}
#define Nl(a...) {I r=cl(a);P(r-OK,r);}
S UC b[2048],m[SZ b];S A fl,fc;S I nb,lu[16];S A1 cr;
S I gvi(Iv)_(Ax=glbk,y=glbv;Li=fAI(x,v);P(i>=0,i)i=xn;P(i-(UC)i,-1)xn=yn=i+1;xi=v;ya=0;i)
S A2(cl,/*0*/I o=xo;Q(xx==av||_t(xx)==tu);Iv=_v(xx);
 Ys(P(xx==av&&_n(fl),Li=fpI(&fl,yv);P(i>15,ez0())lu[i]=nb;h(bs|i);OK)
  Li=fAI(fl,yv);P(i>=0,lu[i]=nb;hc(oA);h(bm);h(i);h(v);OK)
  P(!v,i=gvi(yv);P(i<0,ez0())h(bS);h(i);OK)
  hc(oA);hc(as(yv));h(bM);h(v);OK)
 YS(hc(av+v);hc(au);hc(yR);h(b4);OK)
 YA(In=yn-1;P(n-(UC)n,o)Az=yx;
  P(ztS,hc(av+v);i(n,Nr(yA[n-i]))h(bl);h(n);hc(zR);h(b4);OK)
  P(zts,i(n,Nr(yA[n-i]))h(bl);h(n);Li=fAI(fl,zv);I(i<0,hc(z);h(bM))E(lu[i]=nb;h(bm);h(i))h(v);OK)
  P(z==MKL&&xx==av,h(bL);h(n);i(n,Nl(x,yA[i+1]);h(bp))OK)o)o)
S A1(cr,/*0*/I o=xo;
 Xs(Li=fAI(fl,xv);P(i>=0,lu[i]=nb;h(bg|i);OK)P(xv=='o',h(bo);OK)i=gvi(xv);P(i<0,ez0())h(bG);h(i);OK)
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
S I mxs(Ii,I s)_(I r=s;W(1,UC c=b[i++];Q(s>=0);r=max(r,s);P(!c,r)P(c==bz,i++;s--;max(r,max(mxs(i,s),mxs(i+b[i-1],s))))
 I(c>=bc||c==bo||c-bg<32u,s++)EI(c-bv<32u||c==bp,s--)EI(c==bm,i+=2;s--)EI(c==bM,i++;s-=2)EI(c==bL,s+=b[i++])
 EI(c==bl||c==ba||c==bP,s-=b[i++]-1)EI(c==bj,i+=b[i])EI(c==b4,s-=3)EI(c==bG,i++;s++)EI(c==bS,i++))r)
A3(cpl,/*src,ast,loc*/y=cf(y);P(!y,x(z(0)))
 nb=1;fl=z;fc=a1(au);Ms(lu,-1,SZ lu);I r=cr(y);y(0);I o=0;h(bu);P(r-OK,eS(xR,r);ec0())
 P(nb>=SZ b-1,eS(xR,r);ez0())i(16,Ij=lu[i];I(j>=0&&b[j]==bg,b[j]=bd))
 *b=mxs(1,0);*m=-1;AK(0,AT(to,cat(aV(tA,4,A(x,aCn(b,nb),aCn(m,nb),fl)),fc))))

S V mrn0(A*a,Nn){i(n,I(a[i],mr(a[i])))}
#define p(x) ({A x1=(x);Q(x1)Q(t<s)*--s=x1;})
#define q() ({Q(s<t+ns)Q(*s)*s++;})
AX(run,Q(xto);Q(n==xk);S I d;P(++d>1024,esn(a,n))
 UC*b=_V(xy),c;I ns=*b++,nl=_n(xA[3]);A t[ns+nl],*s=t+ns,*l=s;Mc(l,a,n*SZ x);Ms(l+n,0,(nl-n)*SZ*l);
 W((c=*b++),
  I(c>=bc,p(_R(xA[c-bc+4])))
  EI(c>=bm,
   I(c==bm,A*v=l+*b++,x=*v?*v:au,y=q(),z=*s;*v=*s=0;*v=dmn(A(x,yR,av+*b++,z),4);B(!*v,y(0))*s=apn(_R(*v),y);B(!*s))
   EI(c==bM,Ax=q(),y=q(),z=*s;*s=0;A w=mnd(A(x,yR,av+*b++,z),4,dmn);B(!w,y(0))*s=apn(w,y);B(!*s))
   EI(c==bG,Ax=*--s=_A(glbv)[*b++];B(!x,ev0())xR)
   EI(c==bS,A*v=_A(glbv)+*b++;I(*v,mr(*v))*v=_R(*s);)
   EI(c==bl,Nn=*b++;s+=n-1;*s=sqz(aV(tA,n,s-n+1)))
   EI(c==bL,Nn=*b++;Ax=*s;B(!xtt&&xN-n,*s=el1(x))i(n,p(get(x,n-1-i))))
   EI(c==ba||c==bP,Nn=*b++;Ax=s[n]=(c-ba?prj:app)(*s,s+1,n);mr(*s);s+=n;B(!x))
   EI(c==bz,b+=1+*b*!tru(q()))
   EI(c==bj,b+=*b)
   EI(c==bo,p(xR))
   EI(c==bp,mr(q()))
   EI(c==b4,s+=3;*s=dmd(aV(tA,4,s-3));B(!*s)))
  EI(c>=bs,A*v=l+c%16,x=*v?*v:au;I(c>=bd,p(x);*v=0)EI(c>=bg,p(xR))E(x=x(*v=_R(*s))))
  EI(c>=bv,Ax=q();*s=v2[c-bv](x,*s);B(!*s))
  E(*s=v1[c](*s);B(!*s)))
 I(!*s,eS(_R(xx),_C(xz)[b-1-_C(xy)]);mrn0(s+1,t+ns-s-1))
 mrn0(l,nl);d--;Q(s==l-1);*s)
