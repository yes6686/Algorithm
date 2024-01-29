#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[1001];
int dis[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>>pq;
priority_queue<int>pqk[1001];

void djk(int x) {
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].first;
			int next = v[cur][i].second;
			if (pqk[next].top() > ncost + cost) {
				pqk[next].push(ncost + cost);
				pqk[next].pop();
				pq.push({ ncost + cost,next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int a, b, c;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			pqk[i].push(INF);
		}
	}

	pqk[1].push(0);
	pqk[1].pop();

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}
	djk(1);
	for (int i = 1; i <= n; i++) {
		if (pqk[i].top() == INF) cout << -1 << '\n';
		else {
			cout << pqk[i].top() << '\n';
		}
	}
	
}