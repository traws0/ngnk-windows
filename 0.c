// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/syscall.h>
#include<stdarg.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#undef __USE_EXTERN_INLINES
#include<sys/stat.h>
#ifndef shared
 I main(In,O char**a)_(kinit(n,a);I r=n>1?!cmdl(a[1]):repl();Q(cmdm(""));exit(r);r)
#endif
#ifndef libc
 V*memcpy (V*x,OV*y,Nn)_(C*p=x  ;Qq=y  ;i(n,*p++=*q++)x)
 V*memrcpy(V*x,OV*y,Nn)_(C*p=x+n;Qq=y+n;i(n,*--p=*--q)x)
 V*memmove(V*x,OV*y,Nn)_((y<x&&x<y+n?memrcpy:memcpy)(x,y,n))
 V*memset(V*x,Iv,Nn)_(C*p=x;i(n,*p++=v);x)
 V*memchr(OV*x,Iv,Nn)_(Qs=x;i(n,P(s[i]==v,(V*)(s+i)))(V*)0)
 V*memmem(OV*x,Nm,OV*y,Nn)_(Qp=x,q=y;i((L)m-(L)n+1,P(!memcmp(p+i,q,n),(V*)(p+i)))(V*)0)
 I memcmp(OV*x,OV*y,Nn)_(Qs=x,t=y;i(n,Iv=*s++-*t++;P(v,v))0)
 N strlen(Qs)_(Qp=s;W(*p,p++)p-s)
 char*strchr(O char*s,Iv)_(W(1,P(*s==v,(V*)s)P(!*s++,(V*)0))(V*)0)
 char*strchrnul(Qs,Iv)_(W(1,P(*s==v,(V*)s)P(!*s,(V*)s)s++)(V*)s)
 char*strstr(O char*p,O char*q)_(MM(p,Sn(p),q,Sn(q)))
 I strcmp(Qp,Qq)_(W(*p&&*p==*q,p++;q++)*p-*q)
 #ifndef wasm
  #if defined(__OpenBSD__)||defined(__FreeBSD__)
   V _start(O char**a){main(*(I*)(V*)a,a+1);}
  #else
   asm(".globl _start;_start:"I386("pop %eax;push %esp;push %eax;call main")NI386("pop %rdi;mov %rsp,%rsi;jmp main"));
  #endif
  #define  h(x,a...) I386(".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%eax;int $0x80;ret;")\
                    NI386(".globl "#x";"#x":"a"mov $"M2(SYS_##x)",%rax;syscall;ret;")
  #define h1(x,a...) I386( h(x,a"mov  4(%esp),%ebx;"))NI386(h(x,a))
  #define h2(x,a...) I386(h1(x,a"mov  8(%esp),%ecx;"))NI386(h(x,a))
  #define h3(x,a...) I386(h2(x,a"mov 12(%esp),%edx;"))NI386(h(x,a))
  #define h5(x)      I386(".globl "#x";"#x":mov %esp,%ebx;add $4,%ebx;mov $"M2(SYS_##x)",%eax;int $0x80;ret;")\
                    NI386(h(x,"movq %rcx,%r10;"))
  #define h6 h5
  #ifdef __FreeBSD__
   #define SYS_getdents SYS_freebsd11_getdents
   asm(h(pipe2)h(__getcwd));I pipe(Iv[2])_(pipe2(v,0))char*__getcwd(char*,N);char*getcwd(char*s,Nn)_(__getcwd(s,n))
  #else
   asm(h(pipe)h(getcwd));
  #endif
  asm(h3(read)h3(write)h3(open)h1(close)h2(fstat)h3(lseek)h2(munmap)h2(dup2)h3(socket)h5(setsockopt)h3(connect)
      h(fork)h3(execve)h1(exit)h2(gettimeofday)h6(mmap)h3(getdents)h1(chdir)h2(ftruncate));
 #else
  I js_in(V*,N);V js_out(OV*,N),js_log(OV*),*js_alloc(N),js_time(I*,long*),js_exit(I);
  S ST{C*a,p[16];Nn;}s[8]={{.a=""},{.a=""},
   #include"o/w/fs.h"
  };S ST{C i;N o;}d[8]={{.i=1},{.i=1},{.i=1}};S O I ns=ZZ(s),nd=ZZ(d);//s:storage,d:file descriptor table
  #define FI P((UI)f>=nd||!d[f].i,EBADF)Ii=d[f].i;//validate file descriptor "f" and get inode as "i"
  I open(Qp,Iv,...)_(Im=Sn(p);P(m>=SZ s[0].p,ENAMETOOLONG)Ii=0;W(i<ns&&SQ(s[i].p,p),i++)
   I(i>=ns,P(O_CREAT&~v,ENOENT)i=0;W(i<ns&&s[i].a,i++)P(i>=ns,ENOSPC)s[i].a="";s[i].n=0;Mc(s[i].p,p,m))
   If=0;W(f<nd&&d[f].i,f++)P(f>=nd,EMFILE)d[f].i=1;d[f].i=i;d[f].o=0;f)
  I close(If)_(FI d[f].i=0;0)
  I read(If,V*a,Nn)_(FI P(i==1,js_in(a,n))I o=d[f].o;n=max(0,min(n,s[i].n-o));Mc(a,s[i].a+o,n);d[f].o+=n;n)
  I write(If,OV*a,Nn)_(FI;P(i==1,js_out(a,n);n)
   Im=d[f].o+n;I(m>s[i].n,C*b=js_alloc(m);Mc(b,s[i].a,n);s[i].a=b;s[i].n=m)Mc(s[i].a+d[f].o,a,n);n)
  off_t lseek(If,off_t o,I w)_(FI;o=w==SEEK_CUR?o+d[f].o:w==SEEK_END?o+s[i].n:w==SEEK_SET?o:-1;P(o<0,EINVAL)d[f].o=o)
  I fstat(If,ST stat*r)_(FI;In=s[i].n;
   *r=(TY(*r)){.st_ino=i,.st_mode=S_IFREG,.st_nlink=1,.st_size=n,.st_blksize=512,.st_blocks=n+511>>9};0)
  V*mmap(V*a,Nn,I pr,I fl,If,off_t o)_(I(!a,a=js_alloc(n))P(f<0,a)P(f>=nd||!d[f].i,(V*)-1)
   Ii=d[f].i;Mc(a,s[i].a+o,n);a)//todo:range check
  I munmap(If,In)_(0)
  I gettimeofday(ST timeval*a,ST timezone*b)_(js_time(&a->tv_sec,&a->tv_usec);0)
  V exit(Iv){js_exit(v);}
  I dup2(If,Iv)_(-1)I pipe(Iv[2])_(-1)I execve(Qp,char*O*a,char*O*e)_(-1)I fork()_(-1)I socket(Ii,Ij,Ik)_(-1)
  I setsockopt(If,I l,I s,OV*v,socklen_t n)_(-1)I connect(If,O ST sockaddr*s,socklen_t n)_(-1)I chdir(Qp)_(-1)
  char*getcwd(char*s,Nn)_((V*)0)I getdents(If,char*s,Nn)_(-1)I ftruncate(If,off_t o)_(-1)
 #endif
#endif
