#include <iostream>
#include <queue>
using namespace std;
string s[101];
int arr[101][101];
int c[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m;

queue < pair<int,pair<int,int>>>qq;
int minCnt = 10001;

void bfs(int x, int y) {
	qq.push(make_pair(1, make_pair(x, y)));

	while (!qq.empty()) {

		int kx1 = qq.front().second.first;
		int kx2 = qq.front().second.second;
		int kx3 = qq.front().first+1;

		qq.pop();
		if (c[kx1][kx2] == 0)
			c[kx1][kx2] = 1;
		else {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int knx = kx1 + dx[i];
			int kny = kx2 + dy[i];
			int knz = kx3;

			if (knx == n && kny == m) {
				minCnt = min(minCnt, knz);
				break;
			}

			if (knx <= 0 || kny <= 0 || knx > n || kny > m) continue;
			if (!arr[knx][kny] ) continue;

			qq.push(make_pair(knz, make_pair(knx, kny)));
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			arr[i + 1][j + 1] = s[i][j] - '0';
		}
	}
	bfs(1, 1);
	cout << minCnt;
}