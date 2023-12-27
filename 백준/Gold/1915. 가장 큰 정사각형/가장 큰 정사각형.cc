#include <iostream>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
string s[1001];
int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			dp[i + 1][j + 1] = s[i][j] - '0';
		}
	}
	int result = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 1) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
				if (result < dp[i][j]) {
					result = dp[i][j];
				}
			}

		}
	}
	if (result == -1) {
		cout << 0 << endl;
	}
	else {
		cout << result * result << endl;
	}




}