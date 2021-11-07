#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
enum{bu,bv=32,bs=64,bg=72,bd=80,bm=88,bM,bG,bS,bl,bL,ba,bP,bz,bj,bo,bp,b4,bc};
#define h(a) {b[nb]=a;m[nb]=o;nb+=nb<SZ b-1;}
#define hc(a) {N(lc(a,o));}
#define OK -1
#define Nr(a...) {I r=cr(a);P(r-OK,r);}
#define Nl(a...) {I r=cl(a);P(r-OK,r);}
S UC b[256],m[256];S A fl,fc;S I nb,lu[8];S A1 cr;
SN I lc(Ax/*1*/,I o)_(Ay=fc;Nn=yn,i=0;W(i<n,B(mtc_(x,ya),x(0))i++)I(i==n,_q(fc,x))i+=bc;P(i-(UC)i,ez0())h(i);1)
SN I ig(Iv)_(Ax=gk,y=gv;Li=fAI(x,v);P(i>=0,i)i=xn;P(i-(UC)i,-1)xn=yn=i+1;xi=v;ya=0;i)
SN I il(Iv)_(Li=fAI(fl,v);P(i>=0,lu[i]=nb;i)-1)
S A2(cl,/*0*/I o=xo;Q(xx==av||_t(xx)==tu)Iv=_v(xx);
 Ys(P(xx==av&&_n(fl),Li=fpI(&fl,yv);P(i>15,ez0())lu[i]=nb;h(bs|i)OK)
  Ii=il(yv);P(i>=0,hc(oA)h(bm)h(i)h(v)OK)P(!v,i=ig(yv);P(i>=0,h(bS)h(i)OK)ez0())hc(oA)hc(as(yv))h(bM)h(v)OK)
 YS(hc(av+v)hc(au)hc(yR)h(b4)OK)
 YA(In=yn-1;P(n-(UC)n,o)Az=yx;
  P(ztS,hc(av+v)i(n,Nr(yA[n-i]))h(bl)h(n)hc(zR)h(b4)OK)
  P(zts,i(n,Nr(yA[n-i]))h(bl)h(n);Ii=il(zv);I(i<0,hc(z)h(bM))E(h(bm)h(i))h(v)OK)
  P(z==MKL&&xx==av,h(bL)h(n);i(n,Nl(x,yA[i+1]);h(bp))OK)o)o)
S A1(cr,/*0*/I o=xo;
 Xs(Ii=il(xv);P(i>=0,h(bg|i)OK)P(xv=='o',h(bo)OK)i=ig(xv);P(i<0,ez0())h(bG)h(i)OK)
 XS(P(xn-1,hc(AO(0,xR))h(bu|DOT-av)OK)hc(ii(x,0))OK)
 P(!xtA||!xn,hc(x-PLH?xR:au)OK)
 Nn=xn;Ay=xx;
 P(y==PRG,i(n-1,I(i,h(bp))Nr(xA[i+1]))OK)
 P(n<2,hc(yR)OK)
 P(n==3&&(ytu||y==av)&&_tsSA(xy),Nr(xz);Nl(x,xy);OK)
 P(n>3&&y==CST,n--;I p[n];A*a=xA;i(n&~1,Nr(*++a);h(i&1?bj:bz)p[i]=nb;h(0))Nr(n&1?*++a:au);
  i(n&~1,I d=(i&1?nb:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,ez0())b[p[i]]=d)OK)
 I(n==2&&y==FIR,Az=xy;P(ztA&&zn==2&&zx==REV,Nr(zy);h(bu|LAS-au)OK))
 I p=0;i(n-1,Az=xA[n-1-i];I(z==PLH,p=1;hc(PLH))E(Nr(z)))
 P(p,Nr(xx);h(bP)h(n-1)OK)
 P(y==MKL,n--;P(n-(UC)n,o);h(bl)h(n)OK)
 P(n==2&&ytu,h(bu|yv)OK)
 P(n==3&&ytv,h(bv|yv)OK)
 Nr(xx);h(ba)h(n-1)OK)
S A2(f2,/*0*/P(xtw&&!ytsSA,1)/*P(x==TIL&&ytZ&&yn<4,i(yn,P(!in(gl(ii(y,i)),101),0))1)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,1)0)
S A1(qt,/*1*/xtsSA?enl(x):x)
S A1(cf,XA(P(xx==MKL,i(xn,Ay=xa;YsSA(x))a1(drp(1,x)))
           P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,qt(N(val(x))))
           AO(xo,blw(eac1f(x,cf))))x)
S I mxs(Ii,I s)_(I r=s;W(1,UC c=b[i++];Q(s>=0)r=max(r,s);P(!c,r)P(c==bz,i++;s--;max(r,max(mxs(i,s),mxs(i+b[i-1],s))))
 I(c>=bc||c==bo||c-bg<16u,s++)J(c-bv<32u||c==bp,s--)J(c==bm,i+=2;s--)J(c==bM,i++;s-=2)J(c==bL,s+=b[i++])
 J(c==bl||c==ba||c==bP,s-=b[i++]-1)J(c==bj,i+=b[i])J(c==b4,s-=3)J(c==bG,i++;s++)J(c==bS,i++))r)
A3(cpl,/*src,ast,loc*/y=cf(y);P(!y,x(z(0)))
 nb=1;fl=z;fc=a1(au);Ms(lu,-1,SZ lu);I r=cr(y);y(0);I o=0;h(bu);P(r-OK,eS(xR,r);ec0())
 P(_n(fl)>8||nb>=SZ b-1,eS(xR,0);ez0())i(8,Ij=lu[i];I(j>=0&&b[j]==bg,b[j]=bd))
 *b=mxs(1,0);*m=-1;AK(0,AT(to,cat(aV(tA,4,A(x,aCn(b,nb),aCn(m,nb),fl)),fc))))

S V mrn0(A*a,Nn){i(n,I(a[i],mr(a[i])))}
#define p(x) ({A x_=(x);Q(x_)Q(t<s)*--s=x_;})
#define q() ({Q(s<t+ns)Q(*s)*s++;})
AX(run,Q(xto)P(n-xk,er8(a,n))S I d;P(++d>1024,es8(a,n))
 UC*b=_V(xy),c;I ns=*b++,nl=_n(xA[3]);A t[ns+nl],*s=t+ns,*l=s;Mc(l,a,n*SZ x);Ms(l+n,0,(nl-n)*SZ*l);
 W((c=*b++),
  I(c>=bc,p(_R(xA[c-bc+4])))
  J(c>=bm,
   I(c==bm,A*v=l+*b++,x=*v?*v:au,y=q(),z=*s;*v=*s=0;*v=dm8(A(x,yR,av+*b++,z),4);B(!*v,y(0))*s=dot(_R(*v),y);B(!*s))
   J(c==bM,Ax=q(),y=q(),z=*s;*s=0;A w=mnd(A(x,yR,av+*b++,z),4,dm8);B(!w,y(0))*s=dot(w,y);B(!*s))
   J(c==bG,Ax=*--s=_A(gv)[*b++];B(!x,ev0())xR)
   J(c==bS,A*v=_A(gv)+*b++;I(*v,mr(*v))*v=_R(*s);)
   J(c==bl,Nn=*b++;s+=n-1;*s=sqz(aV(tA,n,s-n+1)))
   J(c==bL,Nn=*b++;Ax=*s;B(!xtt&&xN-n,*s=el1(x))i(n,p(ii(x,n-1-i))))
   J(c==ba||c==bP,Nn=*b++;Ax=s[n]=(c-ba?prj:_8)(*s,s+1,n);mr(*s);s+=n;B(!x))
   J(c==bz,b+=1+*b*!tru(q()))
   J(c==bj,b+=*b)
   J(c==bo,p(xR))
   J(c==bp,mr(q()))
   J(c==b4,s+=3;*s=dmd(s-3,4);B(!*s)))
  J(c>=bd,A*v=l+c-bd;p(*v?*v:au);*v=0)
  J(c>=bg,A*v=l+c-bg;p(_R(*v?*v:au)))
  J(c>=bs,A*v=l+c-bs,y=_R(*s);*v=*v?dex(*v,y):y)
  J(c>=bv,Ax=q();*s=v2[c-bv](x,*s);B(!*s))
  E(*s=v1[c](*s);B(!*s)))
 I(!*s,eS(_R(xx),_C(xz)[b-1-_C(xy)]);mrn0(s+1,t+ns-s-1))
 mrn0(l,nl);d--;Q(s==l-1)*s)
