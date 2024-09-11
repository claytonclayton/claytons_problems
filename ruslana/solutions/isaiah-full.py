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

good = 0
bad = 0
for i in [0,1,2,0,0,0,0,0,0]: # where person 0 ends up
    for j in [0,1,2,1,1,1,1,1,1]: # where person 1 ends up
        for k in [0,1,2,2,2,2,2,2,2]: # where person 2 ends up
            for col0 in cols(i, j, k, 0): # colour of house 0
                for col1 in cols(i, j, k, 1): # colour of house 1
                    for col2 in cols(i, j, k, 2): # colour of house 2
                        if len({col0, col1, col2}) == 3:
                            good += 1/len(cols(i,j,k,0))/len(cols(i,j,k,1))/len(cols(i,j,k,2))
                        else:
                            bad += 1/len(cols(i,j,k,0))/len(cols(i,j,k,1))/len(cols(i,j,k,2))
print(good/(good+bad))