#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	int max1 = -1;
	int max2 = -1;
	int max3 = -1;
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j <= i; j++) {
			for (int t = 0; t < j; t++) {
				if (arr[t] < arr[j]) {
					dp[j] = max(dp[t] + 1, dp[j]);
				}
			}
			if (max1 < dp[j]) {
				max1 = dp[j];
			}
		}
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
		}
		for (int j = i; j < n; j++) {
			for (int t = i; t < j; t++) {
				if (arr[t] > arr[j]) {
					dp[j] = max(dp[t] + 1, dp[j]);
				}
			}
			if (max2 < dp[j]) {
				max2 = dp[j];
			}
		}
		if (max3 < max1 + max2) {
			max3 = max1 + max2;
		}
		for (int i = 0; i < n; i++) {
			dp[i] = 1;
		}
		max1 = -1;
		max2 = -1;
	}
	cout << max3-1 << endl;
}