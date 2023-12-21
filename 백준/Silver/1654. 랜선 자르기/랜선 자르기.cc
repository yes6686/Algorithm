#include <iostream>
#include <algorithm>

using namespace std;
long long int arr[10001];


int main() {
	int k, n;
	cin >> k >> n;
	int max = -1;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	long long int start = 1;
	long long int end = max;
	long long int cnt = 0;
	long long int result=0;
	long long int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result = mid;
		}
	}
	cout << result << endl;
}