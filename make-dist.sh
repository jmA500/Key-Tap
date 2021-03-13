#!/bin/bash

FILES=`cat filelist`
ZIPFILEBASE=config-v0.2-special

mkdir -p stage/$ZIPFILEBASE

for file in $FILES; do
    BASE=`dirname $file`
    mkdir -p stage/$ZIPFILEBASE/$BASE
    cp $file stage/$ZIPFILEBASE/$file
done

cd stage 
rm -f $ZIPFILEBASE.zip
zip -r $ZIPFILEBASE.zip $ZIPFILEBASE

