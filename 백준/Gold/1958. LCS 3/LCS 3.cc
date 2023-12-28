#include <iostream>
#include <stack>
using namespace std;

int dp[101][101][101];
stack<char>s;


int main() {
	
	string a, b, c;
	cin >> a >> b >> c;


	int result = -1;
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			for (int t = 0; t <= c.length(); t++) {
				if (i == 0 || j == 0 || t==0) {
					dp[i][j][t] = 0;
				}
				else if (a[i - 1] == b[j - 1] && b[j-1]==c[t-1]) {
					dp[i][j][t] = dp[i - 1][j - 1][t-1] + 1;
				}
				else {
					dp[i][j][t] = max(dp[i - 1][j][t], dp[i][j - 1][t]);
					dp[i][j][t] = max(dp[i][j][t], dp[i][j][t-1]);
				}
				result = max(result, dp[i][j][t]);
			}
		}
	}
	cout << result;

}