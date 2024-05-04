#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int a, b;
	cin >> a >> b;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	if (a >= 0 && b >= 0) {
		long long int k1 = b * (b + 1) / 2;
		long long int k2 = (a - 1) * a / 2;
		cout << k1 - k2 << '\n';
	}
	else if (a < 0 && b < 0) {
		long long int i = a * (-1);
		long long int j = b * (-1);

		long long int k1 = i * (i + 1) / 2;
		long long int k2 = (j - 1) * (j) / 2;

		cout << (k1 - k2) * (-1) << '\n';
	}
	else {
		long long int i = a * (-1);
		long long int k1 = b * (b + 1) / 2;
		long long int k2 = i * (i+1) / 2;
		k2 *= (-1);
		cout << k1 + k2 << '\n';

	}
}