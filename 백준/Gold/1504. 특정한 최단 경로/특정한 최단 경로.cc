#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>>v[801];
priority_queue<pair<int,int>>pq;
int d[801];
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

	int n, m;
	cin >> n >> m;
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	int v1, v2;
	cin >> v1 >> v2;

	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	dsk(v1);
	d[v1] = 0;
	int a1 = d[1]; // v1 ~ 1
	int b1 = d[v2]; // v1 ~ v2
	int end1 = d[n]; // v1 ~ end 

	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	dsk(v2);
	d[v2] = 0;
	int c1 = d[1]; // v2 ~ 1
	int end2 = d[n]; // v2 ~ end

	if (b1 == 1e9 || (a1==1e9 && b1==1e9 ) || (end1==1e9 && end2 ==1e9)) {
		cout << -1 << '\n';
	}
	else {
		int ans = a1 + b1 + end2 > c1 + b1 + end1 ? c1 + b1 + end1 : a1 + b1 + end2;
		cout << ans;
	}
}
