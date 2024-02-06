#include <iostream>
#include <cmath>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[100001];
int parent[100001][18];
pair<int, int> pp[100001][18]; // 최소, 최대
int level[100001];
int maxL;
void dfs(int x, int depth, int p) {
	level[x] = depth;
	parent[x][0] = p;


	for (int i = 1; i <= maxL; i++) {
		if (pp[x][i - 1].first > pp[parent[x][i - 1]][i - 1].first) {
			pp[x][i].first = pp[parent[x][i - 1]][i - 1].first;
		}
		else {
			pp[x][i].first = pp[x][i - 1].first;
		}
		if (pp[x][i - 1].second < pp[parent[x][i - 1]][i - 1].second) {
			pp[x][i].second = pp[parent[x][i - 1]][i - 1].second;
		}
		else {
			pp[x][i].second = pp[x][i - 1].second;
		}
		parent[x][i] = parent[parent[x][i - 1]][i - 1];

	}

	for (int i = 0; i < v[x].size(); i++) {
		int di = v[x][i].first;
		int k = v[x][i].second;
		if (k == p) continue;
		pp[k][0].first = di;
		pp[k][0].second = di;
		dfs(k, depth + 1, x);
	}
}

void lca(int a, int b) {
	int mi = INF;
	int ma = -INF;
	if (level[a] < level[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (level[a] != level[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b] && parent[a][i] != 0) {
				mi = min(mi, pp[a][i].first);
				ma = max(ma, pp[a][i].second);
				a = parent[a][i];
			}
		}
	}
	int r = a;

	if (a != b) {
		for (int i = maxL; i >= 0; i--) {
			if (parent[a][i] != parent[b][i] && parent[a][i] != 0) {

				mi = min(mi, pp[a][i].first);
				mi = min(mi, pp[b][i].first);
				ma = max(ma, pp[a][i].second);
				ma = max(ma, pp[b][i].second);


				a = parent[a][i];
				b = parent[b][i];

			}
		}
		mi = min(mi, pp[a][0].first);
		mi = min(mi, pp[b][0].first);
		ma = max(ma, pp[a][0].second);
		ma = max(ma, pp[b][0].second);
	}
	cout << mi << " " << ma << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	maxL = (int)floor(log2(100001));
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		v[x].push_back({ c,y });
		v[y].push_back({ c,x });
	}
	dfs(1, 0, 0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		lca(a, b);
	}
}