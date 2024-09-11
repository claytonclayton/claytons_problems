#!/bin/bash

# Run from task directory after running bash ../gen-output.sh
# Usage example: bash ../check.sh

# Description: Tests all solutions in solutions/accepted against
# expected output. Green for AC, red for WA, yellow for TLE. 

time_limit=1

i=1
names=()
ex=()
for sol in solutions/accepted/*; do
    run_solution=./solution

    if [[ $sol == *.cpp ]]; then
        g++ -O2 -std=c++17 $sol -o $i
        ex+=(./$i)
    elif [[ $sol == *.c ]]; then
        gcc -O2 -lm $sol -o $i
        ex+=(./$i)
    elif [[ $sol == *.py ]]; then
        ex+=("python3 $sol")
    else
        echo "unsupported file extension"
        continue
    fi

    short=${sol#solutions/accepted/}
    short=${short%.*}
    names+=($short)
    ((i++))
done

check() {
    x=$1
    name=$2
    file=$3
    expected=$4

    actual=$(timeout $time_limit $x < $file)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        printf "\033[1;33m$name\033[0m "
    elif diff -wq $expected <(echo $actual) > /dev/null; then
        printf "\033[1;32m$name\033[0m "
    else
        printf "\033[1;31m$name\033[0m "
    fi

}

for file in $(find data -name "*.in" | sort); do
    expected=${file%in}out
    short=${file#"data/"}
    short=${short%.in}
    echo -n $short ""

    for i in ${!names[@]}; do
        check "${ex[$i]}" "${names[$i]}" $file $expected
    done
    echo ""
done

for i in "${ex[@]}"; do
    if [[ $i =~ ^\./ ]]; then
        rm ${i#./}
    fi
done