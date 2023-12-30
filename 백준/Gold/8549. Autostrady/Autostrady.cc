#include <iostream>	
#include <algorithm>
using namespace std;

int parent[100001];
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

edge Ed[100001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n>>m;


		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		int x;
		int s = 0;
		for (int i = 0; i < m; i++) {
			cin >> Ed[i].x >> Ed[i].y >> Ed[i].cost;
	}

		sort(Ed, Ed + m, compare);
		long long int sum = 0;
		int max = -1;
		for (int i = 0; i < m; i++) {
			if (findParent(Ed[i].x, Ed[i].y) == 0) {
				unionParent(Ed[i].x, Ed[i].y);
				sum += Ed[i].cost;
				if (max < Ed[i].cost) {
					max = Ed[i].cost;
				}
			}
		}
		cout << max;
	
}