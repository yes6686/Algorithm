#include <iostream>
#define mod 1000000000
using namespace std;

int dp[101][10][1 << 10];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int t = 0; t < (1 << 10); t++) {
				if (j == 0) {
					dp[i][j][t | (1 << j)] = (dp[i][j][t | (1 << j)] + dp[i - 1][j + 1][t]) % mod;
				}
				else if (j == 9) {
					dp[i][j][t | (1 << j)] = (dp[i][j][t | (1 << j)] + dp[i - 1][j - 1][t]) % mod;

				}
				else {

					dp[i][j][t | (1 << j)] = (dp[i][j][t | (1 << j)] + dp[i - 1][j + 1][t]) % mod;
					dp[i][j][t | (1 << j)] = (dp[i][j][t | (1 << j)] + dp[i - 1][j - 1][t]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans+dp[n][i][(1 << 10) - 1])%mod;
	}
	cout << ans;
}