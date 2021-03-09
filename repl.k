#!k
1"ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE\n";
repl.h:(": SET|dex  RETURN     ' each|slide|bin"
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
repl.fmt:{$[x~(::);"";(`A~@x)&1<#x;"(",("\n "/`k'x),")\n";`k[x],"\n"]}
repl.rep:{` 1:," ";x:0:"";$[~#x;:0;];x:-1_x;$[(x~,"\\")|x~"\\h";:#` 0:repl.h;];.[{` 1:repl.fmt[. x]};,x;`e@];1}
{x}repl.rep/1;
\\
