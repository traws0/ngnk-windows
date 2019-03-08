\l 0.k
n:1000000
p:primes n
h:@[n#0x00;p;:;0x01] /sieve
f:{a:10\x
   m:1_'-1_'!(#a)#2              /all patterns except "no stars" and "all stars"
   b:(10/m*a) +/: 10/'(~m)*/:!10 /numbers to test for primality
   b[0;!-2!#*b]:0                /no leading zeroes
   &/c@&h c:,/b@\:&7<+/h b}      /min of the primes from 8+ families
&/f'p
/121313
