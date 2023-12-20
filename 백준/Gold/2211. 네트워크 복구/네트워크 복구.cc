#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>>v[1001];
priority_queue<pair<int, int>>pq;

int d[1001];
int go[1001];
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
    
    int n, m;
	cin >> n>> m;

	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	d[1] = 0;
	dsk(1);

	cout << n - 1 << '\n';

	for (int i = 2; i <= n; i++) {
	
		cout << i << ' ' << go[i] << '\n';
	}
	

}