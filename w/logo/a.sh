#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
for n in 16 24 48 128;do
 inkscape k.svg -o k-${n}x${n}.png -w $n
done
