#!/bin/bash

FILES=`cat filelist-generic`
ZIPFILEBASE=config-v0.2-generic

mkdir -p stage/$ZIPFILEBASE

for file in $FILES; do
    BASE=`dirname $file`
    mkdir -p stage/$ZIPFILEBASE/$BASE
    cp $file stage/$ZIPFILEBASE/$file
done

cd stage 
rm -f $ZIPFILEBASE.zip
zip -r $ZIPFILEBASE.zip $ZIPFILEBASE

