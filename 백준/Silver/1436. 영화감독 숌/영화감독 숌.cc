#include <iostream>
#include <string>
using namespace std;

int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	int k = 1;
	int i = 666;
	while (true) {
		s = to_string(i);
		for (int j = 0; j < s.length() - 2; j++) {
			if (s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6') {
				dp[k] = i;
				k++;
				break;
			}
		}
		if (k == n + 1) {
			cout << dp[k - 1] << '\n';
			break;
		}
		i++;
	}
}