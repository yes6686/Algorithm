#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int arr[51][51];
int dis[51][51];
int visited[51][51];

queue<pair<int, int>>q;
int n, m;
int maxAns = 0;

void bfs(int x, int y) {
	q.push({ x,y });
	memset(visited, 0, sizeof(visited));
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] == 1 || arr[nx][ny]==1) continue;
			visited[nx][ny] = 1;
			if (dis[nx][ny] == 0) {
				dis[nx][ny] = dis[kx][ky] + 1;
			}
			else {
				dis[nx][ny] = min(dis[nx][ny], dis[kx][ky] + 1);
			}
			q.push({ nx,ny });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxAns = max(maxAns, dis[i][j]);
		}
	}
	cout << maxAns;
}
