#!/usr/bin/env python3

n = int(input())
lengths = list(map(int, input().split())) # Shouldn't be needed for python

meriam = dict()
for _ in range(n):
    line = list(input().split())
    word = line[0][:-1]
    meaning = line[1:]
    meriam[word] = meaning

words = list(meriam.keys())
graph = dict()
for word in words:
    graph[word] = []
    meaning = meriam[word]
    for mword in meaning:
        if mword in words:
            graph[word].append(mword)

unknown = words[:]
change = True
while change:
    newuk = []
    for uk in unknown:
        requires = graph[uk]
        newreqs = []
        for require in requires:
            if require in unknown:
                newreqs.append(require)
        graph[uk] = newreqs[:]
        if len(newreqs) > 0:
            newuk.append(uk)

    if newuk == unknown:
        change = False
    unknown = newuk[:]

print(n - len(unknown))