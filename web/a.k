#!../k
/ /usr/lib/llvm-10/bin/wasm-ld should be on $PATH
O:"../o/wasm"
X:{ \x;."\\",x;}
X"mkdir -p ",O
X"cp *.html *.js ",O
X"cc web.c -o ",O,"/web"

{(O,"/",x,".h")0:","/$0+a:1:"../",x}'("./LICENSE";"repl.k");

X@,/("clang ../*.c -o ",O,"/k.wasm -O3 --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include @../opts"
 " -Wl,--no-entry",(,/",--export=",/:$`main`kinit`rep`val`aCz`open`close`write`"__heap_base"),",--initial-memory=33554432,--allow-undefined")

."\\ls -l ",O,"/k.wasm"
