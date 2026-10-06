#!../../k
x:-48+0:"i/09"      /input
x:4(+|9,)/x         /surround with 9s
n:#*x               /width
x:,/x               /flatten
h:(1;n;-1;-n)+\:!#x /neighbours
h:0|h&-1+#x         /avoid outdexing

/part1
+/(1+x)*&/x</:x h

/part2
i:a*+\a:~9=x        /enumerate non-9s
c:{a*x|/x h}/i      /connected component ids
c^:0                /remove 0s
k:#'=c              /sizes of connected components
*/k@3#>k            /product of the largest three
