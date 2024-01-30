#include <iostream>
#include <queue>
using namespace std;

int parent[2001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
	}
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

pair<int,int> arr[2001];
priority_queue<pair<int, pair<int, int>>,
vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>>>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dis = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first)
				+ (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
			pq.push({dis,{i,j}});
		}
	}
	int ans = 0;
	int cnt = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (!findParent(a, b) && cost >= c) {
			ans += cost;
			unionParent(a, b);
			cnt++;
		}
	}
	if (cnt == n - 1) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}