#!../../k
x:"\n\n"\1:"i/05"
s:.*|":"\*x /seeds
m:{,/'+'|'(,'r),\:,0N 2#-1_0,/*r:a@\:<*a:+'|++\2#'0 2_+.'1_"\n"\x}'1_x /maps
f:{(</')#(--/y)+x[0]|x[1]&*y:y,\:,(*|*|*y;*|x)} /apply map
g:{&/*'(+\'x)(,/f\:)/m} /solve

g s,'1   /1
g 0N 2#s /2

/based on https://github.com/rak1507/aoc-2023/blob/main/5.k
