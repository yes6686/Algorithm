#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long int a, b;
		cin >> a >> b;
		long long int A = a * a;
		long long int B = b * b;
		if ( A % B == 0) {
			cout << A / B << '\n';
		}
		else {
			cout << A / B + 1 << '\n';
		}
	}
}