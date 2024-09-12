#!/bin/bash

g++ solution.cpp -o x
g++ brute_force.cpp -o y 

for file in data/random/*.in; do
    # touch data/random/"${file::-3}".out
    # touch data/random/"${file::-3}"brute.out
    (./x < $file) > "${file::-3}".out
    # (./y < $file) > "${file::-3}brute".out
done