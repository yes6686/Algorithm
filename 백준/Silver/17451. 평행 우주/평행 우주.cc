#include <iostream>
using namespace std;
long long int arr[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i + 1] > arr[i]) {
			long long int k;
			if (arr[i + 1] % arr[i] == 0) {
				k = arr[i + 1] / arr[i];
			}
			else {
				k = arr[i + 1] / arr[i] + 1;
			}
			arr[i] *= k;
		}
	}
	cout << arr[0];
}