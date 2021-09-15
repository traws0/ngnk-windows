#faster builds: export MAKEFLAGS=-j8
MD = @mkdir -p $(@D)
STRIP ?= strip

t:k o/t #test
	@cd t;../o/t;cd -;g/0.sh;a19/a.sh;a20/a.sh;e/a.sh
w:k #wasm
	cd w; ./a.k; cd -
h:w #http server
	cd o/w; ./web
c: #clean
	rm -rf o k libk.so k32 k-openbsd
.PHONY: t w h c

o/%.o:%.c *.h makefile opts
	$(MD)
	$(CC) @opts -c $< -o $@
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	$(CC) @opts $^ -o $@; $(STRIP) -R .comment $@ -R '.note*'; ls -l $@
k-openbsd:$(patsubst %.c,o/%.o,$(wildcard *.c))
	$(CC) --static -fno-pie @opts-openbsd $^ -o $@ -lm -lc

o/so/%.o:%.c *.h makefile opts
	$(MD)
	$(CC) @opts -c $< -o $@ -fPIC -Dshared
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	$(CC) @opts $^ -shared -Dshared -o $@

o/t:t/t.c #test runner
	$(CC) $< -o $@ -Wall -Wno-unused-result -Werror

o/asm/%.s:%.c *.h makefile opts
	$(MD)
	$(CC) @opts -c $< -o $@ -S -masm=intel

# #32bit
# C32=$(CC) @opts -m32
# o/32/%.o:%.c *.h makefile opts
# 	@echo -n '$< ' && mkdir -p o/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
# 	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
