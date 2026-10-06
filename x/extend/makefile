# manual steps:
#   go to ../..
#   make c  (for "clean")
#   edit makefile to add "-Wl,-E" to compiler options
#   make k libk.so
#   come back to this directory

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

0:libadd.$(EXT)
	$(LLP)LD_LIBRARY_PATH=../.. ./add.k

libadd.so:add.c
	$(CC) -I../.. -L../.. -shared -fPIC $^ -o $@ -lk

libadd.dylib:add.c
	$(CC) -I../.. -L../.. -shared -fPIC $^ -o $@ -lk -Dshared -undefined dynamic_lookup $(LDFLGS)

.PHONY: c
c:
	$(RM) libadd.dylib* libadd.so
