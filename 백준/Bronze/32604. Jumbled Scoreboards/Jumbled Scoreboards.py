now_t, now_p = -1, -1
flag = True

for _ in range(int(input())):
    a, b = map(int, input().split())

    if not flag:
        continue

    if now_t > a or now_p > b:
        flag = False
        continue

    now_t, now_p = a, b

print("yes" if flag else "no")