#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
S UI rol(UI x,UI y)_(x<<y|x>>(32-y))
A1(md5,P(!xtC,et(x))
 S O C r[]={7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,
  15,21,6,10,15,21,6,10,15,21,6,10,15,21};
 S O UI k[]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,
  0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,0x21e1cde6,
  0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,
  0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,
  0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
 UL l=xn*8;x=apc(x,128);W(xn*8%512!=448,x=apc(x,0))F(8,x=apc(x,l>>(8*i)))
 UI h[]={0x67452301,0xefcdab89,0x98badcfe,0x10325476};
 Fj(xn/64,UI a=h[0],b=h[1],c=h[2],d=h[3];
  F(64,UI f,g;
   Y( i<16,f=b&c|~b&d;g=   i      )
   EY(i<32,f=d&b|~d&c;g=(5*i+1)%16)
   EY(i<48,f=b^c^d   ;g=(3*i+5)%16)
   E(      f=c^(b|~d);g=(7*i  )%16)
   UI t=d;d=c;c=b;b=b+rol(a+f+k[i]+xi[16*j+g],r[i]);a=t)
  h[0]+=a;h[1]+=b;h[2]+=c;h[3]+=d)
 xr;A y=aC(16);F(4,yii=h[i])y)
