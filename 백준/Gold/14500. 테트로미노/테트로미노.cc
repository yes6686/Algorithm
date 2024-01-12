#include <iostream>
using namespace std;
int arr[502][502];
int c[502][502];

int maxval = -1;

void dfs(int x, int y,int depth,int cnt) {
	c[x][y] = 1;
	if (depth == 4) {
		maxval = max(maxval, cnt);
		c[x][y] = 0;
		return;
	}
	if (arr[x + 1][y] && c[x+1][y]==0) {
		c[x + 1][y] = 1;
		dfs(x + 1, y, depth + 1, cnt + arr[x + 1][y]);
		c[x + 1][y] = 0;
	}
	if (arr[x - 1][y] && c[x - 1][y] == 0) {
		c[x - 1][y] = 1;
		dfs(x - 1, y, depth + 1, cnt + arr[x - 1][y]);
		c[x - 1][y] = 0;
	}
	if (arr[x][y + 1] && c[x][y + 1] == 0) {
		c[x][y + 1] = 1;
		dfs(x, y + 1, depth + 1, cnt + arr[x][y + 1]);
		c[x][y + 1] = 0;
	}
	if (arr[x][y - 1] && c[x][y - 1] == 0) {
		c[x][y - 1] = 1;
		dfs(x, y - 1, depth + 1, cnt + arr[x][y - 1]);
		c[x][y - 1] = 0;
	}
	c[x][y] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dfs(i, j, 1, arr[i][j]);
		}
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= m-2; j++) {
			maxval = max(maxval, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m - 2; j++) {
			maxval = max(maxval, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1]);
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			maxval = max(maxval, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i + 1][j + 1]);
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 2; j <= m; j++) {
			maxval = max(maxval, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1]);
		}
	}
	cout << maxval << '\n';
}
