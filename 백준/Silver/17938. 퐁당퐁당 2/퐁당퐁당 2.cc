#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int p, T;
	cin >> p >> T;

	int s = 0;
	int t = 1;
	int TT = T - 1;
	int check = 0;
	while (TT--) {
		s += t;
		if (s > n * 2)
			s %= n * 2;
		if (s == 4 * n) {
			s = n * 2;
		}
		if (check == 0) {
			t++;
		}
		else {
			t--;
		}
		if (t == 2 * n) {
			check = 1;
		}
		if (t == 1) {
			check = 0;
		}
	}
	for (int i = 1; i <= t; i++) {
		int k = s + i;
		if (k > 2 * n) {
			k %= 2 * n;
		}
		if (k == 4 * n) {
			k = 2 * n;
		}
		if (k == (2 * p - 1) || k == (2 * p)) {
			cout << "Dehet YeonJwaJe ^~^" << '\n';
			return 0;
		}
	}
	cout << "Hing...NoJam" << '\n';
}