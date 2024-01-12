#include <iostream>
using namespace std;

int dp[1001];
int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = (2 * dp[i - 1] + 1)%10007;
		}
		else {
			dp[i] = (2 * dp[i - 1] - 1) % 10007;
		}
	}
	cout << dp[n];

}