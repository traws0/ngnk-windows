#include<sys/mman.h> // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
#include<fcntl.h>
#include<arpa/inet.h>
#include"k.h"
#define ZP 4096ll //pagesize
S O UI lh=0x0100007f;SI UH htons_(UH x)_(x>>8|x<<8)S UC octet(C**p)_(UL r=pu(p);r>255?err("addr"),0:r)
S UI inet_addr_(C**p)_(C*s=*p;P(!*s,lh)UC r[4];F(4,$(i,P(*s-'.',err("addr");0)s++)r[i]=octet(&s))*p=s;*(UI*)r)
S L hskt(UI h,UH p)_(L f=skt(AF_INET,SOCK_STREAM,0);P(f<0,err("skt"),0)
 struct sockaddr_in sa;sa.sin_family=AF_INET;sa.sin_addr.s_addr=h;sa.sin_port=htons_(p);0>conn(f,(struct sockaddr*)&sa,Z(sa))?err("conn"),0:f)
S L hops(C*s,L fl)_(C*t=s;W(*t&&*t-':',t++)P(!*t,L f=open(s,fl,0666);f<0?err("open"),0:f)
 UI h=inet_addr_(&s);P(*s-':',err("addr"),0)s++;UL p=pu(&s);*s?err("addr"),0:hskt(h,p))
S L hop_(A x/*1*/,L fl)_(P(xtl,hskt(lh,gl(x)))P(xts,x=symstr(gs(x));!*xc?1:*xc-':'?et(),0:hops(xc+1,fl))P(xtC,x=str0(x);dex(x,hops(xc,fl)))et(x))
A1(hop,al(N(hop_(x,O_RDWR|O_CREAT))))A1(hcl,asrt(xtl);close(gl(x));cu0)
A1(u0c,P(x==as(0)||(xtC&&!xn),xr;C b[1024];aCn(b,max(0,read(0,b,Z(b)))))x=N(u1c(x));x=N(scn(ac(10),&x,1));xn&&!An(xa[xn-1])?cut(al(-1),x):x)
A1(u1c,L f=N(hop_(x,O_RDONLY));struct stat s;P(fstat(f,&s),err("stat"))L n=s.st_size;A y=aC(n+ZP-ZA);asrt(((L)y-ZA)%ZP==0);A u=(A)((L)y+ZP-ZA);
 ul[-2]=0;u=AT(tC,AN(n,u));uR;V*p=mmap_(uc,n,1,MAP_PRIVATE|MAP_FIXED,f,0);close(f);P(p==(V*)-1,yr;err("file"))asrt(p==uc);u)
A2(v0c,$(ytX,y=N(rdc(ac(10),&y,1)))ytC?v1c(x,N(apv(y,"\n"))):et(x,y))
A2(v1c,L f=N(hop_(x,O_RDWR|O_CREAT|O_TRUNC));L n=yn;C*s=yc;yr;W(n>0,L k=write(f,s,n);P(k<=0,err("write"))s+=k;n-=k)$(f-1,close(f));cu0)
