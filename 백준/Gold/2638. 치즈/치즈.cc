#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[101][101];
int visited[101][101];

queue < pair<int, int>>q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] == 1) continue;
			if (arr[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
			else {
				arr[nx][ny] += 1;
			}
		}
	}
}
int ans = 0;
void solve() {	
	while (1) {
		int check = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] >= 3) {
					arr[i][j] = 0;
				}
				if (arr[i][j] > 0) {
					arr[i][j] = 1;
					check = 1;
				}
			}
		}
		if (check == 0) {
			break;
		}
		bfs(0, 0);
		memset(visited, 0, sizeof(visited));
		ans++;
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
	solve();
	cout << ans;
}