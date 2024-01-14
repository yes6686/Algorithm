#include <iostream>
using namespace std;


int arr[51][51];
int dp[51][51];

int main() {

	int r, c, t;
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}
	while (t--) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] != -1) {
					if (i == 0 && j == 0) {
						int cnt = 0;
						if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}
						if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}

						dp[i][j] -= (arr[i][j] / 5) * cnt;

					}

					else if (i == 0 && j != c - 1) {
						int cnt = 0;
						if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (j == c - 1 && i == 0) {
						int cnt = 0;
						if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (j == c - 1 && i != r - 1) {
						int cnt = 0;
						if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (j == 0 && i != r - 1) {
						int cnt = 0;
						if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (i == r - 1 && j == 0) {
						int cnt = 0;
						if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (i == r - 1 && j != c - 1) {
						int cnt = 0;
						if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else if (i == r - 1 && j == c - 1) {
						int cnt = 0;
						if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}
						if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
					else {
						int cnt = 0;
						if (arr[i - 1][j] != -1) {
							dp[i - 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i + 1][j] != -1) {
							dp[i + 1][j] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j - 1] != -1) {
							dp[i][j - 1] += arr[i][j] / 5;
							cnt++;
						}if (arr[i][j + 1] != -1) {
							dp[i][j + 1] += arr[i][j] / 5;
							cnt++;
						}
						dp[i][j] -= (arr[i][j] / 5) * cnt;
					}
				}
			}
		}
		int h = 0;
		for (int i = 0; i < r; i++) {
			if (dp[i][0] == -1 && h == 0) {
				for (int j = 1; j <= i - 1; j++) {
					dp[i - j][0] = dp[i - j - 1][0];
				}
				for (int j = 0; j < c - 1; j++) {
					dp[0][j] = dp[0][j + 1];
				}
				for (int j = 0; j < i; j++) {
					dp[j][c - 1] = dp[j + 1][c - 1];
				}
				for (int j = 0; j < c - 2; j++) {
					dp[i][c - 1 - j] = dp[i][c - 2 - j];
					dp[i][c - 2 - j] = 0;
				}
				h++;
			}
			else if (dp[i][0] == -1 && h != 0) {
				for (int j = 1; j <= r - i - 2; j++) {
					dp[i + j][0] = dp[i + j + 1][0];
				}
				for (int j = 0; j < c - 1; j++) {
					dp[r - 1][j] = dp[r - 1][j + 1];
				}
				for (int j = 0; j < r - i; j++) {
					dp[r - 1 - j][c - 1] = dp[r - 2 - j][c - 1];
				}
				for (int j = 0; j < c - 2; j++) {
					dp[i][c - 1 - j] = dp[i][c - 2 - j];
					dp[i][c - 2 - j] = 0;
				}
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = dp[i][j];
			}
		}


	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += dp[i][j];
		}
	}
	cout << sum+2 << endl;

}