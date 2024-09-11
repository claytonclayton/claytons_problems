#!/bin/bash
# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/secret

echo "Generating inputs"
g++ -std=c++17 -O2 -o dag gen/rand-dag.cpp
g++ -std=c++17 -O2 -o line gen/rand-line.cpp

# small sparse fab
./dag 5 1 > data/secret/1.in
./dag 8 1 > data/secret/2.in
./dag 10 1 > data/secret/3.in

# big sparse fab
./dag 50 1 > data/secret/4.in
./dag 70 1 > data/secret/5.in
./dag 100 1 > data/secret/6.in

# small dense fab
./dag 5 10 > data/secret/7.in
./dag 10 10 > data/secret/8.in

# big dense fab
./dag 50 30 > data/secret/9.in
./dag 70 30 > data/secret/10.in
./dag 100 20 > data/secret/11.in

# straight
./line 5 > data/secret/12.in
./line 10 > data/secret/13.in
./line 50 > data/secret/14.in
./line 100 > data/secret/15.in

rm dag line

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp

