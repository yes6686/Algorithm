#include <iostream>
using namespace std;

int arr[1001];
int dp[1001][31][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, W;
	cin >> T >> W;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= W; j++) {
			for (int t = 1; t <= 2; t++) {
				dp[i][j][t] = -1;
			}
		}
	}

	int maxAns = 1;
	if (arr[0] == 1) {
		dp[0][0][1] = 1;
	}
	else { // arr[0] ==2
		dp[0][0][1] = 0;
		dp[0][1][2] = 1;
	}
	for (int i = 1; i < T; i++) {
		for (int j = 0; j <= W; j++) {
			for (int t = 1; t <= 2; t++) {
				if (arr[i] == 1) {
					if (t == 1) {
						if (dp[i - 1][j][t] != -1)
							dp[i][j][t] = dp[i - 1][j][t] + 1;

						if (j != 0) {
							if (dp[i - 1][j - 1][t + 1] != -1)
								dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j - 1][t + 1] + 1);
						}					
					}
					else { // t==2
						if(dp[i-1][j][t]!=-1)
						dp[i][j][t] = dp[i - 1][j][t];
					}
				}
				else { // arr[i]==2
					if (t == 1) {
						if (dp[i - 1][j][t] != -1)
						dp[i][j][t] = dp[i - 1][j][t];
					}
					else { // t==2
						if (dp[i - 1][j][t] != -1)
							dp[i][j][t] = dp[i - 1][j][t] + 1;
                        
						if (j != 0) {
							if (dp[i - 1][j - 1][t - 1] != -1)
								dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j - 1][t - 1] + 1);
						}
					}
				}
				if (i == T - 1) {
					maxAns = max(maxAns, dp[i][j][t]);
				}
			}
		}
	}
	cout << maxAns;
}