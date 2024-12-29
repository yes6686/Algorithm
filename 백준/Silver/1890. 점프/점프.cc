#include <iostream>
using namespace std;

int arr[101][101];
long long int dp[101][101];

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) continue;
			if (dp[i][j] == 0) continue;
			
			for (int k = 0; k < 2; k++) {
				int nx = i + (dx[k] * arr[i][j]);
				int ny = j + (dy[k] * arr[i][j]);
				if (nx >= n || ny >= n) continue;
				dp[nx][ny] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';
}
