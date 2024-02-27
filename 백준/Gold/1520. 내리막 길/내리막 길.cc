#include <iostream>
#include <string.h>
using namespace std;

int arr[501][501];
int dp[501][501];
int n, m;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (dp[x][y]!=-1) return dp[x][y];
	if (x == n && y == m) return 1;
	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny<1 || nx >n || ny>m) continue;
		if (arr[x][y] <= arr[nx][ny]) continue;
		dp[x][y] += dfs(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout<<dfs(1, 1);
}