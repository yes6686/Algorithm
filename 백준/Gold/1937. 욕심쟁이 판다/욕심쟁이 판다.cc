#include <iostream>
#include <vector>

using namespace std;
vector<int>v[1000001];
int arr[501][501];
int dp[501][501];

int n;
int maxCnt = 1;
int result = 1;
void dfs(int i,int j) {

    
    if (i <= 0 || j <= 0 || i > n || j > n) {
		return;
	}

	if (v[arr[i][j]].size() == 0) {
		dp[i][j] = 1;
		return;
	}

	if (arr[i][j] < arr[i + 1][j]) {
		if (dp[i + 1][j]) {
			dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
		}
		else {
			dfs(i + 1, j);
			dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
		}

	}
	if (arr[i][j] < arr[i - 1][j]) {
		if (dp[i - 1][j]) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
		}
		else {
			dfs(i - 1, j);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
		}
	}
	if (arr[i][j] < arr[i][j - 1]) {
		if (dp[i][j - 1]) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
		}
		else {
			dfs(i, j - 1);
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	if (arr[i][j] < arr[i][j + 1]) {
		if (dp[i][j + 1]) {
			dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
		}
		else {
			dfs(i, j + 1);
			dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
		}
	}
	result = max(result, dp[i][j]);

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cc = 0;
			if (arr[i][j] < arr[i + 1][j]) {
				v[arr[i][j]].push_back(arr[i + 1][j]);
				cc++;
			}
			if (arr[i][j] < arr[i - 1][j]) {
				v[arr[i][j]].push_back(arr[i - 1][j]);
				cc++;
			}
			if (arr[i][j] < arr[i][j - 1]) {
				v[arr[i][j]].push_back(arr[i][j - 1]);
				cc++;
			}
			if (arr[i][j] < arr[i][j + 1]) {
				v[arr[i][j]].push_back(arr[i][j + 1]);
				cc++;
			}
			if (cc == 0) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			maxCnt = 1;
			if (dp[i][j] == 0) {
				dfs(i, j);
			}
		}
	}

	cout << result;
}