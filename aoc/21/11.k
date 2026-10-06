#!../../k
x:-48+0:"i/11"                  /input
h:&'3>+/*/2#,-\:'/2#,!#'1*:\x   /neighbours
x:,/x                           /flatten
f:{(x&10>x)*@[x;h@&9<x;+;1]}/1+ /step
+//~100 f\x                     /part1
-1+#(|/)f\x                     /part2
