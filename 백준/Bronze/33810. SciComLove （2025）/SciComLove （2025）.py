words = "SciComLove"
line = input()
res = 0

for i in range(len(line)):
    if words[i] != line[i]:
        res += 1

print(res)