#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m;

int arr[301][301];
int arr1[301][301];
int visited[301][301];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>>q;

void bfs(int x, int y) {
	q.push({ x,y });
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		if (visited[nx][ny]) continue;
		visited[nx][ny] = 1;
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx <= 0 || ky <= 0 || kx > n || ky > m) continue;
			if (visited[kx][ky] || !arr1[kx][ky]) continue;
			q.push({ kx,ky });
			
		}
	}
}


void go(int cnt) {

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = 0;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
				if (arr[nx][ny] == 0) cnt++;
			}
			arr1[i][j] -= cnt;
			if (arr1[i][j] < 0) arr1[i][j] = 0;
		}
	}
	int cc = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr1[i][j] && !visited[i][j]) {
				cc++;
				bfs(i, j);
			}
		}
	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = arr1[i][j];
		}
	}

	if (cc >= 2) {
		cout << cnt << '\n';
		return;
	}
	else if (cc == 1) {
		memset(visited, 0, sizeof(visited));
		go(cnt + 1);
	}
	else {
		cout << 0 << '\n';
		return;
	}


}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			arr1[i][j] = arr[i][j];
		}
	}
	go(1);
}