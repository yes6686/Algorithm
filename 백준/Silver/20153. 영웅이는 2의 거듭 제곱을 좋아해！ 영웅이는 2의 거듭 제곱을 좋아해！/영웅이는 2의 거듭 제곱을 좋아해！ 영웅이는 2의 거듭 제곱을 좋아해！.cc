#include <iostream>
#include <vector>
using namespace std;

int arr[1 << 22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int r = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r ^= arr[i];
	}
	ans = r;
	for (int i = 0; i < n; i++) {
		ans = max(ans, r ^ arr[i]);
	}
	cout << ans << ans;
}