#!/bin/sh
cd "$(dirname "$0")"
for f in ??*.k; do
 ( ../k $f || echo "exit code $?" ) | grep -v '^`ok$' | sed "1i\\
$f"
done
:
