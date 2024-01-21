#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r;
	cin >> n >> r;
	long long int a = 1;
	long long int b = 1;
	for (int i = 2; i <= n; i++) { // n!
		a *= i;
		a %= MOD;
	}
	for (int i = 2; i <= r; i++) { //r!
		b *= i;
		b %= MOD;
	}
	for (int i = 2; i <= n - r; i++) { //n!(n-r)!
		b *= i;
		b %= MOD;
	}
	long long int T = MOD - 2;
	long long int ans = 1;
	while (T) {
		if (T % 2 == 1) {
			ans = (ans * b) % MOD;
		}
		b = (b * b) % MOD;
		T /= 2;
	}
	ans = (ans * a) % MOD;
	cout << ans<<'\n';	
}