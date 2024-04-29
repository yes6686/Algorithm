#include <iostream>
#include <cmath>
using namespace std;
int arr[214223];
int main() {
	int n; cin >> n;
	long long int k = 0;
	for (int i = 0; i < n; i++) {
		long long int x;
		cin >> x;

		if ((k & x) == 0) {
			k = (k | x);
		}
		else {
			while (k & x) {
				k = (k ^ x);
				x *= 2;
			}
			k = (k | x);
		}
	}
	for (int i = 62;i>=0; i--) {
		if (k & (long long)pow(2, i)) {
			cout << (long long)pow(2, i);
			return 0;
		}
	}
}