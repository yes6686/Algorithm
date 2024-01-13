#include <iostream>
using namespace std;
int arr[3][1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j][i];
		}
	}
	
	for (int i = 1; i < n; i++) {
		arr[0][i] += min(arr[1][i-1], arr[2][i-1]);
		arr[1][i] += min(arr[0][i-1], arr[2][i-1]);
		arr[2][i] += min(arr[0][i-1], arr[1][i-1]);

	}
	int min = 1000001;
	for (int i = 0; i < 3; i++) {
		if (min > arr[i][n-1]) {
			min = arr[i][n-1];
		}
	}
	cout << min;
}