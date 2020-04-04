t:
	$(MAKE) -C ..
	@time ../k e.k | tee /proc/self/fd/2 | diff -c1 o - && echo ok
.PHONY: t
