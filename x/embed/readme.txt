Running make in this directory will build and run an executable which embeds the K, interpretter,
installs a function and then calls that installed function.

To dynamically load foreign functions into the K repl, run make liba.so in this directory and run
the REPL with LD_PRELOAD set to that library.

Note for linux, you'll also need to make the
symbols in the REPL dynamic so they can be called from the library.  Add -rdynamic to the end of the
lopts file and rebuild the REPL.

If you're building a target other than the default you'll likely need to build a libk-<target>.so
for that target and adjust the makefile accordingly.
