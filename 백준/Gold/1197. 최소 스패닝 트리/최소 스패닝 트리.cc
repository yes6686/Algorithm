#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>, 
	vector<pair<int, pair<int, int>>>, 
	greater<pair<int, pair<int, int>>>>pq;

int parent[10001];

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
	int V, E;
	cin >> V >> E;
	int A, B, C;

	for (int i = 1; i <= V; i++) parent[i] = i;
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		pq.push({ C,{A,B} });
	}
	int ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (!findParent(a, b)) {
			unionParent(a, b);
			ans += cost;
		}
	}
	cout << ans;
}