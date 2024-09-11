#!/bin/bash

for i in ../data/random/[0-9][0-9].out; do
    echo -n $i | sed -E "s|(.*)m/(.*)|\2|"
    if [ $(head -1 $i) == "YES" ]; then
        echo ": YES"
    else
        echo ": NO"
    fi
done
