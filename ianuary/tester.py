
def nc2(i):
    return i * (i - 1) / 2

def get_icount(a):
    twos = 0
    total = 0
    for i in range(len(a)):
        if a[i] == '2':
            twos += 1
        elif a[i] == '4':
            total += nc2(twos)
        else:
            return -1
    return total

print(get_icount('22424'))