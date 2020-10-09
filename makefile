#faster builds: export MAKEFLAGS=-j8
C=clang-10 -march=native -O3 -nostdlib \
 -ffreestanding -fno-unroll-loops -fno-math-errno -fno-stack-protector \
 -Werror -Wno-assume -Wno-pointer-sign -Wno-pointer-to-int-cast -Wfatal-errors -Wno-shift-op-parentheses

t:k #test
	@+$(MAKE) -C t && g/0.sh
c: #clean
	@rm -rfv k libk.so o t/t
.PHONY: t c

o/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o    >/dev/null && $(C) -c $< -o $@
o/%.s:%.c *.h makefile
	@echo '$@ ' && mkdir -pv o && $(C) -c $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -static -o $@ # -lgcc (for 32bit)
	@strip -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o/so >/dev/null && $(C) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -shared -Dshared -o $@

#wasm
CW=$(C) --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz
o/wasm/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o/wasm >/dev/null && $(CW) -c $< -o $@
k.wasm:$(patsubst %.c,o/wasm/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CW) $^ -o $@ -Wl,--no-entry,--export=init,--export=rep,--export=__heap_base,--initial-memory=33554432,--allow-undefined
