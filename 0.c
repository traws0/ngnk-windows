// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/syscall.h>
#ifndef SYS_getdents
 #define SYS_getdents SYS_freebsd11_getdents
#endif

V*memcpy(V*x,OV*y,Nn)_(C*p=x  ;Qq=y  ;i(n,*p++=*q++)x)
V*memCPY(V*x,OV*y,Nn)_(C*p=x+n;Qq=y+n;i(n,*--p=*--q)x)
V*memmove(V*x,OV*y,Nn)_((y<x&&x<y+n?memCPY:memcpy)(x,y,n))
V*memset(V*x,Iv,Nn)_(C*p=x;i(n,*p++=v);x)
V*memchr(Qs,Iv,Nn)_(i(n,P(s[i]==v,(V*)(s+i)))(V*)0)
V*memmem(OV*x,Nm,OV*y,Nn)_(Qp=x,q=y;i(m-n+1,P(!memcmp(p+i,q,n),(V*)(p+i)))(V*)0)
I memcmp(OV*x,OV*y,Nn)_(Qs=x,t=y;i(n,Iv=*s++-*t++;P(v,v))0)
N strlen(Qs)_(Qp=s;W(*p,p++)p-s)
C*strchr(Qs,Iv)_(W(1,P(*s==v,(V*)s)P(!*s++,(V*)0))(V*)0)
C*strchrnul(Qs,Iv)_(W(1,P(*s==v,(V*)s)P(!*s,(V*)s)s++)(V*)s)
C*strstr(Qp,Qq)_(MM(p,Sn(p),q,Sn(q)))
I strcmp(Qp,Qq)_(W(*p&&*p==*q,p++;q++)*p-*q)

#ifndef shared
 I main(In,O char**a)_(kinit(n,a);P(n>1,exit(!cmdl(a[1]));0)repl();exit(0);0)
 #if __FreeBSD__
  V _start(O char**a){main(*(I*)(V*)a,a+1);} //can't use _() here
 #elif i386
  asm(".globl _start;_start:pop %eax;push %esp;push %eax;call main");
 #elif !wasm
  asm(".globl _start;_start:pop %rdi;mov %rsp,%rsi;jmp main");
 #endif
#endif

#if !wasm
 #if i386
  #define  h(x,a...) ".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%eax;int $0x80;ret;"
  #define h1(x,a...)  h(x,a"mov  4(%esp),%ebx;")
  #define h2(x,a...) h1(x,a"mov  8(%esp),%ecx;")
  #define h3(x,a...) h2(x,a"mov 12(%esp),%edx;")
  #define h5(x,a...) ".globl "#x";"#x":mov %esp,%ebx;add $4,%ebx;mov $"M2(SYS_##x)",%eax;int $0x80;ret;"
  #define h6(x,a...) ".globl "#x";"#x":mov %esp,%ebx;add $4,%ebx;mov $"M2(SYS_##x)",%eax;int $0x80;ret;"
 #else
  #define h(x,a...) ".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%rax;syscall;ret;"
  #define h1 h
  #define h2 h
  #define h3 h
  #define h4 h
  #define h5(x) h(x,"movq %rcx,%r10;")
  #define h6(x) h(x,"movq %rcx,%r10;")
 #endif

 asm(h3(read)h3(write)h3(open)h1(close)h2(fstat)h3(lseek)h2(munmap)h2(dup2)h3(socket)h5(setsockopt)h3(connect)
     h(fork)h3(execve)h1(exit)h2(gettimeofday)h6(mmap)h3(getdents));
 #if SYS_pipe
  asm(h(pipe));
 #else //freebsd
  I pipe(Iv[2])_(pipe2(v,0));asm(h(pipe2));
 #endif
#endif
