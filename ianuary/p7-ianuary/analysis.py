
with open('mins', 'r') as f:
    mins = [int(i) for i in f.read().split()[1:]]

prev = -1
runs = []
for i in range(len(mins)):
    if mins[i] == prev:
        runs[-1][1] += 1
    else:
        runs.append([mins[i], 1])

    prev = mins[i]

# runs.sort(key=lambda x: x[1])
# print(runs)
