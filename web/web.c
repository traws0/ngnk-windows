#define _GNU_SOURCE // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define   _(a...) {return({a;});}
#define Y(x,a...) if(x){a;}
#define P(x,a...) if(x)_(a)
#define W(x,a...) while(x){a;}
#define F(x,a...) for(I i=0,n_=(x);i<n_;i++){a;}
#define S static
#define O const
#define Z sizeof
#define ZZ(x) (Z(x)/Z*(x))
#define Q(x) ({I r_=(x);r_<0?die(#x):r_;})
#define mc memcpy
#define wr write
#define wrZ(x,y) wr(x,y,Z y)
#define mn strlen
#define sc0 strchrnul
#define MS(x) #x
#define XS(x) MS(x)
typedef void V;typedef char C;typedef int I;typedef unsigned short UH;typedef unsigned UI;typedef unsigned long long UL;

S C*sk(C*s,C c)_(W(*s==c,s++)s) //sk:skip
S C*su(C*s,UL x)_(Y(x>9,s=su(s,x/10))*s++='0'+x%10;s)
S I die(O C*s)_(I e=errno;wrZ(1,"ERR: ");wr(1,s,mn(s));wrZ(1," -> ");s=strerror(e);wr(1,s,mn(s));wrZ(1,"\n");exit(e);0)
S O C*m[][2]={{"html","text/html"},{"js","application/javascript"},{"png","image/png"},{"wasm","application/wasm"}};
S O C*mime(O C*x)_(F(ZZ(m),P(!strcmp(x,*m[i]),m[i][1]))(V*)0)
S V r404(I f){O C*s="HTTP/1.1 404 Not Found\nContent-Length:4\nConnection:close\nContent-Type:text/html\n\n404\n";wrZ(f,s);}
S O C*web(I f)_(C b[1024];I r=read(f,b,Z b-1);P(r<=0,"read failed")b[r]=0;*sc0(b,10)=0;*sc0(b,13)=0;
 wr(1,b,mn(b));wrZ(1," - ");P(strncmp(b,"GET ",4),"not GET")C*s=b+4;s=sk(s,32);s+=*s=='/';*sc0(s,32)=0;
 Y(!*s,s="index.html")O C*d=sc0(s,'.'),*m=*d?mime(d+1):0;P(!m,"bad ext")
 I g=open(s,O_RDONLY);P(g<0,"not found")I n=lseek(g,0,SEEK_END);lseek(g,0,SEEK_SET);
 #define h0 "HTTP/1.1 200 OK\nContent-Length:"
 #define h1 "\nConnection:close\nContent-Type:"
 s=b;mc(s,h0,Z h0-1);s+=Z h0-1;s=su(s,n);mc(s,h1,Z h1-1);s+=Z h1-1;mc(s,m,mn(m));s+=mn(m);mc(s,"\n\n",2);s+=2;r=s-b;
 W(r>0,wr(f,b,r);r=read(g,b,Z b))close(g);wrZ(1,"ok\n");(V*)0)
#define port 8080
I main(){struct sockaddr_in a;a.sin_family=AF_INET;a.sin_addr.s_addr=0;a.sin_port=htons(port);
 I l=Q(socket(AF_INET,SOCK_STREAM,0));Q(bind(l,(V*)&a,Z a));Q(listen(l,64));wrZ(1,"http://127.0.0.1:"XS(port)"/\n");
 W(1,UI n=Z a;I f=Q(accept(l,&a,&n));O C*r=web(f);Y(r,wr(1,r,mn(r));wrZ(1,"\n");r404(f))close(f))}
