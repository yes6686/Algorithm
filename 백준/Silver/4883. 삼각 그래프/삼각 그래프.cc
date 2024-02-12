#include <iostream>
using namespace std;

int arr[100001][3];
int dp[100001][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> arr[i][j];
			}
		}

		dp[1][1] = arr[1][2];
		dp[1][2] = arr[1][2];
		dp[1][3] = arr[1][2] + arr[1][3];
		
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				if (j == 1) {
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + arr[i][j];
				}
				else if(j==2){
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
					dp[i][j] = min(dp[i][j], dp[i][j - 1]+arr[i][j]);
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]+arr[i][j]);
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + arr[i][j]);
				}
			}
		}
		cout << t<<". "<<dp[n][2] << '\n';
		t++;
	}
}