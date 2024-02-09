#include <iostream>
using namespace std;

int arr[1025][1025];
int s[1025][1025];

int dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			s[i][j] = s[i][j - 1] + arr[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = s[i][j - 1] +dp[i-1][j] + arr[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 1; i <= m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]<<'\n';
	}
}