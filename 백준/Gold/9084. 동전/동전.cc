#include <iostream>
#include <string.h>
using namespace std;

int arr[21];
int dp[10001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int m;
		cin >> m;
		for (int i = 0; i < n; i++) {
			dp[arr[i]] += 1;
			for (int j = 1; j+arr[i] <= m; j++) {
				dp[j + arr[i]] += dp[j];
			}
		}
		cout << dp[m] << '\n';
		memset(dp, 0, sizeof(dp));
	}
}