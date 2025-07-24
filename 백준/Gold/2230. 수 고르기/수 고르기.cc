#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int minAns = arr[n - 1] - arr[0];
	for (int i = 0;i < n - 1;i++) {
		int target = m + arr[i];
		int idx = lower_bound(arr + (i + 1), arr + n, target) - arr;
		if (idx >= n) continue;
		minAns = min(minAns, arr[idx] - arr[i]);
	}
	cout << minAns;
}