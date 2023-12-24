#include <iostream>
using namespace std;

int arr[31];
int n;
int check = 1;

int sum[31];

int d[15001];

int dp[101][15001];

void dfs(int i, int w) {

	if (dp[i][w]) return;
	dp[i][w] = 1;
	if (i > n) {
		if (w > 0) {
			d[w] = 1;
		}
		return;

	}

	dfs(i + 1, w);
	dfs(i + 1, w+arr[i]);
	dfs(i + 1, w-arr[i]);

}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	int m;
	cin >> m;
	int x;

	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x > sum[n]) {
			cout << 'N' << ' ';
		}
		else if (x == sum[n]) {
			cout << 'Y' << ' ';
		}
		else {
			dfs(1, 0);
			if (d[x]) {
				cout << 'Y' << ' ';
			}
			else {
				cout << 'N' << ' ';
			}
		}
	}


}