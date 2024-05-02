#include <iostream>
using namespace std;

int arr[5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int maxIndex = 1;
	int maxAns = -1;
	for (int i = 0; i < n; i++) {
		int totalSum = 0;
		for (int t = 0; t < 5; t++) {
			cin >> arr[t];
			totalSum += arr[t];
		}
		for (int h = 0; h < 5; h++) {
			for (int j = h+1; j < 5; j++) {
				int k = (totalSum-arr[h]-arr[j])%10;
				if (maxAns <= k) {
					maxAns = k;
					maxIndex = i + 1;
				}
			}
		}
	}
	cout << maxIndex;
}