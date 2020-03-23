// ngn/k, (c) 2019-2020 ngn, license: GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
// generated by g.k
#define xb Ab(x)
#define xt At(x)
#define xn An(x)
#define yb Ab(y)
#define yt At(y)
#define yn An(y)
#define zb Ab(z)
#define zt At(z)
#define zn An(z)
#define ub Ab(u)
#define ut At(u)
#define un An(u)
#define xr ({mr(x);x=0;})
#define yr ({mr(y);y=0;})
#define zr ({mr(z);z=0;})
#define ur ({mr(u);u=0;})
#define xR mR(x)
#define yR mR(y)
#define zR mR(z)
#define uR mR(u)
#define xci xc[i]
#define xcj xc[j]
#define xhi xh[i]
#define xhj xh[j]
#define xii xi[i]
#define xij xi[j]
#define xli xl[i]
#define xlj xl[j]
#define xdi xd[i]
#define xdj xd[j]
#define xai xa[i]
#define xaj xa[j]
#define yci yc[i]
#define ycj yc[j]
#define yhi yh[i]
#define yhj yh[j]
#define yii yi[i]
#define yij yi[j]
#define yli yl[i]
#define ylj yl[j]
#define ydi yd[i]
#define ydj yd[j]
#define yai ya[i]
#define yaj ya[j]
#define zci zc[i]
#define zcj zc[j]
#define zhi zh[i]
#define zhj zh[j]
#define zii zi[i]
#define zij zi[j]
#define zli zl[i]
#define zlj zl[j]
#define zdi zd[i]
#define zdj zd[j]
#define zai za[i]
#define zaj za[j]
#define uci uc[i]
#define ucj uc[j]
#define uhi uh[i]
#define uhj uh[j]
#define uii ui[i]
#define uij ui[j]
#define uli ul[i]
#define ulj ul[j]
#define udi ud[i]
#define udj ud[j]
#define uai ua[i]
#define uaj ua[j]
#define xc ((C*)dat(x))
#define xh ((H*)dat(x))
#define xi ((I*)dat(x))
#define xl ((L*)dat(x))
#define xd ((D*)dat(x))
#define xa ((A*)dat(x))
#define yc ((C*)dat(y))
#define yh ((H*)dat(y))
#define yi ((I*)dat(y))
#define yl ((L*)dat(y))
#define yd ((D*)dat(y))
#define ya ((A*)dat(y))
#define zc ((C*)dat(z))
#define zh ((H*)dat(z))
#define zi ((I*)dat(z))
#define zl ((L*)dat(z))
#define zd ((D*)dat(z))
#define za ((A*)dat(z))
#define uc ((C*)dat(u))
#define uh ((H*)dat(u))
#define ui ((I*)dat(u))
#define ul ((L*)dat(u))
#define ud ((D*)dat(u))
#define ua ((A*)dat(u))
#define xx xa[0]
#define xy xa[1]
#define xz xa[2]
#define yx ya[0]
#define yy ya[1]
#define yz ya[2]
#define zx za[0]
#define zy za[1]
#define zz za[2]
#define ux ua[0]
#define uy ua[1]
#define uz ua[2]
#define xtX (xt==tX)
#define xtC (xt==tC)
#define xtI (xt==tI)
#define xtL (xt==tL)
#define xtD (xt==tD)
#define xtS (xt==tS)
#define xtA (xt==tA)
#define xta (xt==ta)
#define xtc (xt==tc)
#define xti (xt==ti)
#define xtl (xt==tl)
#define xtd (xt==td)
#define xts (xt==ts)
#define xto (xt==to)
#define xtp (xt==tp)
#define xtq (xt==tq)
#define xtr (xt==tr)
#define xtu (xt==tu)
#define xtv (xt==tv)
#define xtw (xt==tw)
#define ytX (yt==tX)
#define ytC (yt==tC)
#define ytI (yt==tI)
#define ytL (yt==tL)
#define ytD (yt==tD)
#define ytS (yt==tS)
#define ytA (yt==tA)
#define yta (yt==ta)
#define ytc (yt==tc)
#define yti (yt==ti)
#define ytl (yt==tl)
#define ytd (yt==td)
#define yts (yt==ts)
#define yto (yt==to)
#define ytp (yt==tp)
#define ytq (yt==tq)
#define ytr (yt==tr)
#define ytu (yt==tu)
#define ytv (yt==tv)
#define ytw (yt==tw)
#define ztX (zt==tX)
#define ztC (zt==tC)
#define ztI (zt==tI)
#define ztL (zt==tL)
#define ztD (zt==tD)
#define ztS (zt==tS)
#define ztA (zt==tA)
#define zta (zt==ta)
#define ztc (zt==tc)
#define zti (zt==ti)
#define ztl (zt==tl)
#define ztd (zt==td)
#define zts (zt==ts)
#define zto (zt==to)
#define ztp (zt==tp)
#define ztq (zt==tq)
#define ztr (zt==tr)
#define ztu (zt==tu)
#define ztv (zt==tv)
#define ztw (zt==tw)
#define utX (ut==tX)
#define utC (ut==tC)
#define utI (ut==tI)
#define utL (ut==tL)
#define utD (ut==tD)
#define utS (ut==tS)
#define utA (ut==tA)
#define uta (ut==ta)
#define utc (ut==tc)
#define uti (ut==ti)
#define utl (ut==tl)
#define utd (ut==td)
#define uts (ut==ts)
#define uto (ut==to)
#define utp (ut==tp)
#define utq (ut==tq)
#define utr (ut==tr)
#define utu (ut==tu)
#define utv (ut==tv)
#define utw (ut==tw)
#define xtcC (xtc||xtC)
#define xtiI (xti||xtI)
#define xtlL (xtl||xtL)
#define xtdD (xtd||xtD)
#define xtsS (xts||xtS)
#define xtaA (xta||xtA)
#define xtilIL (xtil||xtIL)
#define ytcC (ytc||ytC)
#define ytiI (yti||ytI)
#define ytlL (ytl||ytL)
#define ytdD (ytd||ytD)
#define ytsS (yts||ytS)
#define ytaA (yta||ytA)
#define ytilIL (ytil||ytIL)
#define ztcC (ztc||ztC)
#define ztiI (zti||ztI)
#define ztlL (ztl||ztL)
#define ztdD (ztd||ztD)
#define ztsS (zts||ztS)
#define ztaA (zta||ztA)
#define ztilIL (ztil||ztIL)
#define utcC (utc||utC)
#define utiI (uti||utI)
#define utlL (utl||utL)
#define utdD (utd||utD)
#define utsS (uts||utS)
#define utaA (uta||utA)
#define utilIL (util||utIL)
#define xtaAX (xtaA||xtX)
#define ytaAX (ytaA||ytX)
#define ztaAX (ztaA||ztX)
#define utaAX (utaA||utX)
#define xtil (xti||xtl)
#define ytil (yti||ytl)
#define ztil (zti||ztl)
#define util (uti||utl)
#define xtIL (xtI||xtL)
#define ytIL (ytI||ytL)
#define ztIL (ztI||ztL)
#define utIL (utI||utL)
#define xtt (xt>ta)
#define ytt (yt>ta)
#define ztt (zt>ta)
#define utt (ut>ta)
#define xtT (xt<tA)
#define ytT (yt<tA)
#define ztT (zt<tA)
#define utT (ut<tA)
#define Nx(r) N1(x,r)
#define Ny(r) N1(y,r)
#define Nz(r) N1(z,r)
#define Nu(r) N1(u,r)
