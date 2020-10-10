//ngn
#define _GNU_SOURCE
#include<stdio.h>
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
#define Q(x) ({I r_=(x);Y(r_<0,pr("ERR: "#x" -> %s\n",strerror(errno));exit(1))r_;})
#define pr(a...) {printf(a);fflush(stdout);}
typedef void V;typedef char C;typedef int I;typedef unsigned U;
S O C*mime(O C*x)_(S O C*a[][2]={{"html","text/html"},{"js","application/javascript"},{"png","image/png"},{"wasm","application/wasm"}};
 F(ZZ(a),P(!strcmp(x,*a[i]),a[i][1]))0)
S V r404(I f){O C*s="HTTP/1.1 404 Not Found\nContent-Length:4\nConnection:close\nContent-Type:text/html\n\n404\n";write(f,s,Z s);}
S O C*web(I f)_(C b[1024];I r=read(f,b,Z b);P(r<=0||r>=Z b,"read failed")b[Z b-1]=0;F(r,Y(b[i]==10||b[i]==13,b[i]=0;break))
 pr("%s - ",b)P(strncmp(b,"GET ",4),"not GET")C*s=b+4;W(*s==32,s++)s+=*s=='/';*strchrnul(s,32)=0;
 O C*d=strchrnul(s,'.'),*m=*d?mime(d+1):0;P(!m,"bad ext")I g=open(s,O_RDONLY);P(g<0,"not found")I l=lseek(g,0,SEEK_END);lseek(g,0,SEEK_SET);
 r=sprintf(b,"HTTP/1.1 200 OK\nContent-Length:%d\nConnection:close\nContent-Type:%s\n\n",l,m);W(r>0,write(f,b,r);r=read(g,b,Z b))close(g);
 pr("ok\n");0)
I main(){I p=8080;struct sockaddr_in a;a.sin_family=AF_INET;a.sin_addr.s_addr=0;a.sin_port=htons(p);
 I s=Q(socket(AF_INET,SOCK_STREAM,0));Q(bind(s,(V*)&a,Z a));Q(listen(s,64));pr("http://127.0.0.1:%d/\n",p);
 W(1,U l=Z a;I f=Q(accept(s,&a,&l));O C*r=web(f);Y(r,pr("%s\n",r);r404(f))close(f);)}
