#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int,int>>v[201];
int dis[201][201];
int longDis[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s, e, l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dis[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> l;
		v[s].push_back({ l,e });
		v[e].push_back({ l,s });
		
		if (longDis[s][e] < l) {
			longDis[s][e] = l;
			longDis[e][s] = l;
		}

		dis[s][e] = min(dis[s][e], l);
		dis[e][s] = min(dis[e][s], l);
	}
	for (int k = 1; k <= n; k++) { //플로이드-워셜 알고리즘
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	double minAns = INF;
	for (int i = 1; i <= n; i++) {
		double kk = 0;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (longDis[x][y] != 0) {
					double k = dis[i][y] - dis[i][x];
					if (kk < dis[i][x] + (k + (longDis[x][y] - k) / 2)) {
						kk = dis[i][x] + (k + (longDis[x][y] - k) / 2);
					}
				}
			}
		}
		if (minAns > kk) {
			minAns = kk;
		}
	}
	
	cout << fixed;
	cout.precision(1);
	cout << minAns<<'\n';
}