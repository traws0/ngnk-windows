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
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#undef __USE_EXTERN_INLINES
#include<sys/stat.h>

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

/*
WASM(I js_in(V*,N);V js_out(OV*,N);V*js_alloc(N);L js_time();I js_exit(I);
 V info(Qs){js_out(s,Sn(s));js_out("\n",1);}
 V infoI(Iv){Cb[32],*s=sl(s,v);*s=0;info(b);}
 #define INFOI(x) {js_out(#x,ZZ(#x)-1);js_out(":",1);infoI(x);}
 #define FI P((UI)f>=ZZ(fd)||!fd[f].u,EBADF)Ii=fd[f].i;//check file descriptor "f" and get inode as "i"
 ST{I u;Nn;char p[16],a[1<<18];}fs[8]={{1,0,"stdin",""},{1,0,"stdout",""},{1,0,"stderr",""}};
 ST{I u;UI i,o;}fd[8]={{1,0,0},{1,1,0},{1,2,0}};
 I open(Qp,Iv,...)_(info("open()");info(p);INFOI(v);va_list ap;va_start(ap,v);I m=va_arg(ap,int);va_end(ap);INFOI(m);
  P(Sn(p)>=ZZ(fs[0].p),ENAMETOOLONG)
  If=0;W(f<ZZ(fd)&&fd[f].u,f++)P(f>=ZZ(fd),EMFILE)fd[f].u=1;
  Ii=0;W(i<ZZ(fs)&&SQ(fs[i].p,p),i++)
  I(i>=ZZ(fs),P(~m&O_CREAT,ENOENT)i=0;W(i<ZZ(fs)&&fs[i].u,i++)P(i>=ZZ(fs),ENOSPC)fs[i].u=1;fs[i].n=0;Mc(fs[i].p,p,Sn(p)))
  fd[f]=(TY(fd[f])){1,i,0};INFOI(f);f)
 I close(If)_(info("close()");FI fd[f].u=0;0)
 I read(If,V*a,Nn)_(info("read()");FI P(i<3,js_in(a,n))
  I o=fd[f].o;n=max(0,min(n,fs[i].n-o));Mc(a,fs[i].a+o,n);fd[f].o+=n;n)
 I write(If,OV*a,Nn)_(info("write()");FI P(i<3,js_out(a,n);n)
  n=min(n,ZZ(fs[0].a)-fd[f].o);P(!n,ENOSPC)fs[i].n=max(fs[i].n,fd[f].o+n);Mc(fs[i].a+fd[f].o,a,n);n)
 off_t lseek(If,off_t o,I w)_(info("lseek()");FI P(w-SEEK_SET||w-SEEK_CUR||w-SEEK_END,EINVAL)
  o+=w==SEEK_CUR?fd[f].o:w==SEEK_END?fs[i].n:0;P(o<0,EINVAL)fd[f].o=o)
 I fstat(If,ST stat*r)_(info("fstat()");FI //{dev(8B),ino,mode(S_IFREG=0o100000),nlink,uid,gid,rdev(8B),size,blksize,blocks}
  In=fs[i].n;Ms(r,0,52);r[4]=1<<15;r[5]=1;r[10]=n;r[11]=512;r[12]=(n+511)>>9;0)
 V*mmap(V*a,Nn,I pr,I fl,If,off_t o)_(info("mmap()");I(!a,a=js_alloc(n))
  P(f<0,a)P(f>=ZZ(fd)||!fd[f].u,(V*)-1)Ii=fd[f].i;Mc(a,fs[i].a+o,n);a)//todo:range check
 I munmap(If,In)_(info("munmap()");0)
 I gettimeofday(I*a,I*b)_(info("gettimeofday()");Lv=js_time();*a=v/1000;a[1]=v%1000*1000;0)
 V exit(Iv){info("exit()");js_exit(v);}
 I dup2(If,Iv)_(info("dup2()");-1)
 I pipe(Iv[2])_(info("pipe()");-1)
 I execve(Qp,char*O*a,char*O*e)_(info("execve()");-1)
 I fork()_(info("fork()");-1)
 I socket(Ii,Ij,Ik)_(info("socket()");-1)
 I setsockopt(I s,I level,I optname,OV*optval,socklen_t optlen)_(info("setsockopt()");-1)
 I connect(I s,const struct sockaddr*name,socklen_t namelen)_(info("connect()");-1)
 I chdir(Qp)_(info("chdir()");0)
 I getdents(If,char*s,Nn)_(info("getdents()");-1)
 I ftruncate(If,off_t o)_(info("ftruncate()");-1))
*/
