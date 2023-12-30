#include <iostream>	
#include <algorithm>
using namespace std;

int parent[200001];
int GetParent(int x) {
	if (parent[x] == x) return x;

	return GetParent(parent[x]);
}

void unionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int findParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return 1;
	else return 0;
}

struct edge {
	int x;
	int y;
	int cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

edge Ed[200001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		int totalCost = 0;
		for (int i = 0; i < m; i++) {

			cin >> Ed[i].x >> Ed[i].y >> Ed[i].cost;
			totalCost += Ed[i].cost;
		}
		sort(Ed, Ed + m, compare);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			if (findParent(Ed[i].x, Ed[i].y) == 0) {
				unionParent(Ed[i].x, Ed[i].y);
				sum += Ed[i].cost;

			}
		}
		cout << totalCost - sum << '\n';

	}
}