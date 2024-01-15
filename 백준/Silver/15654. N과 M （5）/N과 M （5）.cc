#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int n, m;
int c[9];
int r[9];
void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (c[i]==0) {
			c[i] = 1;
			arr[depth] = r[i];
			dfs(depth + 1);
			c[i] = 0;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	sort(r, r + n+1);
	dfs(0);
	
}

	
