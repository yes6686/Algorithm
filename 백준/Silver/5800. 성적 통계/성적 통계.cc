#include <iostream>
#include <algorithm>
using namespace std;

int arr[51];

int main() {
	int T;
	cin >> T;
	int n;
	int sum = 0;
	int x = 1;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int LargestGap = -1;
		for (int i = 0; i < n-1; i++) {
			if (LargestGap < arr[i + 1] - arr[i]) {
				LargestGap = arr[i + 1] - arr[i];
			}
		}
		cout << "Class " << x << '\n';
		cout << "Max " << arr[n-1] << ", Min " << arr[0] << ", Largest gap " << LargestGap << '\n';
		x++;
	}
}