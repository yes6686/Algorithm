#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int parent[1001];
struct edge {
	int u, v;
	int d;
};


edge Ed[10001];
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

bool compare(edge a, edge b) {
	return a.d < b.d;
}

char s[1001];

int main() {

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> Ed[i].u >> Ed[i].v >> Ed[i].d;
	}

	sort(Ed, Ed + m, compare);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a = Ed[i].u;
		int b = Ed[i].v;
		 if (findParent(a, b) == 0 && s[a] != s[b] ) {
			unionParent(a, b);
			sum += Ed[i].d;
		}
	}
	int check = 1;
	int k = GetParent(1);
	for (int i = 2; i <= n; i++) {
		if (k != GetParent(i)) {
			check = 0;
			break;
		}
	}
	if (check == 1)
		cout << sum;
	else
		cout << -1;



}