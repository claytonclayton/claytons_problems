#!/bin/bash

rm $i ../data/random/*
g++ generator.cpp -std=c++17 -o g
./g
rm g

sh ../../gen-output.sh ../solutions/accepted/isaiah-full.cpp
