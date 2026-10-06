#!../../k
x@:<x:0:"i/04"
g:0           /current guard
s:0           /minute when fallen asleep
a:(!0)!0#,&60 /sleep[guard;minute]
{e:x 19       /event type
 m:`I$x 15 16 /minute
 $["G"=e;g::`I$*" "\*|"#"\x
   "f"=e;s::m
   "w"=e;a[g]:@[0|a g;s_!m;+;1]
   unk]}'x;

G**>a G:*>+/'a      /part1
G**>a G:*>|/'a=|//a /part2
