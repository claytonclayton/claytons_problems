mkdir -p ../data/random

echo "Generating inputs"
g++ -std=c++17 -O2 -o zero zero.cpp
g++ -std=c++17 -O2 -o random random.cpp

# Batch 1: N <= 50
./zero 50 500 1 > ../data/random/case-1_1.in
./random 10 10 1 > ../data/random/case-1_2.in
./random 20 20 0 > ../data/random/case-1_3.in
./random 30 1000000000 1 > ../data/random/case-1_4.in
./random 40 1000000000 1 > ../data/random/case-1_5.in
./random 50 1000000000 1 > ../data/random/case-1_6.in
# Batch 2: N <= 750
./zero 500 5000 1 > ../data/random/case-2_1.in
./random 100 100 1 > ../data/random/case-2_2.in
./random 300 300 0 > ../data/random/case-2_3.in
./random 500 1000000000 1 > ../data/random/case-2_4.in
./random 750 1000000000 1 > ../data/random/case-2_5.in
./random 750 750 1 > ../data/random/case-2_6.in
# Batch 3: N <= 5'000
./zero 5000 50000 1 > ../data/random/case-3_1.in
./random 2500 2500 1 > ../data/random/case-3_2.in
./random 3000 3000 0 > ../data/random/case-3_3.in
./random 4000 1000000000 1 > ../data/random/case-3_4.in
./random 4500 1000000000 1 > ../data/random/case-3_5.in
./random 5000 1000000000 1 > ../data/random/case-3_6.in
./random 5000 1000000000 1 > ../data/random/case-3_7.in
# Batch 4: N <= 200'000
./zero 100000 1000000 1 > ../data/random/case-4_1.in
./random 100000 100000 1 > ../data/random/case-4_2.in
./random 150000 150000 0 > ../data/random/case-4_3.in
./random 175000 1000000000 1 > ../data/random/case-4_4.in
./random 200000 1000000000 1 > ../data/random/case-4_5.in

rm random

echo "Generating outputs"
sh ../../gen-output.sh ../solutions/accepted/noah-full.cpp

