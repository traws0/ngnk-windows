#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S UI f0(UI x,UI y,UI z)_(x&y|~x&z)S UI f1(UI x,UI y,UI z)_(z&x|~z&y)S UI f2(UI x,UI y,UI z)_(x^y^z)S UI f3(UI x,UI y,UI z)_(y^(x|~z))S UI rol(UI x,UI y)_(x<<y|x>>32-y)
#define h1(q,x,y,z,u,s,m) x=y+rol(x+f##q(y,z,u)+k[i]+d[m],s);i++;
#define h(q,s0,s1,s2,s3,m) W(i<16*(q+1),h1(q,x,y,z,u,s0,m)h1(q,u,x,y,z,s1,m)h1(q,z,u,x,y,s2,m)h1(q,y,z,u,x,s3,m))
S V md5h(UI*d,UI*a,L n){S O UI k[]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,
 0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
 0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,
 0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
 0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
 F(n,UI i=0,x=*a,y=a[1],z=a[2],u=a[3];h(0,7,12,17,22,i)h(1,5,9,14,20,5*i+1&15)h(2,4,11,16,23,3*i+5&15)h(3,6,10,15,21,7*i&15)*a+=x;a[1]+=y;a[2]+=z;a[3]+=u;d+=16)}
#undef h
#undef h1
A1(md5,P(!xtC,et(x))A u=aCn((V*)(UI[]){0x67452301,0xefcdab89,0x98badcfe,0x10325476},16);UL n=xn,k=n/64,r=n%64;
 mr2(x,md5h(xi,ui,k);C c[128];UL m=n+72&~63;mc(c,xc+n-r,r);c[r]=128;ms(c+r+1,0,m-n-9);*(L*)(V*)(c+m-n+r-8)=8*n;md5h((V*)c,ui,m/64-k);u))
