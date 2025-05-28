import sys

T = int(input())

for i in range(1, T + 1):
    N = int(sys.stdin.readline())
    A, B = map(int, sys.stdin.readline().split())

    for _ in range(N):
        U, V = map(int, sys.stdin.readline().split())

    print(f'Material Management {i}')
    print('Classification ---- End!')