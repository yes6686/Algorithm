#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[300000];
int main() {
	int n;
	cin >> n;
	double sum = 0;
	if (n == 0) {
		cout << 0 << endl;
	}
	else if (n == 1) {
		int x;
		cin >> x;
		cout << x << endl;
	}
	else if (n == 2) {
		double a, b;
		cin >> a >> b;
		cout << fixed;
		cout.precision(0);
		cout << round(a+b/2) << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int k = round(n * (0.15));
		sort(arr, arr + n);
		for (int i = k; i < n - k; i++) {
			sum += arr[i];
		}
		double result = sum / (n - 2 * k);
		cout << fixed;
		cout.precision(0);
		cout << round(result);
	}
}