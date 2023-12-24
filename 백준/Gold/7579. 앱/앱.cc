#include <iostream>
using namespace std;

int arr[101];
int c[101];

int dp[10001];
int sum[101];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	} 
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		sum[i] = sum[i - 1] + c[i];
		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = sum[i-1]; j >=0; j--) {
			if (dp[j] < m && dp[j]!=0) {
				dp[c[i] + j] = max(dp[c[i] + j],arr[i]+dp[j]);
			}
		}
		dp[c[i]] = max(dp[c[i]], arr[i]);
	}
	int result = 100001;
	for (int i = 1; i <= sum[n]; i++) {
		if (dp[i] >= m) {
			result = min(result, i);
		}

		//cout << i << " : " << dp[i] << '\n';
	}
	if (result == 100001) {
		cout << 0;
	}
	else {
		cout << result << endl;
	}


}