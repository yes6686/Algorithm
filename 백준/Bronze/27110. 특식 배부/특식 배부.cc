#include <iostream>
using namespace std;
int arr[3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] >= n) {
			ans += n;
		}
		else {
			ans += arr[i];
		}
	}
	cout << ans;
}