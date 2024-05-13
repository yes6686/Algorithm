#include <iostream>
using namespace std;

int arr[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		int m = (b - a + 1) / 2;
		int t = 0;
		for (int j = a; j < a+m; j++) {
			int temp = arr[j];
			arr[j] = arr[b - t];
			arr[b - t] = temp;
			t++;
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}	
}