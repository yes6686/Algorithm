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
		seg[n] = left + right;
		return seg[n];
	}
}

long long int sum(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && r >= e) {
		return seg[n];
	}
	int mid = (s + e) / 2;
	long long int left = sum(n * 2, s, mid, l, r);
	long long int right = sum(n * 2+1, mid+1, e, l, r);
	return left + right;
}

void change(int n, int s, int e, int i, long long int d) {
	if (i<s || i>e) return;
	seg[n] += d;
	if (s != e) {
		int mid = (s + e) / 2;
		change(n * 2, s, mid, i, d);
		change(n * 2+1, mid+1, e, i, d);
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
			long long int di = c - arr[b-1];
			arr[b-1] = c;
			change(1, 0, n - 1, b-1, di);
		}
		else if (a == 2) {
			cout << sum(1, 0, n - 1, b-1, c-1)<<'\n';
		}
	}
}