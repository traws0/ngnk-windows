#!/bin/sh
cd "$(dirname "$0")"
echo 'codegolf tests'
for f in ??*.k; do
 echo -n .
 ( ../k $f || echo "exit code $?" ) | grep -v '^`ok$' | sed "1i\\
$f"
done
echo
:
