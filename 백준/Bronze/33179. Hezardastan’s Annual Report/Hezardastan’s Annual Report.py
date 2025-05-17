n = int(input())
pages = list(map(int, input().split()))
res = 0
for el in pages:
    res += (el + 1) // 2
print(res)