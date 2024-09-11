# Run from task directory
# Usage example: bash gen/gen.sh

mkdir -p data/random

echo "Generating inputs"
g++ -std=c++17 -O2 -o random gen/random.cpp

# sub1 DAGs
./random 20 0.5 0.1 0 > data/random/sub1-01.in
./random 100 0.5 0.1 0 > data/random/sub1-02.in
./random 1000 0.5 0.3 0 > data/random/sub1-03.in
./random 1000 1.0 0.0 0 > data/random/sub1-04.in

# sub1 cycles
./random 10 0.2 0.1 1 > data/random/sub1-05.in
./random 20 0.5 0.1 1 > data/random/sub1-06.in
./random 100 0.5 0.3 5 > data/random/sub1-07.in
./random 1000 0.5 0.3 5 > data/random/sub1-08.in

# sub2 DAGs
./random 10000 0.1 0.1 0 > data/random/sub2-01.in
./random 10000 0.5 0.5 0 > data/random/sub2-02.in
./random 20000 0.1 0.1 0 > data/random/sub2-03.in
./random 20000 0.5 0.5 0 > data/random/sub2-04.in

# sub2 cycles
./random 10000 0.1 0.1 2 > data/random/sub2-05.in
./random 10000 0.5 0.5 5 > data/random/sub2-06.in
./random 20000 0.1 0.1 2 > data/random/sub2-07.in
./random 20000 0.5 0.5 5 > data/random/sub2-08.in

rm random

echo "Generating outputs"
bash ../gen-output.sh solutions/accepted/clayton.cpp

