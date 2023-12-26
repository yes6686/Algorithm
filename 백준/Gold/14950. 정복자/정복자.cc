#include <iostream>
#include <algorithm>
using namespace std;

int parent[10001];

int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
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
	int x, y;
	int cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

edge Ed[30001];
int c[10001];

int main() {
	
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> Ed[i].x >> Ed[i].y >> Ed[i].cost;
	}

	sort(Ed, Ed + m, compare);
	int ac = 0;
	c[1] = 1;
	int sum = 0;
	int cnt = 0;
	while (1) {
		for (int i = 0; i < m; i++) {
			if (!findParent(Ed[i].x, Ed[i].y) &&(c[Ed[i].x]==1 || c[Ed[i].y] == 1)) {
				unionParent(Ed[i].x, Ed[i].y);
				sum += (Ed[i].cost) + (ac * t);
				ac++;
				c[Ed[i].x] = 1;
				c[Ed[i].y] = 1;
				cnt++;
				break;
			}
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << sum;





}
