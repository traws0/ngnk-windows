#define dbg(x...) //x

#define B break
#define $(x,y...) if(x){y;}
#define E(x...) else{x;}
#define E$(x,y...) else if(x){y;}
#define N __attribute__((noinline))
#define O const
#define Q(x,a...)  case x:{a;B;}
#define Q2(x,a...) case x:Q(a)
#define Q3(x,a...) case x:Q2(a)
#define Q4(x,a...) case x:Q3(a)
#define Q5(x,a...) case x:Q4(a)
#define R return
#define S static
#define SI S inline
#define W(x,y...) while(x){y;}
#define DW(x,y) do{x;}while(y);
#define Y(x,y,z...) switch(x){default:{y;break;}z}
#define TD typedef
TD char      C;TD unsigned char      UC;
TD short     H;TD unsigned short     UH;
TD int       I;TD unsigned int       UI;
TD long long L;TD unsigned long long UL;
TD void V;TD double D;
TD V*A __attribute__((align_value(16)));

#define A(x) ((A*)(x))
#define C(x) ((C*)(x))
#define L(x) ((L*)(x))
#define D(x) ((D*)(x))

#define fi(n,b...) for(L n_=(n),i=0;i<n_;i++){b;}
#define fj(n,b...) for(L n_=(n),j=0;j<n_;j++){b;}
#define min(x,y)   ({typeof(x)x_=(x),y_=(y);x_<y_?x_:y_;})
#define max(x,y)   ({typeof(x)x_=(x),y_=(y);x_>y_?x_:y_;})
#define abs(x)     ({typeof(x)x_=(x);x_<0?-x_:x_;})

#include<sys/syscall.h>
#define sc(f,regs...)      ({L r;asm volatile("syscall":"=a"(r):"0"(SYS_##f)regs:"cc","rcx","r11","memory");r;})
#define sc0(f      )       sc(f                      )
#define sc1(f,x    )       sc(f,,"D"(x)              )
#define sc2(f,x,y  )       sc(f,,"D"(x),"S"(y)       )
#define sc3(f,x,y,z)       sc(f,,"D"(x),"S"(y),"d"(z))
#define read(a...)         sc3(read  ,a)
#define write(a...)        sc3(write ,a)
#define open(a...)         sc3(open  ,a)
#define close(a...)        sc1(close ,a)
#define fstat(a...)        sc2(fstat ,a)
#define dup2(a...)         sc2(dup2  ,a)
#define execve(a...)       sc3(execve,a)
#define pipe2(a...)        sc2(pipe2 ,a)
#define fork()             sc0(fork)
#define munmap(a...)       sc2(munmap,a)
#define exit(a...)         sc1(exit  ,a)
#define gettimeofday(a...) sc2(gettimeofday,a)
#define mmap_(x,y,z,t,u,v) ({register L r10 asm("r10")=t,r8 asm("r8")=u,r9 asm("r9")=v;\
                             (V*)sc(mmap,,"D"(x),"S"(y),"d"(z),"r"(r10),"r"(r8),"r"(r9));})

//types
#define tc  1 // "ab"
#define tl  2 // 0 1
#define ts  3 // `a`b
#define td  4 // 0.1 2.3
#define th  5 // `a`b!0 1
#define tg  6 // +`a`b!0 1
#define tf  7 // {}
#define tp  8 // f[0;]
#define tq  9 // +:+
#define tr 10 // +/
#define tu 11 // +:
#define tv 12 // +
#define tw 13 // /
#define te 14 // `lib 2:(`f;1)
#define tn 15
#define tC (-tc) // "a"
#define tL (-tl) // 0
#define tS (-ts) // `a
#define tD (-td) // 0.1
SI I isRefType(C t){R 1&((1|1<<th|1<<tg|1<<tf|1<<tp|1<<tq|1<<tr)>>t);}

TD struct{C b,t;UH o;I r;L n;}Hdr; //bucket,type,offset(or verb rank),refcount,length
TD struct{A s,b,l,g,c,m;}*Fn; //source,bytecode,locals,globals,constants,map
#define btor(b,t,o,r) ((UC)(b)|(UC)(t)<<8|(UI)(o)<<16|(UL)(r)<<32) //build 1st word of Hdr (bucket,type,offset,refcount)
#define btr(b,t,r) btor(b,t,0,r)

#define Ab(x) ((Hdr*)(x))[-1].b
#define At(x) ((Hdr*)(x))[-1].t
#define Ar(x) ((Hdr*)(x))[-1].r
#define An(x) ((Hdr*)(x))[-1].n
#define Ao(x) ((Hdr*)(x))[-1].o

//`0:,/{"#define ",x,y," A",y,"(",x,")"}/:\:/("xyzu";"btrn")
#define xb Ab(x)
#define xt At(x)
#define xr Ar(x)
#define xn An(x)
#define yb Ab(y)
#define yt At(y)
#define yr Ar(y)
#define yn An(y)
#define zb Ab(z)
#define zt At(z)
#define zr Ar(z)
#define zn An(z)
#define ub Ab(u)
#define ut At(u)
#define ur Ar(u)
#define un An(u)

//`0:,/{"#define ",x,(_y)," ",y,"(",x,")"}/:\:/("xyzu";"CLDA")
#define xc C(x)
#define xl L(x)
#define xd D(x)
#define xa A(x)
#define yc C(y)
#define yl L(y)
#define yd D(y)
#define ya A(y)
#define zc C(z)
#define zl L(z)
#define zd D(z)
#define za A(z)
#define uc C(u)
#define ul L(u)
#define ud D(u)
#define ua A(u)

//`0:"#define ",/:+b,/" ",(0 2_b:a@'!#:'a:("xyzu";"clda";"ij")),'"[]"
#define xci xc[i]
#define xcj xc[j]
#define xli xl[i]
#define xlj xl[j]
#define xdi xd[i]
#define xdj xd[j]
#define xai xa[i]
#define xaj xa[j]
#define yci yc[i]
#define ycj yc[j]
#define yli yl[i]
#define ylj yl[j]
#define ydi yd[i]
#define ydj yd[j]
#define yai ya[i]
#define yaj ya[j]
#define zci zc[i]
#define zcj zc[j]
#define zli zl[i]
#define zlj zl[j]
#define zdi zd[i]
#define zdj zd[j]
#define zai za[i]
#define zaj za[j]
#define uci uc[i]
#define ucj uc[j]
#define uli ul[i]
#define ulj ul[j]
#define udi ud[i]
#define udj ud[j]
#define uai ua[i]
#define uaj ua[j]

//`0:{"#define ","xyzu"[x]," ","xyzu"[*x],"a[",($x[1]),"]"}'+!4 2;
#define xx xa[0]
#define xy xa[1]
#define yx ya[0]
#define yy ya[1]
#define zx za[0]
#define zy za[1]
#define ux ua[0]
#define uy ua[1]

#define pagesize 4096LL
#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZV Z(V*)
#define ZC Z(C)
#define ZL Z(L)
#define ZD Z(D)
#define ZHdr Z(Hdr)
#define tz(t) tz_[td+(t)] //type size in bytes
extern O C tz_[];

#define W1 0 //1-byte data types
#define W8 1 //8-byte data types
#define W0 2 //ref types
#define h(t,w) ((L)w<<(((31&(t))<<1)))|
S O L tW_=h(tD,W8)h(tS,W8)h(tL,W8)h(tC,W1)h(0,W0)h(tc,W1)h(tl,W8)h(ts,W8)h(td,W8)
          h(th,W0)h(tg,W0)h(tf,W0)h(tp,W0)h(tq,W0)h(tr,W0)h(tu,W8)h(tv,W8)h(tw,W8)h(te,W8)0;
#undef h
SI C tW(C t){R 3&tW_>>(63&((t)<<1));} //type size as one of W1 W8 W0

#define mstr(x) #x
#define xstr(x) mstr(x)
#define en e("nyi"dbg(":"__FILE__":"xstr(__LINE__)))
#define el e("len"dbg(":"__FILE__":"xstr(__LINE__)))
#define et e("typ"dbg(":"__FILE__":"xstr(__LINE__)))
#define ed e("dom"dbg(":"__FILE__":"xstr(__LINE__)))
#define er e("rnk"dbg(":"__FILE__":"xstr(__LINE__)))
#define ef e("fnc"dbg(":"__FILE__":"xstr(__LINE__)))
#define ei e("idx"dbg(":"__FILE__":"xstr(__LINE__)))
#define ez e("lmt"dbg(":"__FILE__":"xstr(__LINE__)))
#define ev(s) e(s) //value error for name s
#define ea(x) dbg($(!(x),e(__FILE__":"xstr(__LINE__)": "xstr(x)))) //assert
A e(C*); //error. gets source offset for the current bytecode instruction from Fn->m
V eo(C*,A,UH); //error with explicit source offset

//memory management
extern A symlist,mx[];
A mm(L),ma(L,L),acm(C*,C*);V miAll(A),mdAll(A),*memcpy(V*,O V*,L);L m_used(),symidx(C*,L),strlen(O C*);
#define nxt(x) A(x)[-2]
SI V mf_(A x){ea(!xr);UC b=xb;nxt(x)=mx[b];mx[b]=x;} //free (non-recursive)
SI V mf(A x){$(isRefType(xt),mdAll(x))mf_(x);} //free
SI A mi(A x){ea(xr>=0);xr++;R x;}        //ref
SI A mo(A x){ea(xr> 0);xr--;R x;}        //unref without consuming
SI V mu(A x){ea(xr>=0);$(!  xr,mf(x))}   //consume
SI V md(A x){ea(xr> 0);$(!--xr,mf(x))}   //unref and consume
SI L mb(L n){R 67-__builtin_clzll(n+1);} //bucket index. n is size in 64-bit words
SI A symstr(L i){R A(symlist)[i];}       //get the string corresponding to a `symbol. guranteed '\0' after last char

//constructors
SI A atnr(C t,L n,L r){R ma(btr(mb(t==tc?(n+7)>>3:n),t,r),n);}
SI A atno(C t,L n,UH o){R ma(btor(mb(t==tc?(n+7)>>3:n),t,o,0),n);}
SI A atn(C t,L n){R atnr(t,n,0);} //allocate by type and length
SI A ax(A x){R xr?atn(xt,xn):x;}  //allocate the same type and length as x, attempting reuse
SI A aC(C v){A x=atn(tC,1);*xc=v;R x;}
SI A aL(L v){A x=atn(tL,1);*xl=v;R x;}
SI A aS(L v){A x=atn(tS,1);*xl=v;R x;}
SI A aD(D v){A x=atn(tD,1);*xd=v;R x;}
SI A aa(L n){R atn( 0,n);}
SI A al(L n){R atn(tl,n);}
SI A as(L n){R atn(ts,n);}
SI A ad(L n){R atn(td,n);}
SI A ac(L n){R atn(tc,n);}
SI A ag (A x,A y         ){mi(x);mi(y);      A u=atn (tg,2  );ux=x;uy=y;        R u;} //+x!y
SI A ah (A x,A y         ){mi(x);mi(y);      A u=atn (th,2  );ux=x;uy=y;        R u;} //x!y
SI A a1 (A x             ){mi(x);            A u=atn (0 ,1  );ux=x;             R u;} //,x
SI A a2 (A x,A y         ){mi(x);mi(y);      A u=atn (0 ,2  );ux=x;uy=y;        R u;} //(x;y)
SI A a3 (A x,A y,A z     ){mi(x);mi(y);mi(z);A u=atn (0 ,3  );ux=x;uy=y;ua[2]=z;R u;} //(x;y;z)
SI A a2o(A x,A y,    UH o){mi(x);mi(y);      A u=atno(0 ,2,o);ux=x;uy=y;        R u;}
SI A a3o(A x,A y,A z,UH o){mi(x);mi(y);mi(z);A u=atno(0 ,3,o);ux=x;uy=y;ua[2]=z;R u;}

#define v1(f) A f(A x)
#define v2(f) A f(A x,A y)
TD v1(v1);v1 sam,flp,neg,fst,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,cnt,flr,str,unq,typ,val,u0c,u1c,str0,prs,ldf,blw,sqz,cpl,json,out,nil,gl,gd,id_,cmd,mut,mut01,mut10,hopen,hclose,lst;
TD v2(v2);v2 dex,add,sub,mul,div,mod,mxm,mnm,ltn,gtn,eql,mtc,cat,xpt,rsh,cut,cst,fnd,ap1,app,v0c,v1c,v2c,sys,cps,idx,idx_,apd;
TD A advt(A,A*,L);advt eac,rdc,scn,eap,ear,eal;
A glb,apdc(A,C),apdl(A,L),apdd(A,D),apda(A,A),apply(A,A*,L),run(Fn,A*,L),emptyctx(),amd(A,A,A,A*,L),dmd(A,A,A,A*,L);
L fndal(A,L),fndl(A,L),fnda(A,A),fndpc(A*,C),fndpl(A*,L),fndpa(A*,A),mtc_(A,A),tru(A);
V ___();

#define vrbval(x) (31&(((V*)(x)-cu0))/Z(*cuvw_))
SI V*vrbfnc(A x){ea(xt==tu||xt==tv||xt==tw);R(V*)xl[1];}
#define _A(x)  (ZHdr+(V*)(x))
#define cb(i)  _A(cb_[i])        //bools
#define cu(i)  _A(cuvw_[i])      //unary verbs
#define cv(i)  _A(cuvw_[32+(i)]) //binary verbs
#define cw(i)  _A(cuvw_[64+(i)]) //adverbs
#define cea    _A(cea_) //()
#define cu0    cu( 0) //::
#define cu_fst cu( 3) //*:
#define cu_rev cu( 7) //|:
#define cu_str cu(16) //$:
#define cu_cmd cu(31) //\cmd
#define cv0    cv( 0) //:
#define cv_add cv( 1) //+
#define cv_cat cv(12) //,
#define cv_cst cv(16) //$
#define cv_fnd cv(17) //?
#define cv_ap1 cv(18) //@
#define cv_app cv(19) //.
#define cv_lis cv(30) //(x;y;z) create list
#define cv_cps cv(31) //'[+;*] compose
#define cn(t)  cn_[t] //nulls
#define _0W    0x7fffffffffffffffll
#define _0N    0x8000000000000000ll
#define _0n    (0.0/0.0)
#define _0w    (0.1/0.0)
extern O C cf[20];  //verb symbols
extern O L cil[11]; //integer identities for arithmetic verbs
extern O D cid[11]; //floating-point identities for arithmetic verbs
extern O A cn_[tn]; //nulls
TD L L4[4]__attribute__((aligned(32)));extern L4 cb_[2],cuvw_[32+32+6],c1h_,cea_; //pre-allocated objects, never freed
SI L isArith(A x){R cv0<=x&&x<cv(ZZ(cil));}

//indices of predefined symbols
#define s_o 4 //`o
#define s_p 5 //`p
#define s_j 6 //`j
#define s_t 7 //`t

SI L gL(A x){L r=*xl;mu(x);R r;}
SI D gD(A x){D r=*xd;mu(x);R r;}

#define arithL(f,n,p)Y(f,,\
 Q( 0,fi(n,p ((V)a,b)                 ))\
 Q( 1,fi(n,p a+b                      ))\
 Q( 2,fi(n,p a-b                      ))\
 Q( 3,fi(n,p a*b                      ))\
 Q( 4,fi(n,p b?a/b:!a?_0N:a>0?_0W:-_0W))\
 Q( 5,fi(n,p a>0?(b%a+a)%a:a?b/-a:_0N ))\
 Q( 6,fi(n,p min(a,b)                 ))\
 Q( 7,fi(n,p max(a,b)                 ))\
 Q( 8,fi(n,p a<b                      ))\
 Q( 9,fi(n,p a>b                      ))\
 Q(10,fi(n,p a==b                     )))
#define arithD(f,n,p)Y(f,,\
 Q( 0,fi(n,p ((V)a,b)                 ))\
 Q( 1,fi(n,p a+b                      ))\
 Q( 2,fi(n,p a-b                      ))\
 Q( 3,fi(n,p a*b                      ))\
 Q( 4,fi(n,p b?a/b:!a?_0n:a>0?_0w:-_0w))\
 Q( 5,fi(n,p ((V)a,(V)b,_0n) /*todo*/ ))\
 Q( 6,fi(n,p min(a,b)                 ))\
 Q( 7,fi(n,p max(a,b)                 ))\
 Q( 8,fi(n,p *(D*)cb(a<b)             ))\
 Q( 9,fi(n,p *(D*)cb(a>b)             ))\
 Q(10,fi(n,p *(D*)cb(a==b)            )))

//debugging
#define pv(x) pv_(#x,(L)(x));
#define pa(x) pa_(#x" ",(x));
#define nop {asm volatile("nop");}
#define P ps("["__FILE__":"xstr(__LINE__)"]");
V ps(C*),ph(L),pd(L),pa_(C*,A);L pv_(C*,L);
