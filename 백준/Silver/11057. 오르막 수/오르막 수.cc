#include <iostream>
#define MOD 10007
using namespace std;

int dp[1001][10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int t = 0; t <= j; t++) {
				dp[i][j] += dp[i - 1][t];
			}
			dp[i][j] %= MOD;
			if (i == n) {
				ans += dp[i][j];
				ans %= MOD;
			}
		}
	}
	if (n == 1) cout << 10;
	else
		cout << ans;
}