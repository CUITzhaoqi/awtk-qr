#!/bin/bash

if [ $# -lt 3 ]
	then
	echo "Usage: rename filename src det" 1>&2
	exit 1
fi

filelist=$(find ./ -regex $1)

# echo $filelist

if [ x"" == x$filelist ]
	then
	echo "no file found" >&2
	exit 1
fi

for file in $filelist
do
	# echo $file
	mv $file $(echo $file | tr $2 $3)
	echo "$file rename succeeded"
done

exit 0

