#!../../k
x:`I$(0:"i/01")^'"+"
+/x /part1

/part2(ngn)
d:{1<|/@[&1-l-|/x;x-l:&/x;+;1]} /has dupes?
f:{a@*{@[x;d m#a;:;m:-2!+/x]}/0,#a::(~d@){x,x+*|x}/+\x} /binary search

//part2(Alve Björk)
/f:{t:*|s:+\x
/   d:,/p-/:p:s-x
/   m:(~t!d)&(0<d)&(*/2##p)#&1,#p
/   (p(#p)!&m)r?&/r:d@&m}

//part2(DiscoDoug)
/f:{d:(-t)!a|-a:-/s@w:w@\:&>/w:&m=\:m:(t:*|s)!s:+\x
/   (t*d@w)+s(#s)!i@w:*<i:(d*#s)+(+w)@'>/s@w}

$[0>+/x;f x;-f@-x]
