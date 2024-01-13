#include <iostream>
using namespace std;

int arr[100001];
int ans[100001];
int tree[400001];
int init(int n, int s, int e) {
	if (s == e) {
		return tree[n] = 1;
	}
	return tree[n] = init(2 * n, s, (s + e) / 2) + init(2 * n + 1, (s + e) / 2 + 1, e);
}

int query(int n, int s, int e, int k) {

	if (s == e) {
		return s;
	}
	if (tree[2 * n] >= k) {
		return query(2 * n, s, (s + e) / 2, k);
	}
	else {
		return query(2 * n + 1, (s + e) / 2 + 1, e, k - tree[2 * n]);
	}
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
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	int s = 0;
	for (int i = n; i >= 1; i--) {
		int k = n - arr[i] - s;
		s++;
		ans[query(1, 0, n - 1, k) + 1] = i;
		update(1, 0, n - 1, query(1, 0, n - 1, k), 0);
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}