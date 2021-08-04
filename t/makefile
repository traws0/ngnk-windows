0+:t
	@echo 'unit tests'
	@./t
	@+$(MAKE) -sC aes
t:t.c makefile
	$(CC) t.c -o t -Wall -Wno-unused-result -Werror
.PHONY:0
