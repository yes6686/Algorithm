#include <iostream>
#include <algorithm>
#define INF 2000000000
using namespace std;

int arr[100001];
int seg[300001];


int go(int n, int s, int e) {
	if (s == e) {
		seg[n] = s;
		return seg[n];
	}
	else {
		int mid = (s + e) / 2;
		int left = go(2 * n, s, mid);
		int right = go(2 * n + 1, mid + 1, e);
		if (arr[left] > arr[right]) {
			seg[n] = right;
		}
		else {
			seg[n] = left;
		}
		return seg[n];
	}
}

int fi(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return INF;
	if (l <= s && r >= e) {
		return seg[n];
	}
	int mid = (s + e) / 2;
	int left = fi(n * 2, s, mid, l, r);
	int right = fi(n * 2 + 1, mid + 1, e, l, r);
	if (left == INF) return right;
	if (right == INF) return left;
	return arr[left] < arr[right] ? left : right;
}
int maxArea = -1;
int n;
void solve(int s, int e) {
	if (s > e) return;

	int index = fi(1, 0, n - 1, s, e);
	maxArea = max(maxArea, arr[index] * (e - s + 1));
	solve(s, index - 1);
	solve(index+1, e);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(1, 0, n - 1);
	solve(0, n - 1);
	cout << maxArea;
}