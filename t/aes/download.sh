#!/bin/bash
set -e
z=kat_aes.zip
mkdir kat
curl "https://csrc.nist.gov/csrc/media/projects/cryptographic-algorithm-validation-program/documents/aes/$z" >$z
sha256sum -c sums
unzip $z -d kat
