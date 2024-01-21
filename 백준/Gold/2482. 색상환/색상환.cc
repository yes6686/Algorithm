#include <iostream>
#define MOD 1000000003 
using namespace std;

long long int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n/2; j++) {
			if (j == 1) {
				dp[i][j] = i;
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
			}
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k];	
}