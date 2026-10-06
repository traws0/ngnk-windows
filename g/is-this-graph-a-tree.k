#!/../k
/ https://codegolf.stackexchange.com/questions/251191/is-this-graph-a-tree
f:{&//{|/'x*\:x}/x&~2-/3-/x}

\l 0.k
a:{x|+x:(=|/,/x).[;;:;1]/x-1} /list of edges -> adjacency matrix (with self-loops)
t[a(,1 2)                   ]1
t[a(1 2;2 3;2 4)            ]1
t[a(1 2;2 3;3 4;4 5)        ]1
t[a(1 2;1 3;2 4;2 5)        ]1
t[a(1 3;1 6;1 7;2 3;2 5;4 7)]1
t[a(1 2;3 4)                ]0
t[a(1 2;1 3;2 3;2 4)        ]0
t[a(1 2;1 3;2 3;4 5)        ]0
t[a(1 3;1 5;2 3;3 4;4 5)    ]0
t[a(1 2;3 4;3 5;4 5;4 7;6 7)]0
