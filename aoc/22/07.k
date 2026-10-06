#!../../k
x:0:"i/07"
s:,0 /stack: current sizes of ancestors of current directory
t:!0 /total sizes of already visited directories
{$["$ cd .."~x;[t,:-1#s;s::-1_s]
   "$ cd /" ~x;[t,: 1_s;s:: 1#s]
   "$ cd "~5#x;s,:0
   ~"0:"'*x;s+:.*" "\x]}'x;
t,:s
+/(1e5>)#t       /part1
&/((-4e7+*s)>)_t /part2
