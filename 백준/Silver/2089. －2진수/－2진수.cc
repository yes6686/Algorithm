#include <iostream>
using namespace std;

void recur(int a) {
	if (a == 0) {
		cout << 0;
		return;
	}
	if (a == 1) {
		cout << 1;
		return;
	}

	int k = a / (-2);
	if (a < 0) {
		if (k + 1 == 1) {
			cout << 1;
			cout << a - (-2);
			return;
		}
		if (a % (-2) == 0) {
			recur(k);
			cout << a - ((-2) * (k));
		}
		else {
			recur(k + 1);
			cout << a - ((-2) * (k + 1));
		}
	}
	else {
		recur(k);
		cout << a - ((-2) * (k));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	recur(n);
}