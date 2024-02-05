#include <iostream>
#include <queue>
using namespace std;

vector<pair<int,int>>v[40001];
int height[40001];
pair<int,int> parent[40001];

void dfs(int x, int depth, int p) {
	height[x] = depth;
	for (int i = 0; i < v[x].size(); i++) {
		int di = v[x][i].first;
		int k = v[x][i].second;
		if (k == p) continue;
		parent[k].first = di;
		parent[k].second = x;
		dfs(k, depth + 1, x);
	}
}

int dis = 0;

int lca(int a, int b) {
	if (height[a] > height[b]) {
		while (height[a] != height[b]) {
			dis += parent[a].first;
			a = parent[a].second;
		}
	}
	else if (height[a] < height[b]) {
		while (height[a] != height[b]) {
			dis += parent[b].first;
			b = parent[b].second;
		}
	}
	while (a != b) {
		dis += parent[a].first;
		dis += parent[b].first;
		a = parent[a].second;
		b = parent[b].second;
	}
	return dis;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b,c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b>>c;
		v[a].push_back({c,b});
		v[b].push_back({c,a});
	}
	dfs(1, 0, 0);
	int m;
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		dis = 0;
		cin >> x >> y;
		cout << lca(x,y) << '\n';
	}
}