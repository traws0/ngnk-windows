#faster builds: export MAKEFLAGS=-j8
F=-nostdlib -ffreestanding -fno-math-errno -fno-stack-protector -fomit-frame-pointer \
 -Werror -Wno-assume -Wno-pointer-sign -Wfatal-errors -Wno-shift-op-parentheses \
 -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast -Wno-constant-conversion -Wno-unused-result
O=-O3 -march=native
MD= >/dev/null mkdir -pv
STRIP ?= strip

t:k #test
	@+$(MAKE) -sC t && g/0.sh && $(MAKE) -sC a19 && $(MAKE) -sC a20 && $(MAKE) -sC e
c: #clean
	@rm -rfv k libk.so web/k.wasm k32 o t/t web/web
w: #wasm
	@cd web && ./a.sh
W: #web server
	@cd o/wasm && ./web
.PHONY: t c w W

o/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o && $(CC) $(F) -c $(O) $< -o $@
o/%.s:%.c *.h makefile
	@echo    '$@ ' && $(MD) o && $(CC) $(F) -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) $(F) $^ -static -o $@
	@$(STRIP) -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/so && $(CC) $(F) $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) $(F) $(O) $^ -shared -Dshared -o $@

#32bit
C32=$(CC) $(F) -m32
o/32/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/32 && $(C32) -c $< -o $@
k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
