#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[2000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	dp[1] = 1;
	for (int i = 2; i <= 2000000; i++) {
		dp[i] = dp[i-1]*i;
		dp[i] %= MOD;
	}
	while (T--) {
		int n;
		cin >> n;
		long long int s = dp[n];
		for (int i = 2; i <= n+1; i++) { //n!(n-r)!
			s *= i;
			s %= MOD;
		}
		long long int T = MOD - 2;
		long long int ans = 1;
		while (T) {
			if (T % 2 == 1) {
				ans = (ans * s) % MOD;
			}
			s = (s * s) % MOD;
			T /= 2;
		}
		ans = (ans * dp[2*n]) % MOD;	
		cout << ans  << '\n';
	}
}