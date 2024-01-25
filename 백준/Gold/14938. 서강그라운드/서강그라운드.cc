#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int arr[101];
int dis[101];
vector<pair<int, int>>v[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

int n, m, r;

void djk(int x) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	pq.push({ 0,x });
	dis[x] = 0;
	while (!pq.empty()) {
		int len = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[y].size(); i++) {
			int k = v[y][i].second;
			if (dis[k] > len + v[y][i].first) {
				dis[k] = len + v[y][i].first;
				pq.push({ dis[k],k });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int a, b, l;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		v[a].push_back({ l,b });
		v[b].push_back({ l,a });
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		djk(i);
		for (int j = 1; j <= n; j++) {
			if (dis[j] <= m) {
				sum += arr[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
}