#include <iostream>
using namespace std;
int arr[501][501];
int dp[501][501];
int m, n;
void ha() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			{
				if (i == 1 && j == 1) {
					dp[i][j] = 1;
				}
				else {
					if (arr[i][j] < arr[i][j - 1]) {
						if (arr[i][j] < arr[i - 1][j]) {
							if (arr[i][j] < arr[i][j + 1]) {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i][j + 1] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i][j + 1];
								}
							}
							else {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
								}
							}

						}
						else {
							if (arr[i][j] < arr[i][j + 1]) {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i][j - 1] + dp[i][j + 1];
								}
							}
							else {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i][j - 1] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i][j - 1];
								}
							}
						}
					}
					else {
						if (arr[i][j] < arr[i - 1][j]) {
							if (arr[i][j] < arr[i][j + 1]) {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i - 1][j] + dp[i][j + 1] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
								}
							}
							else {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i - 1][j] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i - 1][j];
								}
							}

						}
						else {
							if (arr[i][j] < arr[i][j + 1]) {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
								}
								else {
									dp[i][j] = dp[i][j + 1];
								}
							}
							else {
								if (arr[i][j] < arr[i + 1][j]) {
									dp[i][j] = dp[i + 1][j];
								}
								else {
									dp[i][j] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
}


int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	ha();
	ha();
	ha();
	ha();
    ha();

		cout << dp[m][n];
	
}