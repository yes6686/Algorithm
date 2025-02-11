#include <iostream>
using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	long long int ans = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			ans += 2 * abs(arr[i] - arr[j]);
		}
	}

	cout << ans << '\n';
}