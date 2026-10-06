#!../../k
x:0:"i/08"
c:(" "\"> < >= <= == !=")!(>;<;~<;~>;=;~=) /comparisons
f:{y:" "\y /execute instruction (x:registers dict, y:instruction string)
   d:(1-2*"d"=*y 1)*`I$y 2 /delta
   @[x;*y;+;d*c[y 5;0^x y 4;`I$y 6]]}
|/ (()!!0)f/x /part1
|//(()!!0)f\x /part2
