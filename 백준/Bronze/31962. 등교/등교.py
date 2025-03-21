N, X = map(int, input().split())
busInfo = []
for _ in range(N):
    S, T = map(int, input().split())
    busInfo.append([S, T])

busInfo.sort(key=lambda x: -x[0])

arriveCheck = False
for k, d in busInfo:
    if k + d > X:
        continue
    else:
        arriveCheck = True
        takeTime = k  # 걸리는 시간
        break

if arriveCheck:
    print(takeTime)
else:
    print(-1)