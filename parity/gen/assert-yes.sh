
for i in $(seq 1 16); do
    echo -n $i "- " 
    echo $(head -1 ../data/random/case-$i.out) 
done
