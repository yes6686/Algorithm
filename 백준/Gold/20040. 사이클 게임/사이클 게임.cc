#include <iostream>
using namespace std;

int parent[500001];

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}int x, y;
	int cnt = 0;
	int ans = 0;
	int check = 1;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (!findParent(x, y)) {
			unionParent(x, y);
			cnt++;
		}
		else {
			cnt++;
			if (check) {
				ans = cnt;
				check = 0;
			}

		}
	}
	cout << ans;
	
}