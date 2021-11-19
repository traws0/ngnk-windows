#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
enum{bu,bv=32,bs=64,bg=72,bd=80,ba=88,bP,bi,bx,bI,bX,bm,bM,bG,bS,bl,bL,bz,bj,bA,bo,bp,bc};
#define h(a) {b[nb]=a;m[nb]=o;nb+=nb<255;}
#define hc(a) {N(lc(a,o));}
#define OK -1
#define Nr(a...) {I r=cr(a);P(r-OK,r);}
#define Nl(a...) {I r=cl(a);P(r-OK,r);}
#define fl uA[3]
S A u;S UC*b,*m;S I nb,lu[8];S A cr(A,I);
SN I lc(Ax/*1*/,I o)_(Ay=u;Nn=yn,i=4;W(i<n,B(mtc_(x,ya),x=x(0))i++)I(x,uq(x))h(i+bc-4);1)
SN I ig(Iv)_(Li=fI(gk,gn,v);P(i>=0,i)P(gn-(UC)gn,-1)gk[gn]=v;gv[gn]=0;gn++)
SN I il(Iv)_(Li=fAI(fl,v);P(i>=0,lu[i]=nb;i)-1)
S A cl(Ax,Ay/*00*/,I r)_(I o=xo;Q(xx==av||_t(xx)==tu)Iv=_v(xx);
 Ys(P(xx==av&&_n(fl),Li=fpI(&fl,yv);P(i>15,ez0())lu[i]=nb;h(bs+i)I(r,h(bg+i))OK)
  Ii=il(yv);P(i>=0,h(bm)h(i)h(v)I(r,h(bg+i))OK)i=ig(yv);P(i<0,ez0())h(v?bM:bS)h(i)I(v,h(v))I(r,h(bG)h(i))OK)
 YS(hc(av+v)hc(au)hc(yR)h(bA)I(!r,h(bp))OK)
 YA(In=yn-1;P(n-(UC)n,o)Az=yx;
  P(ztS,hc(av+v)i(n,Nr(yA[n-i],1))h(bl)h(n)hc(zR)h(bA)I(!r,h(bp))OK)
  P(zts,i(n,Nr(yA[n-i],1))h(bl)h(n);Ii=il(zv);P(i<0,hc(z)h(r?bX:bI)h(v)OK)h(r?bx:bi)h(i)h(v)OK)
  P(z==MKL&&xx==av,h(bL)h(n);i(n,Nl(x,yA[i+1],0))I(!r,h(bp))OK)o)o)
S A cr(Ax/*0*/,I r)_(I o=xo;
 Xs(Ii=il(xv);P(i>=0,h(bg+i)I(!r,h(bp))OK)P(xv=='o',I(r,h(bo))OK)i=ig(xv);P(i<0,ez0())h(bG)h(i)I(!r,h(bp))OK)
 XS(P(xn-1,hc(AO(0,xR))h(bu+DOT-av)I(!r,h(bp))OK)I(r,hc(ii(x,0)))OK)
 P(!xtA||!xn,I(r,hc(x-PLH?xR:au))OK)
 Nn=xn;Ay=xx;
 P(y==PRG,i(n-1,Nr(xA[i+1],i==n-2&&r))OK)
 P(n<2,I(r,hc(yR))OK)
 P(n==3&&(ytu||y==av)&&_tsSA(xy),Nr(xz,1);Nl(x,xy,1);I(!r,h(bp))OK)
 P(n>3&&y==CST,n--;I p[n];A*a=xA;i(n&~1,Nr(*++a,1);h(i&1?bj:bz)p[i]=nb;h(0))Nr(n&1?*++a:au,1);
  i(n&~1,I d=(i&1?nb-1:p[i+1])-p[i];I(i&1,Ij=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,ez0())b[p[i]]=d)I(!r,h(bp))OK)
 I(n==2&&y==FIR,Az=xy;P(ztA&&zn==2&&zx==REV,Nr(zy,1);h(bu+LAS-au)I(!r,h(bp))OK))
 I p=0;i(n-1,Az=xA[n-1-i];I(z==PLH,p=1;hc(PLH))E(Nr(z,1)))
 P(p,Nr(xx,1);h(bP)h(n-1)I(!r,h(bp))OK)
 P(y==MKL,n--;P(n-(UC)n,o);h(bl)h(n)I(!r,h(bp))OK)
 P(n==2&&ytu,h(bu+yv)I(!r,h(bp))OK)
 P(n==3&&ytv,h(bv+yv)I(!r,h(bp))OK)
 P(n>9,ez0();o)Nr(xx,1);h(ba)h(n-1)I(!r,h(bp))OK)
S A2(f2,/*0*/P(xtw&&!ytsSA,1)/*P(x==TIL&&ytZ&&yn<4,i(yn,P(!in(gl(ii(y,i)),101),0))1)*/0)
S A3(f3,/*0*/P(ADD<=x&&x<=MUL&&ytL&&ztL&&yn==zn&&yn<101,1)0)
S A1(qt,/*1*/xtsSA?enl(x):x)
S A1(cf,XA(P(xx==MKL,i(xn,Ay=xa;YsSA(x))a1(drp(1,x)))
           P(xn==2?f2(xx,xy):xn==3?f3(xx,xy,xz):0,qt(N(val(x))))
           AO(xo,cA(eac1f(x,cf))))x)
S I mxs(Ii,I s)_(I r=s;W(1,UC c=b[i++];Q(s>=0)r=max(r,s);P(!c,r)P(c==bz,i++;s--;max(r,max(mxs(i,s),mxs(i+b[i-1],s))))
 I(c>=bc||c==bo||c-bg<8u||c-bd<8u||c==bG,s++)J(c-bs<8u||c-bv<32u||c==bp||c==bm||c==bx||c==bM||c==bS,s--)
 J(c==bi||c==bX,s-=2)J(c==bI||c==bA,s-=3)J(c==bL,s+=b[i])J(c==bl||c==ba||c==bP,s-=b[i]-1)
 I(c==bm||c==bx||c==bM||c==bi,i+=2)J(c==bX||c==bI||c==bL||c==bl||c==ba||c==bP||c==bG||c==bS,i++)J(c==bj,i+=b[i]+1))r)
A3(cpl,/*src,ast,loc*/UC b0[256],m0[256];b=b0;m=m0;nb=1;Ik=zn;u=aV(tA,4,A(x,au,au,z));Ms(lu,-1,SZ lu);y=Nu(cf(y));
 I r=cr(y,1);y(0);I o=0;h(bu);P(r-OK,eS(_R(ux),r);u(0);ec0())P(_n(fl)>8||nb>=255||bc-4+un>255,eS(_R(ux),0);u(0);ez0())
 i(8,Ij=lu[i];I(j>=0&&b[j]==bg,b[j]=bd))*b=mxs(1,0);*m=-1;uy=aCn(b,nb);uz=aCn(m,nb);AK(k,AT(to,u)))

#define U(x,a...) B(!(x),a)
AX(run,Q(xto)P(n-xk,er8(a,n))S I d;P(++d>1024,es8(a,n))UC*b=_V(xy),c,ns=*b++,nl=_n(xA[3]);A t[ns+nl],*s=t+ns,*l=s;
 Ms(t,0,SZ t);Mc(l,a,8*n);
 W((c=*b++),
  I(c>=bc,*--s=_R(xA[c-bc+4]))
  J(c>=ba,
   I(c>=bA,
    I(c==bA,s+=3;U(*s=dmd(s-3,4)))
    J(c==bo,*--s=xR)
    E(Q(c==bp)mr(*s++)))
   E(Nn=*b++;
    I(c==ba||c==bP,Ax=*s,*p=s+1;s+=n;U(*s=x((c==ba?_8:prj)(x,p,n))))
    J(c==bi,Ax=l[n],y=*s++;U(x=l[n]=dm4(x?x:au,y ,av+*b++,*s),*s=0)s++)
    J(c==bx,Ax=l[n],y=*s++;U(x=l[n]=dm4(x?x:au,yR,av+*b++,*s),*s=y(0))U(*s=dot(xR,y)))
    J(c==bI,Ax=*s++,y=*s++;U(x=mnd(A(x,y ,av+n,*s),4,dm8),*s=0)s++)
    J(c==bX,Ax=*s++,y=*s++;U(x=mnd(A(x,yR,av+n,*s),4,dm8),*s=y(0))U(*s=dot(x,y)))
    J(c==bm||c==bM,A*v=(c==bm?l:gv)+n,x=*v;U(x,*s=ev1(*s))U(x=*v=v2[*b++](x,*s++),*--s=0))
    J(c==bG,Ax=*--s=gv[n];U(x,ev0())xR)
    J(c==bS,Ax=*s++,y=gv[n];gv[n]=y?y(x):x)
    J(c==bl,s+=n-1;*s=sqz(aV(tA,n,s-n+1)))
    J(c==bL,Ax=*s;U(xtt||xN==n,*s=el1(x))i(n,*--s=ii(x,n-1-i)))
    J(c==bz,b+=n*!tru(*s++))
    E(Q(c==bj)b+=n)))
  J(c>=bs,A*v=l+c%8,x=*v;
   I(c>=bd,*--s=x;*v=0)
   J(c>=bg,U(*--s=x)xR)
   E(Q(c>=bs)Ay=*s++;*v=x?x(y):y))
  J(c>=bv,Ax=*s++;U(*s=v2[c-bv](x,*s)))
  E(U(*s=v1[c](*s))))
 I(!*s,eS(_R(xx),_C(xz)[b-1-_C(xy)]))i(t+ns+nl-s-1,Ax=s[i+1];I(x,mr(x)))d--;Q(s==l-1)*s)
