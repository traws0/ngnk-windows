#!../k
sub:"../o/w"/"%"\
sh:{$[x:."\\",x: \sub x;x;]}
sh"mkdir -p %"
sh"cc web.c -o %/web"

inl:{("<script>\n",(1:y),"\n</script>")/("<script src=",y,"></script>")\x}
h:"index.html";sub["%/",h]1:1:[h]inl/."\\ls *.js"

{sub["%/",x,".h"]0:","/$0+1:"../",x}'("LICENSE";"repl.k");
