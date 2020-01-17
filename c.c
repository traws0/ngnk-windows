#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
#include<sys/time.h>
L now()_(struct timeval t;gtod(&t,0);1000000ll*t.tv_sec+t.tv_usec)
S A1(cmdw,asrt(xtC);L n=mu;P(!xn,xr;al(n))A y=Nx(val(xR));mr(out(y));n=mu-n;xr;n?enl(cat(as(0),al(n))):au0)
S A1(cmdt,asrt(xtC);C*s=xc;L n=*s==':'?++s,pl(&s):1;L t=now();x=N(cpl(N(prs(N(cut(al(s-xc),x))))));F(n,mr(Nx(app(x,0,0))))xr;al((now()-t+500)/1000))
A1(cmd,P(!xtC,et(x))$(!xn||xn==1&&*xc=='\\',exit(0))C c=*xc;
 $(C3('a',c,'z')&&(xn==1||xc[1]==32||xc[1]==':'),I i=0;W(i<xn&&xci-32&&xci-':',i++)I j=i;W(j<xn&&xcj==32,j++)x=N(cut(al(j),x));
  P(c=='l',ldf(x))P(c=='w',cmdw(x))P(c=='t',cmdt(x)))
 K("{0x0a\\`x(,\"/bin/sh\";x)}",x))
A1(frk,P(!xtX||xn-2,ed(x))A y=gkv(&x);P(!xtX||!ytC,ed(x,y))x=mut(x);C*a[xn+1];F(xn,A z=xai;$(!ztC,ed(x,y))a[i]=C(xai=str0(z))) //`x((exe;a1;a2;..);in)
 a[xn]=0;xr;I p[4];pipe2(p,0);pipe2(p+2,0);P(!fork(),yr;dup2(*p,0);dup2(p[3],1);F(4,close(p[i]))exit(execve(*a,a,0));0)close(*p);close(p[3]);
 mr2(y,write(p[1],yc,yn));close(p[1]);A u=aC(256-ZA);L m=0,k;W((k=read(p[2],uc+m,un-m))>0,m+=k;$(m+1000000>un&&2*m>un,A z=aC(2*un+ZA);mc(zc,uc,m);ur;u=z))
 close(p[2]);AN(m,u))
