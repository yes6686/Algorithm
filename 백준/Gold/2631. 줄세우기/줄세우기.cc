#include <iostream>
using namespace std;
int arr[201];
int dp[201];
int main() {
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	cout << n - max;
}