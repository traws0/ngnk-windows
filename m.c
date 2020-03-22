#include<sys/mman.h> // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#include"k.h"
#define nxt(x) ((A*)data(x))[-2]
L mt,mu;S A mx[48],syml;A glb,cn[tn],ci[5][3];dbg(S I ml;/*prevent allocations*/)S CD A oom()_(write(1,"oom\n",4);exit(1);0)
S A ma(I b)_(dbg(asrt(!ml));asrt(4<b);P(b>47,oom())mu+=1ll<<b;A x=mx[b];P(x,mx[b]=nxt(x);AB(b,x))L i=b+1;W(i<ZZ(mx)&&!mx[i],i++)
 Y(i<ZZ(mx),x=mx[i];mx[i]=nxt(x))
 E(i=max(b,24);V*p=mmap_(0,1L<<i,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0);P(((L)p>>4)==-1,oom())mt+=1L<<i;x=(A)(p+ZA))
 W(i>b,i--;A y=mx[i]=(A)(x+(1L<<i));nxt(y)=0)AB(b,x))
A1(mr0,dbg(ml++);asrt(x);P(pkd(x),0)asrt(Ar(x)>0);P(--Ar(x),0)UC b=xb;P(!b,AT(tn,x))nxt(x)=mx[b];mx[b]=x;mu-=1ll<<b;Y(ref(x),mrn(xn,xa))x)
A1(mr1,dbg(ml--);P(!x,0)P(xt==tn,munmap(xc-ZP,xn+ZP);0)dbg(F(xn*tZ(xt),xci=0xab));0)
A1(mr,mr1(mr0(x)))
A1(mut,P(pkd(x)||Ar(x)==1,x)A u=atnv(xt,xn,xc);xr;Y(ref(u),mRa(u))u)
V mrn(L n,O A*a){F(n,mr(a[i]))}A1(mRa,F(xn,mR(xai))x)
A gkv(A*p)_(A x=*p;asrt(xn==2);P(Ar(x)>1,--Ar(x);*p=mR(xx);mR(xy))*p=xx;A u=xy;mr(AN(0,x));u)
I sym(A x/*1*/)_(L m=mu-((Ar(x)==1)<<Ab(x));A u=fpa(&syml,str0(x));mu=m;u)A symstr(I i)_(A x=syml;xai)C*symptr(I i)_(A x=symstr(i);xc)
A atn(UC t,L n)_(I b=67-__builtin_clzll((ZA>>3)+(t==tC?n>>3:n));A x=N(ma(b));Ar(x)=1;AN(n,AT(t,x)))
A atnv(UC t,L n,O V*v)_(A u=atn(t,n);mc(uc,v,n*tZ(t));u)A1(ax,Ar(x)>1?Ar(x)--,atn(xt,xn):x)A0(aa0,aa(enl(as(0)),enl(au0)))
A1(a1,atnv(tX,1,A_(x)))A2(a2,atnv(tX,2,A_(x,y)))A3(a3,atnv(tX,3,A_(x,y,z)))A2(aA,atnv(tA,2,A_(x,y)))A2(aa,atnv(ta,2,A_(x,y)))
A aCn(O C*s,L n)_(atnv(tC,n,s))A aCm(O C*s,O C*t)_(aCn(s,t-s))A aCz(O C*s)_(aCn(s,strlen(s)))
L strlen(O C*x)_(O C*p=x;W(*p,p++)p-x)
V*mc(V*x,O V*y,L n)_(C*p=x;O C*q=y;F(n,p[i]=q[i])x)V*ms(V*x,L n,C c)_(C*p=x;F(n,*p++=c);x)
A room(A x,L l)_(asrt(xtC);L n=xn;P(Ar(x)==1&&ZA+n+l<=1L<<xb,x)A u=AN(n,atnv(tC,n+l,xc));xr;u)
I line(C*p,C*q)_(A x=val(aCm(p,q));P(x,mr(out(x));1)epr();0)S C*skp(C*p)_(W(*p=='/'&&p[1]==10,p+=3;W(*p&&(p[-1]-10||p[-2]-'\\'||p[-3]-10),p++))p)
A1(ldf,x=str0(N(u1c(x)));C*p=xc;W(*p,C*q=p=skp(p);W(*q&&(*q-10||q[1]==32||q[1]=='}'),q++)Nx(line(p,q));p=q+!!*q)xr;au0)
asm(".globl mmap_\nmmap_:\nmovq %rcx,%r10\nmovq $"XS(SYS_mmap)",%rax\nsyscall\nret");
V init()_(A x=syml=aX(5);F(xn,xai=aCn(&"_xyzo"[i],!!i))glb=aa0();cn[tX]=a0();cn[tC]=cn[tc]=ac(32);cn[tL]=cn[tl]=al(_0Nl);
 cn[tI]=cn[ti]=ai(_0Ni);cn[tD]=cn[td]=ad(_0n);cn[tS]=cn[ts]=a0();F(tn-to,cn[to+i]=au0)
 S O struct{D d;L l;I i;}t[]={{0,0,0},{1,1,1},{_0w,_0Wl,_0Wi},{-_0w,-_0Wl,-_0Wi},{_0n,_0Nl,_0Ni}};
 F(5,ci[i][0]=ad(t[i].d);ci[i][1]=ai(t[i].i);ci[i][2]=al(t[i].l)))
#ifndef shared
 S V repl()_(C b[256];L m=0,k;W(0<(k=read(0,b,256)),C*p=b,*q=p+m,*r=q+k;W(q<r,Y(*q==10,line(p,q);p=q+1)q++)mc(b,p,m=q-p)))
 I main(I n,C**a)_(init();P(n>1,exit(!ldf(aCz(a[1])));0)repl();exit(0);0)
 #if __FreeBSD__
  V _start(C**p)_(main(*(L*)(V*)p,p+1);UR)
 #else
  asm(".globl _start\n_start:pop %rdi\nmov %rsp,%rsi\njmp main");
 #endif
#endif
