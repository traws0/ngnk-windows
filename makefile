t:k
	@stat -csize:%s k && echo 'testing' && ./k t.k && g/0.sh
k:
	@echo -n
.PHONY: t k
