#faster builds: export MAKEFLAGS=-j8
O=-O3 -march=native
MD= >/dev/null mkdir -pv
STRIP ?= strip

t:k #test
	@+$(MAKE) -sC t && g/0.sh && a19/a.sh && a20/a.sh && e/a.sh
c: #clean
	@rm -rfv _ k libk.so k32 t/t
w: #wasm
	@cd w && ./a.k
W: #web server
	@cd _/w && ./web
.PHONY: t c w W

_/%.o:%.c *.h makefile opts
	@echo -n '$< ' && $(MD) _ && $(CC) @opts -c $(O) $< -o $@
_/%.s:%.c *.h makefile opts
	@echo    '$@ ' && $(MD) _ && $(CC) @opts -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,_/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) @opts $^ -static -o $@ -lm
	@$(STRIP) -R .comment $@ # -R '.note*'

#lib
_/so/%.o:%.c *.h makefile opts
	@echo -n '$< ' && $(MD) _/so && $(CC) @opts $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,_/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(CC) @opts $(O) $^ -shared -Dshared -o $@

# #32bit
# C32=$(CC) @opts -m32
# _/32/%.o:%.c *.h makefile o
# 	@echo -n '$< ' && $(MD) _/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,_/32/%.o,$(wildcard *.c))
# 	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
