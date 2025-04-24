import sys

n = int(sys.stdin.readline())

menu_list = [sys.stdin.readline().rstrip().split() for _ in range(n)]

for menu in menu_list[0]:
    print(menu)