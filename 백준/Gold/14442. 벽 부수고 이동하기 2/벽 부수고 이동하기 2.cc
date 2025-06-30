// 벽 부수고 이동하기 2 - BFS + 상태 추적
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[1001][1001];               // 맵 정보
int visited[1001][1001][11];      // 방문 여부 [x][y][남은 벽 부수기]
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, k;
int minAns = 1000001;

// 상태: (x, y), 남은 벽 부수기, 이동 거리
void bfs(int x, int y, int wall, int dist) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {wall, dist}});
    visited[x][y][wall] = 1;

    while (!q.empty()) {
        auto [pos, state] = q.front(); q.pop();
        int cx = pos.first, cy = pos.second;
        int cw = state.first, cd = state.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (nx == n - 1 && ny == m - 1) {
                minAns = min(minAns, cd + 1);
                continue;
            }

            if (arr[nx][ny] == 1 && cw > 0 && !visited[nx][ny][cw - 1]) {
                visited[nx][ny][cw - 1] = 1;
                q.push({{nx, ny}, {cw - 1, cd + 1}});
            }

            if (arr[nx][ny] == 0 && !visited[nx][ny][cw]) {
                visited[nx][ny][cw] = 1;
                q.push({{nx, ny}, {cw, cd + 1}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    if (n == 1 && m == 1) {
        cout << 1 << '\n';
        return 0;
    }

    bfs(0, 0, k, 1);

    cout << (minAns == 1000001 ? -1 : minAns) << '\n';
}