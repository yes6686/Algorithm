#include <iostream>
using namespace std;

int arr[1001][1001];
long long int dp[1001][1001];
long long int dp1[1001][1001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = -2e9;
			dp1[i][j] = -2e9;
		}
	}
	for (int i = 1; i <= n; i++) {

		if (i == 1) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			}
		}
		else if (i == n) {
			for (int j = 1; j <= m; j++) {
				if (j == 1) {
					dp[i][j] = dp[i - 1][j] + arr[i][j];
				}
				else
					dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);

			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				if (j == m) {
					dp1[i][j] = dp[i - 1][j] + arr[i][j];
				}
				else {
					dp1[i][j] = max(dp[i - 1][j] + arr[i][j],dp1[i][j + 1] + arr[i][j]);
				}
			}
			for (int j = 1; j <= m; j++) {
				if (j == 1) {
					dp[i][j] = dp[i - 1][j] + arr[i][j];
				}else
				dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j - 1] + arr[i][j]);

			}
			for (int j = 1; j <= m; j++) {
				dp[i][j] = max(dp[i][j], dp1[i][j]);
				
			}
			
		}

	}
	cout << dp[n][m];

}