#include <iostream>
using namespace std;

int r[501];
int c[501];

int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> r[i] >> c[i];
		if (i > 0) {
			dp[i - 1][i] = r[i - 1] * r[i] * c[i];
		}
	}

	if (n == 1) {
		cout << 0 << '\n';
	}
	else {

		dp[0][2] = min(dp[0][1] + r[0] * r[2] * c[2], r[0] * c[0] * c[2] + dp[1][2]);
		for (int i = 3; i < n; i++) {
			for (int j = i-2; j >=0; j--) {
				for (int t = 0; t < i - j; t++) {
					

					if (j == i - t - 1) {
						dp[j][i] = min(dp[j][i], r[j] * c[j] * c[i] + dp[j+1][i]);
					}
					else if (t == 0) {
						dp[j][i] = min(dp[j][i], dp[j][i - t - 1] + r[j] * r[i] * c[i]);
					}
					
					else {
						dp[j][i] = min(dp[j][i], dp[j][i - t - 1] + dp[i - t][i]
							+ r[j] * r[i - t] * c[i]);
					}
				}
			}
		}
		cout << dp[0][n - 1];
	}
}