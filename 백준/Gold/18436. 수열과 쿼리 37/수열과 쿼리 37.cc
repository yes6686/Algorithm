#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
struct Seg {
	int evenCnt; // 짝수의 갯수
	int oddCnt; // 홀수의 갯수
};

Seg seg[400001];
Seg go(int n, int s, int e) {
	if (s == e) {
		if (arr[s] % 2 == 0) {
			seg[n].evenCnt = 1;
			seg[n].oddCnt = 0;
		}
		else {
			seg[n].evenCnt = 0;
			seg[n].oddCnt = 1;
		}
		return seg[n];
	}
	else {
		int mid = (s + e) / 2;
		Seg left = go(2 * n, s, mid);
		Seg right = go(2 * n + 1, mid + 1, e);
		seg[n].evenCnt = left.evenCnt + right.evenCnt;
		seg[n].oddCnt = left.oddCnt + right.oddCnt;
		return seg[n];
	}
}

Seg ans;
Seg fi(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return ans;
	if (l <= s && r >= e) {
		ans.evenCnt += seg[n].evenCnt;
		ans.oddCnt += seg[n].oddCnt;
		return seg[n];
	}
	int mid = (s + e) / 2;
	Seg left = fi(n * 2, s, mid, l, r);
	Seg right = fi(n * 2 + 1, mid + 1, e, l, r);
	return ans;
}

Seg change(int n, int s, int e, int i, int d) {
	if (i<s || i>e) return seg[n];
	if (s == e) {
		if (arr[s] % 2 == 0) {
			seg[n].evenCnt = 1;
			seg[n].oddCnt = 0;
		}
		else {
			seg[n].evenCnt = 0;
			seg[n].oddCnt = 1;
		}
		return seg[n];
	}
	if (s != e) {
		int mid = (s + e) / 2;
		Seg left = change(n * 2, s, mid, i, d);
		Seg right = change(n * 2 + 1, mid + 1, e, i, d);

		seg[n].evenCnt = left.evenCnt + right.evenCnt;
		seg[n].oddCnt = left.oddCnt + right.oddCnt;
		return seg[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
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
			ans.oddCnt = 0;
			ans.evenCnt = 0;
			cout << fi(1, 0, n - 1, b-1,c - 1).evenCnt << '\n';
		}
		else {
			ans.oddCnt = 0;
			ans.evenCnt = 0;
			cout << fi(1, 0, n - 1, b-1, c - 1).oddCnt << '\n';
		}
	}
}