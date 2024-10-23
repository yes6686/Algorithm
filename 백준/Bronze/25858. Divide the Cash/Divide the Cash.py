n, d = map(int, input().split())
cnt = [int(input()) for _ in range(n)]
div = sum(cnt)
print(*[int(d * (c / div)) for c in cnt], sep='\n')