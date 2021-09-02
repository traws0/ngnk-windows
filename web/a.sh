#!/usr/bin/env bash
# /usr/lib/llvm-10/bin/wasm-ld should be on $PATH
set -ex
cd $(dirname $0)
O=../o/wasm
mkdir -p $O
./c.k <../LICENSE >$O/LICENSE.h
./c.k <../repl.k  >$O/repl.k.h
cp *.html *.js $O
cc web.c -o $O/web
clang ../*.c -o $O/k.wasm -O3 --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include \
 -nostdlib -ffreestanding -fno-math-errno -fno-stack-protector -fomit-frame-pointer \
 -Werror -Wno-assume -Wno-pointer-sign -Wfatal-errors -Wno-shift-op-parentheses \
 -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-constant-conversion -Wno-unused-result \
 -Wl,--no-entry,--export=main,--export=kinit,--export=rep,--export=val,--export=aCz,--export=open,--export=close,--export=write,--export=__heap_base,--initial-memory=33554432,--allow-undefined
