#!/bin/bash

if [ "$#" -ne 4 ]; then
    echo "Usage: ./runTest path_to_file min step max"
    exit
fi

path="$1"
min="$2"
step="$3"
max="$4"

for i in `seq $min $step $max`
do
    ./avl $1 $i
done

