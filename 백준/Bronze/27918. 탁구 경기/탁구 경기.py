N = int(input())
dalgoo, ponix = 0, 0
game_record = [input() for _ in range(N)]

for i in game_record:
    if i == "D":
        dalgoo += 1
    else:
        ponix += 1

    if abs(dalgoo - ponix) == 2:
        break
print("{}:{}".format(dalgoo, ponix))