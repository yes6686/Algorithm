#include <iostream>
using namespace std;

long long int arr1[500001];
long long int arr2[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
		sum += arr2[i];
		if (sum < arr1[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << (sum - arr1[n - 1]) / x;
}