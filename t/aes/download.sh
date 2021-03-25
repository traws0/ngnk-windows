#!/bin/sh
#please run this script to download test data for aes
z="kat_aes.zip"
curl "https://csrc.nist.gov/csrc/media/projects/cryptographic-algorithm-validation-program/documents/aes/$z" >$z
want=0xa203b16c9246b2ebae31dee5de21a606be80cf78ceabaca37150236fa098eb60
got=$(../../k <<EOF
\`sha2@1:"$z"
\\\\
EOF
)
if [ $got != $want ]; then
 echo "ERROR: $z checksum did not match.
got  $got
want $want"; exit 1
fi
unzip $z -d kat
