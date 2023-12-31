#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>>v[101];
int d[101];
priority_queue<pair<int, int>>pq;

void dsk(int x) {
	pq.push({ 0,x });
	while (!pq.empty()) {
		int ncost = -pq.top().first;
		int nx = pq.top().second;
		pq.pop();
		if (ncost > d[nx]) continue;
		for (int i = 0; i < v[nx].size(); i++) {
			int kx = v[nx][i].first;
			int kcost = v[nx][i].second;
			if (d[kx] > kcost + ncost) {
				d[kx] = kcost + ncost;
				pq.push({ -d[kx],kx });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int a, b, cost;
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({b,cost});
	
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			d[i] = 1e9;
		}
		d[j] = 0;
		dsk(j);
		for (int i = 1; i <= n; i++) {
			if (d[i] == 1e9) {
				cout << 0 << ' ';
			}else
			cout << d[i] << ' ';
		}
		cout << '\n';
	}

}