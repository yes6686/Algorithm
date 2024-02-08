#include <iostream>
using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		if (dp[i - 1] == 1 && dp[i - 3] == 1) {
			dp[i] = 2;
		}
		else {
			dp[i] = 1;
		}
	}
	dp[n] == 1 ? cout << "SK" : cout << "CY";
}