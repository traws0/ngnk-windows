#native windows build, any gnu make (mingw calls it mingw32-make) and gcc or clang:  make -f win/makefile  [CC="zig cc -target x86_64-windows-gnu"]
SHELL=cmd.exe
CC=gcc
O=-O3 -march=native -I. -Iwin
M=@if not exist $(subst /,\,$(@D)) mkdir $(subst /,\,$(@D))
0:k.exe t #default target
#exports the k.h api to ffi dlls (see win/gdi), which link with o/win/libk.a
k.exe:$(patsubst %.c,o/win/%.o,$(wildcard *.c win/*.c))|eol;$(CC) $O -o $@ $^ -Wl,--export-all-symbols,--out-implib,o/win/libk.a
o/win/%.o:%.c *.h win/*.h;$M
	$(CC) @opts $O -o $@ -c $<
#k needs LF files: undo git core.autocrlf
eol:;@win\eol.bat
o/t.exe:t/t.c o/win/win/w.o;$(CC) -Iwin $^ -o $@ -Wall -Wno-unused-result -Werror

t:tu tr td tg te ta                                          #all tests
tu:k.exe o/t.exe;o\t.exe                     & echo tu  done #unit
tr:k.exe;cd t   && ..\k.exe repltest.k       & echo tr  done #repl
td:k.exe;cd dy  && ..\k.exe a.k              & echo td  done #dyalog
tg:k.exe;cd g   && ..\k.exe a.k              & echo tg  done #codegolf
te:te0 te1 te2                                               #projecteuler
te0:k.exe;.\k.exe l/runparts.k e  1 50       & echo te0 done
te1:k.exe;.\k.exe l/runparts.k e 50 90       & echo te1 done
te2:k.exe;.\k.exe l/runparts.k e 90          & echo te2 done
ta:t15 t16 t17 t18 t19 t20 t21 t22 t23                       #adventofcode
t15:k.exe;.\k.exe l/runparts.k aoc/15        & echo t15 done
t16:k.exe;.\k.exe l/runparts.k aoc/16        & echo t16 done
t17:k.exe;.\k.exe l/runparts.k aoc/17        & echo t17 done
t18:k.exe;.\k.exe l/runparts.k aoc/18        & echo t18 done
t19:k.exe;.\k.exe l/runparts.k aoc/19        & echo t19 done
t20:k.exe;.\k.exe l/runparts.k aoc/20        & echo t20 done
t21:k.exe;.\k.exe l/runparts.k aoc/21        & echo t21 done
t22:k.exe;.\k.exe l/runparts.k aoc/22        & echo t22 done
t23:k.exe;.\k.exe l/runparts.k aoc/23        & echo t23 done

gdi:o/win/gdi.dll;.\k.exe win/gdi/gdi.k                     #graphics demos
reticulum:o/win/gdi.dll;.\k.exe win/gdi/reticulum.k
reticulum-gl:o/win/gdi.dll;.\k.exe win/gdi/reticulum-gl.k
o/win/gdi.dll:win/gdi/gdi.c k.h k.exe;$(CC) -O3 -I. -shared $< -o $@ -Lo/win -lk -lgdi32 -lopengl32 -march=native -fno-trapping-math

c:;if exist o rmdir /s /q o
	if exist k.exe del k.exe
.PHONY: 0 c eol gdi reticulum reticulum-gl t tu tr td tg te te0 te1 te2 ta t15 t16 t17 t18 t19 t20 t21 t22 t23
