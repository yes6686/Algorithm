#include <iostream>
using namespace std;

double arr[100001];

int main() {
	int n;
	cin >> n;
	double ans = 0;
	double maxValue = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i] / 2;
		maxValue = max(maxValue, arr[i]);
	}
	ans += maxValue / 2;
	cout << ans;
}