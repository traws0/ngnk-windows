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
#define TD typedef
#define RE restrict
#define TY __typeof__
#define ST struct
#define SWP(x,y) {TY(x)t_=x;x=y;y=t_;}
#define ALN(x) {Q(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);}
#define PAD(n,p) ((n)+ZA/Z(*p)-1&-ZA/Z(*p))
#define M1(x) #x
#define M2(x) M1(x)
#define A(a...) (A[]){a}
#define CH(x,y,a...) (TY(y)[]){y,a}[x]
#ifdef DEBUG
 #define dbg(x) x
 #define Q(x) Y(!(x),die(__FILE__":"M2(__LINE__)": "M2(x)))
 #define die(x) {write(1,x,Z(x));exit(1);}
#else
 #define dbg(x)
 #define Q(x)
#endif

TD void V;TD char unsigned C,UC;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;TD double D;
TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(OA*,I),AX(A,OA*,I);
#define A0(f,b...) A f(          )_(b)
#define A1(f,b...) A f(Ax        )_(b)
#define A2(f,b...) A f(Ax,Ay     )_(b)
#define A3(f,b...) A f(Ax,Ay,Az  )_(b)
#define AX(f,b...) A f(Ax,OA*a,In)_(b) //doesn't consume x
#define AA(f,b...) A f(   OA*a,In)_(b)

#define extr(c,x,y) ({TY(x) x_=(x),y_=(y);x_ c y_?x_:y_;})
#define min(a...) extr(<,a)
#define max(a...) extr(>,a)
#define rot(x,y) ({TY(x) x_=(x),y_=(y);x_<<y_|x_>>Z(x)*8-y;})
S L absL(Lv)_(v<0?-v:v)S I c3(Cc,Cv,Cd)_(c<=v&&v<=d)S C hx1(Ii)_(i+(i>9?'a'-10:'0'))S I dgt(Cc)_(c3('0',c,'9'))
S I in(Li,Ln)_(0<=i&&i<n)

#define mv(a...) __builtin_memmove(a)
#define mc(a...) __builtin_memcpy(a)
#define ms(a...) __builtin_memset(a)
#define mn(a...) __builtin_strlen(a)
V*memcpy(V*,OV*,size_t),*memmove(V*,OV*,size_t),*memset(V*,I,size_t),exit(I);size_t strlen(OC*);I strcmp(OC*,OC*);

//         () "" ,h ,i ,0 ,d ,` +! ! "c" 0h 0i 0  0. `  {} 1+ ++ +/ +: +  /
enum      {tA,tC,tH,tI,tL,tD,tS,tM,tm,tc,th,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn}; //types
#define TS "A""C""H""I""L""D""S""M""m""c""h""i""l""d""s""o""p""q""r""u""v""w" //their symbols
#define TZ  8, 1, 2, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8  //size in bytes
#define Tz  4, 0, 1, 2, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3  //log2(size) or 4=reftypes
extern OC Zt[],ZT[];S C At(A);                S I sim(Ax)_(c3(tc,xt,ts)) //simple    types
S I reft(Ct)_(Zt[t]==4)                       S I ref(Ax)_(reft(xt))     //reference types
S I pkdt(Ct)_(c3(tc,t,ti)||t==ts||c3(tu,t,tw))S I pkd(Ax)_(pkdt(xt))     //packed    types
S I funt(Ct)_(t>=to)                          S I fun(Ax)_(funt(xt))     //function  types
S C tT(Ct)_(t==tm?tM:t>=to?tA:t>=tc?t+tC-tc:t) //get corresponding list type

//header bytes: b.oorrrrnnnnnnnn (b=bucket,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,i=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tA,tC,tI,tL,tD,tS,tM,tm,tl,td
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ti,th,tc
// tttttttt........ooooooooooooooooiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
#define dat(x) ((V*)((x)<<16>>16))
#define Ar(x) ((I*)dat(x))[-3]

//getters                              setters
S  C At(Ax)_(x>>56)                    S A AT(UL t,Ax)_(Q(t<=tn);               x<<8>>8|t<<56)
S  C Av(Ax)_(x>>51&31)                 S A AV(UL v,Ax)_(Q(v<32);          x&~(31ll<<51)|v<<51)
S  C Ak(Ax)_(x>>48&7)                  S A AK(UL k,Ax)_(Q(k<9);           x&~( 7ll<<48)|k<<48)
S  C Ab(Ax)_(C b=xC[-16];Q(b<48);b)    S A AB( C b,Ax)_(Q(b<48);                  xC[-16]=b;x)
S UH Ao(Ax)_(xts?x>>32:pkd(x)?0:xH[-7])S A AO(UL o,Ax)_(Xs(x&~(0xffffll<<32)|o<<32)xH[-7]=o;x)
S UL An(Ax)_(Ln=xL[-1];Q(n<1ll<<48);n) S A AN(UL n,Ax)_(Q(n<1ll<<48);              xL[-1]=n;x)
S A1(mR,Q(x);P(pkd(x),x)Q(Ar(x)>=0);Ar(x)++;x)
#define tvk(t,v,k) (A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48) //type,value,arity

A0 aa0;
A1 a1,aes0,aes1,asc,ax,blw,cmd,cpl,des,dsc,enl,enla,epr,fir,flp,flr,frk,gD,gH,gI,gL,gS,grp,hcl,hex,hop,jsr,jsw,kst,las,
 ldf,len,md5,mr,mr0,mr1,mRa,mut,neg,not,nul,out,prs,rev,sha1,sha256,sha3_256,sinx,cosx,ser,sqr,sqz,str,str0,til,typ,
 u0c,u1c,unh,unq,val,whr;
A2 a2,add,aM,am,ap1,apn,apd,cat,com,cst,cut,dex,dvd,eql,fnd,gtn,id_,idx,ltn,mnm,mod,mtc,mul,mxm,rsh,sub,v0c,v1c,xpt;
A3 a3,try;
AA amd,am1,dmd,dm1;
AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCm(OC*,OC*),aCn(OC*,L),aCz(OC*),apc(A,C),apv(A,OV*),atn(C,L),atnv(C,L,OV*),catc(A,OC*,L),ea1(A1,A),
 e0(OC*),e1(OC*,A),e2(OC*,A,A),e3(OC*,A,A,A),eN(OC*,I,OA*),get(A,L),getr(A,L),gkv(A*),room(A,L);
V init(),mrn(I,OA*),tilH(V*,L),tilI(V*,L),tilL(V*,L);
C*syp(I*);
I fC(OV*,I,OV*),fH(OV*,I,OV*),fI(OV*,I,OV*),fL(OV*,I,OV*),fAI(A,I),fpA(A*,A),fpC(A*,C),fpI(A*,I),fpL(A*,L),
 si(OC*,I),eS(A,I),mtc_(A,A),syP(OC*);
L len_(A),now(),pl(C**),pu(C**),tru(A);
extern A glb,cn[],ci[3][5];extern OC vc[];extern OV*vf[],*arf[3][11][8];extern L mu;
#define m2(x,a...) ({A t_=mr0(x);TY(({a;}))r_=({a;});dbg(x=0);mr1(t_);r_;}) //two-phase free()

#define h(T) S A a##T(Ln)_(atn(t##T,n))
 h(A)h(C)h(H)h(S)h(I)h(L)h(D)
#undef h
S A0(a0,aA(0))
S A ac(Cv)_(AT(tc,v))     S C gc (Ax)_(Q(xtc);(C)x)
S A ah(Hv)_(AT(th,v))     S H gh (Ax)_(Q(xth);(H)x)
S A as(Iv)_(AT(ts,v))     S I gs (Ax)_(Q(xts);(I)x)
S A ai(Iv)_(AT(ti,v))     S I gi (Ax)_(Q(xti||xts||xth||xtc);(I)x)
S A al(Lv)_(atnv(tl,1,&v))S L gl_(Ax)_(pkd(x)?(I)x:*xL)S L gl(Ax)_(L r=gl_(x);xr;r)
S A ad(Dv)_(atnv(td,1,&v))S D gd_(Ax)_(Q(xtd);*xD)S D gd(Ax)_(Dv=*xD;xr;v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:\
 c=='~'?11:c==','?12:c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S OA au0=au(0),av0=av(0),au_out=au(25),au_cmd=au(28),au_plc=au(29),av_com=av(24),av_mkl=av(25);

#define ND (D)NAN
#define WD (D)INFINITY
#define NL (1ll<<63)
#define WL (~NL)
#define NI (1<<31)
#define WI (~NI)
#define NH (H)(1<<15)
#define WH (~NH)

#define EN(x,y,z,u,n,...) n
#define EF(f,x,a...) P(x,f(a))
#define E_(t,a...) EF(EN(a,e##t##3,e##t##2,e##t##1,e##t##0),a)
#define EA h(c,cpl)h(d,dom)h(i,idx)h(l,len)h(n,nyi)h(o,io)h(p,prs)h(r,rnk)h(s,stk)h(t,typ)h(v,val)h(z,lmt)
#define h(t,m) A0 e##t##0;A1 e##t##1;A2 e##t##2;A3 e##t##3;S A e##t##n(In,OA*a)_(eN(#m,n,a))
 EA
#undef h
#define N_(r,a) ({A r_=(r);P(!r_,a;0)r_;}) //error pass-through
#define N(r)      N_(r,)
#define N1(x,r)   N_(r,mr(x))
#define N2(x,y,r) N_(r,mr(x);mr(y))
#define SF(x,y,s,f...) ({Li=gl(K(s"?",x));Ed(i<0,y);CH(i,&f)(y);})

#define ov(x) ov_(#x":",(L)(x))
#define ox(x) ox_(#x":",(A)(x))
#define oo os("["__FILE__":"M2(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(OC*x)_(write(2,x,mn(x)))
S I oh(Ln)_(C s[17];s[16]=0;F(16,s[15-i]=hx1(n&15);n>>=4)write(2,s,17))
S I ol(Ln)_(C b[32],*u=b+31;L m=n<0;Y(m,n=-n)do{*u--='0'+n%10;n/=10;}while(n);Y(m,*u--='-')write(2,u+1,b+31-u))
S L ov_(C*s,Ln)_(os(s);write(2,"           ",max(1,10-mn(s)));oh(n);write(2,"\n",1);n)
S A ox_(C*s,Ax)_(os(s);oh((L)x);P(!x,0)Y(!pkd(x),os(" b");ol(Ab(x));os("t");ol(xt);os("r");ol(Ar(x));os("n");ol(xn))os(" ");out(x))
