#!../k
a:0:"i/14"
b:36#2
m01x:

M:(,0)!,0
mask:{m01x::&'"01X"=\:-36#x}
mem:{(i;v):.'4 3_'"]"\x;M[i]:b/@[b\v;2#m01x;:;!2]}
{$["ma"~2#x;mask;mem]x}'a;
+/M

M:(,0)!,0
mem:{(i;v):.'4 3_'"]"\x
     i:b\i
     i[m01x 1]:1
     i[m01x 2]:!(#m01x 2)#2
     i:b/i
     M[i]:v}
{$["ma"~2#x;mask;mem]x}'a
+/M
