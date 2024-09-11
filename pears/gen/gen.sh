#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp

./random 1 0 0 > data/random/sub1-01.in
./random 1 0 1 > data/random/sub1-02.in
./random 1 1 0 > data/random/sub1-03.in
# for sub1-04.in manually increment k from sub1-03
./random 2 0 0 > data/random/sub2-01.in
./random 2 0 1 > data/random/sub2-02.in
./random 2 1 0 > data/random/sub2-03.in
# for sub2-04.in manually increment k from sub2-03
./random 3 0 0 > data/random/sub3-01.in
./random 3 0 1 > data/random/sub3-02.in
./random 3 1 0 > data/random/sub3-03.in
# for sub3-04.in manually increment k from sub3-03

rm random

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton/sub3-closed-form.cpp

