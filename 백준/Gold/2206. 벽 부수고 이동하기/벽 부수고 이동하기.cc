#include <iostream>
#include <queue>
using namespace std;

int n, m;
string s[1001];
int arr[1001][1001];
int visited[1001][1001][2];
int dis[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int maxcnt = -1;
int mincnt = 1e9;

queue < pair<pair<int, int>, int>>q;

void bfs(int x, int y) {
	q.push({ { x,y }, 0 });
	while (!q.empty()) {
		int nx = q.front().first.first;
		int ny = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (nx == n && ny == m) {
			mincnt = min(mincnt,dis[nx][ny][cnt]);
			continue;
		}

		if (visited[nx][ny][cnt]) continue;
		visited[nx][ny][cnt] = 1;
		for (int i = 0; i < 4; i++) {
			int kx = nx + dx[i];
			int ky = ny + dy[i];
			if (kx <= 0 || ky <= 0 || kx > n || ky > m) continue;
			if (arr[kx][ky] == 0) {			
				if (visited[kx][ky][cnt] == 0) {
					dis[kx][ky][cnt] = dis[nx][ny][cnt] + 1;
					q.push({ {kx,ky},cnt });
				}
			}
			else {
				if (cnt == 0) {
					if (visited[kx][ky][cnt+1] == 0) {
						dis[kx][ky][cnt+1] = dis[nx][ny][cnt] + 1;
						q.push({ {kx,ky},cnt+1 });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			arr[i + 1][j + 1] = s[i][j]-'0';
		}
	}
	bfs(1, 1);
	if (mincnt == 1e9)cout << -1;
	else
	cout << mincnt+1;

}