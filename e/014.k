n:1000000
c:@[&n;1;:;1] /cached collatz chain lengths
f:{$[v:0|c x;:v;]
   v:$[2!x;2+o@2+3*-2!x;1+o@-2!x] /if x is odd, take two steps at a time
   $[x<n;c[x]:v;v]}
*&r=|/r:f'@[!n;0;:;1]
/837799
