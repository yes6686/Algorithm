#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	for (int i = 0;i < m;i++) {
		sort(arr, arr + n);
		long long int sum = arr[0] + arr[1];
		arr[0] = sum;
		arr[1] = sum;
	}
	long long int ans = 0;
	for (int i = 0;i < n;i++) {
		ans += arr[i];
	}
    
	cout << ans << '\n';
}