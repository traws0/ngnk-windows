// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
typedef unsigned long long A;
A app(A,const A*,int);
A K0(const unsigned char*,int);
#define K(s,a...) ({static A f;if(!f)f=K0(s,sizeof s);sizeof(A[]){a}?app(f,(A[]){a},sizeof((A[]){a})/sizeof(A)):f;})
