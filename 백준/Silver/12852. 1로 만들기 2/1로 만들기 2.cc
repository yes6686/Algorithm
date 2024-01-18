#include <iostream>
#include <string>
using namespace std;

int dp[1000001];
string s[1000001];

int main() {
	int n;
	cin >> n;
	s[1] = "1";
	for (int i = 2; i <= n; i++) {
		int  k;
		dp[i] = dp[i - 1] + 1;
		k = i - 1;
		if (i % 2 == 0) {
			if (dp[i / 2]+1 < dp[i]) {
				dp[i] = dp[i / 2]+1;
				k = i / 2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i / 3]+1 < dp[i]) {
				dp[i] = dp[i / 3]+1;
				k = i / 3;
			}
		}
		s[i] += to_string(i)+" "+ s[k];
	}
	cout << dp[n] << '\n';
	cout << s[n] << '\n';
}