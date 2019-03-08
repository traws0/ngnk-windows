\l 0.k
maxp:20000
sieve:@[&maxp;primes maxp;:;1]
ab:{x@'!#'x}(-1000+!2001;primes 1000)
{i:&1=sieve@v:(x*x)+(x*ab 0)+ab 1;$[maxp<|/v;ERR;~#i;:x];ab::ab@\:i;x+1}/1;
**/ab
/-59231
