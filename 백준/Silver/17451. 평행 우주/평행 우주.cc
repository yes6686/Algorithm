#include <iostream>
using namespace std;
long long int arr[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long int ans = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (ans % arr[i] == 0) continue;
		ans = arr[i] * (ans / arr[i] + 1);
	}
	cout << ans;
}