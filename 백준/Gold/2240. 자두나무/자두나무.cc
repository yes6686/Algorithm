#include <iostream>
using namespace std;

int arr[1001];
int dp[1001][32][3];

int main() {
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
			if (arr[i] == 1) {
				if(dp[i-1][j][1]!=-1)
					dp[i][j][1] = max(dp[i][j][1],dp[i-1][j][1] + 1);
				
				if (j >= 1) {
					if (dp[i - 1][j - 1][2] != -1)
						dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2] + 1);
				}
				
				if (dp[i - 1][j][2] != -1)
					dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2]);
			}
			else { // arr[i] == 2
				if (dp[i - 1][j][1] != -1)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);

				if (dp[i - 1][j][2] != -1)
					dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2]+1);

				if (j >= 1) {
					if (dp[i - 1][j - 1][1] != -1)
						dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1] + 1);
				}
			}
			if (i == T - 1) {
				maxAns = max(maxAns, dp[i][j][1]);
				maxAns = max(maxAns, dp[i][j][2]);
			}
		}
	}
	cout << maxAns;
}