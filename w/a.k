#!../k
\mkdir -p ../o/w

inl:{("<script>\n",(1:y),"\n</script>")/("<script src=",y,"></script>")\x}
"../o/w/index.html"1:(1:"index.html")inl/."\\ls *.js"

e:{$[~^i:"\0\t\r\n\"\\"?x;"\\","0trn\"\\"i;</x<0x207f;x;"\\x",`hex x]}
f:{(,"{.p=\"",x,"\",.n=",($#a),",.a="),("\"",'(,/'e''(0,1+&"\n"=a)_a:1:"../",x),'"\""),,"},"}
"../o/w/fs.h"0:,/f'$`LICENSE`"repl.k";
