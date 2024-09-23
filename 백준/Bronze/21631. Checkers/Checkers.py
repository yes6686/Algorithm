a, b = map(int, input().split())
if a >= b:
    print(b)
elif a < b and b != 0:
    print(a+1)