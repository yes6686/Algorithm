#include <iostream>
#define mod 10007
using namespace std;


int dp[53][53];
int combination(int n, int r) {
	if (n == r || r == 0) return 1;
	if (dp[n][r]) return dp[n][r];
	return dp[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r))%mod;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int ans = 0;
	if (n < 4) cout << 0 << '\n';
	else {
		for (int i = 1; i <= n/4; i++) {
			if (i % 2 == 1) {
				ans += (combination(13, i) * combination(52 - 4 * i, n - 4 * i));
			}
			else {
				ans -= (combination(13, i) * combination(52 - 4 * i, n - 4 * i));
			}
			ans %= mod;
		}
		if (ans < 0) {
			ans += mod;
		}
		cout << ans;

	}
	

}