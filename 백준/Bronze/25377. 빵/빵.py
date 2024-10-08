res = 1001
for _ in range(int(input())) :
    A, B = map(int, input().split())
    if A <= B : res = min(res, B)
print([res, -1][res == 1001])