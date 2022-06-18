#!/bin/sh

make -C .. -j 12 all

for f in `find files -print`
do
	echo ../fdf $f 1920 1080
	../fdf $f 1920 1080
done
