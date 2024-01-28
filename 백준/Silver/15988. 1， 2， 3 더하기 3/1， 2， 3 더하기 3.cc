#include <iostream>
#define MOD 1000000009
#define MAX 1000001
using namespace std;

long long int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <=MAX ; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		dp[i] %= MOD;
	}
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}