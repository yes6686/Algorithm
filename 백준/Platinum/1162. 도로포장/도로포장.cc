#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct moo {

	int nx;
	long long int cost;
	int cnt;
};

struct cmp {

	bool operator() (moo &a, moo &b){
		return a.cost > b.cost;
	}
};

priority_queue<moo,vector<moo>,cmp>pq;
vector<pair<int, long long int>>v[10001];

int n, m, k;
long long int d[10001][22];


void dsk(int x) {
	pq.push({ x,0,0 });

	while (!pq.empty()) {
		long long int cost = pq.top().cost;
		int nx = pq.top().nx;
		int cnt = pq.top().cnt;
		pq.pop();
		if (d[nx][cnt] < cost) continue;
		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			long long int ncost = v[nx][i].second;

			if (d[nnx][cnt] > ncost + cost) {
				d[nnx][cnt] = ncost + cost;
				pq.push({ nnx,d[nnx][cnt],cnt });
			}
			if (cnt >= k) continue;
			if (d[nnx][cnt + 1] > 0 + cost) {
				d[nnx][cnt + 1] = 0 + cost;
				pq.push({ nnx,d[nnx][cnt + 1],cnt+1 });
			}



		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	
	int a, b, cost;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			d[i][j] = 9223372036854775800;
		}
	}
	dsk(1);
	long long ans = 9223372036854775800;
	for (int i = 0; i <= k; i++) {
		ans = min(ans,d[n][i]);
	}
	cout << ans;

}