#!/bin/sh
echo 'codegolf tests'
cd "$(dirname "$0")"
for f in ??*.k; do
 echo -n .
 ( ../k $f || echo "exit code $?" ) | grep -v '^`ok$' | sed "1i\\
$f"
done
echo
:
