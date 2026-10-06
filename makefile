MAKE:=$(MAKE) MAKEFLAGS=-j8
M=mkdir -p $(@D)
#V=$$(git --no-pager log --pretty=format:"-Dver=\"%H\"" -1)
0:;$(MAKE) k && $(MAKE) t #default target
k:;$(MAKE) a N=$@ R=k O='-O3 -march=native' L='-lm -ldl' #for calling k from dynamic libs, add: L='... -Wl,-E'
libk.so:;$(MAKE) a N=$@ R=$@ O='-march=native -fPIC -Dshared -fvisibility=hidden' L='-lm -ldl -shared'
libk.dylib:;$(MAKE) a N=$@ R=$@ O='-fPIC -Dshared -fvisibility=hidden' L='-lm -ldl -install_name $@ -dynamiclib'
libk.a:;$(MAKE) b N=$@ R=$@ O='-O3 -march=native -ffreestanding -lm -ldl -Dldstatic'
o/$N/%.o:%.c *.h;$M;$(CC) @opts $O $V -o $@ -c $<
o/$N/bin:$(patsubst %.c,o/$N/%.o,$(wildcard *.c));$(CC) $O -o $@ $^ @lopts $L # ;$(STRIP) -R .comment $@ -R '.note*'
a:o/$N/bin;cp o/$N/bin $R
b:$(patsubst %.c,o/$N/%.o,$(wildcard *.c));ar rcs o/$R/libk.a o/$N/*.o && cp o/$N/libk.a $R

o/asm/%.s:%.c *.h;$M;$(CC) -O3 @opts -march=native -nostdlib -ffreestanding -c $< -o $@ -S -masm=intel

#/usr/lib/llvm-17/bin/wasm-ld must be on $PATH
#apt-get install gcc-multilib-x86-64-linux-gnux32
w:k o/w/fs.h o/w/k.wasm.lz4 o/w/index.html $(patsubst w/x/%.k,o/w/x/%.k,$(wildcard w/x/*.k)) #wasm
h:w o/w/http;cd o/w;./http
O_WASM=@opts -Oz -nostdlib -ffreestanding --target=wasm32 -U __SIZEOF_INT128__ -Dwasm -I/usr/x86_64-linux-gnux32/include/
o/w/%.o:%.c *.h o/w/fs.h;$M;clang-17 $(O_WASM) -o $@ -c $<
o/w/k.wasm0:$(patsubst %.c,o/w/%.o,$(wildcard *.c));clang-17 $(O_WASM) -o $@ $^\
 -Wl,--export=main,--export=kinit,--export=kargs,--export=rep,--export=open,--export=close,--export=write,--export=evs\
 -Wl,--export=ggp,--export=ggn\
 -Wl,--export=__heap_base,--no-entry,--initial-memory=33554432,-z,stack-size=8388608,--allow-undefined
o/w/k.wasm:o/w/k.wasm0;wasm-opt -Oz $< -o $@
o/w/k.wasm.lz4:o/w/k.wasm;lz4 -12 <$< >$@
G=ngnk-libs
A=w/$G/audio
$A/%.k:;cd w;git clone --depth 1 https://github.com/gitonthescene/$G.git
o/w/fs.h:repl.k LICENSE w/x/smb.mid $A/midi.k $A/riff.k $A/wav.k|k w/fs.k;$M;./k w/fs.k $^ >$@
o/w/x/%.k:w/x/%.k;$M;ln -f $< $@
o/w/index.html:w/index.html k w/inl.k w/*.js;$M;cd w && ./inl.k index.html *.js >../$@ && cd -
o/w/http:w/http.c;$(CC) $< -o $@

#nyi
O_32=@opts -m32
o/32/%.o:%.c *.h;$M;$(CC) $(O_32) -o $@ -c $<
k32:$(patsubst %.c,o/32/%.o,$(wildcard *.c));$(CC) $(O_32) -o $@ $^ -lgcc -lm -ldl

o/t:t/t.c;$(CC) $< -o $@ -Wall -Wno-unused-result -Werror

t:tu tr td tg te ta                       #all tests
tu:k o/t;o/t               ;echo tu  done #unit
tr:k;cd t;./repltest.k     ;echo tr  done #repl
td:k;cd dy;./a.k           ;echo td  done #dyalog
tg:k;cd g;./a.k            ;echo tg  done #codegolf
te:te0 te1 te2                            #projecteuler
te0:k;l/runparts.k e  1 50 ;echo te0 done
te1:k;l/runparts.k e 50 90 ;echo te1 done
te2:k;l/runparts.k e 90    ;echo te2 done
ta:t15 t16 t17 t18 t19 t20 t21 t22 t23    #adventofcode
t15:k;l/runparts.k aoc/15  ;echo t15 done
t16:k;l/runparts.k aoc/16  ;echo t16 done
t17:k;l/runparts.k aoc/17  ;echo t17 done
t18:k;l/runparts.k aoc/18  ;echo t18 done
t19:k;l/runparts.k aoc/19  ;echo t19 done
t20:k;l/runparts.k aoc/20  ;echo t20 done
t21:k;l/runparts.k aoc/21  ;echo t21 done
t22:k;l/runparts.k aoc/22  ;echo t22 done
t23:k;l/runparts.k aoc/23  ;echo t23 done

c:;rm -rf o k libk.so libk.a libk.dylib #clean
.PHONY: 0 c k w h a t tu td tg te te0 te1 te2 ta t15 t16 t17 t18 t19 t20 t21 t22 t23
