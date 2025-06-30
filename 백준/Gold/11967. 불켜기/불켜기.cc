#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int arr[101][101];
pair<int,int> karr[101][101];
int ch[101][101];
int visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;
int n, m;
int check = 0;

queue<pair<int, int>>q;
vector<pair<int, int>>v[101][101];

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (ch[cx][cy] == 0) {
			ch[cx][cy] = 1;
			for (int i = 0;i < v[cx][cy].size();i++) {
				int kx = v[cx][cy][i].first;
				int ky = v[cx][cy][i].second;
				arr[kx][ky] = 1;
				check = 1;
			}
		}
		
		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == 1) continue;
			if (arr[nx][ny] == 0) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	arr[0][0] = 1;

	for (int i = 0;i < m;i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x-1][y-1].push_back({ a-1,b-1 });
	}

	while (true) {
		check = 0;
		bfs(0, 0);
		if (check == 0) break;
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (arr[i][j] == 1) ans++;
		}
	}
	cout << ans << '\n';
}