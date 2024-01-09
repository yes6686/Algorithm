#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

string s[26];
int arr[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>>q;
int c[26][26];
int n;
int ch[626];

int blockCnt = 1;

void bfs(int x, int y) {

	q.push(make_pair(x, y));
	c[x][y] = 1;
	while (!q.empty()) {
		int kx = q.front().first;
		int ky = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			if (c[nx][ny] || !arr[nx][ny]) continue;
			q.push(make_pair(nx, ny)); blockCnt++;
			c[nx][ny] = 1;

		}

	}


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			arr[i + 1][j + 1] = s[i][j] - '0';
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j<=n; j++) {
			if (arr[i][j] && !c[i][j]) {
				blockCnt = 1;
				cnt++;
				bfs(i, j);
				ch[cnt - 1] = blockCnt;
			}
		}
	}
	sort(ch, ch + cnt);

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << ch[i] << '\n';
	}



}