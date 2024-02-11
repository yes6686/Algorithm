#include <iostream>
using namespace std;

int arr[101];
int dp[100001];

int main() {
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		dp[arr[i]] = 1;
		for (int j = 1; j + arr[i] <= m; j++) {
			if (dp[j] == 0) continue;
			if (dp[j + arr[i]] == 0) {
				dp[j + arr[i]] = dp[j]+1;
			}
			else {
				dp[j + arr[i]] = min(dp[j + arr[i]], dp[j]+1);
			}
		}
	}
	if (dp[m] == 0) {
		cout << -1;
	}else
	cout << dp[m] << '\n';
}