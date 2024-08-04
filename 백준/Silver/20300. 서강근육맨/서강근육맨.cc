#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long int M = 0;
	if (n % 2 == 0) {
		for (int i = 0; i < n/2; i++) {
			M = max(M, arr[i] + arr[n - i - 1]);
		}
	}
	else {
		M = arr[n - 1];
		for (int i = 0; i < (n-1) / 2; i++) {
			M = max(M, arr[i] + arr[n - i - 2]);
		}
	}
	cout << M;
}