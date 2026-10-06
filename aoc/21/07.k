#!../../k
a:`I$","\*0:"i/07"
a-:&/a  /translate left end to 0
a@:<a   /sort
n:#a    /length
s:+\0,a /partial sums
S:s n   /sum
Q:+/a*a /sum of squares

f:{(a[x]*-n-2*x)+S-2*s@x}
f@-2!n /part1: sum of distances to median

g:{-2!f[x]+a[x]/(n;-2*S;Q)}
&/g'a'(_m;-_-m:S%n) /part2: sum of squares of distances to mean
