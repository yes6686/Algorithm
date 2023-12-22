#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>>v[1001];
priority_queue<pair<int,int>>pq;
int d[1001];
int go[1001];

void dsk(int x) {
	pq.push({0,x});

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int nx = pq.top().second;
		pq.pop();

		if (cost > d[nx]) continue;

		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			int ncost = v[nx][i].second;
			if (d[nnx] > ncost + cost) {
				d[nnx] = ncost + cost;
				pq.push({-d[nnx],nnx});
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m,x;
	cin >> n >> m>> x;
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({b,cost});
	}
	for (int t = 1; t <= n; t++) {
		if (t == x) continue;
		for (int i = 1; i <= n; i++) {
			d[i] = 1e9;
		}
		d[t] = 0;
		dsk(t);
		go[t] = d[x];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	dsk(x);
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		ans = max(ans, go[i] + d[i]);
	}
	cout << ans;

}