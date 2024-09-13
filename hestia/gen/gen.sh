# Run from task directory
# Usage example: bash gen/gen.sh

FOURTH_ROOT_LLMAX=31600

mkdir -p data/random

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp
g++ -std=c++17 -O2 -o rand_arr gen/rand_arr.cpp

# general test
./random 10 1 1 0 2 3 > data/random/01.in
./random 100 1 1 0 2 3 > data/random/02.in
./random 1000 1 1 0 2 3 > data/random/03.in
./random 10000 1 1 0 2 3 > data/random/04.in

# square numbers
./random 1000 1 1 0 6 > data/random/05.in
./random 10000 1 1 0 6 > data/random/06.in

# squares and ones
./random 1000 1 1 0 1 8 > data/random/07.in
./random 10000 1 1 0 1 8 > data/random/08.in

# only ones
./random 1000 1 1 0 1 > data/random/09.in
./random 10000 1 1 0 1 > data/random/10.in

# ones and randoms
./random 1000 1 1 1 1 > data/random/11.in
./random 10000 1 1 1 1 > data/random/12.in

# ones and fourth_root_llmaxs
./random 1000 1 1 1 1 $FOURTH_ROOT_LLMAX > data/random/13.in
./random 10000 1 1 1 1 $FOURTH_ROOT_LLMAX > data/random/14.in

# random small factors
rand_arr=$(./rand_arr 10 1 100)
./random 1000 1 1 0 $rand_arr > data/random/15.in
./random 10000 1 1 0 $rand_arr > data/random/16.in

# random big factors
rand_arr=$(./rand_arr 10 10000 $FOURTH_ROOT_LLMAX)
./random 1000 1 1 0 $rand_arr > data/random/17.in
./random 10000 1 1 0 $rand_arr > data/random/18.in

# random factors
rand_arr=$(./rand_arr 10 1 $FOURTH_ROOT_LLMAX)
./random 1000 1 1 0 $rand_arr > data/random/19.in
./random 10000 1 1 0 $rand_arr > data/random/20.in

# random array
./random 1000 0 0 1 $rand_arr > data/random/21.in
./random 10000 0 0 1 $rand_arr > data/random/22.in

rm random
rm rand_arr

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/solution.cpp
