#include <iostream>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,1,-1 };
int arr[501][501];
long long int dp[501][501];

int n, m;
int dfs(int a, int b) {
	if (a == 0 && b == 0) return 1;
	if (dp[a][b]) return dp[a][b];

	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (arr[a][b] >= arr[nx][ny]) continue;
		dp[a][b] += dfs(nx, ny);
	}
	if (dp[a][b] == 0) {
		arr[a][b] = 0;
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(n-1, m-1);
    
	cout << dp[n - 1][m - 1] << '\n';
}