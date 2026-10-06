#!../../k
t:`I$*0:"i/03"

/part1
O:-2!1+O-~2!O:_%-1+t /orbit
d|:-d:O-(2*O)!t-*/2#-1+2*O /distance from nearest axis
O+d

/part2
D:(|-1 1*)\!2 /cardinal directions
n:5
a:(2#1+2*n)#0 /grid
a[n;n]:1      /centre
d:1           /direction index
f:{$[~0^a . q:x+D@e:4!d-1;[x:q;d::e];x+:D d]
   a[x 0;x 1]:+/0^,/a[x[0]-1-!3;x[1]-1-!3];x} /step
a.{~t<a. x}f/2#n
