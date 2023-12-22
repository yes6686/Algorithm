#include <iostream>
#include <algorithm>
using namespace std;

int parent[1001];

int c[1001];
int cc[1001];
struct edge {
	int u, v;
	int cost;
};


edge Ed[100001];
int GetParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent[x]);
}


void unionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (c[a] == 1) {
		parent[b] = a;
	}
	else if (c[b] == 1) {
		parent[a] = b;
	}
	else if (a > b) parent[a] = b;
	else parent[b] = a;

}

int findParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) return 1;
	else return 0;

}

bool compare(edge a, edge b) {
	return a.cost < b.cost;
}


int main() { 


	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		c[x] = 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> Ed[i].u >> Ed[i].v >> Ed[i].cost;
		
	}
	sort(Ed, Ed + m, compare);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (!findParent(Ed[i].u, Ed[i].v)) {
			
			
			if (c[Ed[i].u] == 1 && c[Ed[i].v] == 1) {
				unionParent(Ed[i].u, Ed[i].v);
				continue;
			}


			if (c[Ed[i].u] == 1 && c[Ed[i].v] == 0) {
				int k = GetParent(Ed[i].v);
				if (c[k] == 0) {
					sum += Ed[i].cost;
					unionParent(Ed[i].u, Ed[i].v);
				}
			}
			else if (c[Ed[i].u] == 0 && c[Ed[i].v] == 1) {
				int k = GetParent(Ed[i].u);
				if (c[k] == 0) {
					sum += Ed[i].cost;
					unionParent(Ed[i].u, Ed[i].v);
				}
			}
			else {
				int a = GetParent(Ed[i].u);
				int b = GetParent(Ed[i].v);
				if (c[a] == 0 || c[b] == 0) {
					sum += Ed[i].cost;
					unionParent(Ed[i].u, Ed[i].v);
				}
			}
			
			
		}
	}
	cout << sum;




	
}