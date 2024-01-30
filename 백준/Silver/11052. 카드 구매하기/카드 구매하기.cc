#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;	


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <=i/2; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n];
}