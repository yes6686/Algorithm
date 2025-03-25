result = []

for _ in range(7):
    seminar, num = input().split()
    result.append([seminar, int(num)])

result.sort(key=lambda x: -x[1])
print(result[0][0])