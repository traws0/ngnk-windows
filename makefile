# faster builds: export MAKEFLAGS=-j8
C=clang-7 -O3 -nostdlib -ffreestanding -fno-unroll-loops -fno-math-errno -fno-stack-protector \
  -Werror -Wno-assume -Wno-pointer-sign -Wno-pointer-to-int-cast -Wfatal-errors -Wno-shift-op-parentheses -march=native
t:k
	@$(MAKE) -C t && g/0.sh
c: #clean
	@rm -rfv k libk.so o t/t
o/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o    >/dev/null && $(C) -c $< -o $@
o/so/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o/so >/dev/null && $(C) -c $< -o $@ -fPIC
o/%.s:%.c *.h makefile
	@echo '$@ ' && mkdir -pv o && $(C) -c $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -static -o $@
	@strip -R .comment $@ # -R '.note*'
libk.so:$(patsubst %.c,o/so/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -shared -Dshared -o $@
.PHONY: t c
