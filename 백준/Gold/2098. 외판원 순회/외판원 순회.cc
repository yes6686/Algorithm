#include <iostream>
#include <cstring>
using namespace std;

int arr[16][16];
int dp[16][1<<16];

int n;

int dfs(int x, int visit) {

	if (visit == (1 << n) - 1) {
		if (arr[x][0] == 0) {
			return 1e9;
		}
		return arr[x][0];
	}
	if (dp[x][visit] != -1) {
		return dp[x][visit];
	}
	dp[x][visit] = 1e9;

	for (int i = 0; i < n; i++) {
		if (arr[x][i] == 0) continue;
		if((visit & (1<<i))) continue;
		dp[x][visit] = min(dp[x][visit], arr[x][i] + dfs(i, visit | 1 << i));
	}
	return dp[x][visit];


}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);



}