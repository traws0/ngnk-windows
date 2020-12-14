#!../k
a:0:"i/14"

/part1
b:36#2;M:(,0)!,0
ma:{c::&'"01X"=\:-36#x}
me:{(i;v):.'4 3_'"]"\x;M[i]:b/@[b\v;2#c;:;!2]}
{(. 2#x)x}'a;+/M

/part2
Z:{x^0}                 /remove 0s
p2:(2*)\1               /powers of 2
b:36#2                  /base for encoding
ma:{y;c::"01X"?7_x;0}   /"mask" command: "X" becomes 2; global c is the current mask
me:{(i;v):.'4 3_'"]"\x  /"mem" command: apply mask to address and
    (y;v;c|b\i)}        /builds a set represented as (timestamp;value;mask)
sec:{$[~x[0]<y[0];0     /intersection of sets
 |/3=r:0 3 0 3 1 1 0 1 2 x[2]+3*y[2];0 /lookup table to merge "01X" with "01X"; 3=error
 (2#x),,r]}             /result gets the earlier set's timestamp and value and mask r
step:{Z@,/a sec/:\:x}   /from intersections in groups of n to n+1
val:{x[1]*p2@+/2=x 2}   /total contribution of a set: value * 2^numberOfXs
a:Z a{(. 2#x)[x;y]}'!#a /input as sets
r|-r:-1/+/'val''step\a  /inclusion-exclusion
