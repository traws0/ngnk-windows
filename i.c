#include<sys/mman.h> // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include"k.h"
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
#endif
S O UI lh=0x0100007f;SI UH htons_(UH x)_(x>>8|x<<8)S UC octet(C**p)_(UL r=pu(p);r>255?err("addr"),0:r)
S UI inet_addr_(C**p)_(C*s=*p;P(!*s,lh)UC r[4];F(4,$(i,P(*s-'.',err("addr");0)s++)r[i]=octet(&s))*p=s;*(UI*)r)
S L hskt(UI h,UH p)_(L f=skt(AF_INET,SOCK_STREAM,0);P(f<0,err("skt"),0)
 struct sockaddr_in sa;sa.sin_family=AF_INET;sa.sin_addr.s_addr=h;sa.sin_port=htons_(p);0>conn(f,(struct sockaddr*)&sa,Z(sa))?err("conn"),0:f)
S L hops(C*s,L fl)_(C*t=s;W(*t&&*t-':',t++)P(!*t,L f=open(s,fl,0666);f<0?err("open"),0:f)
 UI h=inet_addr_(&s);P(*s-':',err("addr"),0)s++;UL p=pu(&s);*s?err("addr"),0:hskt(h,p))
S I hop_(A x/*1*/,I fl)_(P(xtil,hskt(lh,gi(x)))P(xts,C*s=symptr(gs(x));!*s?1:*s-':'?et(),0:hops(s+1,fl))P(xtC,x=str0(x);dex(x,hops(xc,fl)))et(x))
A1(hop,ai(N(hop_(x,O_RDWR|O_CREAT))))A1(hcl,asrt(xti);close(gi(x));au0)
A1(u0c,P(x==as(0)||(xtC&&!xn),xr;C b[1024];aCn(b,max(0,read(0,b,Z(b)))))x=N(u1c(x));x=N(scn(ac(10),&x,1));xn&&!An(xa[xn-1])?cut(al(-1),x):x)
A u1c_(I f)_(struct stat s;P(fstat(f,&s),err("stat"))L n=s.st_size;I pr=PROT_READ|PROT_WRITE,fl=MAP_NORESERVE|MAP_PRIVATE;
 V*p=mmap_(0,ZP+n,pr,fl|MAP_ANON,-1,0);P(((L)p>>4)==-1,err("mmap0"))A u=(A)(p+ZP);ul[-2]=0;u=AT(tC,AN(n,u));uR;
 V*q=mmap_(p+ZP,n,pr,fl|MAP_FIXED,f,0);P(p+ZP-q,err("mmap1"))u)
A1(u1c,I f=N(hop_(x,O_RDONLY));A u=u1c_(f);close(f);u)
A2(v0c,$(ytX,y=N(rdc(ac(10),&y,1)))ytC?v1c(x,N(apv(y,"\n"))):et(x,y))
A2(v1c,L f=N(hop_(x,O_RDWR|O_CREAT|O_TRUNC));L n=yn;C*s=yc;mr2(y,W(n>0,L k=write(f,s,n);P(k<=0,err("write"))s+=k;n-=k)$(f-1,close(f));au0))
