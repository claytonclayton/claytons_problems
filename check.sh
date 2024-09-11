#!/bin/bash

time_limit=1

g++ ../solutions/accepted/clayton.cpp -o clayton
g++ ../solutions/accepted/clayton-graph.cpp -o clayton-graph
frank=../solutions/frank.py

check() {
    x=$1
    file=$2
    expected=$3
    short=${x#"../solutions/"}
    actual=$(timeout $time_limit ./$x < $file)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        printf "\033[1;33m$short\033[0m "
    elif diff $expected <(echo $actual) > /dev/null; then
        printf "\033[1;32m$short\033[0m "
    else
        printf "\033[1;31m$short\033[0m "
    fi
}

for file in $(find ../data -name "*.in" | sort); do
    expected=${file%in}out
    short=${file#"../data/"}
    short=${short%.in}
    echo -n $short ""
    check clayton-graph $file $expected
    check clayton $file $expected
    check $frank $file $expected
    echo ""
done

rm clayton clayton-graph