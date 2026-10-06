0:libt.so makefile
LD_LIBRARY_PATH=../..

libt.so:t.c makefile
	$(CC) -L../.. -I../.. t.c -o libt.so -g -march=native -Dlibc -fPIC -Dshared -undefined -shared

libt.dylib:t.c makefile
	$(CC) -L../.. -I../.. t.c -o $@ -g -march=native -Dlibc -fPIC -Dshared -undefined dynamic_lookup -dynamiclib -install_name $@

../../libk.so:../../*.c ../../*.h
	$(MAKE) -C../.. libk.so

../../libk.dylib:../../*.c ../../*.h
	$(MAKE) -C../.. libk.dylib
