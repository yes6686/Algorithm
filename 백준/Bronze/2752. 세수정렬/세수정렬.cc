#include <iostream>

using namespace std;

int main() {
	int arr[4];


	for (int i = 1; i <= 3; i++) {
		cin >> arr[i];
	}
	for (int k = 1; k <= 3; k++) {
		for (int i = 1; i <= 2; i++) {
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}

		}
	}

	for (int i = 1; i <= 3; i++) {
		cout<< arr[i]<<' ';
	}
	
}