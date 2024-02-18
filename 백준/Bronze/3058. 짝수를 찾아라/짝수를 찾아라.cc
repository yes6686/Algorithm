#include <iostream>
using namespace std;

int arr[8];

int main() {
	int T; cin >> T;
	while (T--) {
		int minEven = 101;
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) {
				sum += arr[i];
				minEven = min(minEven, arr[i]);
			}
		}
		cout << sum << ' ' << minEven << '\n';
	}
}