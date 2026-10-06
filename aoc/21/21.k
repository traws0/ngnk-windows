#!../../k
x:(.*|" "\)'0:"i/21" /input

/part1 (x:positions,y:scores,z:counter)
{z*&/y}.({$[999<|/y;:(x;y;z);(|x;|@[y;0;+;x[0]:1+10!x[0]+2+/100!z+!3];z+3)]}.)/(x;&2;0)

/part2
(d;k):(!:;.:)@\:#'=3+/!3#3 /possible 3die roll sums and their multiplicities
m:11 11 21 21#0N /memoization
f:{[p;q;s;t]$[20<t;!2;~^*r:m[p;q;s;t];r;m[p;q;s;t]:|+/k*o[q;;t]'[P;s+P:1+10!-1+p+d]]} /p,q:positions, s,t:scores
|/f. x,&2
