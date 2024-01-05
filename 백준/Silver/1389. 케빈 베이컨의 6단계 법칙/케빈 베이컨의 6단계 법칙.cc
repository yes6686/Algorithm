#include <iostream>
using namespace std;

int arr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 1 && i!=j) {
				arr[i][j] = 1e9;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int t = 1; t <= n; t++) {
				if (arr[j][t] > arr[j][i] + arr[i][t]) {
					arr[j][t] = arr[j][i] + arr[i][t];
				}
			}
		}
	}
	int ans = 1e9;
	int index;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 0 && arr[i][j] != 1e9) {
				sum += arr[i][j];
			}

		}
		if (ans > sum) {
			ans = sum;
			index = i;
		}

	}
	cout << index;



}