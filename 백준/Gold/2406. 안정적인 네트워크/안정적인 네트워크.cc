#include <iostream>
#include <queue>
using namespace std;

int parent[1001];

priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>>>pq;

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		unionParent(x, y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i == 1 || j == 1 || i == j) continue;
			pq.push({ cost,{i,j} });
		}
	}
	int X = 0; // 최소 비용
	int K = 0; // 쌍의 개수
	queue<pair<int, int>>q;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (!findParent(x, y)) {
			unionParent(x, y);
			K++;
			X += cost;
			q.push({ x,y });
		}
	}
	cout << X << ' ' << K << '\n';
	while (!q.empty()) {
		cout << q.front().first << ' ' << q.front().second << '\n';
		q.pop();
	}
	
}