#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>>v[1001];
priority_queue < pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
int d[1001];

int arr[101];

void dijkstra(int x) {
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int nx = pq.top().second;
		pq.pop();
		if (cost > d[nx]) continue;
		for (int i = 0; i < v[nx].size(); i++) {
			int nnx = v[nx][i].first;
			int ncost = v[nx][i].second;

			if (d[nnx] > cost + ncost) {
				d[nnx] = cost + ncost;
				pq.push(make_pair(d[nnx], nnx));
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,V, E;
	cin >>n>> V >> E;
	int a1, b1;
	cin >> a1 >> b1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b>>c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= V; j++) {
			d[j] = 1e9;
		}

		d[arr[i]] = 0;	
		dijkstra(arr[i]);
		if (d[a1] == 1e9) sum += -1;
		else sum += d[a1];
		if (d[b1] == 1e9) sum += -1;
		else sum += d[b1];

	}

	cout << sum;
}