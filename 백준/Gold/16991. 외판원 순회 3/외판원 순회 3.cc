#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double arr[20][20];
double dp[20][1 << 16];

int n;
double dfs(int cur, int visit) {

	if (visit == (1 << n) - 1) {
		if (arr[cur][0] == 0) return 1e9;
		return arr[cur][0];
	}
	if (dp[cur][visit] != -1) return dp[cur][visit];
	dp[cur][visit] = 1e9;
	for (int i = 0; i < n; i++) {
		if (arr[cur][i] == 0) continue;
		if (visit & (1 << i)) continue;
		dp[cur][visit] = min(dp[cur][visit], arr[cur][i] + dfs(i, visit | 1 << i));
	}

	return dp[cur][visit];

}

struct st {
	int x, y;
};

st St[17];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> St[i].x >> St[i].y;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = sqrt(((St[i].x - St[j].x) * (St[i].x - St[j].x))
				+ ((St[i].y - St[j].y) * (St[i].y - St[j].y)));

		}
	}
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < (1 << 16); j++){
			dp[i][j] = -1.0;
		}  
	}
	cout << fixed;
	cout.precision(7);

	cout << dfs(0, 1);



}