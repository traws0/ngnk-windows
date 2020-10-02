#include"a.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
enum{bu,bv=0x20,bs=0x40,bg=0x50,bd=0x60,bm=0x70,bM,bl,bL,ba,bP,bz,bj,bo,bp,br=0x7f,bc=0x80,bC=0xff};S A2 cr;
#define fs xx    //src           BYTECODE                               ba:apply n-adic      f[x;y;z]
#define fb xy    //bytecode      bu,bv:apply unary|binary verb   +x*y   bP:make projection   f[x;;z]
#define fm xz    //srcmap        bs,bg,bd:set|get|delete local    a:b   bz:branch if falsey  $[x;y;z]
#define fl xa[3] //local syms    bm,bM:l|glb modified assign  a[i]+:b   bj,bp,br:jmp|pop|ret $[x;:y;]
#define fc xa[4] //constants     bl,bL:make|unmake list   (a;b):(c;d)   bc:load constant     12;`a;""
#define h(a) ({fb=apc(fb,(C)(a));fm=apc(fm,o);}) //add byte
#define hc(a) ({I b=bc+fpa(&fc,a);P(b>bC,err("mxc"))h(b);}) //add a "load constant" instruction
#define lu ((I*)dat(xa[5])) //last usages of locals
#define l(a...) N(cl(a)) //compile left-hand side of assignment
#define r(a...) N(cr(a)) //right
S A3(cl,/*0*/UH o=yo;P(zts&&yx==av0&&xk,L i=fpi(&fl,gs(z));P(i>15,err("mxl"))lu[i]=An(fb);h(bs|i);x)
 P(ztS&&!Av(yx),hc(av0);hc(au0);hc(zR);hc(cv('.'));h(ba);h(4);x)
 P(zts||(ztA&&At(zx)==ts),Y(zts,hc(a0()))E(F(zn-1,r(x,za[zn-1-i]))h(bl);h(zn-1))
  I k=gs(zts?z:zx);L i=fndi(fl,k);Y(i<0,hc(as(k));h(bM))E(lu[i]=An(fb);h(bm);h(i))h(Av(yx));x)
 P(ztA&&zx==av_mkl,h(bL);h(zn-1);F(zn-1,l(x,y,za[i+1]);h(bp))1)err("cpl");eso(mR(fs),o);0)
S A2(cr,/*0*/UH o=yo;Y(yts,P(gs(y)==syC('o'),h(bo);x)L i=fndi(fl,gs(y));P(i>=0,lu[i]=An(fb);h(bg|i);x))P(ytS&&yn==1,hc(as(*yl));x)
 P(ytsS,hc(AO(0,yR));h(bu|vi('.'));x)P(!ytA,hc(y==au_plc?au0:yR);x)L n=yn;P(!n,hc(yR);x)A u=yx;P(utS&&n==1,hc(uR);x)
 P((utu||u==av0)&&n==3,r(x,yz);l(x,y,yy))
 P(u==cv('$')&&n>3,n--;I p[n];A*a=ya;F(n&~1,r(x,*++a);h(i&1?bj:bz);p[i]=An(fb);h(0))r(x,n&1?*++a:au0);
  A z=fb;F(n&~1,I d=(i&1?zn:p[i+1])-p[i];Y(i&1,I j=(n&~1)-1;W(i<j&&d>255,d=p[j]-1-p[i];j-=2))P(d>255,err("mxj");0)zc[p[i]]=d)1)
 Y(u==cu('*')&&n==2,A z=yy;P(ztA&&zn==2&&zx==cu('|'),r(x,zy);h(bu|24);x))Y(utw&&n==2,A z=yy;P(!ztA&&!ztsS,zR;hc(app(u,&z,1));x))
 I p=0;F(n-1,A z=ya[n-1-i];z==au_plc?(p=1),hc(zR):r(x,z))P(p,r(x,yx);h(bP);h(n-1);x)P(u==av0&&n==2,h(br);x)P(u==av_mkl,h(bl);h(n-1);x)
 P(utu&&n==2,h(bu|uv);x)P(utv&&n==3,h(bv|uv);x)r(x,yx);h(ba);h(n-1);x)
A1(cpl,C k=xk;x=mut(x);A y=fb;fb=fm=mR(aC(0));fc=a1(au0);xa[5]=aI(16);C o=0;ms(lu,-1,64);F(yn,P(!cr(x,yai),xr;yr;0)h(i==yn-1?br:bp))yr;
 y=fb;asrt(Ar(y)==1);Fj(16,I i=lu[j];Y(i>=0&&yci==bg,yci=bd))mr(xa[5]);AK(k,AT(to,x)))

S A s0[65536],*s=s0+ZZ(s0),*l;S C*c;S A1(p,*--s=x)S A0(q,*s++) //s:stack,l:locals,c:current instruction,p:push,q:pop
S A1(vm,/*0*/W(1,C b=*c++;
 Y(b>=bm,Y(b>=bc,A y=fc;p(mR(ya[b-bc])))
        EY(b==bm,A*v=l-*c++,y=q();N(*s=apn(mR(*v=Ny(dm1(A(*v,yR,av(*c++),*s),4))),y)))
        EY(b==bM,A x=q()   ,y=q();N(*s=apn(      Ny(dmd(A(x ,yR,av(*c++),*s),4)) ,y)))
        EY(b==bl,C n=*c++;A x=sqz(atnv(tA,n,s));s+=n;p(x))
        EY(b==bL,C n=*c++;A x=*s;el(!xtt&&len_(x)-n)F(n,p(get(x,n-1-i))))
        EY(b==ba||b==bP,C n=*c++;A u=s[n]=(b==ba?app:prj)(*s,s+1,n);mr(*s);s+=n;N(u))
        EY(b==bz,c+=1+*c*!tru(q()))EY(b==bj,c+=(C)*c)EY(b==bo,p(mR(l[1])))EY(b==bp,mr(q()))E(asrt(b==br);_(*s)))
 EY(b>=bs,A*v=l-b%16,x=*v;Y(b>=bd,p(x);*v=au0)EY(b>=bg,p(xR))E(xr;*v=mR(*s)))
 EY(b>=bv,A x=q();N(*s=((A2*)vf[b])(x,*s)))E(N(*s=((A1*)vf[b])(*s))))0)
AX(run,asrt(xto);asrt(n==xk);P(s<s0+16,esn(n,a))p((A)c);p((A)l);p(x);c=dat(fb);l=s-1;I m=An(fl);F(n,p(a[i]))F(m-n,p(au0))
 A u=vm(x);Y(!u,A y=fb,z=fm;eso(mR(fs),zc[c-1-yc]);W(s<l-m,A x=q();Y(x,mr(x))))asrt(s==l-m);mrn(m,s+1);s=l+2;l=(V*)q();c=(V*)q();u)
