\l 0.k
n:100
p:primes n
a:~!n
{[p] {[p;i] a[i+p]+:a[i];}[p]'!0|n-p;}'p;
*&5000<a
/71
