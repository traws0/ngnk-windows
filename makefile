t:k
	@echo "size:`stat -c%s k`" "sha1:`sha1sum k|cut -b-40`"
	@$(MAKE) -C t && g/0.sh
k:
	@
.PHONY: t k
