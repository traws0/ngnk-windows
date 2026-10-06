#include "unistd.h"
#include "k.h"

#define TY __typeof__

#define x(a) ({K r_=(a);unref(x);r_;})
#define y(a) ({K r_=(a);unref(y);r_;})
#define z(a) ({K r_=(a);unref(z);r_;})

#define _(a...) {return({a;});}
#define F_(i,n,a...) for(TY(n)n_=(n),i=0;i<n_;i++){a;}
#define F(a...) F_(i,a)

#define A1(f,b...) K f(K x             )_(b)/*1*/
#define A2(f,b...) K f(K x,K y         )_(b)/*01*/
#define A3(f,b...) K f(K x,K y,K z     )_(b)
#define A4(f,b...) K f(K x,K y,K z,K u )_(b)
#define A5(f,b...) K f(K x1,K x2,K x3,K x4,K x5                )_(b)
#define A6(f,b...) K f(K x1,K x2,K x3,K x4,K x5,K x6           )_(b)
#define A7(f,b...) K f(K x1,K x2,K x3,K x4,K x5,K x6,K x7      )_(b)
#define A8(f,b...) K f(K x1,K x2,K x3,K x4,K x5,K x6,K x7,K x8 )_(b)
