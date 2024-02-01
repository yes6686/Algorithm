#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sum = 0;
	int n;
	cin >> n;
	int a[51];
	int b[51];
	int k = 100;
	int c[51];
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // 1 1 1 6 0
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];   // 2 7 8 3 1
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		c[i] = k - b[i];
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++) {
		sum += a[i]*(k - c[i]);
	}
	cout << sum;}