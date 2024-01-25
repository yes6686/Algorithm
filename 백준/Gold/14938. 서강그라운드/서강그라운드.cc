#include <iostream>
#define INF 1000000000
using namespace std;

int arr[101];
int len[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				len[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int a, b, l; 
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		len[a][b] = l;
		len[b][a] = l;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int t = 1; t <= n; t ++) {
				if (len[j][i] + len[i][t] < len[j][t]) {
					len[j][t] = len[j][i] + len[i][t];
				}
			}
		}
	}
	int maxAns = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (len[i][j] <= m) {
				sum += arr[j];
			}
		}
		maxAns = max(maxAns, sum);
	}
	cout << maxAns;
}