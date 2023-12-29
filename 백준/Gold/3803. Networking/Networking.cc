#include <iostream>	
#include <algorithm>
using namespace std;

int parent[1001];
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

edge Ed[20001];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> m;

		if (m == 0) {
			cout << 0 << '\n';
		}
		else {
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

			for (int i = 0; i < m; i++) {
				if (findParent(Ed[i].x, Ed[i].y) == 0) {
					unionParent(Ed[i].x, Ed[i].y);
					sum += Ed[i].cost;
				}
			}
			int check = 1;
			int k = GetParent(1);
			for (int i = 2; i <= n; i++) {
				if (k != GetParent(i)) {
					check = 0;
				}
			}
			if (check)
				cout << sum<<'\n';
			else {
				cout << -1<<'\n';
			}
		}
	}
}