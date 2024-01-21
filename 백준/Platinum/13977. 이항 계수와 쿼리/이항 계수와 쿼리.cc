#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[4000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		dp[i] = dp[i-1]*i;
		dp[i] %= MOD;
	}
	while (T--) {
		int n,k;
		cin >> n>>k ;
		long long int s = dp[k];
		s = (s * dp[n - k]) % MOD;
		long long int T = MOD - 2;
		long long int ans = 1;
		while (T) {
			if (T % 2 == 1) {
				ans = (ans * s) % MOD;
			}
			s = (s * s) % MOD;
			T /= 2;
		}
		ans = (ans * dp[n]) % MOD;
		
		cout << ans  << '\n';
	}
}