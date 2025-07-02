#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

char arr[101][101];
int visited[101][101];
int key[27];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int h, w;

vector<pair<int, int>>v;
queue<pair<int, int>>q;
int ans = 0;

void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (visited[nx][ny] == 1 || arr[nx][ny]=='*') continue;
			visited[nx][ny] = 1;
			if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z') {
				if (key[arr[nx][ny] - 'A'] == 1) {
					q.push({ nx,ny });
				}
				else {
					v.push_back({ nx,ny });
				}
			}
			else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z') {
				key[arr[nx][ny] - 'a'] = 1;
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == '.') {
				q.push({ nx,ny });
			}
			else {
				ans++;
				q.push({ nx,ny });
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
		cin >> h >> w;
		ans = 0;
		for (int i = 0;i < h;i++) {
			string s;
			cin >> s;
			for (int j = 0;j < s.size();j++) {
				arr[i][j] = s[j];
			}
		}
		string s;
		cin >> s;
		if (s[0] != '0') {
			for (int i = 0;i < s.size();i++) {
				key[s[i] - 'a'] = 1;
			}
		}

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
					if (visited[i][j] == 0) {
						if (arr[i][j] == '.') {
							bfs(i, j);
						}
						else if (arr[i][j] >= 'a' && arr[i][j] <= 'z') {
							key[arr[i][j] - 'a'] = 1;
							bfs(i, j);
						}
						else if (arr[i][j] >= 'A' && arr[i][j] <= 'Z') {
							if (key[arr[i][j] - 'A'] == 1) {
								bfs(i, j);
							}
							else {
								v.push_back({ i,j });
							}
						}
						else if(arr[i][j]=='$') {
							ans++;
							bfs(i, j);
						}
					}
				}			
			}
		}

		while (true) {
			int check = 0;
			for (int i = 0;i < v.size();i++) {
				int x = v[i].first;
				int y = v[i].second;
				if (x == -1 && y == -1) continue;
				if (key[arr[x][y] - 'A'] == 1) {
					v[i] = { -1,-1 };
					bfs(x, y);
					check = 1;
				}
			}

			if (check == 0) {
				break;
			}
		}
		cout << ans << '\n';
		
		memset(key, 0, sizeof(key));
		memset(visited, 0, sizeof(visited));
		while (!v.empty())v.pop_back();
		while (!q.empty()) q.pop();
	}
}