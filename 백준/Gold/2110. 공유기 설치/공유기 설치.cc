#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int s = 1;
	int e = arr[n-1]-arr[0];
	int ans = 1;
	while (s <= e) {
		int curIdx = 0;
		int m = (s + e) / 2;
		int cnt = 0;
		for (int i = curIdx+1; i < n; i++) {
			if (arr[i] - arr[curIdx] >= m) {
				cnt++;
				curIdx = i;
			}
		}
		if (cnt >= k-1) {
			s = m + 1;
			ans = m;
		}
		else {
			e = m - 1;
		}
	}
	cout << ans << '\n';
}