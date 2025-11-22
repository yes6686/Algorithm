#include <iostream>
using namespace std;

int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4;i <= n;i++) {

		if (dp[i]) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
			if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
			if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		else {
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
			if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	cout << dp[n] << '\n';

}