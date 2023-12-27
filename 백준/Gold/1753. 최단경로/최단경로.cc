#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>>v[20001];
priority_queue < pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
int d[20001];

void dijkstra(int x) {
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int nx = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			int ncost = v[nx][i].second;

			if (d[nnx] > cost + ncost) {
				d[nnx] = cost + ncost;
				pq.push(make_pair(d[nnx], nnx));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E;
	cin >> V >> E;
	int k;
	cin >> k;
	int a, b, c;
	
	for (int i = 1; i <= V; i++) {
		d[i] = 1e9;
	}
	d[k] = 0;
	for (int i = 0; i < E; i++) {
		cin >> a >> b>>c;
		v[a].push_back(make_pair(b, c));
	}
	dijkstra(k);
	for (int i = 1; i <= V; i++) {
		if (d[i] == 1e9) { cout << "INF" << '\n'; }
		else {
			cout << d[i] << '\n';
		}
	}
}