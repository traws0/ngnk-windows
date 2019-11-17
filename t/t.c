#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/signal.h>
#define R return
#define S static
#define $(x,y...)if(x){y;}
#define E(x...)else{x;}
#define W(x,y...)while(x){y;}
#define P(x...){printf(x);fflush(stdout);}
#define fi(x,y...)for(L i=0,n_=(x);i<n_;i++){y;}
#define Z(x)sizeof(x)
#define wr write
#define cl close
typedef char C;typedef int I;typedef long long L;
S C*mm(C*f,C**e){I d=open(f,0);struct stat h;fstat(d,&h);L n=h.st_size;C*s=mmap(0,n,1,2,d,0);cl(d);*e=s+n;R s;}
S I fixnl(C*s,I n){C*p=s;I i=0;W(i<n,$(s[i]=='\n'&&i<n-1&&s[i+1]==' ',*p++=';';i+=2)E(*p++=s[i++]))R p-s;}
S I test(C*s,C*e){
 $(*s=='/'||*s=='\n',R 0)
 C*t=strstr(s," /");$(!t,wr(1,"bad test: ",10);wr(1,s,e-s);R-1)
 C*a[]={"../k",0};I p[4];pipe(p);pipe(p+2);$(!fork(),dup2(*p,0);dup2(p[3],1);fi(4,cl(p[i]))exit(execve(*a,a,0));R 0)
 cl(*p);cl(p[3]);$(*s!=' ',wr(p[1],"\\w ",3))wr(p[1],s,t-s);wr(p[1],"\n",1);cl(p[1]);
 C o[256];L m=0;W(1,L k=read(p[2],o+m,Z(o)-1-m);$(k<=0,break)m+=k;$(m<Z(o)-1,break))cl(p[2]);
 m=fixnl(o,m);t+=3;I r=e-t!=m?1:strncmp(o,t,m);$(r,wr(1,"fail: ",6);wr(1,s,e-s);wr(1,o,m);wr(1,"\n",1);R-1)R 1;}
I main(){C*e,*s=mm("t.k",&e);I n=0,f=0;W(s<e,C*t=strchr(s,'\n')+1;I r=test(s,t);n+=!!r;f+=r<0;s=t)
 $(f,P("fail %d/%d\n",f,n);R 1)P("ok %d\n",n);R 0;}
