#!../../k
l:`I$+'+","\''" -> "\'0:"i/05" /lines
n:1+|/|/''l                    /grid shape
p:n/*l                         /start
d:-/|l                         /deltas
s:n/-1|1&d                     /step
k:1+|/d|-d                     /distance
f:{[x;p;s;k] @[x;p+s*!k;+;1]}  /put line on (flattened) grid
i:&m:~*/d                      /only horizontal or vertical
j:&~m                          /only diagonal
+/1<a:f/[&*/n;p i;s i;k i]     /part1
+/1<  f/[a   ;p j;s j;k j]     /part2
