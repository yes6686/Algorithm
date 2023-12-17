#include <iostream>	
#include <algorithm>
using namespace std;

int parent[1001];
struct edge {
	int x, y;
	char cost;
};



edge Ed[500001];
edge St[500001];

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
	return a.cost > b.cost;
}
bool compare2(edge a, edge b) {
	return a.cost < b.cost;
}

int main() {
	int n, m, k;
	
	while (1) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < m; i++) {
			cin >> Ed[i].cost >> Ed[i].x >> Ed[i].y;

		}
		sort(Ed, Ed + m, compare1);
		int minblueCnt = 0;
		for (int i = 0; i < m; i++) {
			if (!findParent(Ed[i].x, Ed[i].y)) {
				unionParent(Ed[i].x, Ed[i].y);
				if (Ed[i].cost == 'B') minblueCnt++;
			}
		}
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		sort(Ed, Ed + m, compare2);
		int maxblueCnt = 0;
		for (int i = 0; i < m; i++) {
			if (!findParent(Ed[i].x, Ed[i].y)) {
				unionParent(Ed[i].x, Ed[i].y);
				if (Ed[i].cost == 'B') maxblueCnt++;
			}
		}
		//cout << "Max : " << maxblueCnt << '\n';
		//cout << "Min : " << minblueCnt << '\n';
		if (k <= maxblueCnt && k >= minblueCnt) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}

	}

}