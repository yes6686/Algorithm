#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[1000001];


int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= abs(n); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}
	if (n == 0) {
		cout << 0<<'\n';
		cout << dp[n]<<'\n';
	}
	else if (n < 0) {
		if (n % 2 == 0) {
			cout << -1 << '\n';
		}
		else {
			cout << 1 << '\n';
		}
		cout << dp[-n];
	}
	else {
		cout << 1 << '\n';
		cout << dp[n];
	}
}