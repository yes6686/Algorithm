#include <iostream>
using namespace std;

int dp[32][32];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 2; i <= 31; i++) {
		for (int j = 1; j <= 31; j++) {
			if (i+1 >= j) {
				dp[i][j] = 0;
			}
			else {
				int check = 1;
				for (int t = 1; t <= i; t++) {
					if (dp[i][j - t] == 1) check = 0;
				}
				if (check == 1) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
	}
	cout << 1 << '\n';
	for (int i = 2; i <= n; i++) {
		if (dp[i][31] == 1)cout << i << '\n';
	}
}