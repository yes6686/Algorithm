#include <iostream>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k, n;
	cin >> k >> n;
	int maxL = 1;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		maxL = max(maxL, arr[i]);
	}

	long long int s = 1;
	long long int e = maxL;
	long long int m = (s+e)/2;
	int r = 0;
	while (s<=e) {
		m = (s + e) / 2;
		long long int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (arr[i]) / m;
		}
		if (cnt < n) {
			e = m - 1;
		}
		else {
			s = m + 1;
			r = m;
		}
	}
	cout << r;
}