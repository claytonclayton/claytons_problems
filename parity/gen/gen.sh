# Run from gen directory
# Usage example: sh gen.sh

mkdir -p ../data/random

echo "Generating inputs"
g++ -std=c++17 -O2 -o random random.cpp

rm ../data/random/*

i=1
path=../data/random/case

# alternating folds
# yes instances
# small
./random 2 1 0 > $path-$i.in && ((i++))
./random 3 1 0 > $path-$i.in && ((i++))
./random 4 1 0 > $path-$i.in && ((i++))
./random 5 1 0 > $path-$i.in && ((i++))
./random 6 1 0 > $path-$i.in && ((i++))

# big
./random 10 1 0 > $path-$i.in && ((i++))
./random 15 1 0 > $path-$i.in && ((i++))
./random 20 1 0 > $path-$i.in && ((i++))

# no instances
# small
./random 2 1 0.5 > $path-$i.in && ((i++))
./random 3 1 0.5 > $path-$i.in && ((i++))
./random 4 1 0.5 > $path-$i.in && ((i++))
./random 5 1 0.5 > $path-$i.in && ((i++))
./random 6 1 0.5 > $path-$i.in && ((i++))

# big
./random 10 1 0.1 > $path-$i.in && ((i++))
./random 15 1 0.1 > $path-$i.in && ((i++))
./random 20 1 0.1 > $path-$i.in && ((i++))

rm random

echo "Generating outputs"
bash ../../gen-output.sh ../solutions/alt.cpp

