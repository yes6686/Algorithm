#include <iostream>
#include <queue>
using namespace std;

int arr[101][101][101];
int visited[101][101][101];
int dis[101][101][101];
int dh[6] = {0,0,0,0,1,-1};
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};

queue < pair<int,pair<int, int>>>q;
queue < pair<int,pair<int, int>>>sq;

int m, n, h;

int checkp = 0;

int maxCnt = -1;

void bfs(int a, int b, int c) {
	q.push({ a,{b,c} });
	while (!q.empty()) {
		int nh = q.front().first;
		int nx = q.front().second.first;
		int ny = q.front().second.second;
		q.pop();
		if (visited[nh][nx][ny]) continue;
		visited[nh][nx][ny] = 1;
		for (int i = 0; i < 6; i++) {
			int kh = nh + dh[i];
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kh <= 0 || kx <= 0 || ky <= 0 || kh > h || kx > n || ky > m) continue;
			if (arr[kh][kx][ky] == -1)continue;
			if (visited[kh][kx][ky]) continue;
			if (arr[kh][kx][ky] == 0) {
				arr[kh][kx][ky] = 1;
				sq.push({ kh,{kx,ky} });
				checkp = 1;
				dis[kh][kx][ky] = dis[nh][nx][ny] + 1;
			}
			maxCnt = max(maxCnt, dis[kh][kx][ky]);	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> h;
	int cc = 0;
	for (int t = 1; t <= h; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[t][i][j];
				if (arr[t][i][j] == 1) sq.push({ t,{i,j} });

				if (arr[t][i][j] == 0) cc = 1;
			}
		}
	}
	if (cc == 0) {
		cout << 0 << '\n';
	}
	else {
		int check = 1;


		while (!sq.empty()) {
			int a1 = sq.front().first;
			int b1 = sq.front().second.first;
			int c1 = sq.front().second.second;
			sq.pop();
			bfs(a1, b1, c1);
		}

		for (int t = 1; t <= h; t++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (arr[t][i][j] == 0) {
						check = 0;
					}
				}
			}
		}
		if (check == 1)
			cout << maxCnt << '\n';
		else
			cout << -1;

	}
}