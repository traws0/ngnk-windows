0:a makefile
	LD_LIBRARY_PATH=../.. ./a
a:../../libk.so a.c makefile
	$(CC) -L../.. -lk a.c -o a
../../libk.so:../../*.c ../../*.h
	$(MAKE) -C../.. libk.so
