N, M = map(int, input().split())
result = 0

for _ in range(N):
    opinion = input()
    agreeCount = opinion.count("O")
    if agreeCount >= (M // 2) + 1:
        result += 1

print(result)