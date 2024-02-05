#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int>v[100001];
int height[100001];
int parent[100001][18];

int maxL;

void dfs(int x, int depth, int p) {
	height[x] = depth;
	parent[x][0] = p;

	for (int i = 1; i <= maxL; i++) {
		parent[x][i] = parent[parent[x][i - 1]][i - 1];
	}

	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (k == p) continue;
		dfs(k, depth + 1, x);
	}
}

int lca(int a, int b) {

	if (a == 1 || b == 1) return 1;

	if (height[a] > height[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (height[parent[a][i]] >= height[b]) {
				a = parent[a][i];
			}
		}
	}
	else if (height[a] < height[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (height[parent[b][i]] >= height[a]) {
				b = parent[b][i];
			}
		}
	}

	int r=a;

	if (a != b) {

		for (int i = maxL; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			else {
				r = parent[a][i];
			}
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	maxL = (int)floor(log2(100001));
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0, 0);
	int m;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
}