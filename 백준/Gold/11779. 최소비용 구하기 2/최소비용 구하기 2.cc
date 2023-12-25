#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>>pq;
vector<int>vv;
int d[1001];
int go[1001];
int n, m;

void dsk(int x) {
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int nx = pq.top().second;
		pq.pop();

		if (d[nx] < cost) continue;
		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			int ncost = v[nx][i].second;
			if (d[nnx] > ncost + cost) {
				go[nnx] = nx;
				d[nnx] = ncost + cost;
				pq.push({ -d[nnx],nnx});
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n>> m;

	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
	}
	int start, end;
	cin >> start >> end;
	d[start] = 0;
	dsk(start);
	cout << d[end]<<'\n';
	int k = end;

	int cnt = 0;
	vv.push_back(k);
	while (1) {
		cnt++;
		vv.push_back(go[k]);
		k = go[k];
		if (k == start) break;
	}
	cout << cnt + 1 << '\n';
	while (!vv.empty()) {
		int kk = vv.back();
		vv.pop_back();
		cout << kk << ' ';
	}
	

}