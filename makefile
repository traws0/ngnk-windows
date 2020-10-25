#faster builds: export MAKEFLAGS=-j8
CC=clang-10
C=$(CC) -nostdlib \
 -ffreestanding -fno-unroll-loops -fno-math-errno -fno-stack-protector \
 -Werror -Wno-assume -Wno-pointer-sign -Wno-pointer-to-int-cast -Wfatal-errors -Wno-shift-op-parentheses -Wno-int-to-pointer-cast
MD= >/dev/null mkdir -pv

t:k #test
	@+$(MAKE) -C t && g/0.sh
c: #clean
	@rm -rfv k libk.so k.wasm k32 o t/t
w:k.wasm #wasm web server
	@+$(MAKE) -C web && echo 'staring web server..' && web/web
.PHONY: t c w

o/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o && $(C) -c -g $< -o $@
o/%.s:%.c *.h makefile
	@echo '$@ ' && $(MD) o && $(C) -c -O3 $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -static -o $@
# 	@strip -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/so && $(C) -O3 -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) -O3 $^ -shared -Dshared -o $@

#wasm
CW=$(C) -O3 --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include
o/wasm/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/wasm && $(CW) -c $< -o $@
k.wasm:$(patsubst %.c,o/wasm/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CW) $^ -o $@ -Wl,--no-entry,--export=main,--export=init,--export=rep,--export=__heap_base,--initial-memory=33554432,--allow-undefined

#32bit
C32=$(C) -m32
o/32/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/32 && $(C32) -c $< -o $@
k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
