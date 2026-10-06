#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
#endif
#if __LP64__||_WIN64
 #define AP(p) ((A)(p))
#else
 #define AP(p) ((A)(U)(p)) //A from pointer
#endif
#ifdef shared
__attribute((weak, visibility("default"))) V kinit();
#endif
#ifndef ver
#define ver "none"
#endif

Z ST{V*p;W n;B f;}reg[128];Z U nreg;Z UC pnd[128];Z U npnd;
Z V mc(){P(!npnd)F(npnd,U j=pnd[i];munmap(reg[j].p,reg[j].n);reg[j].p=0)npnd=0;U j=0;F(nreg,I(reg[i].p,MC(reg+j,reg+i,SZ*reg);j++))nreg=j;}
Z A mu(V*p)_(F(nreg,P(reg[i].p==p,pnd[npnd++]=i;0))die("UNMAP"))
  V*mm(W n,U f)_(V*p=mmap(0,n,PROT_READ|PROT_WRITE,MAP_NORESERVE|MAP_PRIVATE|MAP_ANON,-1,0);P((L)p==(C)p,(V*)0)I(nreg==L(reg),mc();I(nreg==L(reg),die("MMAP")))reg[nreg++]=(TY(*reg)){p,n,f};p)
A mf(U f,U i,U n)_(V*p=mm(pg+n,1);P(!p,eo0())P(mmap(p+pg,n,PROT_READ|PROT_WRITE,MAP_NORESERVE|MAP_PRIVATE|MAP_FIXED,f,i)!=p+pg,mu(p);eo0())A x=AP(p+pg);xb=0;xr=REFB;xT=tC;xn=n;x)

Z A bkt[24];DBG(Z U lck;)
Z W cap(A x/*0*/)_((HD<<xb)-HD)
Z A mb(U i)_(P(i>=L(bkt),V*p=mm(HD<<i,0);P(!p,die("OOM"))AP(p+HD))A x=bkt[i];P(x,bkt[i]=xX;DBG(xX=0);x)x=mb(i+1);A y=x+(HD<<i);MS(yV-HD,0,HD);yb=i;yX=bkt[i];bkt[i]=y;x)
A1(m0,DBG(lck++;)Q(x)XP(0)Q(xr)P(xr>REFB,xr--;0)I(TR(xT),mrn(xn|!xn,xA);xT=tL)U i=xb;P(!i,mu(xV-pg))P(i>=L(bkt),mu(xV-HD))xX=bkt[i];bkt[i]=x;xr=0;x)
DBG(A1(m1,lck--;P(!x||!xb,0)MS(xV,0xab,cap(x));xn=-1;xT=0;0))
A1(_R,Q(x)XP(x)xr++;x)
A1(mr,DBG(m1)(m0(x)))
V mRn(U n,CO A*a){F(n,_R(a[i]))}
V mrn(U n,CO A*a){F(n,mr(a[i]))}
A1(mRa,mRn(xn|!xn,xA);x)

A AW(C w,A x)_(Q(w<6u);xE=w;x)
NI A an(U n,C t)_(Q(!lck)Q(tA<=t)Q(t<tn)Q(!TP(t))U i=59-CLZ(HD|HD-1+(((W)n<<Tw[t])+7>>3));A x=mb(i);xb=i;xr=REFB;xT=t;xn=n;x)
A aV(C t,U n,CO V*v)_(A x=an(n,t);n|=!n;MC(xV,v,((W)n<<Tw[t])+7>>3);x)
A aa_(U n,A x,B c/*n?c*/)_(P(MINE(x)&&((W)n<<xw)+7>>3<=cap(x),AN(n,c?x:xR))A y=an(n,xt);MC(yV,xV,((W)(xn|!xn)<<Tw[xt])+7>>3);I(ytR,I(MINE(x),AZ(x))E(mRa(x)))c?x(y):y)//realloc
A aa(U n,A x/*n1*/)_(aa_(n,x,1))//realloc
A aA0(U n)_(A x=AN(0,aA(n));xx=emp(tC);x)
A1(aA1,aV(tA,1,&x))
A2(aA2,/*11*/aV(tA,2,A(x,y)))
A3(aA3,/*111*/aV(tA,3,A(x,y,z)))
A2(aM,/*11*/Q(xtMT)Q(ytA )Q(xN==yN)aV(tM,2,A(x,y)))
A2(am,/*11*/Q(xtMT)Q(ytMT)Q(xN==yN)aV(tm,2,A(x,y)))
A aA(U n)_(an(n,tA))
A aB(U n)_(an(n,tB))
A aG(U n)_(an(n,tG))
A aH(U n)_(an(n,tH))
A aI(U n)_(an(n,tI))
A aL(U n)_(an(n,tL))
A aF(U n)_(an(n,tF))
A aC(U n)_(an(n,tC))
A aS(U n)_(an(n,tS))
A aCn(S s,U n)_(aV(tC,n,s))
A aCm(S p,S q)_(aCn(p,q-p))
A aCz(S s)_(aCn(s,SL(s)))
A az(L n)_(n-(I)n?al(n):ai(n))
A al(L v)_(aV(tl,1,&v))
A af(F v)_(aV(tf,1,&v))
A ar(L v,C w)_(A x=aV(tr,1,&v);AW(w,AK(0,x)))
A aE(L i,L j)_(Q(i<=j)P(i==j,emp(tG))A x=an(tE,2);*xL=i;xL[1]=j;x)
A mut_(A x,B c)_(XP(x)P(MINE(x),c?x:xR)A y=aV(xt,xn,xV);x=c?x(y):y;XR(mRa(x))x)
A1(mut,mut_(x,1))
C tZ(L v)_(G(tL,tL,tL,tL,tI,tI,tH,tG)[CLZ(v^v>>63|1)-1>>3])
A kv(A*p)_(A x=*p;Q(xn==2);P(!MINE(x),--xr;*p=_R(xx);_R(xy))*p=xx;AZ(x);x(xy))
L gl_(A x)_(XP(xv)*xL)
L gl(A x)_(L v=gl_(x);x(0);v)
F gf(A x)_(F v=*xF;x(0);v)
A AT(W t,A x)_(Q(t<tn);P(TP(t),Lt(t)|-1ull<<56&x)xT=t;x)
A AK(C k,A x)_(Q(k<9u);xk=k;x)
A AO(U m,A x/*m1*/)_(XSA(U n=xn;x=AN(n,aa(n+1,x));XS(xI[n]=m;x)xL[n]=m;x)x)
A AN(U n,A x)_(P(xtM,AN(n,_x(xy));x)xn=n;x)
A1(AZ,xT=tG;x)

Z C s0[1<<16],*s1=s0+1;U ht[1<<16];
Z I hhs(S c,N n,U s)_(W h=0,w=0;F(n>>3,MC(&w,c,8);c+=8;h=hc0(h^w))w=0;MC(&w,c,n&7);hc0(h^w)%s)
Z I hi(S s,N n)_(U h=hhs(s,n++,L(ht)),i=0;W(ht[h%L(ht)]>0,P(i>=L(ht),ez0())B(!strncmp(s0+ht[h%L(ht)],s,n));h+=++i)h%=L(ht);P(ht[h]>0,-h)P(s1+n+1>s0+SZ(s0),die("SYMS"));MC(s1,s,n);ht[h]=s1-s0;s1+=n;-h)
S su(U u)_(P(u&1<<31,s0+ht[-u])Z W r;r=u;(V*)&r)
U us(S s)_(U n=SL(s);P(n<4||(n==4&&!(s[3]&128)),U v=0;MC(&v,s,n);v)hi(s,n))
A sym(S s)_(as(us(s)))

#define KSZ 256
Z S kss[KSZ];Z A ksl[KSZ];
A ksg(S l){I h=hhs((S)&l,SZ(S),KSZ),h0=h;W(ksl[h%KSZ]>0,P(h-h0>=KSZ,ez0())B(kss[h%KSZ]==l);++h);h%=KSZ;kss[h]=l;P(ksl[h],ksl[h]);return evs(l,0);}

Z U gd,gn;Z W gk[256];A gv[256];
Z W gkk(A x/*0*/)_(Xs((U)xv)Q(xtS)xn?(W)_v(jS(drp(-1,xR)))<<32|(U)_v(ii(x,xn-1)):0)
UC gi(A x/*0*/)_(W k=gkk(x);I(!(k>>32)&&id0(*su(k)),k|=(W)gd<<32)U i=fL(gk,gn,k);P(i<gn,i)P(gn>=L(gv),die("GLOBALS"))gk[gn]=k;gv[gn]=0;gn++)
A gg(A x/*1*/)_(//get value of global
 P(xtS&&!xn,x(0);A x=emp(tS),y=emp(tA);F(gn,I(gv[i],L k=gk[i];PSH(x,k-(U)k?jS(aV(tS,2,A((I)(k>>32),k))):as(k));PSH(y,_R(gv[i]))))am(x,y))//special case for 0#`
 W k=gkk(x);x(0);U i=fL(gk,gn,k);i<gn&&gv[i]?_R(gv[i]):ev0())
A*gp(A x/*1*/)_(UC i=gi(x);x(0);gv+i)//get pointer to global
A gns(U k)_(I a[L(gk)];U n=0;F(gn,I(gk[i]>>32==k,a[n++]=gk[i]))aV(tS,n,a))//list namespace
V*ggp(S s)_(A x=gg(sym(s));xV)I ggn(S s)_(A x=gg(sym(s));xn)

Z A bs0(S s)_(en0())
Z A bsbs(S s)_(exit(0);0)
Z A bscd(S s)_(P(!*s,C b[256];getcwd(b,SZ b)?eo0():aCz(b))chdir(s)?eo0():au)
Z A bsd(S s)_(P(!*s,as(gd))s+=*s=='.';gd=us(s);au)
  A bsl(S s)_(I f=open(s,0,0);A x=u1c(ai(f));close(f);N(x);P(!xn,x(au))C*p=xC,*e=p+xn-1;P(*e-10,x(err0("eoleof")))*e=0;I(*p=='#'&&p[1]=='!',p=strchrnul(p,10);p+=!!*p)x(evs(p,1)))
Z A bsf(S s)_(K1("{`0:($!h),'\":\",'`k'. h:(&x=^`o`p`q`r`u`v`w`x?@'h)#h:``repl_.:0#`}",ai(!s)))
Z A bst(S s)_(L n=s[-1]=='t'&&*s==':'?++s,pl(&s):1;S p=s;A x=N(pk(&p,10));x=N(cpl(aCm(s,p),x,0));L t=now();F(n,mr(Nx(run(x,0,0))))x(az((now()-t+500)/1000)))
Z A bsv(S s)_(bsf(0))
Z A bs_(S*p)_(C b[256];S s=*p,e=strchrnul(s,10);P(e-s+1>=L(b),ez0())MC(b,s,e-s);b[e-s]=0;*p=e+!!*e;C c=*b,d=b[1];P(c=='c'&&d=='d'&&(!b[2]||b[2]==32),bscd(b+2+(b[2]==32)))
 P(!d||d==10||d==32||d==':',G(&bsl,bst,bsd,bsbs,bsf,bsv,bsm,bs0)[si("ltd\\fvm",c)](b+1+(d==32)))K1("0x0a\\`x(,,\"/bin/sh\"),,:",aCz(b)))

Z A evs1(S*p)_(S s=*p;P(*s=='\\',++*p;bs_(p))A x=pk((V*)p,10);N(x);x=N(cpl(aCm(s,*p),x,0));x(run(x,0,0)))
A evs(S s,B r)_(W(*s,A x=evs1(&s);P(!x,I(r,s=strchrnul(s,10);s+=!!*s;epr(0))0)I(r,x(out(x)))E(P(!*s,x)x(0))mc())au)
Z A s_;
B rep()_(Z C b[256],*s=b;C*q;A x=aV(tC,256,b);s_=x;s=s-b+xC;
 W(1,L n=read(0,s,xC-s+xn);P(n<=0,s=b;x(0))s+=n;q=memchr(s-n,10,n);
   P(q,C*p=xC;W(q,*q=0;evs(p,1);p=q+1;q=memchr(p,10,s-p))MC(b,p,s-p);s=s-p+b;x(1))
   q=xC;s_=x=x(aV(tC,2*xn,xV));s=s-q+xC)x(1))
V repl(){W(rep())}

A cns,cn[tn];A ce[tn];S*argv,*env;
V kinit(){Z B l;P(l)l=1;pg=sysconf(_SC_PAGESIZE);A b[32],*c=b;
 F(tS-tA+1,*c++=ce[tA+i]=an(0,tA+i))*c++=ce[tm]=am(emp(tS),emp(tA));_x(ce[tA])=_R(ce[tC]);ce[tM]=ce[tA];F(tn-ti,Q(!ce[i+ti]);ce[i+ti]=ce[tA])//empties
 cn[tA]=ce[tC];*c++=cn[ti]=cn[tl]=al(NL);F(tL-tE+1,cn[tE+i]=cn[ti])*c++=cn[tF]=cn[tf]=af(NF);cn[tC]=cn[tc]=ac(32);cn[tS]=cn[ts]=as(0);F(tn-to,cn[to+i]=au)//nulls
 Q(c-b<=32);cns=aV(tA,c-b,b);gk[gn]='v';gv[gn++]=sym(ver);}
V kargs(I n,S*a){argv=(S*)a;env=(S*)a+n+1;n=MAX(0,n-2);A x=n?aA(n):emp(tA);F(n,xa=aCz(a[2+i]))gk[gn]='x';gv[gn++]=x;}
A emp(U t)_(_R(ce[t]))

ZN U ow(S s,U n)_(write(1,s,n))
ZN V o8(W v){C b[16],*s=b;F(16,C c=v>>4*(15-i)&15;*s++="0W"[9<c]+c)ow(b,16);}
U os(S s)_(ow(s,SL(s)))
W ov_(S s,W v)_(os(s);o8(v);ow("\n",1);v)
ZN V od(L v){C b[32];ow(b,sl(b,v)-b);}
ZN V osd(S s,L v){os(s);od(v);}
ZN A1(ox,o8(x);osd(" b",xb);C t=xT;os(" t");I(LH(1,t,tn),ow(&TS[t],1))E(od(t))osd(" r",xr);osd(" n",xn);F(MIN(5,cap(x)/8),os(" ");o8(xl))os("\n");x)
#define RGS(a...) F(nreg,B f=reg[i].f;V*p=reg[i].p,*q=f?p:p+reg[i].n;a)
#define OBS(a...) RGS(A x=(A)(p+HD*!f+pg*f),y=(A)q;W(x<y,a;x+=HD<<xb))
#define XYS(a...) OBS(I(xtR,F(xn|!xn,A y=xa;a)))
#define RTS(a...) {A x=cns;a;F(gn,I(x=gv[i],a))}
A bsm(S s)_(XYS(I(!ytP,yr--))RTS(I(!xtP,xr--))OBS(I(xr&(x!=s_),os("!refc:");ox(x)))RTS(I(!xtP,xr++))XYS(I(!ytP,yr++))
 OBS(I(xT>=tn,os("!type:");ox(x)))OBS(I(xtA&&!xn&&!xx,os("!prot:");ox(x)))XYS(I(!yt,os("!dngl:");ox(x);ox(y)))au)
