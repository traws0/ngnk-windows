#!/usr/bin/env python3
n=119315717514047;m=101741582076661;x=2020;a=1;b=0
inv=lambda x:pow(x,n-2,n)
for s in list(open('22'))[::-1]:
 l=s[:-1].split(' ')[-1]
 if s[0]=='c':b=(b+int(l))%n
 elif s[-2]=='k':a=(-a)%n;b=(-(b+1))%n
 else:k=inv(int(l));a=a*k%n;b=b*k%n
am=pow(a,m,n)
print((x*am+b*((am-1)*inv(a-1)))%n)
