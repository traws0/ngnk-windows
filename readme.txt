ngn/k is an implementation from scratch of a subset of k
https://en.wikipedia.org/wiki/K_(programming_language)
proprietary; x86_64 linux only; mostly compatible with a subset of k5/k6

usage: rlwrap ./k repl.k
try it online  https://tio.run/#k-ngn
discuss        https://chat.stackexchange.com/rooms/90748/the-k-tree

examples:
proj. euler    https://bitbucket.org/ngn/k/src/master/e/e.k
codegolf       https://bitbucket.org/ngn/k/src/master/g/
tests          https://bitbucket.org/ngn/k/src/master/t/t.k

each of a unary verb doesn't require a colon. *'x and *:'x are "first each" but *' in isolation remains "times each"
no prototype in empty generic lists (might change later)
flip always returns a list of lists. +0 is +,0 is ,,0
