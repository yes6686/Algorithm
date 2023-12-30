#include <iostream>
using namespace std;

int arrc[5001];
int arrp[10001];
int dp[10001];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	double m;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0.00) {
			break;
		}
		int k = m * 100+0.5;
		if (k == 0) {
			k = 1;
		}
		double p;
		for (int i = 1; i <= n; i++) {
			cin >> arrc[i] >> p;
			arrp[i] = p * 100+0.5;
			if (arrp[i] == 0) {
				arrp[i] = 1;
			}
		}
		int result = -1;
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= k; j++) {
				if (dp[j] && j + arrp[i] <= k)
				{
					if (dp[j + arrp[i]]) {
						dp[j + arrp[i]] = max(dp[j + arrp[i]], dp[j] + arrc[i]);
						if (result < dp[j] + arrc[i]) {
							result = dp[j] + arrc[i];
						}
					}
					else {
						dp[j + arrp[i]] = dp[j] + arrc[i];
						if (result < dp[j] + arrc[i]) {
							result = dp[j] + arrc[i];
						}

					}
				}
			
				if (j % arrp[i] == 0) {
					if (dp[j] && j!=arrp[i]) {
						dp[j] = max(dp[j],arrc[i] * (j / arrp[i]));
					}
					else {
						dp[j] = arrc[i] * (j / arrp[i]);
					}
				}
				if (result < dp[j] ) {
					result = dp[j] ;
				}
			}
		}
		cout << result << '\n';

		for (int i = 0; i <= k; i++) {
			dp[i] = 0;
		}

	}






}