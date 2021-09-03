#define _GNU_SOURCE // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include<stdlib.h>  // apt-get install libc6-dev-i386
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#define   _(a...) {return({a;});}
#define I(x,a...) if(x){a;}
#define P(x,a...) if(x)_(a)
#define W(x,a...) while(x){a;}
#define i(x,a...) for(I i=0,n_=(x);i<n_;i++){a;}
#define S static
#define O const
#define SZ sizeof
#define ZZ(x) (SZ(x)/SZ*(x))
#define Q(x) ({I r_=(x);r_<0?die(#x):r_;})
#define Mc memcpy
#define wr write
#define wrZ(x,y) wr(x,y,SZ y)
#define Sn strlen
#define SC0 strchrnul
#define SR strrchr
#define M1(x) #x
#define M2(x) M1(x)
typedef void V;typedef char C;typedef int I;typedef unsigned UI;typedef unsigned long long UL;
S C*sk(C*s,C c)_(W(*s==c,s++)s)S C*su(C*s,UL x)_(I(x>9,s=su(s,x/10))*s++='0'+x%10;s)
S I die(O C*s)_(I e=errno;wrZ(1,"ERR: ");wr(1,s,Sn(s));wrZ(1," -> ");s=strerror(e);wr(1,s,Sn(s));wrZ(1,"\n");exit(e);0)
S O C*m[][2]={{"html","text/html"},{"js","application/javascript"},{"k","text/plain"},{"wasm","application/wasm"}};
S O C*mime(O C*x)_(i(ZZ(m),P(!strcmp(x,*m[i]),m[i][1]))(V*)0)
S V r404(I f){wrZ(f,"HTTP/1.1 404 Not Found\nContent-Length:4\nConnection:close\nContent-Type:text/html\n\n404\n");}
S V ap(C**p,O C*s){I n=Sn(s);Mc(*p,s,n);*p+=n;}
S O C*web(I f)_(C b[4096];I r=read(f,b,SZ b-1);P(r<=0,"read failed")b[r]=0;*SC0(b,10)=0;*SC0(b,13)=0;
 wr(1,b,Sn(b));wrZ(1," - ");P(strncmp(b,"GET ",4),"not GET")C*s=b+4;s=sk(s,32);s+=*s=='/';*SC0(s,32)=0;
 I(!*s,s="index.html")O C*d=SR(s,'.'),*m=d?mime(d+1):0;I(!m,m="text/plain")
 I g=open(s,O_RDONLY);P(g<0,"not found")I n=lseek(g,0,SEEK_END);lseek(g,0,SEEK_SET);s=b;
 ap(&s,"HTTP/1.1 200 OK\nContent-Length:");s=su(s,n);ap(&s,"\nConnection:close\nContent-Type:");ap(&s,m);ap(&s,"\n\n");r=s-b;
 W(r>0,wr(f,b,r);r=read(g,b,SZ b))close(g);wrZ(1,"ok\n");(V*)0)
#define port 8080
I main(){struct sockaddr_in a;a.sin_family=AF_INET;a.sin_addr.s_addr=0;a.sin_port=htons(port);
 I l=Q(socket(AF_INET,SOCK_STREAM,0));
 Q(setsockopt(l,SOL_SOCKET,SO_REUSEADDR,(I[]){1},4));
 Q(setsockopt(l,IPPROTO_TCP,TCP_NODELAY,(I[]){1},4));
 Q(bind(l,(V*)&a,SZ a));Q(listen(l,64));wrZ(1,"http://127.0.0.1:"M2(port)"/\n");
 W(1,UI n=SZ a;I f=Q(accept(l,(V*)&a,&n));O C*r=web(f);I(r,wr(1,r,Sn(r));wrZ(1,"\n");r404(f))close(f))}
