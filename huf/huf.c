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
#define O const
#define ms memset
#define getdents(a...) syscall(SYS_getdents,a)
TD void V;TD char C;TD unsigned char UC;TD short H;TD unsigned short UH;TD int I;TD long long L;
S struct{O C*s;I n;}a[256];S I na;
S I f[512],p[512],c[512][2],r[256],nr,l[512]; //f:freq,p:parent,c:children,r:roots,l:bitlengths
S V v(I x){Y(c[x][0]<0,pr("%d",x))E(I y=c[x][0],z=c[x][1];l[y]=l[z]=l[x]+1;pr("[");v(y);pr(",");v(z);pr("]"))}
S I mr()_(I u=0,x=*r,b=f[x];F(nr,Y(f[r[i]]<b,b=f[x=r[u=i]]))r[u]=r[--nr];x) //find and remove root with min freq
I main(){
 //gather data
 I d=open("../g",0);C b[1024];
 W(1,I k=getdents(d,b,Z b),i=0;Y(k<=0,break)
  W(i<k,struct{long _;I _1;UH l;C s[];}*de=(V*)(b+i);C*s=de->s;
   Y(b[i+de->l-1]==DT_REG&&!strcmp(s+strlen(s)-2,".k"),
    I fd=openat(d,s,0),n=lseek(fd,0,SEEK_END);C*s=mmap(0,n,MAP_FILE|MAP_SHARED,PROT_READ,fd,0),*s0=s;close(fd);
    Y(*s=='/'&&s[1]=='h',W(*s&&*s-10,s++))a[na].s=s;a[na].n=n+s0-s;na++)
   i+=de->l))
 close(d);
 //stats
 F(256,f[i]=1)
 F(na,O C*s=a[i].s;Fj(a[i].n,f[(UC)s[j]]++))
 //build huffman tree
 ms(p,-1,Z p);ms(c,-1,Z c);F(nr=256,r[i]=i)
 F(255,I x=mr(),y=mr(),z=r[nr++]=256+i;c[z][0]=x;c[z][1]=y;p[x]=z;p[y]=z;f[z]=f[x]+f[y])
 v(*r);pr("\n");
 //calculate improvement
 I n0=0,n1=0;F(na,n0+=a[i].n;O C*s=a[i].s;Fj(a[i].n,n1+=l[(UC)s[j]]))
 n1=(n1+7)/8;pr("n0:%d,n1:%d,improvement:%d%%\n",n0,n1,(n0-n1)*100/n0);}
