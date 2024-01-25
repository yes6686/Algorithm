#include <iostream>
#include <algorithm>
using namespace std;
string dp[100001];
string Add(string a, string b) {
	string s;
	int sum = 0;
	while (sum || a.empty() == false || b.empty() == false) {
		if (a.empty() == false) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.empty() == false) {
			sum += b.back() - '0';
			b.pop_back();
		}
		s.push_back(sum % 10 + '0');
		sum /= 10;
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
		dp[i] = Add(dp[i - 1] , dp[i - 2]);
	}
	cout << dp[n];

	
}