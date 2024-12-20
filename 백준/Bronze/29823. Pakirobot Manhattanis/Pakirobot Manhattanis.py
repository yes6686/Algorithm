N = int(input())
direction_list = list(input())
x, y = 0, 0
for direction in direction_list:
    if direction == 'E':
        x += 1
    elif direction == 'W':
        x -= 1
    elif direction == 'N':
        y += 1
    elif direction == 'S':
        y -= 1

distance = abs(x) + abs(y)
print(distance)