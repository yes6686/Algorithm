#include <iostream>
#include <stack>
using namespace std;

int dp[1002][1002];
stack<char>s;
int main() {

	string a, b;
	cin >> a >> b;
	int result = -1;
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			if (j == 0 || i == 0) {
				dp[i][j] = 0;
			}
			else if (a[i-1] == b[j-1]) {
				dp[i][j] =dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			result = max(result, dp[i][j]);
		}
	}

	int k = result;
	for (int i = a.length(); i >=0; i--) {
		for (int j = b.length(); j >=0; j--) {
			if (dp[i][j] == k && dp[i-1][j]==k-1) {
				if (a[i-1] == b[j-1]) {
					s.push(a[i - 1]);
					k--;
					break;
				}
			}

		}
	}
	cout << result<<'\n';
	while (!s.empty()) {
		char k = s.top();
		s.pop();
		cout << k;
	}
}