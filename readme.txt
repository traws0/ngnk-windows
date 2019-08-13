x86_64 linux only
usage: ulimit -v 1000000 && rlwrap ./k repl.k  # ulimit is to prevent accidents like swap-freeze
mostly compatible with a subset of k5/k6
each of a unary verb doesn't require a colon. *'x and *:'x are "first each" but *' in isolation remains "times each"
no prototype in empty generic lists (not sure which is better)
flip always returns a list of lists. +0 is +,0 is ,,0
