#include <iostream>
using namespace std;

int dp[50001];
int main() {
	int n;
	dp[1] = 1;
	dp[2] = 2;
	int index;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= 230; j++) {
			if (i < j * j) {
				index = (j - 1);
				break;
			}
		}
		dp[i] = 4;
		if (index*index == i) {
			dp[i] = 1;
		}
		else if (index*index + 1 == i) {
			dp[i] = 2;
		}
		else {
			for (int j = 1; j <= index; j++) {
				dp[i] = min(dp[j*j] + dp[i - j*j], dp[i]);
			}
		}
	}
	cout << dp[n];


}