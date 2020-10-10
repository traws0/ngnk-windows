#faster builds: export MAKEFLAGS=-j8
CC=clang-10
C=$(CC) -march=native -O3 -nostdlib \
 -ffreestanding -fno-unroll-loops -fno-math-errno -fno-stack-protector \
 -Werror -Wno-assume -Wno-pointer-sign -Wno-pointer-to-int-cast -Wfatal-errors -Wno-shift-op-parentheses
MD= >/dev/null mkdir -pv

t:k #test
	@+$(MAKE) -C t && g/0.sh
c: #clean
	@rm -rfv k libk.so o t/t
w:k.wasm #wasm web server
	@+$(MAKE) -C web && echo 'staring web server..' && web/web
.PHONY: t c w

o/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o && $(C) -c $< -o $@
o/%.s:%.c *.h makefile
	@echo '$@ ' && $(MD) o && $(C) -c $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -static -o $@ # -lgcc (for 32bit)
	@strip -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/so && $(C) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -shared -Dshared -o $@

#wasm
CW=$(C) --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include
o/wasm/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/wasm && $(CW) -c $< -o $@
k.wasm:$(patsubst %.c,o/wasm/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CW) $^ -o $@ -Wl,--no-entry,--export=init,--export=rep,--export=__heap_base,--initial-memory=33554432,--allow-undefined
