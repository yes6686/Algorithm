#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

char arr[1001][1001];
int fire[1001][1001];
int visited[1001][1001];
int h, w;
int minAns = 1000001;

queue<pair<pair<int, int>, int>>q;
void bfs(int x, int y, int k) {
	q.push({ {x,y},1 });
	visited[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first.first;
		int ky = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
				if (k == 1) { // 상근이
					minAns = min(minAns, cnt + 1);
				}
				continue;
			}
			if (arr[nx][ny] == '#') continue;
			if (visited[nx][ny] == 1) continue;
			visited[nx][ny] = 1;			
			if (k == 1) { // 상그니
				if (fire[nx][ny] > cnt + 1 || fire[nx][ny]==0) {
					q.push({ {nx,ny},cnt + 1 });
				}
			}
			else { // 불
				fire[nx][ny] = fire[kx][ky] + 1;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		cin >> w >> h;
		int sx, sy;
		int firex=-1, firey=-1;

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					sx = i;
					sy = j;
				}
				else if (arr[i][j] == '*') {
					q.push({ {i,j},1 });
					fire[i][j] = 1;
					firex = i;
					firey = j;
					visited[i][j] = 1;
				}
			}
		}

		if(firex!=-1) bfs(firex, firey, 2);
		memset(visited, 0, sizeof(visited));
		bfs(sx, sy, 1);

		if (minAns == 1000001) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			cout << minAns-1 << '\n';
		}

		minAns = 1000001;
		while (!q.empty()) q.pop();
		memset(arr, 0, sizeof(arr));
		memset(fire, 0, sizeof(fire));
		memset(visited, 0, sizeof(visited));
	}
}