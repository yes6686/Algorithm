#include <iostream>
using namespace std;

int arr[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > k) continue;
		dp[arr[i]] += 1;
		for (int j = 1; j+arr[i] <= k; j++) {
			dp[j + arr[i]] += dp[j];
		}
	}
	cout << dp[k];
}