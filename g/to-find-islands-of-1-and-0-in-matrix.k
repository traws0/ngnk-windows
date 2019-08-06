/https://codegolf.stackexchange.com/questions/188874/to-find-islands-of-1-and-0-in-matrix/188881#188881
f:{#?{|/'x*\:x}/2>+/x*x:x-\:'x:(0,#*x)\&,/x}'~:\
\l 0.k
t[(1 1 1 0;1 1 1 0)                ;1 1]
t[(0 0 0 0;1 1 1 1;0 0 0 0;1 1 1 1);2 2]
t[(1 0 0;0 0 0;0 0 1)              ;2 1]
t[(1 1 0;1 0 0)                    ;1 1]
t[(1 1;1 1)                        ;1 0]
