#define _GNU_SOURCE // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#include<dirent.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/syscall.h>
#include<sys/mman.h>
#define   _(a...) {return({a;});}
#define W(x,a...) while(x){a;}
#define Y(x,a...) if(x){a;}
#define F(x,a...) for(I i=0,n_=(x);i<n_;i++){a;}
#define TD typedef
#define Z sizeof
#define S static
#define o printf
#define getdents(a...) syscall(SYS_getdents,a)
TD void V;TD char C;TD unsigned char UC;TD short H;TD unsigned short UH;TD int I;TD long long L;
S struct{C*s;I n;}a[256];S I na,f[512],c[512][2],r[256],nr; //f:freq,c:children,r:roots
S V v(I x){c[x][0]>=0?o("["),v(c[x][0]),o(","),v(c[x][1]),o("]"):o("%d",x);}
S I g()_(I u=0,x=*r,b=f[x];F(nr,Y(f[r[i]]<b,b=f[x=r[u=i]]))r[u]=r[--nr];x) //rm and return root with least freq
I main(){I d=open("../g",0);C b[1024];I k;
 W((k=getdents(d,b,Z b))>0,I i=0;
  W(i<k,struct{long _,_1;UH l;C s[];}*e=(V*)(b+i);C*s=e->s;
   Y(b[i+e->l-1]==DT_REG&&!strcmp(s+strlen(s)-2,".k"),
    I fd=openat(d,s,0),n=lseek(fd,0,SEEK_END);C*s=mmap(0,n,MAP_FILE|MAP_SHARED,PROT_READ,fd,0),*s0=s;close(fd);
    Y(*s=='/'&&s[1]=='h',W(*s&&*s-10,s++))a[na].s=s;a[na].n=n+s0-s;na++)
   i+=e->l))
 close(d);
 F(256,f[i]=1)F(na,C*s=a[i].s;F(a[i].n,f[(UC)s[i]]++))memset(c,-1,Z c);F(nr=256,r[i]=i)
 F(255,I x=g(),y=g(),z=r[nr++]=256+i;c[z][0]=x;c[z][1]=y;f[z]=f[x]+f[y])v(*r);o("\n");}
