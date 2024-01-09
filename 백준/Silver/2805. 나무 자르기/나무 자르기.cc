#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	int n, m;
	cin >> n >> m;
	int max = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	long long int start = 0;
	long long int end = max;
	long long int mid;
	long long int cnt = 0;
	long long int result = 0;
	while (start <= end) {
		mid = (start + end)/2;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if(arr[i]>=mid)
			cnt += arr[i] - mid;
		}
		if (cnt < m) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;

}