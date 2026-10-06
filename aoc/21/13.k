#!../../k
x:0:"i/13"
i:*&~#'x                     /index of empty line
c:.'i#x                      /coordinates
w:(~2!*|:;.:)@'/:"="\'1_i_x  /fold instructions (axis;index)
p:+((1+|/c)#0).[;;:;1]/c     /paper
f:{(y#x)||(1_y_x),&1+y+y-#x} /fold 1d  f[paper;index]
F:{(y(\:)/f)[x]z}            /fold 2d  F[paper;axis;index]
+//F[p].*w                   /part1
`0:" #"F/[p].+w              /part2
