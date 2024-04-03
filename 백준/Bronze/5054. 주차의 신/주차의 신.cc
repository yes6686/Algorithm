#include <iostream>
#include <algorithm>
using namespace std;
int arr[21];
int main() {

	int T;
	cin >> T;
	int n;
	int min = 100000;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += arr[i] - arr[i - 1];
		}
		cout << sum * 2 << endl;
		for (int i = 0; i < n; i++) {
			arr[i]=0;
		}
	}
}