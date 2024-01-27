#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[2001];
int dis_s[2001];
int dis_h[2001];
int dis_g[2001];
priority_queue<int,vector<int>,greater<int>>desCandidateQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

void djk(int x,int dis[2001]) {
	for (int i = 1; i <= 2000; i++) {
		dis[i] = INF;
	}
	dis[x] = 0;
	pq.push({ dis[x],x});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i<v[cur].size(); i++) {
			int ncost = v[cur][i].first;
			int next = v[cur][i].second;
			if (dis[next] > cost + ncost) {
				dis[next] = cost + ncost;
				pq.push({ dis[next],next });
			}
		}
	}
}
int ans[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		int a, b, d;
		int GHlen;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			v[a].push_back({ d,b });
			v[b].push_back({ d,a });
			if ((a == g && b == h) || (a == h && b == g)) {
				GHlen = d;
			}
		}
		djk(s, dis_s);
		djk(h, dis_h);
		djk(g, dis_g);
		int x;
		for (int i = 0; i < t; i++) {
			cin >> x;
			desCandidateQ.push(x);
		}
		while (!desCandidateQ.empty()) {
			int k = desCandidateQ.top();
			desCandidateQ.pop();
			if ((dis_s[k] == dis_s[g] + GHlen + dis_h[k]) ||
				(dis_s[k] == dis_s[h] + GHlen + dis_g[k])) {
				cout << k << ' ';
			}
			
		}
		for (int i = 1; i <= n; i++) {
			v[i].clear();
		}
		cout << '\n';
	}
}