#include <iostream>
using namespace std;

int dp[16];

int main() {
	int n;
	cin >> n;
	int t, p;
	int maxAns = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		if (t + i > n + 1)continue;
		dp[i] = max(dp[i], dp[i - 1]);
		dp[t + i] = max(dp[t + i], dp[i]+p);
		maxAns = max(maxAns, dp[t + i]);
	}
	cout << maxAns;
}