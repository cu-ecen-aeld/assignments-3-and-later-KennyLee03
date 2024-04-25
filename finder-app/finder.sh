#!/bin/sh
filesdir=$1
searchstr=$2

if [ $# -ne 2];
then
    echo "No argument"
    exit 1
fi

if [! -d $filesdir];
then
    echo "$1 is not a directory"
    exit 1
fi

total_file=$(find -L ${filesdir} -type f -printf "%f\n" 2> /dev/null | wc -l)
total_match=$(grep -Rn "${searchstr}" "${filesdir}" 2> /dev/null | uniq | wc -l);

echo "The number of files are ${total_file} and the number of matching lines are ${total_match}."