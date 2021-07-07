// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
//#define DEBUG
#include<unistd.h>
#include"k.h"
#include"g.h"
#define   _(a...) {return({a;});}
#define W(x,a...) while(x){a;}
#define Y(x,a...) if(x){a;}
#define P(x,a...) Y(x,_(a))
#define  EY(a...) else Y(a)
#define   E(a...) else{a;}
#define   i(a...) F_(i,a)
#define   j(a...) F_(j,a)
#define F_(i,n,a...) for(TY(n)n_=(n),i=0;i<n_;i++){a;}
#define BR break
#define O const
#define S static
#define Z sizeof
#define ZZ(x) (Z(x)/Z((x)[0]))
#define ZP 4096ll //page
#define ZA 32ll   //hdr
#define NO __attribute__((noinline))
#define SN S NO
#define TD typedef
#define TY __typeof__
#define ST struct
#define RE restrict
#define SWP(x,y) {TY(x)t_=x;x=y;y=t_;}
#define AL(x) {Q(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);}
#define PD(n,p) ((n)+ZA/Z(*p)-1&-ZA/Z(*p)) //pad
#define M1(x) #x
#define M2(x) M1(x)
#define A(a...) (A[]){a}
#define CH(x,y,a...) (TY(y)[]){y,a}[x] //choose
#define EX extern
#ifdef DEBUG
 #define dbg(x) x
 #define Q(x) Y(!(x),die(__FILE__":"M2(__LINE__)": "M2(x)"\n")) //assert
#else
 #define dbg(x)
 #define Q(x)
#endif

TD void V;TD char B;TD char unsigned C,UC;TD O C*Q;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;
TD long long L;TD double D;TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(OA*,I),AX(A,OA*,I);TD size_t N;
#define A0(f,b...) A f(          )_(b)
#define A1(f,b...) A f(Ax        )_(b)
#define A2(f,b...) A f(Ax,Ay     )_(b)
#define A3(f,b...) A f(Ax,Ay,Az  )_(b)
#define AX(f,b...) A f(Ax,OA*a,In)_(b) //doesn't consume x
#define AA(f,b...) A f(   OA*a,In)_(b)

#define extr(c,x,y) ({TY(x) x_=(x),y_=(y);x_ c y_?x_:y_;})
#define min(a...) extr(<,a)
#define max(a...) extr(>,a)
#define rot(x,y) ({TY(x) x_=(x);TY(y) y_=(y);y?x_<<y_|x_>>Z(x)*8-y_:x;})
S L absL(Lv)_(v<0?-v:v)S C hx1(Ii)_(i+(i>9?'a'-10:'0'))S I in(Li,Ln)_(0<=i&&i<n)S I c3(Cc,Cv,Cd)_(c<=v&&v<=d)
S I c09(Cc)_(c3('0',c,'9'))S I caf(Cc)_(c3('a',c,'f'))S I cAz(Cc)_(c3('a',c|32,'z'))S I cA9(Cc)_(cAz(c)||c09(c))
S I cAZ(Cc)_(c3('A',c,'Z'))S I cAF(Cc)_(c3('A',c,'F'))S I cAf(Cc)_(c3('a',c|32,'f'))

#define ms(a...) __builtin_memset(a)
#define mv(a...) __builtin_memmove(a)
#define mc(a...) __builtin_memcpy(a)
#define mC(a...) __builtin_memcmp(a)
#define Mc(a...) __builtin_memchr(a)
#define sn(a...) __builtin_strlen(a)
#define sc(a...) __builtin_strchr(a)
#define ss(a...) __builtin_strstr(a)
#define sC(a...) __builtin_strcmp(a)
#define MM(a...)  memmem(a)
#define sc0(a...) strchrnul(a)
C*strchr(Q,I),*strchrnul(Q,I),*strstr(Q,Q);I memcmp(OV*,OV*,N),strcmp(Q,Q),exit(I);N strlen(Q);
V*memCPY(V*,OV*,N),*memchr(Q,I,N),*memcpy(V*,OV*,N),*memmem(OV*,N,OV*,N),*memmove(V*,OV*,N),*memset(V*,I,N);

//             1  2  3  4  5  6  7  8  9 10 11       15 16 17 18 19 20 21 22 23 24 25 26
//            01 02 03 04 05 06 07 08 09 0a 0b       0e 0f 10 11 12 13 14 15 16 17 18 19
//            () "" ,0 ,1 ,2 ,3 ,d ,` +!  ! "c"       2  3 .3  ` {} 1+ ++ +/ +: +  /  f
enum      {t9,tA,tC,tB,tH,tI,tL,tD,tS,tM,tm,tc,t8,t7,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,te,tn}; //types
#define TS "0""A""C""B""H""I""L""D""S""M""m""c""b""h""i""l""d""s""o""p""q""r""u""v""w""e" //their symbols
#define TZ  0, 8, 1, 1, 2, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8  //size in bytes
#define Tz  0, 4, 0, 0, 1, 2, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3  //log2(size) or 4=reftypes
EX OC Zt[],ZT[];S C _t(A);S I _tt(Ct)_(t>tm)S I _tT(Ct)_(t<tM)S I _tz(Ct)_(c3(ti,t,tl))S I _tZ(Ct)_(c3(tB,t,tL))
S I _tF(Ct)_(t>=to)S I _tP(Ct)_(c3(tc,t,ti)||t==ts||c3(tu,t,te))S I _tR(Ct)_(Zt[t]==4)
S C tT(Ct)_(t==tm?tM:t>=to?tA:t>=tc?t+tC-tc:t) //tT():get corresponding list type

//header bytes: btoorrrrnnnnnnnn (b=bucket,t=type,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,i=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tA,tC,tB,tH,tI,tL,tD,tS,tM,tm,tl,td
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii tc,ti
// tttttttt........ooooooooooooooooiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
#define dat(x) ((V*)((x)<<16>>16))
#define rfc(x) ((I*)dat(x))[-3]
#define _q(x,y) (x=apd(x,y))
A0 aa0;
A1 a1,aes0,aes1,asc,ax,blw,cf,cls,cpl,des,dsc,enl,enla,epr,fir,flp,flr,frk,gB,gC,gD,gH,gI,gL,gS,grp,
 hex,js0,js1,kst,las,len,md5,mr,m0,m1,mRa,mut,neg,not,nul,opn,out,prs,rev,sam,sha1,sha256,sha3_256,sin,ser,sqr,sqz,
 str,str0,til,typ,u0c,u1c,unh,unq,val,whr;
A2 a2,add,aM,am,ap1,apn,apd,bin,cat,com,cst,cut,dex,dvd,eql,fil,fnd,gtn,id_,idx,ltn,mnm,mod,mtc,mul,mxm,que,rsh,
 sub,v0c,v1c,xpt;
A3 a3,try;
AA amd,am1,dmd,dm1;
AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCl(Q),aCm(Q,Q),aCn(Q,N),aCz(Q),apc(A,C),apv(A,OV*),atn(C,N),atnv(C,N,OV*),az(L),cts(A,Q,N),cmdl(Q),cmdm(Q),die(Q),
 eac1(A1,A),eac2(A,A,A),e0(Q),e1(Q,A),e2(Q,A,A),eN(Q,I,OA*),evs(Q,Q),get(A,L),getr(A,L),jc(C,A),jC(Q,N,A),
 kv(A*),mf(I,N),room(A,N),splc(C,A),sur(C,A,C),wdn(A,N,N,N),K0(Q,I);
V mrn(I,OA*),repl();
C*sl(C*,L),sup(A*,A*),*syp(L*),tZ(L);
I asg(Ax),cD(D,D),si(Q,I),eS(A,I),mtc_(A,A),syP(Q);
L _N(A),now(),pl(Q*),pu(Q*),tru(A),fL(OV*,N,L),fAI(A,I),fpA(A*,A),fpB(A*,B),fpH(A*,H),fpI(A*,I),fpL(A*,L);
EX A glb,cns,ce[],cn[],ci[2][5];EX OC vc[];EX A1*ct[];EX Q*argv,*env;
EX OV*vf[],*arr[][11],*ars[][11],*arp[][11],*ara[][11];
#define _2(x,a...) ({A t_=m0(x);TY(({a;}))r_=({a;});dbg(x=0);m1(t_);r_;}) //two-phase free()

//getters                           setters
S  C _t(Ax)_(Ct=x>>56;t?t:xC[-15])  S A AT(UL t,Ax)_(Q(c3(0,t,tn));P(_tP(t),x=x<<8>>8|t<<56)xC[-15]=t;x)
S  C _v(Ax)_(x>>51&31)              S A AV(UL v,Ax)_(Q(v<32);          x&~(31ll<<51)|v<<51)
S  C _k(Ax)_(x>>48&7)               S A AK(UL k,Ax)_(Q(k<9);           x&~( 7ll<<48)|k<<48)
S UH _o(Ax)_(xts?x>>32:xtP?0:xH[-7])S A AO(UL o,Ax)_(Xs(x&~(0xffffll<<32)|o<<32)xH[-7]=o;x)
S  N _n(Ax)_(xL[-1])                S A AN(  Nn,Ax)_(Q(n<1ll<<48||n==-1);       xL[-1]=n;x)
S A1(mR,Q(x);XP(x)Q(xr>=0);xr++;x)
#define tvk(t,v,k) (A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48) //type,value,arity

#define h(T) S A a##T(Nn)_(atn(t##T,n))
 h(A)h(C)h(B)h(H)h(I)h(L)h(D)h(S) //aA aC aB aH aI aL aD aS
#undef h
#define h(T,tt) S A a##tt(T v)_(AT(t##tt,(I)v))
 h(C,c)h(I,i)h(I,s) //ac ai as
#undef h
S A al(Lv)_(atnv(tl,1,&v))S A ad(Dv)_(atnv(td,1,&v))S I gi (Ax)_(Q(c3(tc,xt,ti)||xts);x)
S L gl_(Ax)_(XP((I)x)*xL)S L gl(Ax)_(Lv=gl_(x);x(0);v)S D gd_(Ax)_(Q(xtd);*xD)S D gd(Ax)_(Dv=*xD;x(0);v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:\
 c=='~'?11:c==','?12:c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S OA au0=au(0),av0=av(0),OUT=au(25),PLH=au(29),PRG=au(30),COM=av(24),MKL=av(25);

#define ND (D)(0./0.)
#define WD __builtin_inf()
#define NL (1ll<<63)
#define WL (~NL)

#define EN(x,y,z,n,...) n
#define EF(f,x,a...) P(x,f(a))
#define E_(t,a...) EF(EN(a,e##t##2,e##t##1,e##t##0),a)
#define EA h(c,cpl)h(d,dom)h(i,idx)h(l,len)h(n,nyi)h(o,io)h(p,prs)h(r,rnk)h(s,stk)h(t,typ)h(v,val)h(z,lmt)
#define h(t,m) A0 e##t##0;A1 e##t##1;A2 e##t##2;S A e##t##n(In,OA*a)_(eN(#m,n,a))
 EA
#undef h
#define N_(r,a) ({A r_=(r);P(!r_,a;0)r_;}) //error pass-through
#define N(r)      N_(r,)
#define N1(x,r)   N_(r,x(0))
#define N2(x,y,r) N_(r,x(y(0)))
#define Ss(a...) S O C s[][4]={a};
#define Sf(x,y,s,f...) ({Iv=gi(x);i(Z(s)/4,P(((I*)(V*)s)[i]==v,CH(i,&f)(y)));ed1(y);})
#define K(s,a...) ({static A f;if(!f)f=K0(s,sizeof s);sizeof(A[]){a}?app(f,(A[]){a},sizeof((A[]){a})/sizeof(A)):f;})

#define ov(x) ov_(#x":",(L)(x))
#define oo os("["__FILE__":"M2(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(Qs)_(write(2,s,sn(s)))
S I oh(Ln)_(C s[17];s[16]=0;i(16,s[15-i]=hx1(n&15);n>>=4)write(2,s,17))
S L ov_(Qs,Nn)_(os(s);write(2,"           ",max(1,10-sn(s)));oh(n);write(2,"\n",1);n)
