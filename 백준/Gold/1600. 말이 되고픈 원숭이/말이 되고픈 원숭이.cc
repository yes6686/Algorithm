#include <iostream>
#include <queue>
using namespace std;

int arr[201][201];
int visited[201][201][31];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int hx[8] = { -2,-1,1,2,-2,-1,1,2 };
int hy[8] = { -1,-2,-2,-1,1,2,2,1 };
int minAns = 40001;
int w, h;

queue<pair<pair<int, int>, pair<int, int>>>q;

void bfs(int x, int y, int k) {
	q.push({ {x,y},{0,0} });
	visited[x][y][0] = 1;

	while (!q.empty()) {
		int kx = q.front().first.first;
		int ky = q.front().first.second;
		int cnt = q.front().second.first;
		int u = q.front().second.second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
			if (arr[nx][ny] == 1 || visited[nx][ny][u] == 1) continue;
			visited[nx][ny][u] = 1;
			if (nx == w - 1 && ny == h - 1) {
				minAns = min(minAns, cnt + 1);
				continue;
			}
			q.push({ {nx,ny},{cnt + 1,u} });
		}
		if (k > u) {
			for (int i = 0;i < 8;i++) {
				int nx = kx + hx[i];
				int ny = ky + hy[i];
				if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				if (arr[nx][ny] == 1 || visited[nx][ny][u + 1] == 1) continue;
				visited[nx][ny][u + 1] = 1;
				if (nx == w - 1 && ny == h - 1) {
					minAns = min(minAns, cnt + 1);
					continue;
				}
				q.push({ {nx,ny},{cnt + 1,u + 1} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;
	cin >> h >> w;
	for (int i = 0;i < w;i++) {
		for (int j = 0;j < h;j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0, 0, k);

	if (h == 1 && w == 1) {
		cout << 0 << '\n';
	}else if (minAns == 40001) {
		cout << -1 << '\n';
	}
	else {
		cout << minAns << '\n';
	}
}