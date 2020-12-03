// ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#include<sys/mman.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#include"a.h"
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
#endif
I fstat(I,struct stat*),getdents(UI,V*,UI);
S O I lh=0x0100007f;S C octet(C**p)_(UL r=pu(p);r>255?err("addr"),0:r)
S UI inet_addr_(C**p)_(C*s=*p;P(!*s,lh)C r[4];F(4,Y(i,P(*s-'.',err("addr");0)s++)r[i]=octet(&s))*p=s;*(UI*)r)
S L skt(UI h,UH p)_(L f=socket(AF_INET,SOCK_STREAM,0);P(f<0,err("skt"),0)
 struct sockaddr_in a;a.sin_family=AF_INET;a.sin_addr.s_addr=h;a.sin_port=rot(p,8);0>connect(f,(struct sockaddr*)&a,Z(a))?err("conn"),0:f)
S L opn(C*s,L fl)_(C*t=s;W(*t&&*t-':',t++)P(!*t,L f=open(s,fl,0666);f<0?err("open"),0:f)
 UI h=inet_addr_(&s);P(*s-':',err("addr"),0)s++;UL p=pu(&s);*s?err("addr"),0:skt(h,p))
S I op_(Ax/*1*/,I fl)_(P(xtil,gi(x))P(xts,C*s=syp(gs(x));P(!*s,1)et(*s-':')opn(s+1,fl))et(!xtC,x)x=str0(x);dex(x,opn(xc,fl)))
A1(hop,ai(N(op_(x,O_RDWR|O_CREAT))))A1(hcl,Q(xti);close(gi(x));au0)
A2(v0c,Y(ytA,y=N(rdc(ac(10),&y,1)))et(!ytC,x,y)v1c(x,N(apc(y,10))))
A2(v1c,et(!ytC,x)I f=N(op_(x,O_RDWR|O_CREAT|O_TRUNC));Ln=yn;C*s=yc;
 m2(y,Au=au0;W(n>0,Lk=write(f,s,n);Y(k<=0,u=err("write");B)s+=k;n-=k)Y(f>2,close(f))u))
S A ls(I f)_(Cb[1024];Ik;Au=a0();
 W((k=getdents(f,b,Z b))>0,Ii=0;W(i<k,struct{long a,b;UH l;C s[];}*e=(V*)(b+i);u=apd(u,aCz(e->s));i+=e->l))u)
S I dir(A x)_(I f=op_(xR,O_RDONLY);struct stat s;Iv=fstat(f,&s);v=v>=0&&!!(s.st_mode&S_IFDIR);close(f);v)
A1(u0c,P(x==as(0)||(xtC&&!xn),xr;C b[1024];aCn(b,max(0,read(0,b,Z(b)))))P(dir(xR),ls(op_(x,O_RDONLY)))
 x=N(u1c(x));x=N(scn(ac(10),&x,1));xn&&!An(xa[xn-1])?cut(al(-1),x):x)
A u1cm(I f)_(Ln=lseek(f,0,SEEK_END);P(n<0,err("lseek"))I p=PROT_READ|PROT_WRITE,m=MAP_NORESERVE|MAP_PRIVATE;
 V*a=mmap(0,ZP+n,p,m|MAP_ANON,-1,0);P((L)a>>4==-1,err("mmap0"))Au=(A)(a+ZP);ul[-2]=0;u=AT(tC,AN(n,u));uR;
 V*b=mmap(a+ZP,n,p,m|MAP_FIXED,f,0);b==(V*)uc?u:err("mmap1"))
A1(u1c,P(xti,C s[1024];I r=read(gi(x),s,Z s);r<0?err("read"):aCn(s,r))P(xtl,u1c(gI(x)))I f=N(op_(x,O_RDONLY));Au=u1cm(f);close(f);u)

L now()_(struct timeval t;gettimeofday(&t,0);1000000ll*t.tv_sec+t.tv_usec)
S A1(cmdw,Q(xtC);Ln=mu;P(!xn,xr;al(n))Ay=Nx(val(xR));mr(out(y));n=mu-n;xr;n?enl(cat(as(0),al(n))):au0)
S A1(cmdt,Q(xtC);C*s=xc;Ln=*s==':'?++s,pl(&s):1;L t=now();x=N(cpl(N(prs(N(cut(al(s-xc),x))))));F(n,mr(Nx(app(x,0,0))))xr;al((now()-t+500)/1000))
A1(cmd,et(!xtC,x)Y(!xn||xn==1&&*xc=='\\',exit(0))Cc=*xc;
 Y(c3('a',c,'z')&&(xn==1||xc[1]==32||xc[1]==':'),Ii=1;W(i<xn&&xci==32,i++)x=N(cut(al(i),x));A1*f=(A1*[]){ldf,cmdt,cmdw,0}[si("ltw",c)];P(f,f(x)))
 K("{0x0a\\`x(,\"/bin/sh\";x)}",x))
S A rda(I f)_(Au=aC(256-ZA);L m=0,k;W((k=read(f,uc+m,un-m))>0,m+=k;Y(m+1000000>un&&2*m>un,Az=aC(2*un+ZA);mc(zc,uc,m);ur;u=z))close(f);AN(m,u))
A1(frk,et(!xtA||xn-2,x)Ay=gkv(&x);ed(!xtA||!ytC,x,y)x=Ny(ea1(str0,x));C*a[xn+1];F(xn,a[i]=dat(xai))a[xn]=0;I p[4];pipe(p);pipe(p+2);
 P(!fork(),dup2(*p,0);dup2(p[3],1);F(4,close(p[i]))exit(execve(*a,(char**)a,0));0)xr;close(*p);close(p[3]);N(v1c(ai(p[1]),y));rda(p[2]))
