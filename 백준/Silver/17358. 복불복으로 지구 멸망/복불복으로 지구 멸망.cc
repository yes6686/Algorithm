#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[2] = 1;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * (i - 1);
		dp[i] %= MOD;
	}
	cout << dp[n];
}