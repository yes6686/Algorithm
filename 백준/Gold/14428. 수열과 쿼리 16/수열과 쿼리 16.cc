#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1000001];
struct Seg {
	int idx;
	int mi;
};

Seg seg[400001];
Seg go(int n, int s, int e) {
	if (s == e) {
		seg[n].mi = arr[s];
		seg[n].idx = s;
		return seg[n];
	}
	else {
		int mid = (s + e) / 2;
		Seg left = go(2 * n, s, mid);
		Seg right = go(2 * n + 1, mid + 1, e);
		if (left.mi < right.mi) {
			seg[n].mi = left.mi;
			seg[n].idx = left.idx;
		}
		else if (left.mi > right.mi) {
			seg[n].mi = right.mi;
			seg[n].idx = right.idx;
		}
		else {
			if (left.idx < right.idx) {
				seg[n].mi = left.mi;
				seg[n].idx = left.idx;
			}
			else {
				seg[n].mi = right.mi;
				seg[n].idx = right.idx;
			}
		}
		return seg[n];
	}
}

Seg ans;
Seg fi(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return ans;
	if (l <= s && r >= e) {
		return seg[n];
	}
	int mid = (s + e) / 2;
	Seg left = fi(n * 2, s, mid, l, r);
	Seg right = fi(n * 2 + 1, mid + 1, e, l, r);
	if (left.mi < right.mi) {
		ans.mi = left.mi;
		ans.idx = left.idx;
	}
	else if (left.mi > right.mi) {
		ans.mi = right.mi;
		ans.idx = right.idx;
	}
	else {
		if (left.idx < right.idx) {
			ans.mi = left.mi;
			ans.idx = left.idx;
		}
		else {
			ans.mi = right.mi;
			ans.idx = right.idx;
		}
	}
	return ans;
}

Seg change(int n, int s, int e, int i, int d) {
	if (i<s || i>e) return seg[n];
	if (s == e) {
		seg[n].idx = s;
		seg[n].mi = d;
		return seg[n];
	}
	if (s != e) {
		int mid = (s + e) / 2;
		Seg left = change(n * 2, s, mid, i, d);
		Seg right = change(n * 2 + 1, mid + 1, e, i, d);
		if (left.mi < right.mi) {
			seg[n].mi = left.mi;
			seg[n].idx = left.idx;
		}
		else if (left.mi > right.mi) {
			seg[n].mi = right.mi;
			seg[n].idx = right.idx;
		}
		else {
			if (left.idx < right.idx) {
				seg[n].mi = left.mi;
				seg[n].idx = left.idx;
			}
			else {
				seg[n].mi = right.mi;
				seg[n].idx = right.idx;
			}
		}
		return seg[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(1, 0, n - 1);
	cin >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b - 1] = c;
			change(1, 0, n - 1, b - 1, c);
		}
		else if (a == 2) {
			ans.idx = 100001;
			ans.mi = 1000000001;
			cout << fi(1, 0, n - 1, b - 1, c - 1).idx+1 << '\n';
		}
	}
}