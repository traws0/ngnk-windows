#include"k.h"
#define CT(x) CT_[(UC)x] //char type
//     a    0    +    '    "    `    (    [    {    \n;)]}  spc
S O UC CL=0,CD=1,CV=2,CA=3,CQ=4,CS=5,CP=6,CB=7,CC=8,CN=9,   CX=10;
S O UC CT_[256]={['0'...'9']=CD,['\'']=CA,['/']=CA,['\\']=CA,['"']=CQ,['`']=CS,
 ['(']=CP,['[']=CB,['{']=CC,[')']=CN,[']']=CN,['}']=CN,[';']=CN,[0 ...' '-1]=CN,[' ']=CX,
 [':']=CV,['+']=CV,['-']=CV,['*']=CV,['%']=CV,['!']=CV,['&']=CV,['|']=CV,['<']=CV,['>']=CV,
 ['=']=CV,['~']=CV,[',']=CV,['^']=CV,['#']=CV,['_']=CV,['$']=CV,['?']=CV,['@']=CV,['.']=CV,};
//     noun verb ()   []   {}   start/end
S O UC GN=0,GV=1,GP=2,GB=3,GC=4,GG=5; //grammatical categories
S C unh(C c){R(c&15)+9*(c>'9');} S C num(C*s){R CT(s[*s=='-'])==CD;} S C ldg(C c){R CT(c)<=CD;}
#define ep {ec=1;eo(s0,s-s0);R 0;}
#define psh(gi,ti,oi){g[n]=gi;t[n]=ti;o[n]=(C)(oi);n++;$(n>ZZ(t),ep)}
S v1(mon){$(xt==tv&&x!=cv0,R cu(*xi))$(!xt&&xn==2&&xx==cw(0),x=mut10(x);xy=mi(mon(xy)))R x;}
S I prsname(C**p){C*s=*p,c=*s;
 $(c&0x80,DW(c=*++s,(c&0xc0)==0x80))E$(c==':',DW(c=*++s,ldg(c)||c=='.'||c==':'||c=='/'))E(W(ldg(c),c=*++s))
 I v=sym(*p,s-*p);*p=s;R v;}
S N A prsnames(C**p,C sep){C*s=*p,c=*s;A x=aS(0);W(1,x=apdi(x,prsname(&s));$(*s!=sep,B)c=*++s)*p=s;R x;}
v1(prs){x=str0(x);C*s=xc,*s0=s;I n=1;A t[64];UC g[ZZ(t)];UH o[ZZ(t)];*t=a2(x,aS(0));*g=GG;*o=0;I*na=0;
 W(1,C c=*s;A x=0;C gx=GN;W(c==' ',c=*++s)
  $(c=='/'&&(s==s0||s[-1]==' '||s[-1]=='\n'),DW(c=*++s,c&&c!='\n'));UH ox=s-s0;
  Y(CT(c),ep,
   Q(CL,C*s1=s;x=prsnames(&s,'.');Ao(x)=ox;$(xn==1,xt=ts;$(na&&s-s1==1&&(*s1=='y'||*s1=='z'),*na=max(*s1-'w',*na))))
   Q(CS,s++;x=prsnames(&s,'`');c=*s;$(xn>1,x=a1(x)))
   Q(CQ,x=aC(0);c=*++s;W(c&&c!='"',$(c=='\\',c=*++s;fi(4,$(c=="tnr0"[i],c="\t\n\r"[i])))x=apdc(x,c);c=*++s)
        $(!c,ep)c=*++s;$(xn==1,xt=tc))
   Q(CA,$(c=='\\'&&(!s[1]||CT(s[1])==CL),c=*++s;C*s1=s;W(c&&c!='\n',c=*++s)x=a2o(cu_cmd,acm(s1,s),ox))
        E(I h=s[1]==':';gx=GV;x=cw((c!='\'')+(c=='\\')+3*h);s+=1+h;c=*s))
   case CV:$(!num(s)||(c=='-'&&s!=s0&&(ldg(s[-1])||s[-1]==')'||s[-1]==']'||s[-1]=='}')),
           I u=s[1]==':';C v=0;W(cf[v]!=c,v++)gx=GV;x=u?cu(v):cv(v);s+=1+u;B) //falls through
   Q(CD,$(c=='0'&&s[1]=='x',s+=2;C*p=s;W(CT(*p)==CD||('a'<=*p&&*p<='f'),p++)I m=(p-s)/2;
                            x=atn(m==1?tc:tC,m);fi(m,xci=unh(*s)<<4|unh(s[1]);s+=2))
        E$(s[1]==':',I u=s[2]==':';s+=2+u;I i=c+(20-'0');gx=GV;x=u?cu(i):cv(i))
        E(I fp=0;C*p=s;c=*p;
          W(1,p+=*p==' ';p+=*p=='-';c=*p;$(!ldg(c),B)
              W(ldg(c)||c=='.'||c==':',fp=fp||c=='.'||c=='n'||c=='w';c=*++p))
          $(fp,x=aF(0);W(1,I m=*s=='-';s+=m;F v=0;c=*s;W(CT(c)==CD,v=10*v+(c-'0');c=*++s)
                           $(c=='.',c=*++s;F w=.1;W(CT(c)==CD,v+=w*(c-'0');c=*++s;w/=10))
                           E$(c=='n',c=*++s,v=_0n)
                           E$(c=='w',c=*++s;v=_0w)
                           x=apdf(x,(1-2*m)*v);$(c!=' '||!num(s+1),B)c=*++s)
               $(xn==1,xt=tInv(xt)))
          E(x=aI(0);W(1,I m=*s=='-';s+=m;I v=0;c=*s;W(CT(c)==CD,v=10*v+(c-'0');c=*++s)
                        $(c=='W',v=_0W;c=*++s)E$(c=='N',v=_0N;c=*++s)
                        x=apdi(x,(1-2*m)*v);$(c!=' '||!num(s+1),B)c=*++s)
            $(xn==1,xt=tInv(xt)))))
   Q(CP,$(s[1]==')',s+=2;x=cea)E(s++;gx=GP;x=a1(cv_lis)))
   Q(CC,psh(GC,a1(aS(0)),ox);s0+=ox;C c=*++s;$(c=='[',c=*++s;psh(GB,a1(cv_lis),255);na=0)E(t[n-1]=apdx(t[n-1],na=ai(1))))
   Q(CN,I i=n-1;W(g[i]<=GV,i--)$(c!=';'&&c!='\n'&&c!=")]}"[g[i]-GP],ep)
        $(n-i==1,t[n++]=g[i]==GB?cv_plc:cu0)
        $(g[n-1]==GV,
         A z=t[--n];$(g[n-1]==GN,--n;z=a3o(z,t[n],cv_plc,o[n]))
         W((g[n-1]<=GV)&&t[n-1]!=cv0,
          A u=t[--n];$(g[n]==GV&&g[n-1]==GN,--n;u=a2o(u,t[n],o[n]))E(u=mon(u))
          z=a3o(cv_cps,u,z,Ao(u)))
         g[n]=GV;t[n++]=z)
        A y=t[--n];W(n-i>1,$(n-i>2&&g[n-2]==GN&&g[n-1]==GV,y=a3o(t[n-1],t[n-2],y,o[n-1]);n-=2)
                           E(--n;y=a2o(mon(t[n]),y,o[n])))
        s++;A x=t[i]=apdx(t[i],y);
        Y(c,,Q(0,$(n!=1,ep)A y=xa[xn-1];$(!yt&&yn,A z=yx;$(z==cv0||(zt==tu&&yn>2),x=apdx(x,cu0)))R x)
             Q(')',g[i]=GN;$(xn==2,md(xx);t[i]=mo(xy);mf_(x)))
             Q(']',g[i]=GN;$(xx==cv_lis,x=cut(cb(1),x);$(xt!=tS,ep)n--;t[n-1]=apdx(t[n-1],x));Ao(t[n-1])=o[n-1];
                   $(xn==2&&xy==cv_plc,mo(xy);xy=mi(cu0)))
             Q('}',g[i]=GN;xt=tl;md(xx);xx=mi(acm(s0,s));s0-=o[i]-1;
                   y=mo(xy);$(yt==ti,xy=mi(cxyz(gi(y)-1)))E(A z=xy=mi(sqz(y));$(zt!=tS,ep))
                   Ao(x)=An(xy);asrt(Ao(x));na=0;I j=n-1;W(j>0&&g[j]!=GC,j--)$(j,A z=t[j];z=zy;$(zt==ti,na=zi))))))
 $(x,psh(gx,x,ox))
 $(g[n-1]<=GV,
  W(CT(*s)==CA,C c=*s++,u=*s==':';s+=u;t[n-1]=a2(cw((c!='\'')+(c=='\\')+3*u),t[n-1]);g[n-1]=GV)
  $(*s=='[',s++;t[n-1]=a1(t[n-1]);g[n-1]=GB)))}
