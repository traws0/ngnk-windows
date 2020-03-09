// ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
//#define DEBUG
#include<sys/syscall.h>
#include<math.h>
#include"g.h"
#define    _(a...) {R({a;});}
#define  Y(x,a...) if(x){a;}
#define  P(x,a...) Y(x,_(a))
#define    E(a...) else{a;}
#define EY(x,a...) else if(x){a;}
#define  W(x,a...) while(x){a;}
#define  F(x,a...) for(__typeof__(x)n_=(x),i=0;i<n_;i++){a;}
#define Fj(x,a...) for(__typeof__(x)n_=(x),j=0;j<n_;j++){a;}
#define  Q(x,a...) case x:{a;B;}
#define SW(x,y,a...) switch(x){default:{y;B;}a}
#define B break
#define O const
#define R return
#define S static
#define SI S inline
#define SN S NI
#define NI __attribute__((noinline))
#if __clang__||__GNUC__
 #define UR __builtin_unreachable();
#else
 #define UR
#endif
#define CD __attribute__((cold))
#define XT extern
#define TD typedef
#define MS(x) #x
#define XS(x) MS(x)
#define N(r)      ({A r_=(r);P(!r_,            0);r_;})
#define N1(x,r)   ({A r_=(r);P(!r_,mr(x);      0);r_;})
#define N2(x,y,r) ({A r_=(r);P(!r_,mr(x);mr(y);0);r_;})
#define swp(x,y) {__typeof__(x)tmp=x;x=y;y=tmp;}
#ifdef DEBUG
 #define dbg(x) x
 #define die(x) {write(1,x,sizeof(x));exit(1);}
 #define asrt(x) Y(!(x),die(__FILE__":"XS(__LINE__)": "XS(x)))
#else
 #define dbg(x)
 #ifdef __clang__
  #define asrt(x) __builtin_assume(x)
 #else
  #define asrt(x)
 #endif
#endif

TD char C;TD unsigned char UC;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;TD unsigned long long UL;TD double D;
TD void V;TD L A;TD A A0(),A1(A),A2(A,A),A3(A,A,A),AA(O A*,I),AX(A,O A*,I);
#define V(x) ((V*)((UL)(x)<<16>>16))
#define C(x) ((C*)V(x))
#define H(x) ((H*)V(x))
#define I(x) ((I*)V(x))
#define L(x) ((L*)V(x))
#define D(x) ((D*)V(x))
#define A(x) ((A*)V(x))
#define A_(a...) (A[]){a}
#define A0(f,b...) A f()             _(b)
#define A1(f,b...) A f(A x)          _(b)
#define A2(f,b...) A f(A x,A y)      _(b)
#define A3(f,b...) A f(A x,A y,A z)  _(b)
#define AA(f,b...) A f(O A*a,I n)    _(b)
#define AX(f,b...) A f(A x,O A*a,I n)_(b)

#define sc(f,a...  ) ({L r;asm volatile("syscall":"=a"(r):"0"(SYS_##f)a:"cc","rcx","r11","memory");r;})
#define sc1(f,x    ) sc(f,,"D"(x)              )
#define sc2(f,x,y  ) sc(f,,"D"(x),"S"(y)       )
#define sc3(f,x,y,z) sc(f,,"D"(x),"S"(y),"d"(z))
#define   read(a...) sc3(        read,a)
#define  write(a...) sc3(       write,a)
#define   open(a...) sc3(        open,a)
#define  close(a...) sc1(       close,a)
#define  fstat(a...) sc2(       fstat,a)
#define   dup2(a...) sc2(        dup2,a)
#define execve(a...) sc3(      execve,a)
#define  pipe2(a...) sc2(       pipe2,a)
#define munmap(a...) sc2(      munmap,a)
#define    skt(a...) sc3(      socket,a)
#define   conn(a...) sc3(     connect,a)
#define   gtod(a...) sc2(gettimeofday,a)
#define   exit(a...){sc1(        exit,a);UR;}
#define fork() sc(fork)
V*mmap_(V*,L,L,L,L,L);

#define extr(x,y,c)({__typeof__(x) x1=(x),y1=(y);x1 c y1?x1:y1;})
#define min(x,y)extr(x,y,<)
#define max(x,y)extr(x,y,>)
SI L absL(L x)_(x<0?-x:x)SI I c3(UC x,UC y,UC z)_(x<=y&&y<=z)SI D l2d(L v)_(*(D*)(V*)&v)SI C hex(I x)_(x+(x>9?'a'-10:'0'))SI I dgt(C c)_(c3('0',c,'9'))

//   () "" ,i ,0 ,d ,` +! ! "a" 0i 0  0. `  {} 1+ ++ +/ +: +  /
enum{tX,tC,tI,tL,tD,tS,tA,ta,tc,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn};
#define tsym "XCILDSAacildsopqruvw"
//header bytes: bfoorrrrnnnnnnnn (b=bucket,f=flags,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,cis=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0000 tX,tC,tI,tL,tD,tS,tA,ta,tl,td
// tttttttt................................................cccccccc tc
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ti
// tttttttt........oooooooooooooooossssssssssssssssssssssssssssssss ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx0000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
SI UC At(A x)_((UL)x>>56   )SI A AT(UC t,A x)_((A)((UL)t<<56|(UL)x<<8>>8))
SI I reft(UC t)_(t==tX||t==ta||t==tA||t==to||t==tp||t==tq||t==tr)SI I ref(A x)_(reft(xt))SI I pkd(A x)_(xtc||xti||xts||xtu||xtv||xtw)
SI I sim(A x)_(ta<xt&&xt<to)SI I fun(A x)_(to<=xt)SI UC t_lst(UC t)_(t==ta?tA:t>=to?tX:t>=tc?t+tC-tc:t)
SI UC Ak(A x)_((UL)x>>48&7 )SI A AK(UC k,A x)_(asrt(k< 8);asrt(xt<tu||tw<xt);(A)(((UL)x&~( 7ull<<48))|(UL)k<<48))
SI UC Av(A x)_((UL)x>>51&31)SI A AV(UC v,A x)_(asrt(v<32);asrt(xt<tu||tw<xt);(A)(((UL)x&~(31ull<<51))|(UL)v<<51))
SI UC Ab(A x)_(UC b=xc[-16];asrt(b<48);b)SI A AB(UC b,A x)_(asrt(b<48);xc[-16]=b;x)
SI UL An(A x)_(L n=xl[-1];asrt(0<=n);asrt(n<(1ll<<48));n)SI A AN(L n,A x)_(asrt(0<=n);asrt(n<1ull<<48);xl[-1]=n;x)
SI UH Ao(A x)_(xts?(UL)x>>32:pkd(x)?0:xh[-7])SI A AO(UH o,A x)_(P(xts,(A)(((UL)x&~(0xffffull<<32)|(UL)o<<32)))H(x)[-7]=o;x)
#define Ar(x) I(x)[-3]

#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZV Z(V*)  //ptr
#define ZP 4096ll //page
#define ZA 16     //hdr
#define ZR 4
SI UC tz(UC t)_(t==tC?0:t==tI||t==tS?2:reft(t)?ZR:3) //log(tZ(t)) with a special value ZR for ref types
SI UC tZ(UC t)_(t==tC?1:t==tI||t==tS?4:reft(t)?ZV:8) //type size in bytes

A1 a1,asc,ax,blw,cmd,cpl,dsc,enl,enla,fir,flp,flr,frk,gD,gI,gL,gS,grp,hcl,hop,json,kst,las,ldf,len,mr,mr0,mr1,mRa,mut,neg,not,nul,out,prs,rev,sqr,sqz,
   str,str0,til,typ,u0c,u1c,unq,val,whr;
A2 a2,aa,aA,add,ap1,ap2,apd,cat,com,cst,cut,dex,dvd,eql,fnd,id_,gtn,idx,ltn,mnm,mod,mtc,mul,mxm,rsh,sub,v0c,v1c,xpt;
A0 aa0;A3 a3,try;AA amd,am1,dmd,dm1;AX eac,rdc,scn,eap,ear,eal,app,prj,run;XT A syml,glb;XT L mu;
A err0(O C*),err1(O C*,A),err2(O C*,A,A),err3(O C*,A,A,A),errn(O C*,I,O A*),ea1(A1,A),apv(A,O V*),apc(A,C),catc(A,O C*,L),room(A,L),
  get(A,L),getr(A,L),atn(UC,L),atnv(UC,L,O V*),aCn(O C*,L),aCm(O C*,O C*),aCz(O C*),gkv(A*),till(L);
V mrn(L,O A*),*mc(V*,O V*,L),*ms(V*,L,C),*mz(V*,L),init();
I Ci(O C*,C),epr(),eso(A,I),memcmp(O V*,O V*,L),mtc_(A,A),sym(A);
L strlen(O C*),len_(A),fndl(A,L),fndi(A,I),fpc(A*,C),fpi(A*,I),fpl(A*,L),fpa(A*,A),tru(A),now(),pl(C**),slc_(A,L,L),pu(C**);

SI A1(mR,asrt(x);P(pkd(x),x)asrt(Ar(x)>=0);Ar(x)++;x)SI A symstr(I i)_(A(syml)[i])SI C*symptr(I i)_(C(symstr(i)))
#define atv(t,v) ({A r_=atn((t),1);*(typeof(v)*)V(r_)=(v);r_;})
SI A aX(L n)_(atn(tX,n))SI A pck(UL t,UI v)_(t<<56|v)SI A0(a0,aX(0))
SI A aC(L n)_(atn(tC,n))SI A ac(UC v)_(pck(tc,v))SI UC gc(A x)_(asrt(xtc);(UC)x)
SI A aS(L n)_(atn(tS,n))SI A as(I v)_(pck(ts,v))SI I gs(A x)_(asrt(xts);(I)x)
SI A aI(L n)_(atn(tI,n))SI A ai(I v)_(pck(ti,v))SI I gi(A x)_(asrt(xti||xtc||xts);(I)x)
SI A aL(L n)_(atn(tL,n))SI A al(L v)_(atv(tl,v))SI L gl_(A x)_(pkd(x)?(I)x:*xl)SI L gl(A x)_(L r=gl_(x);xr;r)
SI A aD(L n)_(atn(tD,n))SI A ad(D v)_(atv(td,v))SI D gd_(A x)_(*xd)SI D gd(A x)_(D v=*xd;xr;v)

#define err_(x,y,z,u,n,...) n
#define err(a...) ({dbg(os("["__FILE__":"XS(__LINE__)"]"));err_(a,err3,err2,err1,err0)(a);})
#define en(a...) err((C*)0,##a)
#define el(a...) err((C*)1,##a)
#define et(a...) err((C*)2,##a)
#define ed(a...) err((C*)3,##a)
#define er(a...) err((C*)4,##a)
#define ei(a...) err((C*)5,##a)
#define ep(a...) err((C*)6,##a)
#define h(t,i) SI A e##t##n(I n,O A*a)_(errn((C*)i,n,a))
h(n,0)h(l,1)h(t,2)h(d,3)h(r,4)h(i,5)h(p,6)
#undef h

#define tvk(t,v,k) ((A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48))
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:c=='~'?11:c==','?12:\
 c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S O A au0=au(0),av0=av(0),au_out=au(25),au_cmd=au(26),au_plc=au(29),av_com=av(24),av_mkl=av(25);
#define _0Nl (1ull<<63)
#define _0Wl (~_0Nl)
#define _0Ni (1<<31)
#define _0Wi (~_0Ni)
#define _0n  (D)NAN
#define _0w  (D)INFINITY
#define K(s,a...) ({S A f;Y(!f,f=K0(s,Z(s)))app(f,A_(a),Z(A_(a))/ZV);})
A K0(O C*,I);
XT O C vc[];XT A cn[],ci[5][3];XT O V*vf[];

XT O V*arf[3][10][6];
#define ar_(f,n,p,a4,a5,a8,a9,a10) SW(f,UR,Q(0,F(n,p ((V)a,b)))Q(1,F(n,p a+b))Q(2,F(n,p a-b))Q(3,F(n,p a*b))\
 Q(4,a4)Q(5,a5)Q(6,F(n,p min(a,b)))Q(7,F(n,p max(a,b)))Q(8,a8)Q(9,a9)Q(10,a10))
#define arI(f,n,p)ar_(f,n,p,F(n,p b?a/b:!a?_0Ni:a>0?_0Wi:-_0Wi),F(n,p a>0?(b%a+a)%a:a?b/-a:_0Ni),F(n,p a<b     ),F(n,p a>b     ),F(n,p a==b))
#define arL(f,n,p)ar_(f,n,p,F(n,p b?a/b:!a?_0Nl:a>0?_0Wl:-_0Wl),F(n,p a>0?(b%a+a)%a:a?b/-a:_0Nl),F(n,p a<b     ),F(n,p a>b     ),F(n,p a==b))
#define arD(f,n,p)ar_(f,n,p,F(n,p   a/b                       ),F(n,p((V)a,(V)b,_0n))           ,F(n,p l2d(a<b)),F(n,p l2d(a>b)),F(n,p l2d(a==b)))

#define mr2(x,a...) ({A t_=mr0(x);__typeof__(({a;}))r_=({a;});dbg(x=0);mr1(t_);r_;})

#define ov(x) ov_(#x":",(L)(x))
#define ox(x) ox_(#x":",(A)(x))
#define oo os("["__FILE__":"XS(__LINE__)"]");
#define nop {asm volatile("fnop");}
SI I os(O C*x)_(write(2,x,strlen(x)))
SI I oh(L x)_(C s[17];s[16]=0;F(16,s[15-i]=hex(x&15);x>>=4)write(2,s,17))
SI I ol(L x)_(C b[32],*u=b+31;L m=x<0;Y(m,x=-x)do{*u--='0'+x%10;x/=10;}while(x);Y(m,*u--='-')write(2,u+1,b+31-u))
SI L ov_(C*s,L x)_(os(s);write(2,"           ",max(1,10-strlen(s)));oh((L)x);write(2,"\n",1);x)
SI A ox_(C*s,A x)_(os(s);oh((L)x);P(!x,0)Y(!pkd(x),os(" b");ol(xb);os("t");ol(xt);os("r");ol(Ar(x));os("n");ol(xn))os(" ");out(x))
