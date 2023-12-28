#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
string s[21];
int arr[21][21];
int visited[21][21];
int alpha[51];
int maxCnt = -1;
int r, c;
void dfs(int x, int y,int cnt) {

	if (visited[x][y]) return;
	if (alpha[arr[x][y]]) return;
	visited[x][y] = 1;
	alpha[arr[x][y]] = 1;
	maxCnt = max(maxCnt, cnt);

	for (int i = 0; i < 4; i++) {
		int kx = x + dx[i];
		int ky = y + dy[i];
		if (kx <= 0 || ky <= 0 || kx > r || ky > c) continue;
		if (visited[kx][ky] || alpha[arr[kx][ky]]) continue;
		dfs(kx, ky,cnt+1);
		alpha[arr[kx][ky]] = 0;
		visited[kx][ky] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s[i];
		for (int j = 0; j < c; j++) {
			arr[i + 1][j + 1] = s[i][j] - 'A'+1;
		}
	}
	dfs(1, 1,1);
	cout << maxCnt;

}