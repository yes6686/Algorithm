#include <iostream>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int s = 0;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			if (s == 0) {
				s = arr[i - 1];
			}
			if (i == n - 1) {
				ans = max(ans, arr[i] - s);
			}
		}
		else {
			if(s!=0) ans = max(ans, arr[i-1]-s);
			s = 0;
		}
	}
	cout << ans;
}