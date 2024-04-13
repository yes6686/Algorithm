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

	if (a < 0) {

		if (a / (-2) + 1 == 1) {
			cout << 1;
			cout << a - (-2);
			return;
		}
		if (a % (-2) == 0) {
			recur(a / (-2));
			cout << a - ((-2) * (a / (-2)));
		}
		else {
			recur(a / (-2) + 1);
			cout << a - ((-2) * (a / (-2) + 1));
		}
	}
	else {
		recur(a / ( - 2));
		cout << a - ((-2)*(a / (-2)));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	recur(n);
}