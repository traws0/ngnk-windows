#!../k
a:0:"i/14"

h:(!0)!0;ma:{c::&'"01"=\:-36#x};me:{(i;v):.'4 3_'"]"\x;h[i]:2/@[(36#2)\v;c;:;!2]};{(. 2#x)x}'a;+/h /part1

ma:{y;c::"01X"?7_x;0}   /"mask" command: "X" becomes 2; global c is the current mask
me:{(i;v):.'4 3_'"]"\x  /"mem" command: apply mask to address and
    (y;v;c|(36#2)\i)}   /build a set represented as (timestamp;value;mask)
Z:{x^0}                 /remove 0s (used as an ignored value instead of a set)
a:Z a{(. 2#x)[x;y]}'!#a /input as sets; consecutive ints are used as "timestamps"
t:0 3 0 3 1 1 0 1 2     /3x3 lookup table to merge "01X" with "01X"; 3=error
X:{$[~x[0]<y[0];0       /intersection of sets; x must be earlier than y
 |/3=r:t@x[2]+3*y[2];0  /merge masks and handle errors
 (2#x),,r]}             /result gets the earlier set's timestamp and value; mask is r
s:Z@,/a X/:\:           /step from intersections in groups of n to n+1
f:{x[1]*/x[2]^!2}       /total contribution of a set: value * 2^numberOfXs
r|-r:-1/+/'f''s\a       /inclusion-exclusion principle
