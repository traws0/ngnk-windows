ngn/k is a simple fast vector programming language
license: GNU AGPLv3 (v3 only) - https://codeberg.org/ngn/k/raw/branch/master/LICENSE

build with "make k-cosm" on wsl and copy the k.com to main windows

that is an attempt to make a working build for Windows using comspolitan libc
included the bestline library from jart since we don't have rlwrap
pagesize had to be changed to avoid errors in mmap

todo:
fix io error when running repl.k
system commands - currently ngn/k calls /bin/sh, have to find an equivalent for windows
