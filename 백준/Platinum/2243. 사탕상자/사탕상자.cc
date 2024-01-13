#include <iostream>
using namespace std;

int arr[1000001];
int tree[4000001];

int query(int n, int s, int e, int d) {
	if (s == e) return e;
	if (tree[2 * n] >= d) {
		return query(2 * n, s, (s + e) / 2, d);
	}
	else {
		return query(2 * n+1, (s+e)/2+1, e, d-tree[2*n]);
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
		update(2 * n+1, (s+e)/2+1, e, i, v);
		tree[n] = tree[2 * n] + tree[2 * n + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			int k = query(1, 0, 1000000, b);
			cout << k+1 << '\n';
			arr[k] -= 1;
			update(1, 0, 1000000, k, arr[k]);
		}
		else if (a == 2) {
			cin >> b >> c;
			arr[b-1] += c;
			update(1, 0, 1000000, b-1, arr[b-1]);
		}
	}
}