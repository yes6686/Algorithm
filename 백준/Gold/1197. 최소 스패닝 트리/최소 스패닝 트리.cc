#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,pair<int,int>>>v;

int parent[10001];

int getParent(int n) {

	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = getParent(parent[n]);
	}
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int findParent(int a, int b) {
	return getParent(a) == getParent(b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
		v.push_back({ c,{b,a} });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		if (!findParent(x, y)) {
			unionParent(x, y);
			ans += v[i].first;
		}
	}
	cout << ans << '\n';	
}