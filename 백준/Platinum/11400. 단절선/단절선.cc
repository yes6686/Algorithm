#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int visited[100001];

int dfs(int n, int x, int pre) {
	visited[x] = n;
	int minD = n;
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i];
		if (pre == k) continue;
		if (visited[k] == 0) {
			int kk = dfs(n+1, k, x);
			if (kk > visited[x]) {
				pq.push({ min(x,k),max(x,k) });
			}
			minD = min(minD, kk);
		}
		else {
			minD = min(minD, visited[k]);
			continue;
		}
	}
	return minD;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			dfs(1, i, 0);
		}
	}
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top().first << ' ' << pq.top().second << '\n';
		pq.pop();
	}
}