#!../../k
x:-48+0:"i/15"           /input
D:(|1 -1*)\!2            /cardinal directions
f:{                      /solve
 n::#'1*:\x              /shape
 h::n/'(n-1)&/:0|D+\:!n  /neighbours
 a::,/x                  /flattened input
 d::&*/n                 /distances (0 for unknown)
 q::(,,0),9999#,!0       /q[x]:list of cells at distance x
 {q[d[i]:x+a i],:i:?(d@)_,/h@\:q x;x+~*|d}/0 /wave
 *|d}
f@x                      /part1
f@,/,'/'5':1+9!x+/:-1+!9 /part2
