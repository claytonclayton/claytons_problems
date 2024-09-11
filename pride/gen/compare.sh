
g++ ../solutions/accepted/clayton.cpp -o clayton
# gcc ../solutions/saxon.c -o saxon

for i in ../data/secret/*; do
    diff <(./clayton < $i) <(../solutions/./saxon.py < $i)
done

# rm clayton saxon
