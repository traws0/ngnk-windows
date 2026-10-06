#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define C2(x,a...) case x:C(a)
#define C6(u,v,w,x,y,z,a...) case u:case v:case w:case x:case y:case z:{a;break;}
#define C16(x,a...) case x:case x+1:case x+2:case x+3:case x+4:case x+5:case x+6:case x+7:case x+8:case x+9:case x+10:case x+11:case x+12:case x+13:case x+14:case x+15:{a;break;}
#define C32(x,a...) C16(x,C16(x+16,a))
#define U(x,a...) I(!(x),a;goto l)
#define OFF 4 //offset of constants in a function object
#define n1 -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
#define p1  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
enum {bu,  bv=32,bs=64,bg=80,bd=96,ba=112,bp,bm,bM,bx,bX,by,bY,bG,bS,bl,bL,bz,bj,bo,bP,bV,bn,bc};        //opcodes
Z CO C di[]={                     [ba]= 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 0},        //extra bytes after opcode
ds[]={[bv]=n1,n1,n1,   p1,   p1,  [ba]= 1, 1,-1,-1,-1,-1,-1,-1, 1,-1, 1, 0,-1, 0, 1,-1, 0, 0, 1},        //stack size delta
ks[]={                            [ba]=-1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 1, 0, 0, 0, 0, 0, 0, 0};        //stack size delta (coefficient for the next byte)
AX(run,Q(xto)Z I d;P(++d>2048,es8(a,n))P(n-xk,er8(a,n))UC*b=_V(xy),*start=b,*b0,c,nl=_n(xA[3]);A l[nl+1+*b++],*s=l+L(l)-1,oc=0;MS(l,0,SZ l);MC(l,a,8*n);//virtual machine
 W((c=*(b0=b++)),S(c,                                                                                    //          |BYTES |          STACK        |         EFFECT
  C32(bu,U(*s=v1[c-bu](*s)))                                                                             //monad     |bu+m  |.. x -> monads[m][x]   |
  C32(bv,A x=*s++;U(*s=x(v2[c-bv](x,*s))))                                                               //dyad      |bv+d  |.. y x -> dyads[d][x;y]|
  C16(bs,A*p=l+c%16;I(*p,mr(*p))U(s-l<L(l)-1,*s=el0())*p=*s++)                                           //set local |bs+i  |.. x -> ..             |locals[i]:x
  C16(bg,A*p=l+c%16,x=*p;U(*--s=x)xR)                                                                    //get local |bg+i  |.. -> .. locals[i]     |
  C16(bd,A*p=l+c%16,x=*p;U(*--s=x)*p=0)                                                                  //del local |bd+i  |.. -> .. locals[i]     |locals[i]:NULL (freed)
  C2(ba,bp,UC n=*b++;A x=*s;s+=n;U(*s=x((c==ba?_8:prj)(x,s-n+1,n))))                                     //apply|proj|ba,n  |.. z y x -> .. x[y;z]  |
  C6(bm,bM,bx,bX,by,bY,A*p=(c&1?gv:l)+*b++,x=*p;U(x,*s=ev(*s))A y=*s++;                                  //          |      |                       |
   I(c==bm||c==bM,y=v2[*b++](x,y);U(y,*--s=0)*p=x(y))                                                    //mod asgn  |bm,i,d|.. x -> ..             |vars[i]:dyads[d][vars[i];x]
   E(x=*p=d4(x,y,av+*b++,*s);mr(*s);I(c==bx||c==bX,mr(y);U(x,*s=0)s++)                                   //ind asgn  |bx,i,d|.. z y -> ..           |vars[i]:  .[vars[i];y;dyads[d];z]
                                    E(U(x,*s=y(0))U(*s=dot(x,y)))))                                      //ind asgn  |by,i,d|.. z y -> .. r         |vars[i]:r:.[vars[i];y;dyads[d];z]
  C(bG,A x=*--s=gv[*b++];U(x,ev0())xR)                                                                   //get global|bG,i  |.. -> .. globals[i]    |
  C(bS,A*p=gv+*b++,x=*s++,y=*p;*p=y?y(x):x)                                                              //set global|bS,i  |.. x -> ..             |globals[i]:x
  C(bl,UC n=*b++;s+=n-1;*s=sqz(aV(tA,n,s-n+1)))                                                          //list      |bl,n  |.. y x -> .. (x;y)     |
  C(bL,UC n=*b++;A x=*s;I(n==2&&xtm,A y=kv(&x);*s=x=aA2(x,y))
    U(xtt||!xtm&&xN==n,*s=el(x))F(n,*--s=ii(x,n-1-i)))                                                   //unlist    |bL,n  |.. x -> .. x[0] x[1]   |
  C(bj,UC n=*b++;b+=n)                                                                                   //jump      |bj,n  |.. x -> ..             |PC+:n
  C(bz,UC n=*b++;b+=n*!tru(*s++))                                                                        //branch    |bz,n  |.. x -> ..             |if x is falsy, PC+:n
  C(bo,I(*b++&&s-l>=L(l)-n-1,U(oc++<1<<16,*s=ez0());b=start+1;s=l+L(l)-1)E(*--s=xR))                     //recur     |bo    |.. -> .. o             |o is the current lambda
  C(bP,mr(*s++))                                                                                         //pop       |bP    |.. x -> ..             |
  C(bn,b+=2)                                                                                             //filler    |bn    |.. x -> ..             |
  C(bV,UC i=*b++;U(*s=v2[*b++](_R(xA[i+OFF]),*s),mr(xA[i+OFF]))mr(xA[i+OFF]))                            //const dyad|bV,i,d|.. x -> .. r           |r:dyads[d][consts[i];x]
  D(*--s=_R(xA[c-bc+OFF]))))                                                                             //const     |bc+i  |.. -> .. consts[i]     |
   l:d--;A u=*s;MS(l+nl,0,s-l-nl+1<<3);F(L(l),A x=l[i];I(x,mr(x)))I(!u,A y=xz;UH f=0,*m=(UH*)xz;UC*e=_C(xy)+1,fd=0;W(e<b0&&(H*)m<yH+yn,UC* d=(UC*)m++;I(d[0]-255,e+=d[0];fd=d[1])E(f=*m++;fd=0))eS(xx,f+fd))u)
#define Nr(a...) {I r_=cr(a);P(r_-OK,r_);}                                                               //compile rvalue; return on error
#define Nl(a...) {I r_=cl(a);P(r_-OK,r_);}                                                               //compile lvalue; return on error
#define OK -1                                                                                            //returned by cl() and cr() on success
#define MB 256                                                                                           //max bytecode size
Z A u,lu,ms;Z UC *b;Z H *m;Z I ol,nb,nb0,nl,ml,l[16],cr(A,B);                                            //u:lambda(src;b:bytes;m:map;l:locals;consts..)
#define M(a) {_C(uy)[nb]=a;nb+=nb<_n(uy)-1;}                                                             //append byte
#define SM {A y=uz;Q(nb-nb0<255)UC bd=nb-nb0;nb0=nb;I od=o-ol;I(m+2>yH+yn,uz=aa(2*yn,y);m=_H(uz)) \
  I(od>255,*(m++)=255;*(m++)=o;ol=o;od=0)J(od<0,*(m++)=255;ol=MAX(0,o-8);*(m++)=ol;od=o-ol) \
  *(m++)=bd|(od<<8);}                                                                                    // append debug stab
#define SE(a,b) {M(a)I(0<=(b),M(b))A u=ms;UC c=MIN(bc,(a));A z=mut(uA[un-1]);I(c==bV,MC(zH,sec,4))I(zH[0]>=0,zH[1]+=ds[c]+ks[c]*(H)(b);zH[0]=MAX(zH[0],zH[1]));uA[un-1]=z;}
B gr(I r,I l,I p)_(A y=uy;P(nb>yn-p,uy=aa(2*yn,y);nb=r;ml=l;b=_C(uy);m=_H(uz);1)0)                       // grow byte code buffer
ZN I li(I v)_(U i=fI(l,nl,v);P(i==nl,-1);i)                                                              //index of a local variable (returns -1 if not found)
ZN V rl(I v,U m){I j=0,*p=_I(lu);F(_n(lu),                                                               //reference local variable (m:mode 0=write, 1=read, 2=delete)
 I((b[p[i]]&15)!=v,p[j++]=p[i])J(m&&LH(bd,b[p[i]],bd+15),b[p[i]]+=bg-bd));AN(j,lu);I(m==2,PSH(lu,ai(nb)))}
ZN A2(mu/*11*/,A z=an(xn+yn,tI);I *p=zI;U i=0,j=0,n=xn,m=yn;W(i<n&&j<m,                                  //merge uses of local variables
 I(xI[i]<yI[j],*p++=xI[i++])J(yI[j]<xI[i],*p++=yI[j++])E(*p++=xI[i++],j++))W(i<n,*p++=xI[i++])W(j<m,*p++=yI[j++]);zn=p-zI;x(y(z)))
Z B cm(A x/*0*/){X(Rv(!xv)Ru(1)RS(P(xn-1,0)S s=su(*xI);U n=SL(s);n&&s[n-1]==':')R_(0))}                  //is x a valid modifier? i.e. :: or primitive monad or symbol ending with ":"
Z H sec[2];
Z V cc(A x/*0*/){U n=un,i=OFF;                                                                           //append a "load constant" instruction
  W(i<n&&!mtc_(x,ua),i++)I(i>=n,PSH(u,xR))MC(sec,(V*)_A(ms)[-1+_n(ms)],4);SE(i+bc-OFF,-1)}
Z I cl(A x,A y/*00*/,B r){I ns=nb;Q(cm(xx))I v=_v(xx),o=xo;                                              //compile lvalue (x:assignmentNode,y:tree,r:wantResult)
 Y(R_(o)
   Ru(P(y-au,o)I(!r,SE(bP,-1))OK)                                                                        // (::): x    discard
   RS(I(yn==1,I w=*yI,i=li(w);P(xx==av&&nl,I(i<0,i=nl;P(i>15,o)l[nl++]=w;ml=MAX(ml,nl))I(i>=ml,ml++)rl(i,0);SM;SE(bs+i,-1);I(r,o=yo;rl(i,2);SE(bd+i,-1))OK)P(i>=0&&xx!=au,rl(i,1);SM;SE(bm,i)M(v)I(r,o=yo;rl(i,2);SE(bd+i,-1))OK))
      UC i=gi(y);SM;SE(v?bM:bS,i)I(v,M(v))I(r,SM;SE(bG,i))OK)
   RA(I n=yn-1;P(n==-1,SM;SE(bL,0)I(!r,SE(bP,-1))OK)P(n>8u,o)A z=yx;C j=1;I(!n,y=z;P(!ytA,o)z=MKL;j=0;n=yn;F(n,P(ya-au,o)))P(z==MKL&&(xx==av||_t(xx)==tu)||n==1&&z==ENL,SM;SE(bL,n)F(n,Nl(x,yA[i+j],0))I(r,P(xx-av&&xx-au,o))E(SE(bP,-1))OK)
      ZS(F(n,Nr(yA[n-i],1))SM;SE(bl,n)I i=zn-1?-1:li(*zI);i=i<ml?i:-1;I(i>=0,SM;SE(r?by:bx,i)rl(i,1))E(i=gi(z);SM;SE(r?bY:bX,i))M(v)OK)o))}
Z I cr(A x/*0*/,B r)_(                                                                                   //compile rvalue (x:tree,r:wantResult)
 XS(I o=xo;I i=xn-1?-1:li(*xI);i=i<ml?i:-1;                                                              // x.y      variable (possibly qualified)
    I(i>=0,rl(i,2);SE(bd+i,-1);)J(xn==1&&*xI=='o',SM;SE(bo,-1)M(0))E(SM;SE(bG,gi(x)))I(!r,SE(bP,-1))OK)
 P(!xtA||!xn,I(r,cc(x-GAP?x:au))OK)                                                                      // 0        constant
 U n=xn;A y=xx;                                                                                          //
 P(y==GAP,F(n-1,A z=xA[i+1];               // [x;y]    block
            Nr(z,i==n-2&&r))OK)
 P(n==1,I(r,cc(y))OK)                                                                                    // `a       quoted
 I o=xo;
 P(n==3&&cm(y)&&(_tchk(_tsSA,xy)),                                                                       // x[y]+:z     assignment
  YS(I o=yo;Nr(xz,1);Nr(xy,1);A z=AO(o,enl(cS(drp(-1,str(ii(y,0))))));Nr(z,1);mr(z);SE(ba,2)z=AO(o,aA1(au));Nl(z,xy,r);z(0);OK)
  Nr(xz,1);Nl(x,xy,r);OK)
 P(n>3&&(y==av||y==DLR),n--;I p[n];A*a=xA,v=an(0,tH);A k=_R(_A(ms)[-1+_n(ms)]);                          // :[x;y;z] cond
  F(n/2,PSH(ms,k);Nr(*++a,1);SE(bz,0)k=aV(tH,2,_V(_A(ms)[-1+_n(ms)]));p[2*i]=nb-1;A w=aV(tI,_n(lu),_V(lu));Nr(*++a,r)v=mu(v,lu),lu=w;SE(bj,0)p[2*i+1]=nb-1;)PSH(ms,k);Nr(n&1?*++a:au,r);lu=mu(lu,v);
    {I b=0,c=n+2>>1;A x=ms,z=xA[xn-c-1];F(c,A y=xA[xn-c+i];I(yH[0]<0,SW(xA[xn-c+i],xA[xn-c+i-b]))E(b++;I(zH[0]<yH[0],zH[0]=MAX(zH[0],yH[0]);zH[1]=MAX(zH[1],yH[1]))J(zH[0]==yH[0],zH[1]=MAX(zH[1],yH[1]))))F(c-b,SW(xA[xn-c-1+i],xA[xn-c+i]))ms=drp(-b,x);}
  F(n&~1,I d=(i&1?nb-1:p[i+1])-p[i];I(i&1,I j=(n&~1)-1;W(i<j&&d>255,d=p[j]-2-p[i];j-=2))P(d>255,o)b[p[i]]=d)OK)
 I(n==2&&y==FIR,A z=xy;I(ztA&&zn==2,P(zx-REV<3u,Nr(zy,1);SM;SE(bu+zx-REV+LAS-au,-1)I(!r,SE(bP,-1))OK)))  // *|x      recognized idioms
 I p=0;F(n-1,A z=xA[n-1-i];I(z-GAP,Nr(z,1))E(p=1;cc(GAP)))I(p,Nr(xx,1);SM;SE(bp,n-1))                    // x[y;]    projection
 J(y==MKL,n--;P(n>255u,o)SM;SE(bl,n))                                                                    // (x;y)    list
 J(n==2&&ytu,SM;SE(bu+yv,-1)I(!yv,AN(0,lu);A z=_A(ms)[-1+_n(ms)];I(zH[0]>=0,zH[0]=-zH[0])))              // +x       monad
 J(n==3&&ytv,I(!p&&!_tchk(_tSA,xy),Q(nb==_n(uy)-1||b[nb-1]>=bc);                                         // x+y      dyad
               I i=b[--nb]-bc;SM;SE(bV,i)M(yv))E(SM;SE(bv+yv,-1)))
 E(P(n>9,o)Nr(xx,1)SM;SE(ba,n-1))                                                                        // x[y]     application
 I(!r,SE(bP,-1))OK)
A1(qte,/*1*/xtS||xtA?aA1(x):x)                                                                           //quote
Z A2(c2,/*00*/P(xtw&&!ytSA,1)/*P(x==TIL&&ytZ&&yn<4,F(yn,P(gl(ii(y,i))>100u,0))1)*/0)                     //constant folding
Z A3(c3,/*000*/P(x==aw&&ytU&&ztU,1)P(ADD<=x&&x<=MUL&&ytzZ&&ztzZ&&(ytt||ztt||yn==zn)&&MAX(xN,yN)<101,1)0) //constant folding
A1(cp,/*1*/A y=xy,z=xz;P(ytU&&yK==1,
 P(ztU,AZ(x);P(ztq,A u=zy;P(utq,PSH(zy,y);x(AO(yo,z)))zy=com(y,u);x(y(AO(yo,z))))x(y(AO(yo,com(y,z)))))
 P(ztA&&zn==3&&zx==aw,A u=zy;P(utU&&uK==1,AZ(x);P(utq,PSH(zy,y);x(z))zy=com(y,zy);x(y(z)))x)x)x)
A1(cf,P(!xtA||!xn,x)I m=xo;x=AO(m,mut(x));
   P(xx==GAP,A y=rsz(xn,au);yx=GAP;Fj(xn-1,U i=j+1;A u=xa;xa=au;ya=u;I(utSA&&un,U m=uo;ya=cf(u);ya=ytSA&&yn?AO(m,ya):ya)P(!ya,die("CF")))AO(xo,x(y)))
   A y=rsz(xn,au);C t=0;B q=0;F(xn,A u=ya=cf(xa);xa=au;I(utSA,q=1)t|=(u==GAP|utSA<<1);P(!ya,die("CF")))y=x(AO(xo,y));
   P(yx==MKL,P(q,y)qte(N(drp(1,y))))I(_tchk(_tw,yx),I(yn==3,y=cp(y))P(!ytA||!yn,y))P(yn==2?c2(yx,yy):yn==3?c3(yx,yy,yz):0,qte(N(val(y))))A u=yx;P(t-1||u==DLR||!utU,y)AZ(y);u(y(AO(uo,prj(u,yA+1,yn-1)))))
Z B shy(A x/*0*/)_(P(!xtA||xn<2,0)P(xx==GAP,A u=xA[xn-1];shy(u))xn==3&&cm(xx)&&_tchk(_tSA,xy))     //is last expr an assignment?
Z V tco(C k,UC* s){I i=1,l=nb;B o=0,e=0;W(i<l,I(b[i]==bo&&b[i+2]==ba,UC *c=b+i+4;W(c-s<l&&*c==bj,c+=2+*(c+1))I(c-s==l-1&&l-i-2<256,I(!e,e=1;F(k,M(bs+i))M(bo)M(1))b[i]=bj;b[i+1]=l-i-2;b[i+2]=bu))i+=1+di[MIN(bc,b[i])])}
A3(cpl,/*111*/u=aA(OFF);uy=aC(MB);uz=aH(MB);m=_H(uz);b=_C(uy);nb=nb0=1;I ls,ns=nb;lu=an(0,tI);ms=emp(tA);A j=aH(2);PSH(ms,j);I r,k=0;I(z,k=zn;MC(l,zV,OFF*k);z(0))nl=ml=ls=k;y=Nx(cf(y));ux=x;uA[3]=au;B s=shy(y);B p=1;W(p,ms=rsz(1,ms);MS(_V(*_A(ms)),0,4);r=cr(y,!s);p=gr(ns,ls,4);AN(0,lu);)y(0);P(r-OK,ec0();eS(ux,r);mrn(2,A(lu,ms));u(0))
   ol=0;I(s,cc(au))P(un>255||nl>L(l)-2,ez0();eS(ux,0);mrn(2,A(lu,ms));u(0))SE(bu,-1)p=1;ns=nb;ls=nl;UC* st=(UC*)uy;W(p,tco(k,st);p=gr(ns,ls,0))P(un>255-bc,eS(ux,0);u(0);ez0())AN(m-(H*)uz,uz);
 UC se=0;{A x=ms;F(xn,A y=xa;H v=yH[0];P(v>255||-v>255,mrn(2,A(lu,ms));es(u))v=v<0?-v:v;se=MAX(se,v))}
 mrn(2,A(lu,ms));*b=se;AN(nb,uy);uA[3]=aV(tS,nl,l);AK(k,AT(to,u)))
#undef SE
#undef SM
#undef M
