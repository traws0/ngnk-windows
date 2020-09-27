// ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
typedef unsigned long long A;
A app(A,const A*,int);
#define K(s,a...) ({static A f;if(!f)f=K0(s,sizeof s);sizeof(A[]){a}?app(f,(A[]){a},sizeof((A[]){a})/sizeof(A)):f;})
