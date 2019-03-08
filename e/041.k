\l 0.k
mp:_%10000
p:primes mp
isprime:{$[|/~2 3 5 7!'x;0;x<mp;~^p?x;~|/~p!'x]}
|/,/{isprime#10/1+prm x}'4 7 /digit sum of other pandigitals is divisible by 3
/7653241
