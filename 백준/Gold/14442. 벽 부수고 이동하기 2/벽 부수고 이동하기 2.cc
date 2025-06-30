#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int visited[1001][1001][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k;
int minAns = 1000001;

queue<pair<pair<int, int>, pair<int,int>>>q;

void bfs(int x, int y,int kk,int cnt) {
	q.push({ {x,y},{kk,cnt} });
	visited[x][y][kk] = 1;
	while (!q.empty()) {
		int kx = q.front().first.first;
		int ky = q.front().first.second;
		int kkk = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (kkk == 0 && arr[nx][ny] == 1) continue;
			if (nx == n - 1 && ny == m - 1) {
				minAns = min(minAns, cnt+1);
				continue;
			}
			if (kkk > 0) {
				if (arr[nx][ny] == 1) {
					if (visited[nx][ny][kkk - 1] == 0) {
						visited[nx][ny][kkk-1] = 1;
						q.push({ {nx,ny},{kkk - 1,cnt + 1} });
					}
				}
				else {
					if (visited[nx][ny][kkk] == 0) {
						visited[nx][ny][kkk] = 1;
						q.push({ {nx,ny},{kkk,cnt + 1} });
					}
				}
			}
			else { // kkk==0
				if (visited[nx][ny][kkk] == 0) {
					visited[nx][ny][kkk] = 1;
					q.push({ {nx,ny},{kkk,cnt + 1} });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			if (s[j] == '1') {
				arr[i][j] = 1;
			}
		}
	}

	if (n == 1 && m == 1) {
		cout << 1 << '\n';
		return 0;
	}
	
	bfs(0, 0, k, 1);

	if (minAns == 1000001) {
		cout << -1 << '\n';
	}
	else {
		cout << minAns << '\n';
	}	
}