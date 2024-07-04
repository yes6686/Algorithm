#include <iostream>
using namespace std;

int arr[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int T;
	cin >> T;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		s += arr[i];
		if (s > T) break;
		ans++;
	}
	cout << ans;
}