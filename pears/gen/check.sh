#!/bin/bash

# cool program that compares the other three clayton solutions against the
# sub3-closed-form solution. appears green if outputs match with 
# sub3-closed, otherwise red. there should be something like this 
# permanently in the github (maybe it exists and i can't find it). 
# please steal this if it can help you

g++ ../solutions/accepted/sub1.cpp -o sub1
g++ ../solutions/accepted/sub2.cpp -o sub2
g++ ../solutions/accepted/sub3-binary-search.cpp -o sub3-binary
g++ ../solutions/accepted/sub3-closed-form.cpp -o sub3-closed

check() {
    x=$1
    file=$2
    expected=$3
    if diff $expected <(./$x < $file) > /dev/null; then
        printf "\033[1;32m$x\033[0m "
    else
        printf "\033[1;31m$x\033[0m "
    fi
}

for file in $(find ../data -name "*.in" | sort); do
    expected=${file%in}out
    short=${file#"../data/"}
    short=${short%.in}
    echo -n $short ""
    case $file in
        *sub1*)
            check sub1 $file $expected
            check sub2 $file $expected
            check sub3-binary $file $expected
            check sub3-closed $file $expected
            echo ""
        ;;

        *sub2*)
            check sub2 $file $expected
            check sub3-binary $file $expected
            check sub3-closed $file $expected
            echo ""
        ;;

        *sub3*)
            check sub3-binary $file $expected
            check sub3-closed $file $expected
            echo ""
        ;;
    esac 
done

rm sub1 sub2 sub3-binary sub3-closed
