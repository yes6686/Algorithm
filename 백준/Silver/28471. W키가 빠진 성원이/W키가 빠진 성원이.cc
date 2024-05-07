#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>>q;

int dx[7] = { -1,-1,0,0,1,-1,1 };
int dy[7] = { -1,1,-1,1,-1,0,1 };

int arr[2001][2001];
int visited[2001][2001];
int ans = 0;
int n;
void bfs(int x, int y) {
	visited[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 7; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[nx][ny] == 1 || arr[nx][ny]==1)continue;
			visited[nx][ny] = 1;
			ans++;
			q.push({ nx,ny });

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	int fi, fj;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '#') {
				arr[i][j] = 1;
			}
			else if (s[j] == '.') {
				arr[i][j] = 0;
			}
			else {
				fi = i;
				fj = j;
				arr[i][j] = 2;
			}
		}
	}
	bfs(fi, fj);
	cout << ans;
}