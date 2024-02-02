#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>V[100001];
int visited[100001];
int ans[100001];

int depth = 1;

void dfs(int x) {
	visited[x] = 1;
	ans[x] = depth++;
	for (int i = 0; i < V[x].size(); i++) {
		int k = V[x][i];
		if (!visited[k]) {
			dfs(k);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(V[i].begin(), V[i].end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
}