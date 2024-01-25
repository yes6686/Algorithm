#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string dp[10001];

string sum(string a, string b) {
	string s = "";
	int rn=0;

	while (a.size() || b.size()) {
		int k1=0, k2 = 0;
		if (a.size()) {
			k1 = a.back()-'0';
			a.pop_back();
		}

		if (b.size()) {
			k2 = b.back()-'0';
			b.pop_back();
		}
		int n = k1 + k2;
		s += to_string((n + rn) % 10);
		if (n + rn >= 10) {
			rn = 1;
		}
		else {
			rn = 0;
		}
	}
	if (rn == 1) {
		s += "1";
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int n;
	cin >> n;
	dp[0] = "0";
	dp[1] = "1";
	for (int i = 2; i <= n; i++) {
		dp[i] = sum(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n];
}