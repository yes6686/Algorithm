#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[101][101];
vector<int>v[101];
int c[101];

void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (c[k] == 0) {
			c[k] = 1;
			dfs(k);
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) v[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
		for (int j = 1; j <= n; j++) {
			if (c[j]) cout << 1 << ' ';
			else cout << 0 << ' ';

		}
		memset(c, 0, sizeof(c));
		cout << '\n';
	}

}