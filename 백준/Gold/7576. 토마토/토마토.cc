#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m;

int arr[1001][1001];
int c[1001][1001];
int sk[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>>q;

int maxCnt = 0;
void bfs() {

	c[q.front().first][q.front().second] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
			if (arr[nx][ny] == -1 || c[nx][ny] != 0 || arr[nx][ny]==1) continue;
			c[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			if (arr[nx][ny] == 0) {
				sk[nx][ny] = sk[kx][ky] + 1;
				maxCnt = max(maxCnt, sk[nx][ny]);
				arr[nx][ny] = 1;
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();
	int check = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j]==0) {
				check = 0;
				break;
			}
		}
		if (check == 0) break;
	}

	if (check) {
		cout << maxCnt << '\n';
	}
	else {
		cout << -1 << '\n';
	}

}