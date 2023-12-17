#include <iostream>
#include <algorithm>
using namespace std;

int parent[10001];
int co[10001];

struct edge {
	int x, y;
	int cost1;
	int cost2;
};

edge Ed[200001];

bool compare(edge a, edge b) {
	return a.cost1+a.cost2 < b.cost1+b.cost2;
}

int Getparent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Getparent(parent[x]);
}

void unionParent(int a, int b) {
	a = Getparent(a);
	b = Getparent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}

int findParent(int a, int b) {
	a = Getparent(a);
	b = Getparent(b);
	if (a == b) return 1;
	else return 0;
}


int main() {
	int n, p;
	cin >> n >> p;
	int minco = 1001;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> co[i];
		if (minco > co[i]) {
			minco = co[i];
		}
	}
	int a, b, c;
	int kk = 0;
	for (int i = 0; i < p; i++) {
		cin >> a >> b >> c;
		Ed[kk].x = a;
		Ed[kk].y = b;
		Ed[kk].cost1 = c + co[b];
		Ed[kk].cost2 = c + co[a];
		kk++;
		Ed[kk].x = b;
		Ed[kk].y = a;
		Ed[kk].cost1 = c + co[a];
		Ed[kk].cost2 = c + co[b];
		kk++;
	}
	long long int sum = 0;
	sort(Ed, Ed + kk, compare);
	for (int i = 0; i < kk; i++) {
		if (!findParent(Ed[i].x, Ed[i].y)) {
			unionParent(Ed[i].x, Ed[i].y);
			sum += Ed[i].cost1;
			sum += Ed[i].cost2;
		}
	}
	cout << sum+minco;

}