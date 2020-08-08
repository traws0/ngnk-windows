// ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//#define DEBUG
#include<sys/syscall.h>
#include<math.h>
#include"g.h"
#define      _(a...) {return({a;});}
#define    W(x,a...) while(x){a;}
#define    Y(x,a...) if(x){a;}
#define    P(x,a...) Y(x,_(a))
#define     EY(a...) else Y(a)
#define      E(a...) else{a;}
#define      F(a...) F_(i,a)
#define     Fj(a...) F_(j,a)
#define F_(i,n,a...) for(__typeof__(n)n_=(n),i=0;i<n_;i++){a;}
#define B break
#define O const
#define S static
#define NI __attribute__((noinline))
#define XT extern
#define TD typedef
#define RE restrict
#define ALN(x) {asrt(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);}
#define PAD(n,p) ((n)+ZA/Z(*p)-1&-ZA/Z(*p))
#define MS(x) #x
#define XS(x) MS(x)
#define N_(r,a) ({A r_=(r);P(!r_,a;0)r_;}) //error pass-through
#define N(r)      N_(r,)
#define N1(x,r)   N_(r,mr(x))
#define N2(x,y,r) N_(r,mr(x);mr(y))
#define SWP(x,y) {__typeof__(x)t_=x;x=y;y=t_;}
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
#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZV Z(V*)  //ptr
#define ZP 4096ll //page
#define ZA 32     //hdr
#define ZR 4

TD void V;TD char unsigned C;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;TD double D;
TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(O A*,I),AX(A,O A*,I);
#define dat(x) ((V*)((x)<<16>>16))
#define A_(a...) (A[]){a}
#define A0(f,b...) A f(             )_(b)
#define A1(f,b...) A f(A x          )_(b)
#define A2(f,b...) A f(A x,A y      )_(b)
#define A3(f,b...) A f(A x,A y,A z  )_(b)
#define AX(f,b...) A f(A x,O A*a,I n)_(b)
#define AA(f,b...) A f(    O A*a,I n)_(b)

#define sc(f,a...  ) ({L r;asm volatile("syscall":"=a"(r):"0"(SYS_##f)a:"cc","rcx","r11","memory");r;})
#define sc1(f,x    ) sc(f,,"D"(x)              )
#define sc2(f,x,y  ) sc(f,,"D"(x),"S"(y)       )
#define sc3(f,x,y,z) sc(f,,"D"(x),"S"(y),"d"(z))
#define   read(a...) sc3(        read,a)
#define  write(a...) sc3(       write,a)
#define   open(a...) sc3(        open,a)
#define  close(a...) sc1(       close,a)
#define lseek_(a...) sc3(       lseek,a)
#define   dup2(a...) sc2(        dup2,a)
#define execve(a...) sc3(      execve,a)
#if SYS_pipe
 #define  pipe(a...) sc1(        pipe,a)
#else
 #define  pipe(a...) sc2(       pipe2,a,0)
#endif
#define munmap(a...) sc2(      munmap,a)
#define    skt(a...) sc3(      socket,a)
#define   conn(a...) sc3(     connect,a)
#define   gtod(a...) sc2(gettimeofday,a)
#define   exit(a...) sc1(        exit,a)
#define fork() sc(fork)
V*mmap_(V*,L,L,L,L,L);

#define extr(x,y,c) ({__typeof__(x) x1=(x),y1=(y);x1 c y1?x1:y1;})
#define min(x,y) extr(x,y,<)
#define max(x,y) extr(x,y,>)
S L absL(L x)_(x<0?-x:x)S I c3(C x,C y,C z)_(x<=y&&y<=z)S C hx1(I x)_(x+(x>9?'a'-10:'0'))S I dgt(C c)_(c3('0',c,'9'))S I in(L i,L n)_(0<=i&&i<n)

//         () "" ,i ,0 ,d ,` +! ! "a" 0i 0  0. `  {} 1+ ++ +/ +: +  /
enum      {tX,tC,tI,tL,tD,tS,tA,ta,tc,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn}; //types
#define TZ ZV, 1, 4, 8, 8, 4,ZV,ZV, 8, 8, 8, 8, 8,ZV,ZV,ZV,ZV, 8, 8, 8 //size in bytes
#define Tz ZR, 0, 2, 3, 3, 2,ZR,ZR, 3, 3, 3, 3, 3,ZR,ZR,ZR,ZR, 3, 3, 3 //log(tZ[t]) with a special value ZR for ref types
#define TS SX,SC,SI,SL,SD,SS,SA,Sa,Sc,Si,Sl,Sd,Ss,So,Sp,Sq,Sr,Su,Sv,Sw
XT O C tz[],tZ[];
S C At(A);S C t_lst(C t)_(t==ta?tA:t>=to?tX:t>=tc?t+tC-tc:t)   S I sim(A x)_(ta<xt&&xt<to)
S I reft(C t)_(t==tX||t==ta||t==tA||t==to||t==tp||t==tq||t==tr)S I ref(A x)_(reft(xt))
S I pkdt(C t)_(t==tc||t==ti||t==ts||t==tu||t==tv||t==tw)       S I pkd(A x)_(pkdt(xt))
S I funt(C t)_(t>=to)                                          S I fun(A x)_(funt(xt))

//header bytes: b.oorrrrnnnnnnnn (b=bucket,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,cis=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tX,tC,tI,tL,tD,tS,tA,ta,tl,td
// tttttttt................................................cccccccc tc
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ti
// tttttttt........oooooooooooooooossssssssssssssssssssssssssssssss ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw

//getters                                   setters
S  C At(A x)_(x>>56)                        S A AT(UL t,A x)_(asrt(t<=tn);               x<<8>>8|t<<56)
S  C Av(A x)_(x>>51&31)                     S A AV(UL v,A x)_(asrt(v<32);          x&~(31ll<<51)|v<<51)
S  C Ak(A x)_(x>>48&7)                      S A AK(UL k,A x)_(asrt(k<9);           x&~( 7ll<<48)|k<<48)
S  C Ab(A x)_(C b=xc[-16];asrt(b<48);b)     S A AB( C b,A x)_(asrt(b<48);                  xc[-16]=b;x)
S UH Ao(A x)_(xts?x>>32:pkd(x)?0:xh[-7])    S A AO(UL o,A x)_(P(xts,x&~(0xffffll<<32)|o<<32)xh[-7]=o;x)
S UL An(A x)_(UL n=xl[-1];asrt(n<1ll<<48);n)S A AN(UL n,A x)_(asrt(n<1l<<48);               xl[-1]=n;x)
#define Ar(x) ((I*)dat(x))[-3]
S A1(mR,asrt(x);P(pkd(x),x)asrt(Ar(x)>=0);Ar(x)++;x)
#define atv(t,v) ({A r_=atn((t),1);*(typeof(v)*)dat(r_)=(v);r_;}) //type,value
#define tvk(t,v,k) ((A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48))     //type,value,arity

#define ariths(h,a...) h(dex,a)h(add,a)h(sub,a)h(mul,a)h(dvd,a)h(mod,a)h(mnm,a)h(mxm,a)h(ltn,a)h(gtn,a)h(eql,a)
A1 a1,aes0,aes1,asc,ax,blw,cmd,cpl,des,dsc,enl,enla,fir,flp,flr,frk,gD,gI,gL,gS,grp,hcl,hex,hop,json,kst,las,ldf,len,md5,mr,mr0,mr1,mRa,mut,
 neg,not,nul,out,prs,rev,sha1,sha256,sha3_256,sinx,cosx,ser,sqr,sqz,str,str0,til,typ,u0c,u1c,unh,unq,val,whr;
#define h(x,y) ,x
A2 a2,aa,aA,ap1,ap2,apd,cat,com,cst,cut,fnd,id_,idx,mtc,rsh,v0c,v1c,xpt ariths(h,);
#undef h
A3 a3,try;A0 aa0;AA amd,am1,dmd,dm1;AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCm(O C*,O C*),aCn(O C*,L),aCz(O C*),apc(A,C),apv(A,O V*),atn(C,L),atnv(C,L,O V*),catc(A,O C*,L),ea1(A1,A),err0(O C*),err1(O C*,A),err2(O C*,A,A),
 err3(O C*,A,A,A),errn(O C*,I,O A*),get(A,L),getr(A,L),gkv(A*),room(A,L),K0(O C*,I);
V init(),*mc(V*,O V*,L),mrn(I,O A*),*ms(V*,I,L),revl(L*,UL),tilh(H*,UH),tili(I*,UI),till(L*,UL);C*syp(I);
I Ci(O C*,C),epr(),eso(A,I),mtc_(A,A),strcmp(O C*,O C*),syP(O C*);
L fndi(A,I),fndl(A,L),fpa(A*,A),fpc(A*,C),fpi(A*,I),fpl(A*,L),len_(A),now(),pl(C**),pu(C**),strlen(O C*),tru(A);
XT A glb,cn[],ci[3][5];XT O C vc[];XT O V*vf[],*arf[3][11][8];XT L mu;
#define m2(x,a...) ({A t_=mr0(x);__typeof__(({a;}))r_=({a;});dbg(x=0);mr1(t_);r_;}) //two-phase free()
#define K(s,a...) ({S A f;Y(!f,f=K0(s,Z(s)))app(f,A_(a),Z(A_(a))/ZV);})
#define syC(c) (2*(c)) //symbols: char to index

S A aX(L n)_(atn(tX,n))S A pck(UL t,UI v)_(AT(t,v))S A0(a0,aX(0))
S A aC(L n)_(atn(tC,n))S A ac(C v)_(pck(tc,v))S C gc (A x)_(asrt(xtc);          (C)x)
S A aS(L n)_(atn(tS,n))S A as(I v)_(pck(ts,v))S I gs (A x)_(asrt(xts);          (I)x)
S A aI(L n)_(atn(tI,n))S A ai(I v)_(pck(ti,v))S I gi (A x)_(asrt(xti||xtc||xts);(I)x)
S A aL(L n)_(atn(tL,n))S A al(L v)_(atv(tl,v))S L gl_(A x)_(         pkd(x)?(I)x:*xl)S L gl(A x)_(L r=gl_(x);xr;r)
S A aD(L n)_(atn(tD,n))S A ad(D v)_(atv(td,v))S D gd_(A x)_(asrt(xtd);           *xd)S D gd(A x)_(D v=*xd;xr;v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:c=='~'?11:c==','?12:\
 c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S O A au0=au(0),av0=av(0),au_out=au(25),au_cmd=au(28),au_plc=au(29),av_com=av(24),av_mkl=av(25);

#define _0Ni (1<<31)
#define _0Wi (~_0Ni)
#define _0Nl (1ll<<63)
#define _0Wl (~_0Nl)
#define _0n  (D)NAN
#define _0w  (D)INFINITY

#define err_(x,y,z,u,n,...) n
#define err(a...) ({dbg(oo)err_(a,err3,err2,err1,err0)(a);})
#define eM "nyi","len","typ","dom","rnk","idx","prs","stk"
#define en(a...) err((C*)0,##a)
#define et(a...) err((C*)2,##a)
#define ed(a...) err((C*)3,##a)
#define En(x,a...) P(x,err((C*)0,##a))
#define El(x,a...) P(x,err((C*)1,##a))
#define Et(x,a...) P(x,err((C*)2,##a))
#define Ed(x,a...) P(x,err((C*)3,##a))
#define Er(x,a...) P(x,err((C*)4,##a))
#define Ei(x,a...) P(x,err((C*)5,##a))
#define Ep(x,a...) P(x,err((C*)6,##a))
#define Es(x,a...) P(x,err((C*)7,##a))
#define h(t,i) S A e##t##n(I n,O A*a)_(errn((C*)i,n,a))
h(n,0)h(l,1)h(t,2)h(d,3)h(r,4)h(i,5)h(p,6)h(s,7)
#undef h

#define ov(x) ov_(#x":",(L)(x))
#define ox(x) ox_(#x":",(A)(x))
#define oo os("["__FILE__":"XS(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(O C*x)_(write(2,x,strlen(x)))
S I oh(L x)_(C s[17];s[16]=0;F(16,s[15-i]=hx1(x&15);x>>=4)write(2,s,17))
S I ol(L x)_(C b[32],*u=b+31;L m=x<0;Y(m,x=-x)do{*u--='0'+x%10;x/=10;}while(x);Y(m,*u--='-')write(2,u+1,b+31-u))
S L ov_(C*s,L x)_(os(s);write(2,"           ",max(1,10-strlen(s)));oh((L)x);write(2,"\n",1);x)
S A ox_(C*s,A x)_(os(s);oh((L)x);P(!x,0)Y(!pkd(x),os(" b");ol(xb);os("t");ol(xt);os("r");ol(Ar(x));os("n");ol(xn))os(" ");out(x))
