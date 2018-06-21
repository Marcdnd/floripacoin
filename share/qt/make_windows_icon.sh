#!/bin/bash
# create multiresolution windows icon
<<<<<<< HEAD
ICON_SRC=../../src/qt/res/icons/bitcoin.png
ICON_DST=../../src/qt/res/icons/bitcoin.ico
convert ${ICON_SRC} -resize 16x16 bitcoin-16.png
convert ${ICON_SRC} -resize 32x32 bitcoin-32.png
convert ${ICON_SRC} -resize 48x48 bitcoin-48.png
convert bitcoin-16.png bitcoin-32.png bitcoin-48.png ${ICON_DST}
=======
ICON_SRC=../../src/qt/res/icons/floripacoin.png
ICON_DST=../../src/qt/res/icons/floripacoin.ico
convert ${ICON_SRC} -resize 16x16 floripacoin-16.png
convert ${ICON_SRC} -resize 32x32 floripacoin-32.png
convert ${ICON_SRC} -resize 48x48 floripacoin-48.png
convert floripacoin-16.png floripacoin-32.png floripacoin-48.png ${ICON_DST}
>>>>>>> upstream/master

