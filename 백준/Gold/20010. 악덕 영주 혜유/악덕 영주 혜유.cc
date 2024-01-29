#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int,int>>v[1001];
priority_queue<pair<int, pair<int, int>>, 
	vector<pair<int, pair<int, int>>>, 
	greater<pair<int, pair<int, int>>>>pq;

int parent[1001];
int dis[1001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>>pq1;

int maxDis = 0;

void djk(int x,int n) {
	for (int i = 0; i < n; i++) {
		dis[i] = INF;
	}
	dis[x] = 0;
	pq1.push({ dis[x],x });
	while (!pq1.empty()) {
		int cost = pq1.top().first;
		int cur = pq1.top().second;
		pq1.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].first;
			int next = v[cur][i].second;
			if (ncost == -1) continue;
			if (dis[next] > ncost + cost) {
				dis[next] = ncost + cost;
				pq1.push({ dis[next],next });
				maxDis = max(maxDis, dis[next]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	int A, B, C;

	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		pq.push({ C,{A,B} });
	}
	int ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (!findParent(a, b)) {
			unionParent(a, b);
			v[a].push_back({ cost,b });
			v[b].push_back({ cost,a });
			ans += cost;
		}
	}
	for (int i = 0; i < V; i++) {
		djk(i, V);
	}
	cout << ans<<'\n';
	cout << maxDis<<'\n';
}