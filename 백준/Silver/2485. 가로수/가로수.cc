#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int gcd(int a, int b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int k = gcd(arr[1]-arr[0], arr[2]-arr[1]);
	for (int i = 3; i < n; i++) {
		k = gcd(k, arr[i] - arr[i - 1]);
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (arr[i] - arr[i - 1]) / k - 1;
	}
	cout << ans;
}