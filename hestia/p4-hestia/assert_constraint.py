
for i in range(3, 39):
    with open("data/random/"+str(i)+".in", 'r') as f:
        nums = [int(j) for j in f.read().split()[1:]]

    for j in range(len(nums) - 1):
        for k in range(j + 1, len(nums)):
            assert nums[j] * nums[k] <= 10 ** 18, f'{i}, {j}, {k}'
