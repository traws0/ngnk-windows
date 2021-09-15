#faster builds: export MAKEFLAGS=-j8
MD = @mkdir -p $(@D)
STRIP ?= strip

t:k o/t;o/t;g/0.sh;a19/a.sh;a20/a.sh;e/a.sh #test
c:;rm -rf o k libk.so k32 k-openbsd         #clean
w:k;cd w;./a.k;cd -                         #wasm
h:w;cd o/w;./web                            #http
.PHONY: t c w h

o/%.o:%.c *.h makefile opts;$(MD);$(CC) @opts -c $< -o $@
k:$(patsubst %.c,o/%.o,$(wildcard *.c));$(CC) @opts $^ -o $@;$(STRIP) -R .comment $@ -R '.note*';ls -l $@
o/t:t/t.c;$(CC) $< -o $@ -Wall -Wno-unused-result -Werror
k-openbsd:$(patsubst %.c,o/%.o,$(wildcard *.c));$(CC) --static -fno-pie @opts-openbsd $^ -o $@ -lm -lc
o/so/%.o:%.c *.h makefile opts;$(MD);$(CC) @opts-so -c $< -o $@
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c));$(CC) @opts-so -shared $^ -o $@
o/asm/%.s:%.c *.h makefile opts;$(MD);$(CC) @opts -c $< -o $@ -S -masm=intel

# #32bit
# C32=$(CC) @opts -m32
# o/32/%.o:%.c *.h makefile opts
# 	@echo -n '$< ' && mkdir -p o/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c))
# 	@echo '$@ ' && $(C32) $^ -static -o $@ -lgcc
