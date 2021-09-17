#!../k
\mkdir -p ../o/w

inl:{("<script>\n",(1:y),"\n</script>")/("<script src=",y,"></script>")\x}
"../o/w/index.html"1:(1:"index.html")inl/."\\ls *.js"

"../o/w/fs.h"0:,/{(,"S C file_",("_"/"."\x),"[]={"),(,/'0N 32#($0+1:"../",x),'","),,"};"}'$`LICENSE`"repl.k"
