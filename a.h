// ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
//#define DEBUG
#include<unistd.h>
#include<math.h>
#include"k.h"
#include"g.h"
#define      _(a...) {return({a;});}
#define    W(x,a...) while(x){a;}
#define    Y(x,a...) if(x){a;}
#define    P(x,a...) Y(x,_(a))
#define     EY(a...) else Y(a)
#define      E(a...) else{a;}
#define      F(a...) F_(i,a)
#define     Fj(a...) F_(j,a)
#define F_(i,n,a...) for(TY(n)n_=(n),i=0;i<n_;i++){a;}
#define B break
#define O const
#define S static
#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZP 4096ll //page
#define ZA 32     //hdr
#define NO __attribute__((noinline))
#define SN S NO
#define XT extern
#define TD typedef
#define RE restrict
#define TY __typeof__
#define SWP(x,y) {TY(x)t_=x;x=y;y=t_;}
#define ALN(x) {asrt(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);}
#define PAD(n,p) ((n)+ZA/Z(*p)-1&-ZA/Z(*p))
#define MS(x) #x
#define XS(x) MS(x)
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

TD void V;TD char unsigned C,UC;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;TD double D;
TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(O A*,I),AX(A,O A*,I);
#define A0(f,b...) A f(             )_(b)
#define A1(f,b...) A f(A x          )_(b)
#define A2(f,b...) A f(A x,A y      )_(b)
#define A3(f,b...) A f(A x,A y,A z  )_(b)
#define AX(f,b...) A f(A x,O A*a,I n)_(b) //doesn't consume x
#define AA(f,b...) A f(    O A*a,I n)_(b)

#define extr(x,y,c) ({TY(x) x_=(x),y_=(y);x_ c y_?x_:y_;})
#define min(x,y) extr(x,y,<)
#define max(x,y) extr(x,y,>)
#define rot(x,y) ({TY(x) x_=(x),y_=(y);x_<<y_|x_>>Z(x)*8-y;})
S L absL(L x)_(x<0?-x:x)S I c3(C x,C y,C z)_(x<=y&&y<=z)S C hx1(I x)_(x+(x>9?'a'-10:'0'))S I dgt(C c)_(c3('0',c,'9'))S I in(L i,L n)_(0<=i&&i<n)

#define mv(a...) __builtin_memmove(a)
#define mc(a...) __builtin_memcpy(a)
#define ms(a...) __builtin_memset(a)
#define mn(a...) __builtin_strlen(a)
V*memcpy(V*,O V*,size_t),*memmove(V*,O V*,size_t),*memset(V*,I,size_t),exit(I);size_t strlen(O C*);I strcmp(O C*,O C*);

XT O C Zt[],ZT[]; //type widths

//         () "" ,h ,i ,0 ,d ,` +! ! "c" 0h 0i 0  0. `  {} 1+ ++ +/ +: +  /
enum      {tA,tC,tH,tI,tL,tD,tS,tM,tm,tc,th,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn}; //types
#define TS "A""C""H""I""L""D""S""M""m""c""h""i""l""d""s""o""p""q""r""u""v""w" //their symbols
#define TZ  8, 1, 2, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8  //size in bytes
#define Tz  4, 0, 1, 2, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3  //log2(size) or 4=reftypes
S C At(A);                                                     S I sim(A x)_(tm<xt&&xt<to) //simple    types
S I reft(C t)_(t==tA||t==tm||t==tM||t==to||t==tp||t==tq||t==tr)S I ref(A x)_(reft(xt))     //reference types
S I pkdt(C t)_(t==tc||t==ti||t==ts||t==tu||t==tv||t==tw)       S I pkd(A x)_(pkdt(xt))     //packed    types
S I funt(C t)_(t>=to)                                          S I fun(A x)_(funt(xt))     //function  types
S C t_lst(C t)_(t==tm?tM:t>=to?tA:t>=tc?t+tC-tc:t) //corresponding list type

//header bytes: b.oorrrrnnnnnnnn (b=bucket,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,i=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tA,tC,tI,tL,tD,tS,tM,tm,tl,td
// tttttttt................................................iiiiiiii tc
// tttttttt........................................iiiiiiiiiiiiiiii th
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ti
// tttttttt........ooooooooooooooooiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
#define dat(x) ((V*)((x)<<16>>16))
#define Ar(x) ((I*)dat(x))[-3]

//getters                                   setters
S  C At(A x)_(x>>56)                        S A AT(UL t,A x)_(asrt(t<=tn);               x<<8>>8|t<<56)
S  C Av(A x)_(x>>51&31)                     S A AV(UL v,A x)_(asrt(v<32);          x&~(31ll<<51)|v<<51)
S  C Ak(A x)_(x>>48&7)                      S A AK(UL k,A x)_(asrt(k<9);           x&~( 7ll<<48)|k<<48)
S  C Ab(A x)_(C b=xc[-16];asrt(b<48);b)     S A AB( C b,A x)_(asrt(b<48);                  xc[-16]=b;x)
S UH Ao(A x)_(xts?x>>32:pkd(x)?0:xh[-7])    S A AO(UL o,A x)_(P(xts,x&~(0xffffll<<32)|o<<32)xh[-7]=o;x)
S UL An(A x)_(UL n=xl[-1];asrt(n<1ll<<48);n)S A AN(UL n,A x)_(asrt(n<1ll<<48);              xl[-1]=n;x)
S A1(mR,asrt(x);P(pkd(x),x)asrt(Ar(x)>=0);Ar(x)++;x)
#define tvk(t,v,k) (A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48) //type,value,arity

A1 a1,aes0,aes1,asc,ax,blw,cmd,cpl,des,dsc,enl,enla,epr,fir,flp,flr,frk,gD,gI,gL,gS,grp,hcl,hex,hop,jsr,jsw,kst,las,ldf,len,md5,mr,mr0,mr1,mRa,mut,
 neg,not,nul,out,prs,rev,sha1,sha256,sha3_256,sinx,cosx,ser,sqr,sqz,str,str0,til,typ,u0c,u1c,unh,unq,val,whr;
A2 a2,add,aM,am,ap1,apn,apd,cat,com,cst,cut,dex,dvd,eql,fnd,gtn,id_,idx,ltn,mnm,mod,mtc,mul,mxm,rsh,sub,v0c,v1c,xpt;
A3 a3,try;A0 aa0;AA amd,am1,dmd,dm1;AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCm(O C*,O C*),aCn(O C*,L),aCz(O C*),apc(A,C),apv(A,O V*),atn(C,L),atnv(C,L,O V*),catc(A,O C*,L),ea1(A1,A),e0(O C*),e1(O C*,A),e2(O C*,A,A),
 e3(O C*,A,A,A),eN(O C*,I,O A*),get(A,L),getr(A,L),gkv(A*),room(A,L);
V init(),mrn(I,O A*),tilH(H*,UH),tilI(I*,UI),tilL(L*,UL);C*syp(I);
I Ci(O C*,I),eso(A,I),mtc_(A,A),syP(O C*);
L fndI(A,I),fndL(A,L),fpA(A*,A),fpC(A*,C),fpI(A*,I),fpL(A*,L),len_(A),now(),pl(C**),pu(C**),tru(A);
XT A glb,cn[],ci[3][5];XT O C vc[];XT O V*vf[],*arf[3][11][8];XT L mu;
#define m2(x,a...) ({A t_=mr0(x);TY(({a;}))r_=({a;});dbg(x=0);mr1(t_);r_;}) //two-phase free()
#define syC(c) (2*(c)) //symbols: char to index

S A aA(L n)_(atn(tA,n))S A0(a0,aA(0))
S A aC(L n)_(atn(tC,n))S A ac(C v)_(AT(tc,v))     S C gc (A x)_(asrt(xtc);     (C)x)
S A aS(L n)_(atn(tS,n))S A as(I v)_(AT(ts,v))     S I gs (A x)_(asrt(xts);     (I)x)
S A aI(L n)_(atn(tI,n))S A ai(I v)_(AT(ti,v))     S I gi (A x)_(asrt(xti||xts);(I)x)
S A aL(L n)_(atn(tL,n))S A al(L v)_(atnv(tl,1,&v))S L gl_(A x)_(    pkd(x)?(I)x:*xl)S L gl(A x)_(L r=gl_(x);xr;r)
S A aD(L n)_(atn(tD,n))S A ad(D v)_(atnv(td,1,&v))S D gd_(A x)_(asrt(xtd);      *xd)S D gd(A x)_(D v=*xd;xr;v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:c=='~'?11:c==','?12:\
 c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S O A au0=au(0),av0=av(0),au_out=au(25),au_cmd=au(28),au_plc=au(29),av_com=av(24),av_mkl=av(25);

#define ND (D)NAN
#define WD (D)INFINITY
#define NL (1ll<<63)
#define WL (~NL)
#define NI (1<<31)
#define WI (~NI)

#define err(a...) ({dbg(oo)eH(a,e3,e2,e1,e0)(a);})
#define eH(x,y,z,u,n,...) n
#define eM "nyi","len","typ","dom","rnk","idx","prs","stk"
#define en(x,a...) P(x,err((C*)0,##a))
#define el(x,a...) P(x,err((C*)1,##a))
#define et(x,a...) P(x,err((C*)2,##a))
#define ed(x,a...) P(x,err((C*)3,##a))
#define er(x,a...) P(x,err((C*)4,##a))
#define ei(x,a...) P(x,err((C*)5,##a))
#define ep(x,a...) P(x,err((C*)6,##a))
#define es(x,a...) P(x,err((C*)7,##a))
#define h(t,i) S A e##t##n(I n,O A*a)_(eN((C*)i,n,a))
h(n,0)h(l,1)h(t,2)h(d,3)h(r,4)h(i,5)h(p,6)h(s,7)
#undef h
#define N_(r,a) ({A r_=(r);P(!r_,a;0)r_;}) //error pass-through
#define N(r)      N_(r,)
#define N1(x,r)   N_(r,mr(x))
#define N2(x,y,r) N_(r,mr(x);mr(y))

#define ov(x) ov_(#x":",(L)(x))
#define ox(x) ox_(#x":",(A)(x))
#define oo os("["__FILE__":"XS(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(O C*x)_(write(2,x,mn(x)))
S I oh(L x)_(C s[17];s[16]=0;F(16,s[15-i]=hx1(x&15);x>>=4)write(2,s,17))
S I ol(L x)_(C b[32],*u=b+31;L m=x<0;Y(m,x=-x)do{*u--='0'+x%10;x/=10;}while(x);Y(m,*u--='-')write(2,u+1,b+31-u))
S L ov_(C*s,L x)_(os(s);write(2,"           ",max(1,10-mn(s)));oh((L)x);write(2,"\n",1);x)
S A ox_(C*s,A x)_(os(s);oh((L)x);P(!x,0)Y(!pkd(x),os(" b");ol(xb);os("t");ol(xt);os("r");ol(Ar(x));os("n");ol(xn))os(" ");out(x))
