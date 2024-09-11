import random

def cols(i, j, k, house):
    ans = []
    if i == house and house != 0:
        ans.append(0)
    if j == house and house != 1:
        ans.append(1)
    if k == house and house != 2:
        ans.append(2)
    if len(ans) == 0:
        ans.append((house+1)%3)
    return ans

def colour():
    where0 = random.choice([0,1,2,0,0,0,0,0,0])
    where1 = random.choice([0,1,2,1,1,1,1,1,1])
    where2 = random.choice([0,1,2,2,2,2,2,2,2])
    col0 = random.choice(cols(where0, where1, where2, 0))
    col1 = random.choice(cols(where0, where1, where2, 1))
    col2 = random.choice(cols(where0, where1, where2, 2))
    return col0, col1, col2

tests = 1000000
good = 0
for i in range(tests):
    if len(set(colour())) == 3:
        good += 1
print(good/tests)