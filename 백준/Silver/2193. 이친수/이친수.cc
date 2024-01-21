#include <iostream>
using namespace std;

long long int dp[91];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i - 2; j++) {
			dp[i] += dp[j];
		}
		dp[i] += 1;
	}
	cout << dp[n];
}