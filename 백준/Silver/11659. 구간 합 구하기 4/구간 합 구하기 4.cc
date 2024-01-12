#include <iostream>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] += (dp[i - 1]+arr[i]);
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << dp[b-1] - dp[a-2] << '\n';
	}
}