#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int>v[100001];
int parent[100001][18];
int level[100001];
int maxL;
void dfs(int x,int depth,int p) {
	level[x] = depth;
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

int lca(int a,int b) {
	if (a == 1 || b == 1) return 1;

	if (level[a] < level[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (level[a] != level[b]) {
		for (int i = maxL; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) {
				a = parent[a][i];
			}
		}
	}
	int r = a;
	if (a != b) {
		for (int i = maxL; i >=0; i--) {
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
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0, 0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}