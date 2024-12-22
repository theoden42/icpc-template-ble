#!/usr/bin/env bash

for ((testNum=0;testNum<$4;testNum++))
do
    echo $testNum
    ./$3 > input
    ./$2 < input > outSlow
    ./$1 < input > outWrong
    if !(cmp -s "outWrong" "outSlow")
    then
        echo "Error found!"
        echo "Input:"
        cat input
        echo "Wrong Output:"
        cat outWrong
        echo "Slow Output:"
        cat outSlow
        exit
    fi
done
echo Passed $4 tests
