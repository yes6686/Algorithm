#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int parent[1001];
struct edge {
	double h1, h2;
	double k;
};

struct spot {
	double x,y;
};

edge Ed[500001];
spot S[1001];
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
	return a.k < b.k;
}



int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> S[i].x >> S[i].y;
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (i != j) {
				Ed[s].h1 = i;
				Ed[s].h2 = j;
				Ed[s].k = sqrt((S[i].x - S[j].x) * (S[i].x - S[j].x) +
					(S[i].y - S[j].y) * (S[i].y - S[j].y));
				s++;
			}
		}
	}
	sort(Ed, Ed + s, compare);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		unionParent(a, b);
	}
	double sum = 0;
	for (int i = 0; i < s; i++) {
		if (!findParent(Ed[i].h1, Ed[i].h2)) {
			unionParent(Ed[i].h1, Ed[i].h2);
			sum += Ed[i].k;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;

}