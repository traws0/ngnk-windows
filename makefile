#faster builds: export MAKEFLAGS=-j8
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
	@echo -n '$< ' && $(MD) o && $(CC) @opts -c $(O) $< -o $@
o/%.s:%.c *.h makefile
	@echo    '$@ ' && $(MD) o && $(CC) @opts -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) @opts $^ -static -o $@
	@$(STRIP) -R .comment $@ # -R '.note*'

#lib
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/so && $(CC) @opts $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) @opts $(O) $^ -shared -Dshared -o $@

#32bit
C32=$(CC) @opts -m32
o/32/%.o:%.c *.h makefile
	@echo -n '$< ' && $(MD) o/32 && $(C32) -c $< -o $@
k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
