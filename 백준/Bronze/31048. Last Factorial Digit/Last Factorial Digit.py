t = int(input())
for _ in range(t):
    n = int(input())
    temp = 1
    for i in range(1,n+1):
        temp *= i
    print(temp % 10)
