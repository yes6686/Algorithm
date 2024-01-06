#include <iostream>
using namespace std;

int dp[1500001];
int T[1500001];
int p[1500001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int k = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		cin >> T[i] >> p[i];

	}
	int result = 0;
	int maxt = 0;
	for (int i = 0; i <= n; i++) {
		maxt = max(maxt, dp[i]);
		if (i + T[i] >= n + 1) {
			continue;
		}
		dp[i + T[i]] = max(dp[i + T[i]], maxt + p[i]);
		result = max(result, dp[i + T[i]]);

	}
	
	cout << result;

}