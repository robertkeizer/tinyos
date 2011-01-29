#!/usr/bin/env bash
if [ ! -d "src/" ] ; then
	echo "Use scripts/clean.sh";
	exit 1;
fi;
for file in `ls build/ | grep -v "^placeholder$"`; do
	rm build/$file;
done;
