#!../../k
x:`$"-"\'0:"i/12"
v:?`start`end,v@:>v:,/x        /vertices ("caves")
N:(#v)-n:+/v=_v                /number of big and small caves
g|:+g:((2##v)#0).[;;:;1]/v?x   /graph (adjacency matrix)
w:- 2/=n                       /binary digit weights (negated)
P:2*D:*/n2:n#2                 /state: (P*position)+(D*doubleVisit)+2/smallCaveVisits
t:(P*#v)#-1;t[2/~!n]:1         /dynamic programming table
f:{(x;d;s):(0 2,D)\x           /how many paths lead to state x?
   h:P*&g[x]&(n2\s),N#1        /neighbours that have been visited or are big
   $[~x<n;+/(!0),F'h+s+D*d
     ~2!w[x]!s;0
     d&1<x;+/(!0),F'(h+s),h+D+s+w x
           +/(!0),F'h+(D*d)+s+w x]}
F:{$[0>t x;:t[x]:f x;t x]}     /memoized f
+/F'P+!D /part1
+/F'P+!P /part2
