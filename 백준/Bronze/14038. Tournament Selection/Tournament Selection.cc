#include <iostream>
using namespace std;

int main() {
	char c;
	int wcnt = 0;
	int lcnt = 0;
	for (int i = 0; i < 6; i++) {
		cin >> c;
		if (c == 'W') {
			wcnt++;
		}
		else {
			lcnt++;
		}
	}
	if (wcnt == 5 || wcnt == 6) {
		cout << 1;
	}
	else if (wcnt == 3 || wcnt == 4) {
		cout << 2;
	}
	else if (wcnt == 1 || wcnt == 2) {
		cout << 3;
	}
	else {
		cout << -1;
	}
}