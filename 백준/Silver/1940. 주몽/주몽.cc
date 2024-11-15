#include <iostream>
#include <algorithm>
using namespace std;

int arr[15001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int m;
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] > m) break;
			if (arr[i] + arr[j] == m) {
				ans++;
			}
		}
	}
	cout << ans<<'\n';
}