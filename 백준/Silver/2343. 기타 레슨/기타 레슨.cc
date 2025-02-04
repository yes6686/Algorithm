#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int sum = 0;
	int maxV = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		maxV = max(maxV, arr[i]);
	}

	int s = maxV;
	int e = sum;
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int sm = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			sm += arr[i];
			if (sm > mid) {
				cnt++;
				sm = 0;
				i--;
			}
		}
		if (sm > 0) cnt++;

		if (cnt <= m) {
			e = mid - 1;
			ans = mid;
		}
		else if (cnt > m) {
			s = mid + 1;
		}
	}
	cout << ans << '\n';
}