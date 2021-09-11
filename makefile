#faster builds: export MAKEFLAGS=-j8
O=-O3 -march=native
MD= >/dev/null mkdir -pv
STRIP ?= strip

t:k _/t #test
	@cd t/ && echo 'unit tests' && ../_/t && cd -
	@g/0.sh
	@a19/a.sh
	@a20/a.sh
	@e/a.sh
w:k #wasm
	cd w && ./a.k
h:w #http server
	cd _/w && ./web
c: #clean
	rm -rfv _ k libk.so k32 t/t
.PHONY: t c w h

_/%.o:%.c *.h makefile opts
	@mkdir -p _
	$(CC) @opts -c $(O) $< -o $@
_/%.s:%.c *.h makefile opts
	@mkdir -p _
	$(CC) @opts -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,_/%.o,$(wildcard *.c))
	$(CC) @opts $^ -o $@
	$(STRIP) -R .comment $@ -R '.note*'

_/t:
	$(CC) t/t.c -o $@ -Wall -Wno-unused-result -Werror

_/so:
	mkdir -p _/so
_/so/%.o:%.c *.h makefile opts _/so
	$(CC) @opts $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,_/so/%.o,$(wildcard *.c))
	$(CC) @opts $(O) $^ -shared -Dshared -o $@

# #32bit
# C32=$(CC) @opts -m32
# _/32/%.o:%.c *.h makefile o
# 	@echo -n '$< ' && $(MD) _/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,_/32/%.o,$(wildcard *.c))
# 	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
