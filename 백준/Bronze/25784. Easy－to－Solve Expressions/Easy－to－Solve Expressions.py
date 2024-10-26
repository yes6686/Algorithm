A, B, C = sorted([*map(int, input().split())])
res = 3
if A + B == C : res = 1
elif A * B == C : res = 2
print(res)