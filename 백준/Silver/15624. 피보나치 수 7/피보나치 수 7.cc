#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[1000001];

int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}
	cout << dp[n];
}