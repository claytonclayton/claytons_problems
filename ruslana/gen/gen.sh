mkdir -p ../data/random
rm ../data/random/*

handcases=1

to_name() {
    filename=""
    if [ $1 -lt 10 ]; then
        filename+="0"
    fi
    filename+=$1.in
    echo $filename
}

only=../data/only.in

for i in $(seq $((handcases + 1)) 10); do
    filename=../data/random/$(to_name $i)
    cp $only $filename 
done

# not working for some reason
# echo "Generating outputs"
# sh ../../gen-output.sh ../solutions/clayton.cpp

g++ ../solutions/clayton.cpp -o x

for i in ../data/random/*; do
    pref=$(echo $i | sed -E "s/(.*).in/\1/")
    out=$pref.out
    (./x < $i) > $out
done

rm x
