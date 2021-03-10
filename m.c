// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/syscall.h>
#include<sys/mman.h>
#define nxt(x) ((A*)dat(x))[-2]
S A mx[40];A glb,ce[tn],cn[tn],ci[2][5];L mu;S I ml;SN A oom()_(write(1,"oom\n",4);exit(1);0)
S A ma(UI b)_(Q(!ml);Q(4<b);P(b>=ZZ(mx),oom())mu+=1ll<<b;Ax=mx[b];P(x,mx[b]=nxt(x);bkt(x)=b;x)Ii=b+1;W(i<ZZ(mx)&&!mx[i],i++)
 Y(i<ZZ(mx),x=mx[i];mx[i]=nxt(x))
 E(i=max(b,24);V*p=mmap(0,1ll<<i,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANON,-1,0);P(((L)p>>4)==-1,oom())x=(A)(p+ZA))
 W(i>b,i--;Ay=mx[i]=(A)(x+(1ll<<i));nxt(y)=0)bkt(x)=b;x)
A1(mr0,dbg(ml++);Q(x);XP(0)Q(xr>0);P(--xr,0)Cb=bkt(x);P(!b,AT(tn,x))
 nxt(x)=mx[b];mx[b]=x&~(-1ull<<48);mu-=1ll<<b;Y(xtR,mrn(xn,xA))x)
A1(mr1,dbg(ml--);P(!x,0)P(xt==tn,munmap(xC-ZP,xn+ZP);0)dbg(ms(xC,0xab,xn*ZT[xt]));0)
A1(mr,mr1(mr0(x)))V mrn(In,OA*a){i(n,mr(a[i]))}A1(mRa,i(xn,mR(xa))x)
A1(mut,XP(x)P(xr==1,x)Au=x(atnv(xt,xn,xC));Y(utR,mRa(u))u)N strlen(OC*x)_(OC*p=x;W(*p,p++)p-x)
V*memcpy(V*x,OV*y,Nn)_(C*p=x;OC*q=y;i(n,p[i]=q[i])x)V*memmove(V*x,OV*y,Nn)_(memcpy(x,y,n))
V*memset(V*x,I c,Nn)_(C*p=x;i(n,*p++=c);x)I strcmp(OC*s,OC*t)_(W(*s&&*s==*t,s++;t++)*s-*t)
I memcmp(OV*x,OV*y,Nn)_(OC*s=x,*t=y;i(n,Iv=*s++-*t++;P(v,v))0)
A atn(Ct,Nn)_(Ax=ma(64-__builtin_clzll(ZA+7+n*ZT[t]));xr=1;AT(t,AN(n,x)))
A atnv(Ct,Nn,OV*v)_(Au=atn(t,n);mc(uC,v,n*ZT[t]);u)A1(ax,xr>1?xr--,atn(xt,xn):x)A0(aa0,am(enl(as(0)),enl(au0)))
A1(a1,atnv(tA,1,A(x)))A2(a2,atnv(tA,2,A(x,y)))A3(a3,atnv(tA,3,A(x,y,z)))A2(aM,atnv(tM,2,A(x,y)))A2(am,atnv(tm,2,A(x,y)))
A aCn(OC*s,Nn)_(atnv(tC,n,s))A aCm(OC*s,OC*t)_(aCn(s,t-s))A aCz(OC*s)_(aCn(s,mn(s)))
A az(Lv)_(NH<v&&v<=WH?ah(v):(L)NI<v&&v<=(L)WI?ai(v):al(v))
A kv(A*p)_(Ax=*p;Q(xn==2);P(xr>1,--xr;*p=mR(xx);mR(xy))*p=xx;Au=xy;AN(0,x);x(u)) //get keys and values
A room(Ax,N k)_(Q(xtC);Nn=xn;P(xr==1&&ZA+n+k<=1ll<<bkt(x),x)Au=AN(n,aC(n+k));mc(uC,xC,n);x(u))
S C sy0[1<<16]__attribute__((aligned(ZA))),*sy1=sy0+1;C*syp(I*p)_(*p<0?sy0-*p:(V*)p)
I syP(OC*s)_(In=mn(s)+1;P(n<5,mc(&n,s,n);n)
 OC*p=sy0+1;W(p<sy1,OC*q=p,*t=s;W(*q&&*q==*t,q++;t++)P(!*q&&!*t,sy0-p)p=q;W(*p,p++)p++)
 P(sy1+n>sy0+Z sy0,write(1,"syms ",5);oom())mc(sy1,s,n);Iv=sy0-sy1;sy1+=n;v)
I line(C*p,C*q)_(Ax=val(aCm(p,q));Y(x,x=out(x))P(x,mr(x);1)epr(0))
S C*skp(C*p)_(W(*p=='/'&&p[1]==10,p+=3;W(*p&&(p[-1]-10||p[-2]-'\\'||p[-3]-10),p++))p)
A1(cmdl,x=N(u1c(x));Ed(!xn||xC[xn-1]-10,x)xC[xn-1]=0;C*p=xC;Y(*p=='#'&&p[1]=='!',p+=2;W(*p&&*p-10,p++))
 W(*p,C*q=p=skp(p);W(*q&&(*q-10||q[1]==32||q[1]=='}'),q++)Nx(line(p,q));p=q+!!*q)x(au0))
V init(){Ax=ce[tS]=aS(0);i(tS,ce[i]=AT(i,x))ce[tm]=am(aS0,aA0);glb=aa0();
 cn[tA]=ce[tA];cn[tC]=ac(32);cn[tB]=cn[tH]=cn[tI]=cn[tL]=al(NL);cn[tD]=ad(ND);cn[tS]=as(0);
 mc(cn+tc,cn+tC,(tS-tC+1)*Z(*cn));i(tn-to,cn[to+i]=au0)
 ci[0][0]=al(0);          ci[0][1]=al(1);ci[0][2]=al(WL);ci[0][3]=al(-WL);ci[0][4]=cn[tL];
 ci[1][0]=AT(td,ci[0][0]);ci[1][1]=ad(1);ci[1][2]=ad(WD);ci[1][3]=ad(-WD);ci[1][4]=cn[tD];}
I rep()_(S Cb[256];L m=0,k=read(0,b,256);P(k<0,0)C*p=b,*q=p+m,*r=q+k;W(q<r,Y(*q==10,line(p,q);p=q+1)q++)mc(b,p,m=q-p);1)

#ifndef shared
 I main(In,C**a)_(init();P(n>1,exit(!cmdl(aCz(a[1])));0)W(rep())exit(0);0)
 #if __FreeBSD__
  V _start(C**p){main(*(I*)(V*)p,p+1);} //can't use _() here
 #elif i386
  asm(".globl _start;_start:pop %eax;push %esp;push %eax;call main");
 #elif !wasm
  asm(".globl _start;_start:pop %rdi;mov %rsp,%rsi;jmp main");
 #endif
#endif

#if !wasm
 #if i386
  #define h(x,a...) ".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%eax;int $0x80;ret;"
  #define h1(x,a...)  h(x,a"mov  4(%esp),%ebx;")
  #define h2(x,a...) h1(x,a"mov  8(%esp),%ecx;")
  #define h3(x,a...) h2(x,a"mov 12(%esp),%edx;")
  #define h6(x,a...) asm(".globl "#x";"#x":mov %esp,%ebx;add $4,%ebx;mov $"M2(SYS_##x)",%eax;int $0x80;ret;");
 #else
  #define h(x,a...) ".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%rax;syscall;ret;"
  #define h1 h
  #define h2 h
  #define h3 h
  #define h6(x) h(x,"movq %rcx,%r10;")
 #endif
 asm(h3(read)h3(write)h3(open)h1(close)h2(fstat)h3(lseek)h2(munmap)h2(dup2)h3(socket)h3(connect)h(fork)h3(execve)
     h1(exit)h3(getdents)h2(gettimeofday)h6(mmap));
 #if SYS_pipe
  asm(h(pipe));
 #else
  asm(h(pipe2));I pipe(I x[2])_(pipe2(x,0)); //freebsd
 #endif
#endif
