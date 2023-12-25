#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int parent[1001];
struct edge {
	int a, b;
	int c;
};


edge Ed[500001];
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

bool compare1(edge a, edge b) {
	return a.c > b.c;
}
bool compare2(edge a, edge b) {
	return a.c < b.c;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m+1; i++) {
		cin >> Ed[i].a >> Ed[i].b >> Ed[i].c;
	}
	sort(Ed, Ed + m + 1, compare1);
	int k1 = 0;
	for (int i = 0; i < m + 1; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			if (Ed[i].c == 0) {
				k1++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(Ed, Ed + m + 1, compare2);
	int k2 = 0;
	for (int i = 0; i < m + 1; i++) {
		if (!findParent(Ed[i].a, Ed[i].b)) {
			unionParent(Ed[i].a, Ed[i].b);
			if (Ed[i].c == 0) {
				k2++;
			}
		}
	}
	cout << k2 * k2-k1*k1;


}