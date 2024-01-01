#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1000001];
long long int seg[4000001];


long long int go(int n, int s, int e) {
	if (s == e) {
		return seg[n] = arr[s];
	}
	else {
		int mid = (s + e) / 2;
		long long int left = go(2 * n, s, mid);
		long long int right = go(2 * n + 1, mid + 1, e);
		seg[n] = (left * right) % 1000000007;
		return seg[n];
	}
}

long long int mul(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return 1;
	if (l <= s && r >= e) {
		return seg[n];
	}
	int mid = (s + e) / 2;
	long long int left = mul(n * 2, s, mid, l, r);
	long long int right = mul(n * 2 + 1, mid + 1, e, l, r);
	return (left * right) % 1000000007;
}

int change(int n, int s, int e, int i, long long int d) {
	if (i<s || i>e) return seg[n];
	if (s == e) {
		seg[n] = d;
		return seg[n] % 1000000007;
	}
	if (s != e) {
		int mid = (s + e) / 2;
		long long int left = change(n * 2, s, mid, i, d);
		long long int right =  change(n * 2 + 1, mid + 1, e, i, d);
		return seg[n] = (left*right)% 1000000007;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(1, 0, n - 1);
	long long int a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b - 1] = c;
			change(1, 0, n - 1, b - 1, c);
		}
		else if (a == 2) {
			cout << mul(1, 0, n - 1, b - 1, c - 1) % 1000000007 << '\n';
		}
	}
}