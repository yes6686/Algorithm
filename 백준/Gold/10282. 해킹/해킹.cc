#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[10001];
int dis[10001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

void djk(int x) {
	dis[x] = 0;
	pq.push({ dis[x],x});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].first;
			int next = v[cur][i].second;
			if (dis[next] > cost + ncost) {
				dis[next] = cost + ncost;
				pq.push({dis[next],next});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, d, c;
		cin >> n >> d >> c;
		int a, b, s;

		for (int i = 1; i <= n; i++) {
			dis[i] = INF;
		}

		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			v[b].push_back({ s,a });
		}
		djk(c);
		int cnt = 0;
		int maxAns = 0;
		for (int i = 1; i <= n; i++) {
			if (dis[i] != INF) {
				cnt++;
				maxAns = max(maxAns, dis[i]);
			}
		}
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		cout << cnt << ' ' << maxAns << '\n';
	}
}