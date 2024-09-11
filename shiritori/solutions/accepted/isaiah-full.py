N = int(input())
seen = set()
prev = ''
for _ in range(N):
    word = input().strip()
    if (prev and prev[-1] != word[0]) or word in seen:
        print(word)
        exit()
    seen.add(word)
    prev = word
print(-1)