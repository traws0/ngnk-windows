t:
	$(MAKE) -C ..
	@time ../k a.k | tee /proc/self/fd/2 | diff -c1 r.txt - && echo ok
.PHONY: t
