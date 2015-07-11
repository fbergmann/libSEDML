#!/bin/bash
DIRECTORY=$(cd `dirname $0` && pwd)
ASTYLE=astyle

for f in $DIRECTORY/sedml/*.h \
         $DIRECTORY/sedml/*.cpp \
         $DIRECTORY/sedml/common/*.cpp \
         $DIRECTORY/sedml/common/*.h
do
    echo $f
    $ASTYLE \
    --break-blocks  \
    --convert-tabs \
    --indent-preprocessor \
    --indent-switches \
    --indent=spaces=2 \
    --keep-one-line-blocks \
    --keep-one-line-statements \
    --min-conditional-indent=0 \
    --mode=c \
    --pad-header \
    --pad-oper \
    --quiet \
    --style=gnu \
    --suffix=none \
    --unpad-paren \
    $f
done

