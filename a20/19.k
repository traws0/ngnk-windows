#!../k
(a;b):(.:';.''"|"\')@'+": "\'*(a;m):0 1_'(0,&""~/:a)_a:0:"i/19"
r:@[&1+|/a;a;:;b]
f:{$[~c[x;y]~-1;c[x;y];`C~@r y;c[x;y]:(s[x]=*r y)&i=1+x;c[x;y]:|/q[x]'r y]} /x:pos,y:rule -> mask
F:{0|/(&x)f'y} /x:mask,y:rule -> mask
q:{(i=x)F/y} /x:pos,y:rule -> mask
g:+/{i::!1+#s::x;c::(1+|/#'m;#r)#-1;*|f[0]0}'
g m

r[8 11]:((,42;42 8);(42 31;42 11 31))
\t { \x} g m
