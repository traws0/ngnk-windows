#!/bin/bash
set -e
z=kat_aes.zip
mkdir kat
curl "https://csrc.nist.gov/csrc/media/projects/cryptographic-algorithm-validation-program/documents/aes/$z" >$z
sha256sum -c <<<"a203b16c9246b2ebae31dee5de21a606be80cf78ceabaca37150236fa098eb60 $z"
unzip $z -d kat
