#include <iostream>
using namespace std;

int arr[101][101];
int n, m;
void dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return;
	}
	for (int i = x; i < n; i++) {
		for (int j = y; j < m; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				dfs(i, j);
				return;
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int check = 0;
		int a, b;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				check = 1;
				a = i;
				b = j;
			}
		}
		if (check == 1) {
			dfs(a, b);
			ans++;
		}
	}
	cout << ans;
}