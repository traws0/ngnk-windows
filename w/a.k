#!../k
sub:"../_/w"/"%"\
sh:{$[x:."\\",x: \sub x;x;]}
sh"mkdir -p %"
sh"cc web.c -o %/web"

inl:{("<script>\n",(1:y),"\n</script>")/("<script src=",y,"></script>")\x}
h:"index.html";sub["%/",h]1:1:[h]inl/."\\ls *.js"

{sub["%/",x,".h"]0:","/$0+1:"../",x}'("LICENSE";"repl.k");

/ /usr/lib/llvm-10/bin/wasm-ld must be on $PATH
sh@,/("clang ../*.c -o %/k0.wasm --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include @../o"
 " -Wl,--no-entry",(,/",--export=",/:$`main`kinit`rep`val`aCz`open`close`write`"__heap_base"),",--initial-memory=33554432,--allow-undefined")
sh"wasm-opt -O3 %/k0.wasm -o %/k.wasm"
sh"ls -l %/k.wasm"
