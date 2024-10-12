A, B, C = map(int, input().split())
res = max([A, B, C])*3 - sum([A, B, C])
print(res)