#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
	int n;
	cin >> n;
	int t = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + 3);
		cout << "Scenario #" << t << ":" << '\n';
		if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
		cout << '\n';
		t++;

	}
	
}