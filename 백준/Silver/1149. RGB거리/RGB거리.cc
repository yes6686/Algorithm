#include <iostream>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				dp[i][j] = arr[i][j];
			}
			else {
				if (j == 0) {
					dp[i][j] = min(arr[i][j] + dp[i - 1][j + 1],
						arr[i][j] + dp[i - 1][j + 2]);
				}
				else if (j == 1) {
					dp[i][j] = min(arr[i][j] + dp[i - 1][j - 1],
						arr[i][j] + dp[i - 1][j + 1]);
				}
				else {
					dp[i][j] = min(arr[i][j] + dp[i - 1][j - 1],
						arr[i][j] + dp[i - 1][j - 2]);
				}
			}
		}
	}
	cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}