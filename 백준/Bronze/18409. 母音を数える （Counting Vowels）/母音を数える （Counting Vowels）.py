n = int(input())
string = input()
cnt = 0
for i in string:
    if i in ['a', 'e', 'i', 'o', 'u']:
        cnt += 1
print(cnt)