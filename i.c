// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#undef __USE_EXTERN_INLINES
#include<sys/stat.h>
#include"a.h"
ssize_t getdents(I,char*,N);
#if __FreeBSD__
 ST DE{UI d_fileno;UH d_reclen;C d_type,d_namlen,d_name[255+1];};
#else
 ST DE{long d_ino;off_t d_off;UH d_reclen;C d_name[];};
#endif
S UI addr(Q*p)_(Qs=*p;P(!*s,0x0100007f)C r[4];i(4,Y(i,Ed(*s-'.')s++)r[i]=pu(&s);Ed(r[i]>255))*p=s;*(UI*)r)
S I skt(UI h,UH p)_(If=socket(AF_INET,SOCK_STREAM,0);Eo(f<0)Iv=setsockopt(f,IPPROTO_TCP,TCP_NODELAY,(I[]){1},4);Eo(v<0)
 ST sockaddr_in a;a.sin_family=AF_INET;a.sin_addr.s_addr=h;a.sin_port=rot(p,8);Eo(connect(f,(ST sockaddr*)&a,Z(a))<0)f)
S I o1(Qs,L fl)_(P(!sc(s,':'),If=open(s,fl,0666);Eo(f<3/*fbsd*/)f)UI h=addr(&s);Ed(*s-':')s++;UL p=pu(&s);Ed(*s)skt(h,p))
S I o(Ax/*1*/,I fl)_(Xz(gl(x))Xs(Lv=gi(x);P(!v,1)Qs=syp(&v);o1(s,fl))Et(!xtC,x)x=str0(x);x2(o1(xC,fl)))
S C ft(If)_(ST stat s;Iv=fstat(f,&s);P(v<0,0)Lm=s.st_mode&S_IFMT;
 S L a[]={-1,S_IFCHR,S_IFDIR,S_IFIFO,S_IFLNK,S_IFREG,S_IFSOCK};"?cdflrs"[max(0,fL(a,ZZ(a),m))])
A1(opn,az(N(o(x,O_RDWR|O_CREAT))))A1(cls,xtz?close(gl(x)):x(0);au0)
A1(u0c,x=N(splc(10,N(u1c(x))));xn&&!_n(xA[xn-1])?cut(az(-1),x):x)
A1(u1c,Xz(If=gl(x);Cb[8192];Ik=read(f,b,Z b);Eo(k<0)aCn(b,k))If=N(o(x,O_RDONLY));P(f<3,u1c(ai(f)))Ct=ft(f);
 P(t=='d',Cb[ZP];Ik;Au=oC;
  W((k=getdents(f,b,Z b))>0,Ii=0;W(i<k,ST DE*e=(V*)b+i;Qs=e->d_name;u=cts(u,s,sn(s));u=apc(u,10);i+=e->d_reclen))
  close(f);u)
 P(t=='r',Ln=lseek(f,0,SEEK_END);P(n<0,close(f);eo0())Ax=mf(f,n);close(f);x)
 Au=u1c(ai(f));close(f);u)
A2(v0c,Y(ytA,y=Nx(jc(10,y)))Et(!ytC,x,y)v1c(x,N(apc(y,10))))
A2(v1c,Et(!ytC,x)Xz(If=gl(x);Nn=yn;Qs=yC;y2(Au=au0;W(n>0,Lk=write(f,s,n);Y(k<0,u=eo0())Y(k<=0,BR)s+=k;n-=k)u))
 If=N(o(x,O_RDWR|O_CREAT|O_TRUNC));Au=v1c(ai(f),y);f>2&&close(f);u)

S A rda(If)_(Au=aC(256-ZA);L m=0,k;
 W((k=read(f,uC+m,un-m))>0,m+=k;Y(m+1000000>un&&2*m>un,Az=aC(2*un+ZA);mc(zC,uC,m);u=u(z)))close(f);AN(m,u))
A1(frk,Et(!xtA||xn-2,x)Ay=kv(&x);Ed(!xtA||!ytC,x,y)x=Ny(eac1(str0,x));Q a[xn+1];i(xn,a[i]=dat(xa))a[xn]=0;
 I p[4];pipe(p);pipe(p+2);P(!fork(),dup2(*p,0);dup2(p[3],1);i(4,close(p[i]))exit(execve(*a,(char**)a,(char*O*)env));0)
 close(*p);close(p[3]);N(v0c(ai(p[1]),x(y)));close(p[1]);rda(p[2]))
L now()_(ST timeval t;gettimeofday(&t,0);1000000ll*t.tv_sec+t.tv_usec)
