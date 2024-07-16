#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, R, A;
	cin >> L >> R >> A;
	while (true) {
		if (L > R) {
			if (A == 0) {
				cout << 2 * R << '\n';
				break;
			}
			else {
				R++;
				A--;
			}
		}
		else if (L < R) {
			if (A == 0) {
				cout << 2 * L << '\n';
				break;
			}
			else {
				L++;
				A--;
			}
		}
		else {
			R += A / 2;
			cout << 2 * R << '\n';
			break;
		}
	}
}