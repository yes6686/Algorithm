#include <iostream>
using namespace std;

long long int arr[100001][3];
long long int dp[100001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][1];
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) {
					dp[i][j] = min(dp[i-1][j], dp[i - 1][j + 1]) + arr[i][j];
				}
				else if (j == 1) {
					dp[i][j] = min(dp[i-1][j-1],min(dp[i - 1][j], dp[i - 1][j + 1]))+arr[i][j];
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[i][j]);
				}
				else {
					dp[i][j] = min(dp[i][j-1],min(dp[i - 1][j - 1], dp[i - 1][j]))+arr[i][j];
				}
			}
		}
		cout <<t<<". " << dp[n - 1][1] << '\n';
        t++;
	}
}