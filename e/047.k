\l 0.k
n:1000000
k:4
p:primes 2+_%n
omega:(&n){x[y*!(-y)!-1+#x]+:1;x}/p /number of prime factors (or 0 for primes larger than sqrt n)
*1-k-&(k-1)&':/k=omega
/134043
