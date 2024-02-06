#include <iostream>
#include <cmath>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[100001];
int parent[100001][18];
int s[100001][18];
int level[100001];
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
	if (level[a] < level[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (level[a] != level[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) {
				ans += s[a][i];
				a = parent[a][i];
			}
		}
	}
	int r = a;
	if (a != b) {
		for (int i = maxL; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				ans += s[a][i] + s[b][i];
				a = parent[a][i];
				b = parent[b][i];

			}
		}
		ans += s[a][0] + s[b][0];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	maxL = (int)floor(log2(100001));
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < n - 1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ c,y });
		v[y].push_back({ c,x });
	}
	dfs(1, 0, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout<<lca(a, b)<<'\n';
	}
}