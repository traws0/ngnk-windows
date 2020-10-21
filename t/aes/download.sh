#!/bin/sh
set -e
z=kat_aes.zip
mkdir kat
curl "https://csrc.nist.gov/csrc/media/projects/cryptographic-algorithm-validation-program/documents/aes/$z" >$z
if [ "$(echo "\`sha256@1:\"$z\"\n\\" | ../../k)" != 0xa203b16c9246b2ebae31dee5de21a606be80cf78ceabaca37150236fa098eb60 ]; then
 echo "ERROR: $z checksum did not match"; exit 1
fi
unzip $z -d kat
