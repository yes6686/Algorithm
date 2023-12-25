#include <iostream>	
using namespace std;

int arr[551];
int dp[551][551];
int dpSum[551][551];
int sum[551];
int main() {

	int T;
	cin >> T;
	int n;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i > 0) {
				dp[i - 1][i] = arr[i - 1] + arr[i];
				sum[i] = sum[i - 1] + arr[i];
			}
			else {
				sum[i] = arr[i];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (i > 0) {
					dpSum[i][j] = sum[j] - sum[i - 1];
				}
				else {
					dpSum[i][j] = sum[j];
				}
			}
		}


		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + j + 1 >= n) {
					break;
				}

				for (int t = j; t < i + j + 1; t++) {
					if (dp[j][i + j + 1] == 0) {
						dp[j][i + j + 1] = dp[j][t] + dp[t + 1][i + j + 1] + dpSum[j][i + j + 1];
					}
					else {
						dp[j][i + j + 1] = min(dp[j][i + j + 1], dp[j][t] + dp[t + 1][i + j + 1] + dpSum[j][i + j + 1]);
					}
				}
			}
		}

		cout << dp[0][n - 1] << '\n';



		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 0;
				dpSum[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
			sum[i] = 0;
		}


	}

}