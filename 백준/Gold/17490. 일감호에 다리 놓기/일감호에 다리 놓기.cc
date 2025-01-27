#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,pair<int,int>>>v;


int ch[1000001];
int parent[1000001];

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

	int n, m;
	long long int k;
	cin >> n >> m >> k;

	if (m <= 1) {
		cout << "YES" << '\n';
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({x, { i + 1,n+1 }});
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (a == 1 && b == n) {
			ch[b] = 1;
		}
		else {
			ch[a] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ch[i] == 0) {
			if (i == n) {
				v.push_back({ 0,{1,n} });
			}
			else {
				v.push_back({ 0,{i,i + 1} });
			}
		}
	}
	sort(v.begin(), v.end());
	long long int totalMinWeight = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		int w = v[i].first;
		if (!findParent(x, y)) {
			unionParent(x, y);
			totalMinWeight += w;
		}
	}
	if (k < totalMinWeight) {
		cout << "NO" << '\n';
	}
	else {
		cout << "YES" << '\n';
	}

}