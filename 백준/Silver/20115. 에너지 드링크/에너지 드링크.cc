#include <iostream>
#include <algorithm>
using namespace std;

double arr[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	double ans = arr[n-1];
	for (int i = 0; i < n - 1; i++) {
		ans += arr[i] / 2;
	}
	cout << ans;
}