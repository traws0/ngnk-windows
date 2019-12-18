C=clang-7 -O3 -nostdlib -ffreestanding -fno-unroll-loops -fno-math-errno -Werror -Wunused -Wno-assume -Wfatal-errors # -march=native
t:k
	@echo "size:`stat -c%s k`" "sha1:`sha1sum k|cut -b-40`"
	@$(MAKE) -C t && g/0.sh
c:
	@echo 'cleaning up' && rm -rfv k o t/t
o/%.o:%.c *.h makefile
	@echo -n '$< ' && mkdir -pv o >/dev/null && $(C) -c $< -o $@
o/%.s:%.c *.h makefile
	@echo '$@ ' && mkdir -pv o && $(C) -c $< -o $@ -S -masm=intel
k:$(patsubst %.c,o/%.o,$(wildcard *.c))
	@echo '$@ ' && $(C) $^ -static -o $@
	@strip -R .comment $@ # -R '.note*'
.PHONY: t c
