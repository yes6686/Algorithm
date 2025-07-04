#include <iostream>
#include <queue>
using namespace std;

char arr[1001][1001];
int visited[1001][1001];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = {-1,0,1,-1,1,-1,0,1 };

queue<pair<int, int>>q1;
queue<pair<int, int>>q2;
vector<pair<int, int>>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w;
	cin >> h >> w;
	for (int i = 0;i < h;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			arr[i][j] = s[j];
			if (arr[i][j] != '.') {
				v.push_back({ i,j });
			}
		}
	}

	int ans = 0;
	
	while (true) {

		for (int i = 0;i < v.size();i++) {
			int cx = v[i].first;
			int cy = v[i].second;
			int cnt = 0;

			for (int j = 0;j < 8;j++) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (arr[nx][ny] == '.') cnt++;
			}

			if (arr[cx][cy] - '0' <= cnt) {
				q1.push({ cx,cy });
				visited[cx][cy] = 1;
			}
		}

		v.clear();

		int check = 0;
		while (!q1.empty()) {
			int cx = q1.front().first;
			int cy = q1.front().second;
			q1.pop();
			arr[cx][cy] = '.';
			for (int i = 0;i < 8;i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (visited[nx][ny] == 1) continue;
				
				if (arr[nx][ny] >= '1' && arr[nx][ny] <= '9') {
					visited[nx][ny] = 1;
					q2.push({ nx,ny });
				}
			}
			check = 1;
		}
		if (check == 0) break;

		while (!q2.empty()) {
			int cx = q2.front().first;
			int cy = q2.front().second;
			q2.pop();
			visited[cx][cy] = 0;
			v.push_back({ cx,cy });
		}

		ans++;

	}
	cout << ans << '\n';
}