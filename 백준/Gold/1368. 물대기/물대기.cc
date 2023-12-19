#include <iostream>
#include <algorithm>
using namespace std;

int parent[301];

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
	int a, b;
	int cost;
};

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}

int wi[301];
edge Ed[50001];
int c[301];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int s = 0;
	int x;

	for (int i = 1; i <= n; i++) {
		cin >> x;
		Ed[s].a = i;
		Ed[s].b = 0;
		Ed[s].cost = x;
		s++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			if (i < j) {
				Ed[s].a = i;
				Ed[s].b = j;
				Ed[s].cost = x;
				s++;
			}
		}
	}
	sort(Ed, Ed + s, compare);
	int sum = 0;
	for (int i = 0; i < s; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			sum += Ed[i].cost;
			
		}
	}
	cout << sum;

	


}
