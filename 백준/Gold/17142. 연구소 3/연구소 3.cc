#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[51][51];
int arr1[51][51];
int n, m;
int s = 0;

queue<pair<int, int>>q;
queue<pair<int, int>>sq;

struct virus {
	int x, y;
};
virus Vi[11];
int vivi[51][51];
int visited[51][51];
int dis[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int minCnt = 2501;
int maxCnt = -1;

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

			if (kx <= 0 || ky <= 0 || kx > n || ky > n) continue;
			if (visited[kx][ky]) continue;
			if (arr1[kx][ky] == 0) {
				arr1[kx][ky] = -1;
				dis[kx][ky] = dis[nx][ny] + 1;
				maxCnt = max(maxCnt, dis[kx][ky]);
				sq.push({ kx,ky });
			}
			if (arr1[kx][ky] == 2 && vivi[kx][ky] == 0) {
				dis[kx][ky] = dis[nx][ny] + 1;
				sq.push({ kx,ky });
			}

		}
	}
}


void dfs(int x, int cnt) {
	if (x==s+1) return;
	if (cnt == m) {
		maxCnt = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 2 && visited[i][j] == 0 && vivi[i][j] == 1) {
					bfs(i, j);
				}
			}
		}
		while (!sq.empty()) {
			int nx = sq.front().first;
			int ny = sq.front().second;
			sq.pop();
			bfs(nx, ny);
		}

		int check = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr1[i][j] == 0) {
					check = 0;
				}
                arr1[i][j]=arr[i][j];
			}
		}
		if (check == 1) {
			minCnt = min(minCnt, maxCnt);
		}
		memset(dis, 0, sizeof(dis));
		memset(visited, 0, sizeof(visited));
		return;
	}
		vivi[Vi[x].x][Vi[x].y] = 1;
		dfs(x + 1, cnt + 1);
		vivi[Vi[x].x][Vi[x].y] = 0;
		dfs(x + 1, cnt);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int checkp = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) checkp = 0;
			arr1[i][j] = arr[i][j];
			if (arr[i][j] == 2) {
				Vi[s].x = i;
				Vi[s].y = j;
				s++;
			}
		}
	}
	if (checkp == 1) cout << 0 << '\n';
	else {
		dfs(0, 0);
		if (minCnt == 2501) { cout << -1 << '\n'; }
		else {
			cout << minCnt << '\n';
		}
	}
}