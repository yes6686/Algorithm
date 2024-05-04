#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;
	cin >> m >> n;
	int maxL = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxL = max(maxL, arr[i]);
	}
	int s = 1;
	int e = maxL;
	int r = 0;
	while (s <= e) {
		int mid = (s + e) / 2;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < m) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
			r = mid;
		}
	}
	cout << r;
}