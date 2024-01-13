#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>arr;
int tree[4000001];
int init(int n, int s, int e) {
	if (s == e) {
		return tree[n] = 1;
	}
	return tree[n] = init(2 * n, s, (s + e) / 2) + init(2 * n + 1, (s + e) / 2 + 1, e);
}

int sum(int n, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[n];

	return sum(2 * n, s, (s + e) / 2, l, r) + sum(2 * n + 1, (s + e) / 2 + 1, e, l, r);
}

void update(int n, int s, int e, int i, int v) {
	if (i < s || e < i) return;
	if (s == e) {
		tree[n] = v;
		return;
	}
	else {
		update(2 * n, s, (s + e) / 2, i, v);
		update(2 * n + 1, (s + e) / 2 + 1, e, i, v);
		tree[n] = tree[2 * n] + tree[2 * n + 1];
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back({ x,i });
	}
	sort(arr.begin(), arr.end());
	init(1, 0, n - 1);
	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		int k = arr[i].second;
		ans += sum(1, 0, n - 1, 0, k - 1);
		update(1, 0, n - 1, k, 0);
	}
	cout << ans;
}