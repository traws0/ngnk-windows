// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/syscall.h>

V*memcpy(V*x,OV*y,Nn)_(C*p=x;OC*q=y;i(n,p[i]=q[i])x)
V*memmove(V*x,OV*y,Nn)_(memcpy(x,y,n))
V*memset(V*x,Iv,Nn)_(C*p=x;i(n,*p++=v);x)
I memcmp(OV*x,OV*y,Nn)_(OC*s=x,*t=y;i(n,Iv=*s++-*t++;P(v,v))0)
I strcmp(OC*x,OC*y)_(W(*x&&*x==*y,x++;y++)*x-*y)
N strlen(OC*x)_(OC*p=x;W(*p,p++)p-x)

#ifndef shared
 I main(In,C**a)_(init(n,a);P(n>1,exit(!cmdl(aCz(a[1])));0)repl();exit(0);0)
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
     h(fork)h3(execve)h1(exit)h2(gettimeofday)h6(mmap));
 #if SYS_pipe
  asm(h(pipe)h3(getdents));
 #else //freebsd
  I pipe(Iv[2])_(pipe2(v,0));I getdirentries(UI,V*,UI,V*);I getdents(UI x,V*y,UI z)_(getdirentries(x,y,z,0));
  asm(h(pipe2)h4(getdirentries));
 #endif
#endif
