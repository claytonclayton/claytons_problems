#!/bin/bash

g++ ../solutions/accepted/clayton.cpp -std=c++11  -o x
g++ generator.cpp -std=c++11 -o g

rm $i ../data/random/*

./g

for i in ../data/random/*.in; do
    (./x < $i) > $(echo $i | sed -E "s/(.*)\.in/\1.out/") 
done

rm x
rm g