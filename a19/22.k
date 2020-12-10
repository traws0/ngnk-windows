#!../k
a:0:"i/22"
2019{10007!$["c"=*y;x-.*|" "\y;"k"=*|y;-x+1;x*.*|" "\y]}/a
n:119315717514047
m:101741582076661
rep:{[f;e;x;y]$[y;f/(~2!y)_x,2#o[f;e;x;-2!y];e]}
mul:rep[n!+]0
pow:rep[mul]1
inv:pow[;n-2]
div:{mul[x]inv y}
(b;c):1 0{l:*|" "\y;n!$["c"=*y;x+0,. l;"k"=*|y;-x+!2;x div'. l]}/|a
bm:pow[b]m
n!mul[2020;bm]+mul[c]div[bm-1]b-1
