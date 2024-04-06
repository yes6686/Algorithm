#include <iostream>
using namespace std;

int arr[100001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int maxAns = -10000001;
	
	int t = 0;
	for (int i = 0; i < k; i++) {
		t += arr[i];
	}

	maxAns = max(maxAns, t);

	for (int i = k; i < n; i++) {
		int tt = t + arr[i] - arr[i - k];
		t = tt;
		maxAns = max(maxAns, tt);
	}
	cout << maxAns;
}