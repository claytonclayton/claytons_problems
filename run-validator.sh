#!/bin/bash
# Run from task directory
# Usage example: bash ../run-validator.sh SUB1

if [ "$#" -lt 1 ]; then
  echo "no subtask flag provided"
  exit 1
fi
g++ -std=c++17 -O2 -o validator -D $1 validator.cpp
for input in $(find data -name "*.in" | sort); do
    printf $input
    printf " "
    if ./validator < $input; then
      printf "\033[1;32mOK\033[0m\n"
    fi
done
rm validator
