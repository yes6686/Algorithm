#include <iostream>
#define MOD 1000000007
using namespace std;

long long int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, u;
	cin >> l >> u;
	dp[1] = 1;
	dp[2] = 1;
	long long int k = 26;
	for (int i = 3; i <= u; i++) {
		dp[i] += k;
		dp[i] %= MOD;
		if (i % 2 == 0) {
			k *= 26;
			k %= MOD;
		}
	}
	long long int sum = 0;
	for (int i = l; i <= u; i++) {
		sum += dp[i];
		sum %= MOD;
	}
	if (l == 1 && u == 1) {
		cout << "H" << '\n';
	}
	else if (l == 1 && u == 2) {
		cout << "A" << '\n';
	}
	else if(l==1) {
		cout << "A" << '\n';
	}
	else if(l==2){
		cout << "H" << '\n';
	}
	else {
		cout << "A" << '\n';
	}

	cout << sum << '\n';
}