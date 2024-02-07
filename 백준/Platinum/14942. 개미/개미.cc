#include <iostream>
#include <cmath>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[100001];
int parent[100001][18];
int s[100001][18];
int level[100001];
int hp[100001];
int maxL;
void dfs(int x, int depth, int p) {
	level[x] = depth;
	parent[x][0] = p;

	for (int i = 1; i <= maxL; i++) {
		s[x][i] = s[x][i - 1] + s[parent[x][i - 1]][i - 1];
		parent[x][i] = parent[parent[x][i - 1]][i - 1];
	}

	for (int i = 0; i < v[x].size(); i++) {
		int di = v[x][i].first;
		int k = v[x][i].second;
		if (k == p) continue;
		s[k][0] = di;
		dfs(k, depth + 1, x);
	}
}

int lca(int a, int b) {
	int ans = 0;
	int rhp = hp[a];
	if (level[a] != level[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b] && rhp - s[a][i] >= 0 ) {
				ans += s[a][i];
				rhp -= s[a][i];
				a = parent[a][i];
			}
		}
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	maxL = (int)floor(log2(100001));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> hp[i];
	}
	for (int i = 0; i < n-1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ c,y });
		v[y].push_back({ c,x });
	}
	dfs(1, 1, 0);
	for (int i = 1; i <= n; i++) {
		cout << lca(i, 1) << '\n';
	}
}