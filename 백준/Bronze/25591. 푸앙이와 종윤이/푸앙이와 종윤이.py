n, m = map(int, input().split())
a = 100 - n
b = 100 - m
c = 100 - (a + b)
d = a * b
q = d // 100
r = d % 100
print(a, b, c, d, q, r)
if d >= 100 :
    print(c + q, r)
else :
    print(c, d)