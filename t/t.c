#include<fcntl.h> // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - http://git.sr.ht/~ngn/k/blob/master/LICENSE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#define   _(a...) {return({a;});}
#define Y(x,a...) if(x){a;}
#define   E(a...) else{a;}
#define P(x,a...) if(x)_(a)
#define W(x,a...) while(x){a;}
#define i(x,a...) for(I i=0,n_=(x);i<n_;i++){a;}
#define S static
#define BR break
#define Z sizeof
#define pr(x...) {printf(x);fflush(stdout);}
#define wr write
#define cl close
typedef char C;typedef int I;typedef long long L;
S C*mm(C*f,C**e)_(I d=open(f,0);struct stat h;fstat(d,&h);L n=h.st_size;
 C*s=mmap(0,n,PROT_READ,MAP_PRIVATE,d,0);cl(d);*e=s+n;s)
S I nl(C*s,I n)_(C*p=s;I i=0;W(i<n,Y(s[i]==10&&i<n-1&&s[i+1]==32,*p++=';';i+=2)E(*p++=s[i++]))p-s)
S I t(C*s,I n)_(write(1,".",1);P(*s=='/'||*s==10,0)
 C*u=strstr(s," /");P(!u,wr(1,"bad test: ",10);wr(1,s,n);-1)
 C*a[]={"../k",0};I p[4];pipe(p);pipe(p+2);
 I c=fork();P(!c,dup2(*p,0);dup2(p[3],1);i(4,cl(p[i]))exit(execve(*a,a,0));0)
 cl(*p);cl(p[3]);Y(*s-32,wr(p[1],"\\w ",3))wr(p[1],s,u-s);wr(p[1],"\n",1);cl(p[1]);
 C o[256];L m=0;W(1,L k=read(p[2],o+m,Z(o)-1-m);Y(k<=0,BR)m+=k;Y(m<Z(o)-1,BR))
 cl(p[2]);m=nl(o,m);u+=3;kill(c,SIGKILL);P(s+n==u+m&&!strncmp(o,u,m),1)
 wr(1,"\nfail: ",6);wr(1,s,n);wr(1,o,m);wr(1,"\n",1);-1)
I main()_(C*e,*s=mm("t.k",&e);I n=0,f=0;W(s<e,C*u=strchr(s,10)+1;I r=t(s,u-s);n+=!!r;f+=r<0;s=u)
 P(f,pr("\nfail %d/%d\n",f,n);1)pr("\n");0)
