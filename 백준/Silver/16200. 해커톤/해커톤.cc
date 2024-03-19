#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans++;
		i += arr[i]-1;
	}
	cout << ans;
}