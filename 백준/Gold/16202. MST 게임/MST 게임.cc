#include <iostream>
using namespace std;

int parent[1001];

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


edge Ed[500001];

int main() {
	
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> Ed[i].x >> Ed[i].y;
		Ed[i].cost = i + 1;
	}
	int s = 0;
	int check = 1;
	while (k--) {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		if (check == 0) {
			cout << 0 << ' ';
		}
		else {
			int sum = 0;
			int cnt = 0;
			for (int i = s; i < m; i++) {
				if (!findParent(Ed[i].x, Ed[i].y)) {
					unionParent(Ed[i].x, Ed[i].y);
					sum += Ed[i].cost;
					cnt++;
				}
			}

			if (cnt == n - 1) {
				cout << sum << ' ';
				s++;
			}
			else {
				check = 0;
				cout << 0 << ' ';
			}
		}
	}
	


}
