#include<sys/mman.h> // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#include"k.h"
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
#endif
S O I lh=0x0100007f;S C octet(C**p)_(UL r=pu(p);r>255?err("addr"),0:r)
S UI inet_addr_(C**p)_(C*s=*p;P(!*s,lh)C r[4];F(4,Y(i,P(*s-'.',err("addr");0)s++)r[i]=octet(&s))*p=s;*(UI*)r)
S L hskt(UI h,UH p)_(L f=skt(AF_INET,SOCK_STREAM,0);P(f<0,err("skt"),0)
 struct sockaddr_in sa;sa.sin_family=AF_INET;sa.sin_addr.s_addr=h;sa.sin_port=p<<8|p>>8;0>conn(f,(struct sockaddr*)&sa,Z(sa))?err("conn"),0:f)
S L hops(C*s,L fl)_(C*t=s;W(*t&&*t-':',t++)P(!*t,L f=open(s,fl,0666);f<0?err("open"),0:f)
 UI h=inet_addr_(&s);P(*s-':',err("addr"),0)s++;UL p=pu(&s);*s?err("addr"),0:hskt(h,p))
S I hop_(A x/*1*/,I fl)_(P(xtil,gi(x))P(xts,C*s=syp(gs(x));!*s?1:*s-':'?et(),0:hops(s+1,fl))P(xtC,x=str0(x);dex(x,hops(xc,fl)))et(x))
A1(hop,ai(N(hop_(x,O_RDWR|O_CREAT))))
A2(v0c,Y(ytX,y=N(rdc(ac(10),&y,1)))Et(!ytC,x,y)v1c(x,N(apv(y,"\n"))))
A2(v1c,Et(!ytC,x)I f=N(hop_(x,O_RDWR|O_CREAT|O_TRUNC));L n=yn;C*s=yc;
 m2(y,A u=au0;W(n>0,L k=write(f,s,n);Y(k<=0,u=err("write");B)s+=k;n-=k)Y(f>2,close(f))u))
A1(hcl,asrt(xti);close(gi(x));au0)
A1(u0c,P(x==as(0)||(xtC&&!xn),xr;C b[1024];aCn(b,max(0,read(0,b,Z(b)))))x=N(u1c(x));x=N(scn(ac(10),&x,1));xn&&!An(xa[xn-1])?cut(al(-1),x):x)
A u1cm(I f)_(L n=lseek_(f,0,SEEK_END);P(n<0,err("lseek"))I p=PROT_READ|PROT_WRITE,m=MAP_NORESERVE|MAP_PRIVATE;
 V*a=mmap_(0,ZP+n,p,m|MAP_ANON,-1,0);P((L)a>>4==-1,err("mmap0"))A u=(A)(a+ZP);ul[-2]=0;u=AT(tC,AN(n,u));uR;
 V*b=mmap_(a+ZP,n,p,m|MAP_FIXED,f,0);b==(V*)uc?u:err("mmap1"))
A1(u1c,P(xti,C s[1024];I r=read(gi(x),s,Z s);r<0?err("read"):aCn(s,r))P(xtl,u1c(gI(x)))I f=N(hop_(x,O_RDONLY));A u=u1cm(f);close(f);u)

L now()_(struct timeval t;gtod(&t,0);1000000ll*t.tv_sec+t.tv_usec)
S A1(cmdw,asrt(xtC);L n=mu;P(!xn,xr;al(n))A y=Nx(val(xR));mr(out(y));n=mu-n;xr;n?enl(cat(as(0),al(n))):au0)
S A1(cmdt,asrt(xtC);C*s=xc;L n=*s==':'?++s,pl(&s):1;L t=now();x=N(cpl(N(prs(N(cut(al(s-xc),x))))));F(n,mr(Nx(app(x,0,0))))xr;al((now()-t+500)/1000))
A1(cmd,Et(!xtC,x)Y(!xn||xn==1&&*xc=='\\',exit(0))C c=*xc;
 Y(c3('a',c,'z')&&(xn==1||xc[1]==32||xc[1]==':'),I i=1+(i>1);I j=i;W(j<xn&&xcj==32,j++)x=N(cut(al(j),x));A1*f=(A1*[]){ldf,cmdt,cmdw,0}[Ci("ltw",c)];P(f,f(x)))
 K("{0x0a\\`x(,\"/bin/sh\";x)}",x))
S A rda(I f)_(A u=aC(256-ZA);L m=0,k;W((k=read(f,uc+m,un-m))>0,m+=k;Y(m+1000000>un&&2*m>un,A z=aC(2*un+ZA);mc(zc,uc,m);ur;u=z))close(f);AN(m,u))
A1(frk,Et(!xtX||xn-2,x)A y=gkv(&x);Ed(!xtX||!ytC,x,y)x=Ny(ea1(str0,x));C*a[xn+1];F(xn,a[i]=dat(xai))a[xn]=0;I p[4];pipe(p);pipe(p+2);
 P(!fork(),dup2(*p,0);dup2(p[3],1);F(4,close(p[i]))exit(execve(*a,a,0));0)xr;close(*p);close(p[3]);N(v1c(ai(p[1]),y));rda(p[2]))
