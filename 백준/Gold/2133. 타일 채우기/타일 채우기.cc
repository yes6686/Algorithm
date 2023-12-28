#include <iostream>
using namespace std;


int dp[31];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);	

	dp[0] = 1;
	dp[2] = 3;
	int n;
	cin >> n;
	for (int i = 4; i <= n; i+=2) {
		for (int j = 0; j < i; j+=2) {
			if (j == i - 2)
				dp[i] += 3 * dp[j];
			else
				dp[i] += 2 * dp[j];
		}
	}
	cout << dp[n];


}