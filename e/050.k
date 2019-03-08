\l 0.k
n:1000000
p:primes n
a:!0
b:-1_p
{x}{b+:(#b)#x_p;b::(n>)#b;a,:b;$[#b;x+1;0]}/1;
sieve:@[&n;p;:;1]
*|{0|sieve x}#a
/997651
