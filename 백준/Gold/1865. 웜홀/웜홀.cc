#include <iostream>
using namespace std;
int arr[501][501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = 1e9;
			}
		}
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			arr[s][e] = min(arr[s][e], t);
			arr[e][s] = min(arr[e][s], t);
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			arr[s][e] = min(arr[s][e], -t);
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {				
					if (arr[i][k] + arr[k][j] < arr[i][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
				}
			}
		}
		int check = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					if (arr[i][j] < 0) {
						check = 0;
					}
				}
			}
		}
		if (check) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}
}