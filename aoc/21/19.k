#!../../k
s:(+.'1_"\n"\)'"\n\n"\1:"i/19"  /scanner data
P:?<'+!3#3;D:+1-2*!3#2;B:10000  /permutations,directions,base for encoding
F:(){$[x;x;y@:z;,(,z),*y;x]}/   /F[f;x]: first (x i;f x i) with truthy f x i
q:11<+/~^?                      /is there overlap? (x and y must be encoded)
q1:{F[q[B/x]@B/y+;+x(,/-\:)'y]} /() or ,offset
q2:{F[q1[x]y*;D]}               /() or ,(direction;offset)
q3:{F[q2[x]y@;P]}               /() or (permutation;direction;offset)
d:(+/*/2#,(,/-\:)'/2#,:)'s      /distances
h:66<#{x^x^y}/d@                /heuristic
qh:{$[h x;q3/s x;()]}           /q3 with heuristic
t:{x[2]+x[1]*y@*x}              /apply transform
l:(#s;3)#0                      /scanner locations
m:=#s                           /m[i;j]: have we tried to match s[i] and s[j]?
(u;v):0 1_!#s                   /indices of done and pending
{`{$[x~`;;:`];x:*v;$[m[x;y];:`;];m[x;y]:1;r:qh y,x
   $[#r;;:`];l[x]:(*r)2;s[x]:t[*r]s x;u,:x;v::1_v;r}/u
 :v@:(#v)!1+!#v}/0;

#?,/+'s             /part1
|/+/'a|-a:,/l-/:\:l /part2
