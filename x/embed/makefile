OS=mac
ifeq ($(OS), mac)
  EXT=dylib
  LLP=DY
  LDFLGS=-dynamiclib -install_name $@
else
  EXT=so
  LLP=
  LDFLGS=
endif

0:a makefile
	$(LLP)LD_LIBRARY_PATH=../.. ./a

a:../../libk.$(EXT) a.c makefile
	$(CC) -L../.. -lk a.c -o a
astatic:../../libk.a a.c makefile
	$(CC) -static a.c ../../libk.a -o a

liba.so:a.c makefile
	$(CC) -L../.. a.c -o $@ -g -march=native -Dlibc -fPIC -Dshared -undefined -shared

liba.dylib:a.c makefile
	$(CC) -L../.. a.c -o $@ -g -march=native -Dlibc -fPIC -Dshared -undefined dynamic_lookup $(LDFLGS)

../../libk.$(EXT):../../*.c ../../*.h
	$(MAKE) -C../.. $(notdir $@)

../../libk.a:../../*.c ../../*.h
	$(MAKE) -C../.. $(notdir $@)

.PHONY: c
c:
	$(RM) a astatic libadd.dylib* libadd.so
