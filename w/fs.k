#!../k
/render a given set of files as c string literals for ../0.c
e:{$[~^i:"\0\t\r\n\"\\"?x;"\\","0trn\"\\"i;0x207f'x;"\\x",`hex[,x],"\"\"";x]}
bn:*|"/"\
`0:,/{(,"{.p=\"",bn[x],"\",.n=",($#a),",.a="),("\"",'(,/'e''(0,1+&"\n"=a)_a:1:x),'"\""),,"},"}'x
