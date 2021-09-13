#faster builds: export MAKEFLAGS=-j8
O=-O3 -march=native
MD= >/dev/null mkdir -pv
STRIP ?= strip

t:k o/t #test
	@cd t/ && echo 'unit tests' && ../o/t && cd -
	@g/0.sh
	@a19/a.sh
	@a20/a.sh
	@e/a.sh
w:k #wasm
	cd w && ./a.k
h:w #http server
	cd o/w && ./web
c: #clean
	rm -rfv o k libk.so k32 k-openbsd
.PHONY: t c w h

o/%.o:%.c *.h makefile opts
	@mkdir -p o
	$(CC) @opts -c $(O) $< -o $@
o/%.s:%.c *.h makefile opts
	@mkdir -p o
	$(CC) @opts -c $(O) $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	$(CC) @opts $^ -o $@
	$(STRIP) -R .comment $@ -R '.note*'
k-openbsd:$(patsubst %.c,o/%.o,$(wildcard *.c))
	$(CC) --static -fno-pie @opts-openbsd $^ -o $@ -lm -lc

o/t: #test runner
	$(CC) t/t.c -o $@ -Wall -Wno-unused-result -Werror

o/so:
	mkdir -p o/so
o/so/%.o:%.c *.h makefile opts o/so
	$(CC) @opts $(O) -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	$(CC) @opts $(O) $^ -shared -Dshared -o $@

# #32bit
# C32=$(CC) @opts -m32
# o/32/%.o:%.c *.h makefile opts
# 	@echo -n '$< ' && $(MD) o/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
# 	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
