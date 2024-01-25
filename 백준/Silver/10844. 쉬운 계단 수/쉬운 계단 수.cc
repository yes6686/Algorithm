#include <iostream>
#define MOD 1000000000
using namespace std;

long long int dp[101][10];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else { // 1<= j <= 8
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= MOD;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i];
	}
	cout << ans%MOD;
}