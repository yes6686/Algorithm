#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int d[1001];
vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>,
	vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dsk(int x) {
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int nx = pq.top().second;
		pq.pop();

		if (cost > d[nx]) continue;

		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			int ncost = v[nx][i].second;
			if (d[nnx] > ncost + cost) {
				d[nnx] = ncost + cost;
				pq.push(make_pair(d[nnx], nnx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b, cost;
	for (int i = 0; i <= n; i++) {
		d[i] = 1e9;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back(make_pair(b, cost));
	}
	
	int start, last;
	cin >> start >> last;
	d[start] = 0;
	dsk(start);


	cout << d[last] << '\n';
	
}