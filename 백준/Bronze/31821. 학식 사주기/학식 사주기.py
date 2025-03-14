N = int(input())
menu = [int(input()) for _ in range(N)]
result = 0

M = int(input())
for _ in range(M):
    eatMenu = int(input())
    result += menu[eatMenu - 1]

print(result)