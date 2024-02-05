#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>>v[100001];
int ans = 0;
int ve = 0;

void dfs(int x, int d, int p) {
	if (ans < d) {
		ans = d;
		ve = x;
	}
	for (int i = 0; i < v[x].size(); i++) {
		int cost = v[x][i].first;
		int k = v[x][i].second;
		if (k != p) {
			dfs(k, d + cost, x);
		}
	}
}

int main() {
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		while (1) {
			int y,cost;
			cin >> y;
			if (y == -1) break;
			else {
				cin >> cost;
			}
			v[x].push_back({ cost,y });
		}
	}
	dfs(1, 0, 1);
	dfs(ve, 0, ve);
	cout << ans;
}