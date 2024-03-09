#include <iostream>
using namespace std;
int arr[16][16];
int dp[16][16];
int main() {
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	int indexi=0;
	int indexj=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] = (i - 1) * m + j;
			if (arr[i][j] == k) {
				indexi = i;
				indexj = j;
			}
		}
	}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

			
				if (i<indexi && j>indexj && k) {
					dp[i][j] = 0;
				}
				else if (i > indexi && j < indexj && k) {
					dp[i][j] = 0;
				}
				else if (i == 1 || j == 1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}

		cout << dp[n][m];

}