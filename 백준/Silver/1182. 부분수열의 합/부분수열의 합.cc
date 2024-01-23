#include <iostream>
#include <algorithm>
using namespace std;

int arr[21];
int n, s;
int ans = 0;

void solve(int depth, int a) {
	if (a == s && depth) {
		ans++;
	}
	if (depth >= n) return;
	for (int i = depth+1; i <= n; i++) {
		solve(i, a + arr[i-1]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i< n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0, 0);
	cout << ans;
}