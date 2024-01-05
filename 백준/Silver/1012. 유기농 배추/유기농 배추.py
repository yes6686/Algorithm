t = int(input())
dx =[1,-1,0,0]
dy=[0,0,1,-1]

def bfs(x,y):
    queue=[(x,y)]
    arr[x][y]=0
    while queue:
        x,y = queue.pop(0)

        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx <0 or ny<0 or nx>=n or ny>=m :
                continue
            if arr[nx][ny]==1:
                arr[nx][ny]=0
                queue.append((nx,ny))

for i in range(t):
    m,n,k = map(int,input().split())
    arr = [[0]*(m) for _ in range(n)]
    for i in range(k):
        x,y = map(int,input().split())
        arr[y][x]=1

    cnt=0
    for i in range(n):
        for j in range(m):
            if arr[i][j]!=0:
                cnt+=1       
                bfs(i,j)
    print(cnt)