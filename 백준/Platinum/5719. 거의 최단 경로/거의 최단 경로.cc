#include <iostream>
#include <string.h> //memset 사용
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int, int>>v[501];
vector<int>vI[501]; // Inverse vector
int dis[501];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>>pq;

void djk(int x,int n) {
	for (int i = 0; i < n; i++) {
		dis[i] = INF;
	}
	dis[x] = 0;
	pq.push({ dis[x],x });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int ncost = v[cur][i].first;
			int next = v[cur][i].second;
			if (ncost == -1) continue; 
			if (dis[next] > ncost + cost) {
				dis[next] = ncost + cost;
				pq.push({ dis[next],next });
				vI[next].clear();
				vI[next].push_back(cur);
			}
			else if (dis[next] == ncost + cost) {
				vI[next].push_back(cur);
			}
		}
	}
}

queue<int>q;
int visited[501];
void eraser(int x) {
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (int i = 0; i < vI[cur].size(); i++) {
			int next = vI[cur][i];
			for (int j = 0; j < v[next].size(); j++) {
				if (v[next][j].second == cur) {
					v[next][j].first = -1;
				}
			}
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		int S, D;
		cin >> S >> D;
		int U, V, P;
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			v[U].push_back({ P,V });
		}
		djk(S, N);
		eraser(D);
		djk(S, N);
		if (dis[D] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << dis[D] << '\n';
		}
		for (int i = 0; i < N; i++) {
			v[i].clear();
			vI[i].clear();
		}
		memset(visited, 0, sizeof(visited));
	}
}