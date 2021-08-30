// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/syscall.h>
V*memcpy (V*x,OV*y,Nn)_(C*p=x  ;Qq=y  ;i(n,*p++=*q++)x)
V*memrcpy(V*x,OV*y,Nn)_(C*p=x+n;Qq=y+n;i(n,*--p=*--q)x)
V*memmove(V*x,OV*y,Nn)_((y<x&&x<y+n?memrcpy:memcpy)(x,y,n))
V*memset(V*x,Iv,Nn)_(C*p=x;i(n,*p++=v);x)
V*memchr(Qs,Iv,Nn)_(i(n,P(s[i]==v,(V*)(s+i)))(V*)0)
V*memmem(OV*x,Nm,OV*y,Nn)_(Qp=x,q=y;i((L)m-(L)n+1,P(!memcmp(p+i,q,n),(V*)(p+i)))(V*)0)
I memcmp(OV*x,OV*y,Nn)_(Qs=x,t=y;i(n,Iv=*s++-*t++;P(v,v))0)
N strlen(Qs)_(Qp=s;W(*p,p++)p-s)
C*strchr(Qs,Iv)_(W(1,P(*s==v,(V*)s)P(!*s++,(V*)0))(V*)0)
C*strchrnul(Qs,Iv)_(W(1,P(*s==v,(V*)s)P(!*s,(V*)s)s++)(V*)s)
C*strstr(Qp,Qq)_(MM(p,Sn(p),q,Sn(q)))
I strcmp(Qp,Qq)_(W(*p&&*p==*q,p++;q++)*p-*q)
#ifndef shared
 I main(In,O char**a)_(kinit(n,a);I r=n>1?!cmdl(a[1]):repl();Q(cmdm(""));exit(r);r)
#endif
NWASM(
 FBSD(V _start(O char**a){main(*(I*)(V*)a,a+1);})
 NFBSD(asm(".globl _start;_start:"I386("pop %eax;push %esp;push %eax;call main")
                                 NI386("pop %rdi;mov %rsp,%rsi;jmp main"));)
 #define  h(x,a...) I386(".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%eax;int $0x80;ret;")\
                   NI386(".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%rax;syscall;ret;")
 #define h1(x,a...) I386( h(x,a"mov  4(%esp),%ebx;"))NI386(h(x,a))
 #define h2(x,a...) I386(h1(x,a"mov  8(%esp),%ecx;"))NI386(h(x,a))
 #define h3(x,a...) I386(h2(x,a"mov 12(%esp),%edx;"))NI386(h(x,a))
 #define h5(x)      I386(".globl "#x";"#x":mov %esp,%ebx;add $4,%ebx;mov $"M2(SYS_##x)",%eax;int $0x80;ret;")\
                   NI386(h(x,"movq %rcx,%r10;"))
 #define h6 h5
 #ifdef SYS_freebsd11_getdents
  #define SYS_getdents SYS_freebsd11_getdents
 #endif
 FBSD(asm(h(pipe2));I pipe(Iv[2])_(pipe2(v,0)))NFBSD(asm(h(pipe));)
 asm(h3(read)h3(write)h3(open)h1(close)h2(fstat)h3(lseek)h2(munmap)h2(dup2)h3(socket)h5(setsockopt)h3(connect)
     h(fork)h3(execve)h1(exit)h2(gettimeofday)h6(mmap)h3(getdents)h1(chdir)h2(ftruncate));)
