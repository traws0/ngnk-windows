// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#define DEBUG
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

TD void V;TD char B;TD char unsigned C,UC;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;
TD double D;TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(OA*,I),AX(A,OA*,I);TD size_t N;
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
S L absL(Lv)_(v<0?-v:v)S I c3(Cc,Cv,Cd)_(c<=v&&v<=d)S C hx1(Ii)_(i+(i>9?'a'-10:'0'))S I dgt(Cc)_(c3('0',c,'9'))
S I ltr(Cc)_(c3('a',c|32,'z'))S I ldg(Cc)_(ltr(c)||dgt(c))S I in(Ni,Nn)_(i<n)

#define ms(a...) __builtin_memset(a)
#define mv(a...) __builtin_memmove(a)
#define mc(a...) __builtin_memcpy(a)
#define mC(a...) __builtin_memcmp(a)
#define mn(a...) __builtin_strlen(a)
V*memcpy(V*,OV*,N),*memmove(V*,OV*,N),*memset(V*,I,N),exit(I);N strlen(OC*);I strcmp(OC*,OC*),memcmp(OV*,OV*,N);

//             1  2  3  4  5  6  7  8  9 10 11 13 14 15 16 17 18 19 20 21 22 23 24 25
//            01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18
//            () "" ,0 ,1 ,2 ,3 ,d ,` +!  ! "c" 0  1  2  3 .3  ` {} 1+ ++ +/ +: +  /
enum      {t_,tA,tC,tB,tH,tI,tL,tD,tS,tM,tm,tc,tb,th,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn}; //types
#define TS "0""A""C""B""H""I""L""D""S""M""m""c""b""h""i""l""d""s""o""p""q""r""u""v""w" //their symbols
#define TZ  0, 8, 1, 1, 2, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8  //size in bytes
#define Tz  0, 4, 0, 0, 1, 2, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3  //log2(size) or 4=reftypes
EX OC Zt[],ZT[];S C At(A);S I _t(Ct)_(t>tm)S I _T(Ct)_(t<tM)S I _z(Ct)_(c3(tb,t,tl))S I _Z(Ct)_(c3(tB,t,tL))
S I _F(Ct)_(t>=to)S I _P(Ct)_(c3(tc,t,ti)||t==ts||c3(tu,t,tw))S I _R(Ct)_(Zt[t]==4)
S C tT(Ct)_(t==tm?tM:t>=to?tA:t>=tc?t+tC-tc:t) //tT():get corresponding list type

//header bytes: btoorrrrnnnnnnnn (b=bucket,t=type,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,i=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tA,tC,tB,tH,tI,tL,tD,tS,tM,tm,tl,td
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii tc,tb,th,ti
// tttttttt........ooooooooooooooooiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
#define dat(x) ((V*)((x)<<16>>16))
#define rfc(x) ((I*)dat(x))[-3]
#define bkt(x) ((C*)dat(x))[-16]
#define cap(x) ((ZA<<bkt(x))-ZA)
#define _q(x,y) (x=apd(x,y))
A die(OC*);

//getters                           setters
S  C At(Ax)_(Ct=x>>56;t?t:xC[-15])  S A AT(UL t,Ax)_(Q(c3(0,t,tn));P(_P(t),x=x<<8>>8|t<<56)xC[-15]=t;x)
S  C Av(Ax)_(x>>51&31)              S A AV(UL v,Ax)_(Q(v<32);          x&~(31ll<<51)|v<<51)
S  C Ak(Ax)_(x>>48&7)               S A AK(UL k,Ax)_(Q(k<9);           x&~( 7ll<<48)|k<<48)
S UH Ao(Ax)_(xts?x>>32:xtP?0:xH[-7])S A AO(UL o,Ax)_(Xs(x&~(0xffffll<<32)|o<<32)xH[-7]=o;x)
S  N An(Ax)_(xL[-1])                S A AN(  Nn,Ax)_(Q(n<1ll<<48||n==-1);       xL[-1]=n;x)
S A1(mR,Q(x);XP(x)Q(xr>=0);xr++;x)
#define tvk(t,v,k) (A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48) //type,value,arity

A0 aa0;
A1 a1,aes0,aes1,asc,ax,blw,cf,cls,cmd,cmdl,cmdm,cpl,des,dsc,enl,enla,epr,fir,flp,flr,frk,gB,gD,gH,gI,gL,gS,grp,
 hex,jsr,jsw,kst,las,len,md5,mr,m0,m1,mRa,mut,neg,not,nul,opn,out,prs,rev,sam,sha1,sha256,sha3_256,sin,ser,sqr,sqz,
 str,str0,til,typ,u0c,u1c,unh,unq,val,whr;
A2 a2,add,aM,am,ap1,apn,apd,cat,com,cst,cut,dex,dvd,eql,fil,fnd,gtn,id_,idx,join,ltn,mnm,mod,mtc,mul,mxm,rsh,sub,v0c,v1c,xpt;
A3 a3,try;
AA amd,am1,dmd,dm1;
AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCm(OC*,OC*),aCn(OC*,N),aCz(OC*),apc(A,C),apv(A,OV*),atn(C,N),atnv(C,N,OV*),az(L),catc(A,OC*,N),ea1(A1,A),
 e0(OC*),e1(OC*,A),e2(OC*,A,A),eN(OC*,I,OA*),get(A,N),getr(A,N),kv(A*),mf(I,N),room(A,N),wdn(A,N,N,N);
V init(I,C**),mrn(I,OA*),repl();
C*sl(C*,L),*syp(I*),tZ(L);
I asg(Ax),si(OC*,I),eS(A,I),mtc_(A,A),sup(A*,A*),syP(OC*);
L _N(A),now(),pl(C**),pu(C**),tru(A),fL(OV*,N,L),fAI(A,I),fpA(A*,A),fpB(A*,B),fpH(A*,H),fpI(A*,I),fpL(A*,L);
TD V(*Fc)(OV*RE,V*RE,N);EX Fc wf[];EX A glb,cns,ce[],cn[],ci[2][5];EX OC vc[];EX L mU;EX A1*ct[];EX C**argv,**env;
EX OV*vf[],*arr[][11],*ars[][11],*arp[][11],*ara[][11];
#define m2(x,a...) ({A t_=m0(x);TY(({a;}))r_=({a;});dbg(x=0);m1(t_);r_;}) //two-phase free()

#define h(T) S A a##T(Nn)_(atn(t##T,n))
 h(A)h(C)h(B)h(H)h(I)h(L)h(D)h(S) //aA aC aB aH aI aL aD aS
#undef h
#define h(T,tt) S A a##tt(T v)_(AT(t##tt,(I)v))
 h(C,c)h(B,b)h(H,h)h(I,i)h(I,s) //ac ab ah ai as
#undef h
S A al(Lv)_(atnv(tl,1,&v))S A ad(Dv)_(atnv(td,1,&v))S I gi (Ax)_(Q(c3(tc,xt,ti)||xts);x)
S L gl_(Ax)_(Xb((B)x)Xh((H)x)XP((I)x)*xL)S L gl(Ax)_(Lv=gl_(x);x(0);v)S D gd_(Ax)_(Q(xtd);*xD)S D gd(Ax)_(Dv=*xD;x(0);v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:\
 c=='~'?11:c==','?12:c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S OA au0=au(0),av0=av(0),OUT=au(25),CMD=au(28),PLH=au(29),PRG=au(30),COM=av(24),MKL=av(25);

#define ND (D)(0./0.)
#define WD __builtin_inf()
#define NL (1ll<<63)
#define WL (~NL)

#define iut(t,v...) ({i(un,u##t=({v;}))u;})
#define iua(v...) iut(a,v)
#define iuc(v...) iut(c,v)
#define iuh(v...) iut(h,v)
#define iui(v...) iut(i,v)
#define iul(v...) iut(l,v)
#define iud(v...) iut(d,v)

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
#define SF(x,y,s,f...) ({Li=gl(K(s"?",x));Ed(i<0,y);CH(i,&f)(y);})

#define ov(x) ov_(#x":",(L)(x))
#define oo os("["__FILE__":"M2(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(OC*x)_(write(2,x,mn(x)))
S I oh(Ln)_(C s[17];s[16]=0;i(16,s[15-i]=hx1(n&15);n>>=4)write(2,s,17))
S L ov_(C*s,Nn)_(os(s);write(2,"           ",max(1,10-mn(s)));oh(n);write(2,"\n",1);n)
