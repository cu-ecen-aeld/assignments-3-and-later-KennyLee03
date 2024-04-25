#!/bin/sh

writefile=$1
writestr=$2

if [ $# -ne 2 ]
then
    echo "No argument"
    exit 1
fi
DIR_NAME=$(dirname $1)
mkdir -p ${DIR_NAME}
touch $1
echo $2 > $1