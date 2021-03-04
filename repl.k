#!k
1"ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE\n";
h:(": SET|dex  RETURN     ' each|slide|bin"
   "+ add      transpose  / fold|join |dec  /      comment"
   "- subtract negate     \\ scan|split|enc  \\      exit"
   "* multiply first     ': eachprior       \\t:n x time"
   "% divide   sqrt      /: eachright       \\l a.k load"
   "! mod|dict enum|key  \\: eachleft        \\w     workspace"
   "& min|and  where                        \\cmd   system"
   "| max|or   reverse                      a \\b   trace"
   "< less     asc       0: lines i/o"
   "> more     desc      1: bytes i/o          !n enum"
   "= equal    group                           !N odometer"
   "~ match    not                            n?x draw"
   ", concat   enlist                        -n?x deal"
   "^ fill|w/o null?                           =n unitmatrix"
   "# reshape  length                        `p@s parse"
   "_ drop|cut floor                         `k@x fmt"
   "$ cast     string    $[c;t;f] COND       `j?s json"
   "? find|rnd uniq                          `t[] time"
   "@ apply(1) type      @[x;i;[f;]y] amend  `e[] printerror"
   ". apply(n) eval      .[x;i;[f;]y] drill  `x@(argv;in) fork")
fmt:`k@
{x}{` 1:," ";$[~#s:0:"";` 1:,"\r";s~"\\h\n";` 0:h;.[{` 0:fmt@.-1_x};,s;`e@]];#s}/1;
\\
