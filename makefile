#faster builds: export MAKEFLAGS=-j8
MD=mkdir -p $(@D)
STRIP ?= strip
O=@opts

t:k o/t;o/t;g/0.sh;a19/a.sh;a20/a.sh;e/a.sh #test
c:;rm -rf o k k-libc libk.so k32 k-obsd #clean
w:k o/w/fs.h o/w/k.wasm o/w/index.html
h:w o/w/http;cd o/w;./http
.PHONY: t c w h

O_DFLT=$(O) -O3 -march=native -nostdlib -ffreestanding
o/dflt/%.o:%.c *.h;$(MD);$(CC) $(O_DFLT) -o $@ -c $<
k:$(patsubst %.c,o/dflt/%.o,$(wildcard *.c));$(CC) $(O_DFLT) -o $@ $^;$(STRIP) -R .comment $@ -R '.note*';ls -l $@

O_LIBC=$(O) -O3 -march=native -Dlibc
o/libc/%.o:%.c *.h;$(MD);$(CC) $(O_LIBC) -o $@ -c $<
k-libc: $(patsubst %.c,o/libc/%.o,$(wildcard *.c));$(CC) $(O_LIBC) -o $@ $^ -lm;ls -l $@

O_OBSD=$(O) -fPIC -Dlibc=1 -DSYS_getcwd=304 -Dstrchrnul=strchr
o/obsd/%.o:%.c *.h;$(MD);$(CC) $(O_OBSD) -o $@ -c $<
k-obsd: $(patsubst %.c,o/obsd/%.o,$(wildcard *.c));$(CC) $(O_OBSD) -o $@ $^ --static -fno-pie -lm -lc

O_LIBK=$(O) -O3 -march=native -nostdlib -ffreestanding -fPIC -Dshared
o/libk/%.o:%.c *.h;$(MD);$(CC) $(O_LIBK) -o $@ -c $<
libk.so:$(patsubst %.c,o/libk/%.o,$(wildcard *.c));$(CC) $(O_LIBK) -o $@ $^ -shared

o/t:t/t.c;$(CC) $< -o $@ -Wall -Wno-unused-result -Werror
o/asm/%.s:%.c *.h;$(MD);$(CC) $(O_DFLT) -c $< -o $@ -S -masm=intel

#/usr/lib/llvm-10/bin/wasm-ld must be on $PATH
O_WASM=$(O) -Oz -nostdlib -ffreestanding --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -I/usr/include
o/w/%.o:%.c *.h o/w/fs.h;$(MD);clang $(O_WASM) -o $@ -c $<
o/w/k.wasm0:$(patsubst %.c,o/w/%.o,$(wildcard *.c));clang $(O_WASM) -o $@ $^\
 -Wl,--export=main,--export=kinit,--export=rep,--export=open,--export=close,--export=write\
 -Wl,--export=__heap_base,--no-entry,--initial-memory=33554432,--allow-undefined
o/w/k.wasm:o/w/k.wasm0;wasm-opt -Oz $< -o $@ && ls -l $@
o/w/fs.h:repl.k LICENSE|k w/fs.k;$(MD);./k w/fs.k $^ >$@
o/w/index.html:w/index.html|k w/inl.k w/*.js;$(MD);cd w && ./inl.k index.html *.js >../$@ && cd -
o/w/http:w/http.c;$(MD);$(CC) $< -o $@

# C32=$(CC) $(O) -m32
# o/32/%.o:%.c *.h
# 	@echo -n '$< ' && mkdir -p o/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c));$(C32) $^ -static -o $@ -lgcc
