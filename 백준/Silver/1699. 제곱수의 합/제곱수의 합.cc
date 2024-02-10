#include <iostream>
#include <cmath>
using namespace std;

int dp[100001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = sqrt(i); j >= 1; j--) {
			if (dp[i] == 0) {
				dp[i] = 1 + dp[i - j * j];
			}
			else {
				dp[i] = min(dp[i], 1 + dp[i - j * j]);
			}
		}
	}
	cout << dp[n];
}