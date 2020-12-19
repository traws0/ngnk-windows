#!../k
a:0:"i/19"
(r;m):0 1_'(0,&""~/:a)_a
(a;b):+@[;1;" | "\]'": "\'r
a:.'a;b:.''b
r:@[&1+|/a;a;:;b]
f:{$[`C~@r y;:(s[x]=*r y)&i=1+x;|/seq[x]'r y]} /x:pos,y:rule -> mask
F:{0i|/(&x)f'y} /x:mask,y:rule -> mask
seq:{(i=x)F/y} /x:pos,y:rule -> mask
g:{+/{s::x;i::`i$!1+#s;*|f[0i]0i}'m}
g[]

r[8 11]:((,42;42 8);(42 31;42 11 31))
g[]

