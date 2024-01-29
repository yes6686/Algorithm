#include <iostream>
using namespace std;

int dp[41][2]; // dp[][0] : 왼쪽  , dp[][1] : 가만히
int vip[41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		vip[x] = 1;
	}

	dp[1][0] = 0;
	dp[1][1] = 1;
	if (vip[1] == 1 || vip[2]==1) {
		dp[2][0] = 0;
	}
	else {
		dp[2][0] = 1;
	}
	dp[2][1] = 1;

	int ans = 0;
	for (int i = 3; i <= n; i++) {
		if (vip[i] == 1) {
			dp[i][0] = 0;
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		}
		else {
			if (vip[i - 1] == 1) {
				dp[i][0] = 0;
			}
			else {
				dp[i][0] = dp[i - 2][0] + dp[i - 2][1];
			}
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		}
	}
	cout << dp[n][0] + dp[n][1];
}