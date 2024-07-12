#include <iostream>
using namespace std;

int arr[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	while (true) {
		int check = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				for (int t = 0; t < 5; t++) {
					cout << arr[t] << ' ';
				}
				cout << '\n';
				check = 1;
			}
		}
		if (check == 0) {
			break;
		}
	}
}