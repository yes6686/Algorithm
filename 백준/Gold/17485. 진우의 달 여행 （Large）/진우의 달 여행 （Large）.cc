#include <iostream>
#define INF 1e9
using namespace std;

int arr[1001][1001];
int dp[3][1001][1001];

int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			for (int h = 0; h < 3; h++) {
				dp[h][i][j] = INF;
			}
			if (i == 0) {
				dp[0][i][j] = arr[i][j];
				dp[1][i][j] = arr[i][j];
				dp[2][i][j] = arr[i][j];
			}

		}
	}
	int minAns = INF;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			for (int h = 0; h < 3; h++) { // <- . ->
				int nx = i + dx[h];
				int ny = j + dy[h];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				int m;
				if (h == 0) {
					m = min(dp[1][i][j], dp[2][i][j]);
				}
				else if (h == 1) {
					m = min(dp[0][i][j], dp[2][i][j]);
				}
				else {
					m = min(dp[0][i][j], dp[1][i][j]);
				}
				if (dp[h][nx][ny]) {
					dp[h][nx][ny] = min(dp[h][nx][ny], m + arr[nx][ny]);
				}
				else {
					dp[h][nx][ny] = m + arr[i][j];
				}
				if (i == n - 2)
					minAns = min(minAns, dp[h][nx][ny]);
			}
		}
	}
	cout << minAns << '\n';
}