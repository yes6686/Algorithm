#include <iostream>
using namespace std;

long long int dp[101][101];
long long int L[101][101];
int arr[101][101];
int combination(int n, int r) {
	if (n == r || r == 0) return arr[n][r]=1;
	if (arr[n][r]) return arr[n][r];
	return arr[n][r] = (combination(n - 1, r - 1)
		+ combination(n - 1, r))% 1000000007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, r;
	cin >> n >> l >> r;
	L[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			L[i][j] = ((i - 1) * L[i - 1][j]
				+ L[i - 1][j - 1])% 1000000007;
			
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[1][i + 1] = L[n - 1][i];
		dp[i + 1][1] = L[n-1][i];
	}
	for (int i = 2; i <= n; i++) {	
		for (int j = 1; j <= (i - 1) / 2; j++) {
			dp[1 + j][i - j] = (dp[1][i] * combination(i - 1, j))%1000000007;
			dp[i - j][1 + j] = dp[1 + j][i - j];

		}
	}
    if(n==1){
        cout<<1<<endl;
    }else
	cout << dp[l][r]<< endl;

}