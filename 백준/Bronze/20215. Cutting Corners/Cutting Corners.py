w, h = map(int, input().split())
res = w + h - (w**2 + h**2)**0.5
print(res)