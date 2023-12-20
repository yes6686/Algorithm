#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[1001][1001];
int ans[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0, 0 };
int n, m;
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 0 || ans[nx][ny] != -1) continue;
			ans[nx][ny] = ans[kx][ky] + 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			ans[i][j] = -1;
			if (arr[i][j] == 2) {
				ans[i][j] = 0;
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << 0 << ' ';
				continue;
			}
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}