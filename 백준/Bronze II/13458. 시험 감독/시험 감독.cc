#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	
	int n;
	cin >> n;
	long long  sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	int b, c;
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		sum += 1;
		if (arr[i] > 0) {
			if (arr[i] % c == 0) {
				sum += arr[i] / c;
			}
			else {
				sum += arr[i] / c + 1;
			}
		}
	}
	cout << sum;

}