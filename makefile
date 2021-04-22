#faster builds: export MAKEFLAGS=-j8
F=-nostdlib -ffreestanding -fno-math-errno -fno-stack-protector \
 -Werror -Wno-assume -Wno-pointer-sign -Wfatal-errors -Wno-shift-op-parentheses \
 -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-constant-conversion
O=-O3 -march=native
MD= >/dev/null mkdir -pv

t:k #test
	@+$(MAKE) -sC t && g/0.sh && $(MAKE) -sC a20
c: #clean
	@rm -rfv k libk.so web/k.wasm k32 o t/t web/web
w:web/k.wasm #wasm web server
	@+$(MAKE) -sC web && echo 'starting web server..' && cd web && ./web
.PHONY: t c w

o/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o && $(CC) $(F) -c $(O) $< -o $@
o/%.s:%.c *.h makefile
	@echo    '$@ ' && $(MD) o && $(CC) $(F) -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) $(F) $^ -static -o $@
	@strip -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/so && $(CC) $(F) $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) $(F) $(O) $^ -shared -Dshared -o $@

#wasm
CW=clang $(F) -O3 --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -Oz -I/usr/include
o/wasm/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/wasm && $(CW) -c $< -o $@
web/k.wasm:$(patsubst %.c,o/wasm/%.o,$(wildcard *.c)) # /usr/lib/llvm-10/bin/wasm-ld should be on $PATH
	@echo '$@ ' && $(CW) $^ -o $@ -Wl,--no-entry,--export=main,--export=kinit,--export=rep,--export=val,--export=aCz,--export=__heap_base,--initial-memory=33554432,--allow-undefined

#32bit
C32=$(CC) $(F) -m32
o/32/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/32 && $(C32) -c $< -o $@
k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
