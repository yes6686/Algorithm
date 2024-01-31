#include <iostream>
using namespace std;

int arr[3][100001];
int dp[3][100001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[1][1][1] = arr[1][1];
		dp[2][1][1] = arr[2][1];
		dp[1][2][1] = arr[1][2] + arr[2][1];
		dp[2][2][1] = arr[1][1] + arr[2][2];
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j <= 2; j++) {
				if (j == 1) {
					dp[j][i][1] = max(dp[j][i - 2][1], dp[j + 1][i - 2][1]) + arr[j][i];
					dp[j][i][1] = max(dp[j][i][1], dp[j + 1][i - 1][1] + arr[j][i]);
				}
				else {
					dp[j][i][1] = max(dp[j][i - 2][1], dp[j - 1][i - 2][1]) + arr[j][i];
					dp[j][i][1] = max(dp[j][i][1], dp[j - 1][i - 1][1] + arr[j][i]);
				}
			}
		}
		cout << max(dp[1][n][1], dp[2][n][1])<<'\n';
	}
}