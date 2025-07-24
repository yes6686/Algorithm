#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int ans = 2e9;  // 최대값으로 초기화
	int left = 0, right = 0;

	while (right < n) {
		int diff = arr[right] - arr[left];

		if (diff >= m) {
			ans = min(ans, diff);
			left++;
		}
		else {
			right++;
		}
	}

	cout << ans;
}
