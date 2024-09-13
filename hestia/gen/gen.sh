# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/random

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp

./random 10 1 1 0 2 3 > data/random1/01.in

rm random

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/solution.cpp

