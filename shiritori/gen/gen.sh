#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp

# chain rule broken, no repeats
./random 100 0.10 0 > data/secret/1.in
./random 100 0.01 0 > data/secret/2.in
# chain rule satisfied, no repeats
./random 100 0    0 > data/secret/3.in
./random 100 0    0 > data/secret/4.in
# chain rule broken, repeats
./random 100 0.10 1 > data/secret/5.in
./random 100 0.01 1 > data/secret/6.in
# chain rule satisfied, repeats
./random 100 0    1 > data/secret/7.in

rm random

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp
