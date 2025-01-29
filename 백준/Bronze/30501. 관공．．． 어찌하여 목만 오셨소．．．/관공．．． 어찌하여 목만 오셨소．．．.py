import sys
N = int(input())
target = ''
for _ in range(N):
    name = sys.stdin.readline().rstrip()
    if 'S' in name:
        target = name
print(target)