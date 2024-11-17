#include <iostream>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int arr[5][5];
int visited[5][5];

int r, c, k;
int ans = 0;

void bfs(int x, int y, int d) {
	if (d > k) return;
	if (d == k && x == 0 && y == c - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (arr[nx][ny] == -1) continue;
		if (visited[nx][ny] == 1) continue;
		visited[nx][ny] = 1;
		bfs(nx, ny, d + 1);
		visited[nx][ny] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = -1;
			}
		}
	}
	visited[r - 1][0] = 1;
	bfs(r-1, 0, 1);
	cout << ans;
}