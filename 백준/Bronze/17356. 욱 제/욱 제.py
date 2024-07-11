a, b = map(float, input().split())
M = (b-a) / 400
res = 1 / (1 + 10**M)
print(res)