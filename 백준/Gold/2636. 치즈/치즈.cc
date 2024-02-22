#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,1,-1 };

queue<pair<int, int>>q;

int n, m;

int cnt = 0;

void bfs(int x, int y) {
	q.push({ x,y });
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || arr[nx][ny]==2) continue;
			visited[nx][ny] = 1;
			if (arr[nx][ny] == 0) {
				q.push({ nx,ny });
			}
			else if(arr[nx][ny]==1) {
				arr[nx][ny] = 2;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int t = 0;
	int preCnt = 0;
	while (1) {
		cnt = 0;
		bfs(0, 0);
		if (cnt == 0) {
			break;
		}
		preCnt = cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 2) arr[i][j] = 0;
			}
		}
		memset(visited, 0, sizeof(visited));
		t++;
	}
	cout << t << '\n' << preCnt << '\n';
}