#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[51][51];
int ss[51][51];
int sn[255];
int visited[51][51];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

queue<pair<int, int>>q;

int n, m;
int maxSize = 1;
int cmax = 1;


int cnt = 0;
void bfs(int x, int y,int num) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		cnt++;
		ss[kx][ky] = num;
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx<1 || ny<1 || nx >m || ny>n) continue;
			if (visited[nx][ny] == 1) continue;
			if (arr[kx][ky] & (1 << i)) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

void cbfs(int x, int y,int num) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx<1 || ny<1 || nx >m || ny>n) continue;
			if (visited[nx][ny] == 1 && ss[nx][ny]==num) continue;
			if (ss[nx][ny] == num) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
			else {
				cmax = max(cmax, sn[num]+sn[ss[nx][ny]]);
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>arr[i][j];
		}
	}
	int roomCnt = 0;
	int t = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				cnt = 0;
				roomCnt++;
				bfs(i, j,t);
				maxSize = max(maxSize, cnt);
				sn[t] = cnt;

				t++;

			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] == 0) {
				cbfs(i, j,ss[i][j]);
			}
		}
	}

	
	cout << roomCnt << '\n';
	cout << maxSize << '\n';
	cout << cmax << '\n';
}