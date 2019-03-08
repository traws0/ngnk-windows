#!/bin/bash
cd "$(dirname "$0")"
for f in ??*.k; do
 ( ulimit -v $((32*1024)) -t 1; ../k $f <<<'' || echo "exit code $?" ) | grep -v '^`ok$' | sed "1 i$f"
done
:
