#include <iostream>
using namespace std;

int arr[9];
int visited[9];

int n, k;
int ans = 0;
void dfs(int d, int x) {
	if (x < 0) return;
	if (d == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(d + 1, x + arr[i]);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] -= k;
	}
	dfs(0, 0);
	cout << ans;
}