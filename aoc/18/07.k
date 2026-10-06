#!../../k
e:(0:"i/07")[;5 36]-"A" /edges
n:1+|//e                /number of vertices
g:(=n).[;;:;1]/e        /adjacency matrix
`0:`c$"A"+>+/0>n{x-g@x?0}\-1+/g /part1
|/*|{(t;d):x;$[a:((5-/t<d)&#a)#a:&(~d)&1=+/g*(~d)|t<d;d[a]:t+61+a;t:&/(t<)#d];(t;d)}/0,,&n /part2

/
t:current time
d[i]:when will task i be done (or 0 if not started yet)
5-/t<d : number of idle workers
a:available tasks
