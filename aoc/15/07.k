#!../../k
H:!/|+" -> "\'0:"i/07"
b:16#2
g:()!()
g["NOT"]:2/~b\
g["AND"]:2/&/b\'
g["OR"]:2/|/b\'
g["LSHIFT"]:{2/(y_b\x),&y}.
g["RSHIFT"]:{2/(-y)_b\x}.
f:{$[~"0:"'*x;`I$x;`i=@e:h x;e;:h[x]:$[1=#e:" "\e;o e 0;2=#e;g[e 0]o e 1;g[e 1]@o'e 0 2]]}
h:H;:r:f@,"a" /part1
h:H;h[,"b"]:r;f@,"a" /part2
