native windows build of [growler/k](https://codeberg.org/growler/k), the maintained fork of [ngn/k](https://codeberg.org/ngn/k).
no msys/cygwin/wsl: `k.exe` needs only `kernel32.dll` and `msvcrt.dll`. passes all tests.

```
need:    gcc or clang targeting x86_64-w64-mingw32 (mingw-w64, w64devkit, winlibs, zig cc), gnu make
build:   make -f win/makefile                 # k.exe + all tests
         make -f win/makefile k.exe           # only k.exe
         make -f win/makefile CC="zig cc -target x86_64-windows-gnu"
test:    make -f win/makefile tu|tr|td|tg|te|ta
clean:   make -f win/makefile c
use:     k.exe repl.k
```

notes:
- k is gnu c: msvc and tcc can't build it
- mingw ships gnu make as `mingw32-make.exe`; copy it to `make.exe`, ahead of any msys `usr\bin` in PATH
- k needs LF files. `win/eol.bat` (run by the makefile) turns off `core.autocrlf` for the clone and re-checks out CRLF files
- `\cmd` runs through `cmd.exe`. no sockets

outside `win/` the port changes four lines: `m.c` (`_WIN64` is LP64 for pointers), `3.c` (`1ull`: `long` is 32-bit), `g/a.k` (quote `"../k"` for cmd), `.gitignore`.

```
win/w.h                               posix for mingw-w64: constants, prototypes, pipe open fstat kill wait4 -> windows
win/w.c                               mmap dlopen fork(CreateProcess, #!, /bin/sh->cmd) dirs, msvcrt sin cos exp log
win/sys/ netinet/ arpa/ dlfcn.h       one-line stubs including w.h (-Iwin)
win/eol.bat                           keep LF line endings
win/makefile                          build and tests
win/gdi/                              ffi example
```

## ffi

`` `"lib.dll"2:(`f;n) `` loads `K f(K..)` (n=1..8) from a dll. the dll uses the `k.h` api, which
`k.exe` exports (`-Wl,--export-all-symbols,--out-implib,o/win/libk.a`):

```
gcc -I. -shared lib.c -o lib.dll -Lo/win -lk
```

`win/gdi/gdi.c` is a window library:

```
win[w;h;scale;title]   open a window showing a w*h image
draw c                 paint w*h ints 0xrrggbb, then poll
poll 0                 events: (open;mouse x;mouse y;buttons;key;ms)
glsl s                 compile a glsl fragment shader (uniforms frame size mouse)
shade t                draw frame t with it, then poll
vcos x  vsin x         simd cos sin
```

`win/gdi/gdi.k`, a gradient with a disc following the mouse:

```k
L:`"o/win/gdi.dll";win:L 2:(`win;4);draw:L 2:(`draw;1);poll:L 2:(`poll;1)
w:320;h:240;i:!w*h;X:w!i;Y:_i%w
fr:{[t;e]c:(65536*256!X+t)+(256*256!Y+2*t)+64+191*0<e 3
 d:((X-e 1)*X-e 1)+(Y-e 2)*Y-e 2;c|16777215*d<400}
{*x>27=x 4}{draw fr[_0.06*x 5;x]}/win[w;h;2;"k gdi - esc to quit"];
```

```
make -f win/makefile gdi
```

### reticulum

"reticulum" from [special k](https://beyondloom.com/tools/specialk.html), twice.

`win/gdi/reticulum.k`: the shader as k array code, all pixels per step, on the cpu (200x200 shown 3x).

```k
f:{[t;x;y;z]z:z-t*0.01;c:C a:z*0.1;s:S a
 p:((x*c)+y*s;(y*c)-x*s;z);0.1-N(C 2#p)+S 1_p}
fr:{p:32{y+D*\:f[x]. y}[x]/0 0 0
 256/_255*0|1&(2 5 9+S p)%\:N p}
```

```
make -f win/makefile reticulum
```

![reticulum, k on the cpu](win/gdi/reticulum-cpu.png)

`win/gdi/reticulum-gl.k`: the glsl special k compiles it to, through `opengl32.dll` on the gpu (600x600).

```
make -f win/makefile reticulum-gl
```

![reticulum, glsl on the gpu](win/gdi/reticulum-gl.png)
