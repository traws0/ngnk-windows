//ngn
#define _GNU_SOURCE
#include<dirent.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/syscall.h>
#include<sys/mman.h>
#define    _(a...) {return({a;});}
#define  W(x,a...) while(x){a;}
#define  Y(x,a...) if(x){a;}
#define    E(a...) else{a;}
#define  F(x,a...) for(I i=0,n_=(x);i<n_;i++){a;}
#define Fj(x,a...)for(I j=0,n_=(x);j<n_;j++){a;}
#define pr printf
#define TD typedef
#define Z sizeof
#define S static
#define ms memset
#define getdents(a...) syscall(SYS_getdents,a)
TD void V;TD char C;TD unsigned char UC;TD short H;TD unsigned short UH;TD int I;TD long long L;
S I f[512],p[512],c[512][2],r[256],nr; //f:freq,p:parent,c:children,r:roots
S V v(I x){Y(c[x][0]<0,pr("%d",x))E(pr("[");v(c[x][0]);pr(",");v(c[x][1]);pr("]"))}
S I mr()_(I u=0,x=*r,b=f[x];F(nr,Y(f[r[i]]<b,b=f[x=r[u=i]]))r[u]=r[--nr];x)
I main(){
 //gather stats
 I d=open("../g",0);C b[1024];F(256,f[i]=1)
 W(1,I k=getdents(d,b,Z b),i=0;if(k<=0)break;
  W(i<k,struct{long _i;I _o;UH l;C s[];}*de=(V*)(b+i);C*s=de->s;
   Y(b[i+de->l-1]==DT_REG&&!strcmp(s+strlen(s)-2,".k"),
    I fd=openat(d,s,0),n=lseek(fd,0,SEEK_END);C*a=mmap(0,n,MAP_FILE|MAP_SHARED,PROT_READ,fd,0),*a0=a;close(fd);
    Y(*a=='/'&&a[1]=='h',W(*a&&*a-10,a++))F(n+a0-a,f[(UC)(a[i])]++)munmap(a0,n))
   i+=de->l))
 close(d);
 //build huffman tree
 ms(p,-1,Z p);ms(c,-1,Z c);F(nr=256,r[i]=i)
 F(255,I x=mr(),y=mr(),z=r[nr++]=256+i;c[z][0]=x;c[z][1]=y;p[x]=z;p[y]=z;f[z]=f[x]+f[y])
 v(*r);}
