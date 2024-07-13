#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[201][201];

queue<pair<int, int>>q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0, 0 };
int visited[201][201];
int n, k;

void bfs(int x,int y, int num) {
    visited[x][y] = 1;
    q.push({ x,y });

    while (!q.empty()) {
        int kx = q.front().first;
        int ky = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = kx + dx[i];
            int ny = ky + dy[i];
            if (nx <1 || ny < 1 || nx >n || ny >n) continue;
            if (visited[nx][ny] == 1) continue;
            if (arr[nx][ny] == 0) {
                visited[nx][ny] = 1;
                arr[nx][ny] = num;
            }
            else if (arr[nx][ny] == num) {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    int s, x, y;
    cin >> s >> x >> y;
    while (s--) {
        for (int i = 1; i <= k; i++) {
            for (int r = 1; r <= n; r++) {
                for (int c = 1; c <= n; c++) {
                    if (visited[r][c] == 0 && arr[r][c] == i) {
                        bfs(r, c, i);
                    }
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        if (arr[x][y]) {
            cout << arr[x][y];
            return 0;
        }
    }
    cout << arr[x][y];
}