#include <iostream>
using namespace std;

int s1p[100001];
int s1d[100001];
int s2p[100001];
int s2d[100001];
int dp[3][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
        
        int n, l1, l2, s1, s2;
		cin >> n >> l1 >> l2 >> s1 >> s2;

		for (int i = 0;i < n - 1;i++) {
			cin >> s1p[i];
		}
		for (int i = 0;i < n - 1;i++) {
			cin >> s1d[i];
		}
		for (int i = 0;i < n - 1;i++) {
			cin >> s2p[i];
		}
		for (int i = 0;i < n - 1;i++) {
			cin >> s2d[i];
		}

		dp[1][0] = l1;
		dp[2][0] = l2;

		for (int i = 1;i < n;i++) {
			dp[1][i] = min(dp[2][i - 1] + s2p[i-1], dp[1][i - 1] + s1d[i-1]);
			dp[2][i] = min(dp[1][i - 1] + s1p[i-1], dp[2][i - 1] + s2d[i-1]);
		}
		int minAns = min(dp[1][n - 1] + s1, dp[2][n - 1] + s2);
		cout << minAns << '\n';
	}
}