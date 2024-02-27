#include <iostream>
using namespace std;

int arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++) {

		if (abs(100 - s) < abs(100 - (s+arr[i]))) {
			break;
		}
		s += arr[i];
	}
	cout << s;
}