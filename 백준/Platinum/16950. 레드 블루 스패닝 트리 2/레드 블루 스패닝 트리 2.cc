#include <iostream>	
#include <algorithm>
#include <queue>
using namespace std;

int parent[1001];
int c[1001][1001];
queue<pair<int, int>>q;
struct edge {
	int x, y;
	char cost;
};

struct re {
	int rx, ry;
};


edge Ed[500001];
edge St[500001];
re R[500001];

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
	
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < m; i++) {
			cin >> Ed[i].cost >> Ed[i].x >> Ed[i].y;

		}
		sort(Ed, Ed + m, compare1);
		int minblueCnt = 0;
		int kk = 0;
		for (int i = 0; i < m; i++) {
			if (!findParent(Ed[i].x, Ed[i].y)) {
				unionParent(Ed[i].x, Ed[i].y);
				if (Ed[i].cost == 'B') {
						c[Ed[i].x][Ed[i].y] = 1;
						c[Ed[i].y][Ed[i].x] = 1;
						R[kk].rx = Ed[i].x;
						R[kk].ry = Ed[i].y;
						kk++;
					minblueCnt++;
				}
				
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
				if (Ed[i].cost == 'B') {
					if (c[Ed[i].x][Ed[i].y] == 0) {
						R[kk].rx = Ed[i].x;
						R[kk].ry = Ed[i].y;
						kk++;
					}
					maxblueCnt++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		int cc = 0;
		for (int i = 0; i < kk; i++) {
			if (!findParent(R[i].rx, R[i].ry)) {
				unionParent(R[i].rx, R[i].ry);
				cc++;
				q.push(make_pair(R[i].rx, R[i].ry));
				if (cc == k) break;
			}
		}

		sort(Ed, Ed + m, compare1);
		for (int i = 0; i < m; i ++) {
			if (Ed[i].cost == 'R') {
				if (!findParent(Ed[i].x, Ed[i].y)) {
					unionParent(Ed[i].x, Ed[i].y);
					q.push(make_pair(Ed[i].x, Ed[i].y));
					//kk++;
				}
			}
		}
		
		if (k <= maxblueCnt && k >= minblueCnt) {
			while (!q.empty()) {
				cout << q.front().first << ' ' << q.front().second << '\n';
				q.pop();
			}
		}
		else {
			cout << 0 << '\n';
		}
	

	

}