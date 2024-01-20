#include <iostream>

using namespace std;
int arr[501][501];
int dp[501][501];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				arr[i][j] += arr[i - 1][j];
				dp[i][j] = arr[i][j];
			}
			else if (j == i) {
				arr[i][j] += arr[i - 1][j-1];
				dp[i][j] = arr[i][j];
			}
			else {
				arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
				dp[i][j] = arr[i][j];
			}
		}
	}
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < arr[n - 1][i]) {
			max = arr[n - 1][i];
		}
	}
	cout << max;
	


}