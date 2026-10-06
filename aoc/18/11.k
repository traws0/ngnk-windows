#!../../k
N:2#n:300
g:`I$*0:"i/11"       /grid serial number
(X;Y):1+!N           /fuel cell coordinates
r:10+X               /rack id
p:-5+10!-100!r*g+Y*r /power level
s:2(++\0,')/N#p      /sums

/f[l]:find square of size l with the largest total power; returns (X;Y;l;totalpower)
f:{d:x,-x
   XY:1+(N+1-x)\*&a=t:|/a:,/-/-/d_\:/:d_'\:s
   XY,x,t}

`0:","/$2#f 3 /part1
`0:","/$3#r@*>*|+r:f'1+!n /part2
