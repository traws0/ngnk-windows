#faster builds: export MAKEFLAGS=-j8
MD = mkdir -p $(@D)
STRIP ?= strip

t:k o/t;o/t;g/0.sh;a19/a.sh;a20/a.sh;e/a.sh #test
c:;rm -rf o k libk.so k32 k-obsd #clean
w:k;cd w;./a.k;cd - #wasm
h:w;cd o/w;./web #http
.PHONY: t c w h

O_DFLT=@opts -O3 -march=native -nostdlib -ffreestanding
o/dflt/%.o:%.c *.h makefile opts;$(MD)            ;$(CC) $(O_DFLT) -o $@ -c $<
k:      $(patsubst %.c,o/dflt/%.o,$(wildcard *.c));$(CC) $(O_DFLT) -o $@ $^;$(STRIP) -R .comment $@ -R '.note*';ls -l $@

O_LIBC=@opts -O3 -march=native -Dlibc
o/libc/%.o:%.c *.h makefile opts;$(MD)            ;$(CC) $(O_LIBC) -o $@ -c $<
k-libc: $(patsubst %.c,o/libc/%.o,$(wildcard *.c));$(CC) $(O_LIBC) -o $@ $^ -lm;ls -l $@

O_OBSD=@opts -fPIC -Dlibc=1 -DSYS_getcwd=304 -Dstrchrnul=strchr
o/obsd/%.o:%.c *.h makefile opts;$(MD)            ;$(CC) $(O_OBSD) -o $@ -c $<
k-obsd: $(patsubst %.c,o/obsd/%.o,$(wildcard *.c));$(CC) $(O_OBSD) -o $@ $^ --static -fno-pie -lm -lc

O_LIBK=@opts -O3 -march=native -nostdlib -ffreestanding -fPIC -Dshared
o/libk/%.o:%.c *.h makefile opts;$(MD)            ;$(CC) $(O_LIBK) -o $@ -c $<
libk.so:$(patsubst %.c,o/libk/%.o,$(wildcard *.c));$(CC) $(O_LIBK) -o $@ $^ -shared

o/t:t/t.c;$(CC) $< -o $@ -Wall -Wno-unused-result -Werror
o/asm/%.s:%.c *.h makefile opts;$(MD)             ;$(CC) $(O_DFLT) -c $< -o $@ -S -masm=intel

# C32=$(CC) @opts -m32
# o/32/%.o:%.c *.h makefile opts
# 	@echo -n '$< ' && mkdir -p o/32 && $(C32) -c $< -o $@
# k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c));$(C32) $^ -static -o $@ -lgcc
