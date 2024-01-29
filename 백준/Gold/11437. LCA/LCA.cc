#include <iostream>
#include <queue>
using namespace std;

vector<int>v[50001];
int height[50001];
int parent[50001];

void dfs(int x,int depth,int p) {
	height[x] = depth;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (k == p) continue;
		parent[k] = x;
		dfs(k, depth + 1,x);
	}
}

int lca(int a, int b) {
	if (height[a] > height[b]) {
		while (height[a] != height[b]) {
			a = parent[a];
		}
	}
	else if (height[a] < height[b]) {
		while (height[a] != height[b]) {
			b = parent[b];
		}
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0,0);
	int m;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}
}