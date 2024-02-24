#include <iostream>
#include <algorithm>
using namespace std;

int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 5; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 5);
		if (arr[3] - arr[1] >= 4) {
			cout << "KIN" << '\n';
		}
		else {
			int sum = 0;
			for (int i = 1; i < 4; i++) {
				sum += arr[i];
			}
			cout << sum << '\n';
		}
	}
}