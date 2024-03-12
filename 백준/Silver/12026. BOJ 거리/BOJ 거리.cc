#include <iostream>
using namespace std;

int n;
string s;
int minAns = 1e9;
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cin >> s;

	for (int i = 0; i < s.size()-1; i++) {
		char c = s[i];
		for (int j = i + 1; j < s.size(); j++) {
			if (c == 'B') {
				if (s[j] == 'O') {
					if (i != 0 && dp[i] == 0) continue;
					if (dp[j] == 0) {
						dp[j] = dp[i] + (j - i) * (j - i);
					}
					else {
						dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
					}
				}
			}
			else if (c == 'O') {
				if (s[j] == 'J') {
					if (i != 0 && dp[i] == 0) continue;
					if (dp[j] == 0) {
						dp[j] = dp[i] + (j - i) * (j - i);
					}
					else {
						dp[j] = min(dp[j],dp[i]+ (j - i) * (j - i));
					}
				}
			}
			else {
				if (s[j] == 'B') {
					if (i != 0 && dp[i] == 0) continue;
					if (dp[j] == 0) {
						dp[j] = dp[i] + (j - i) * (j - i);
					}
					else {
						dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
					}
				}
			}
		}
	}
	if (dp[n - 1] == 0) {
		cout << -1;
	}
	else {
		cout << dp[n - 1];
	}
}