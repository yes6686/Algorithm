#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;
	if (x % 3 == 1) {
		cout << "U" << '\n';
	}
	else if (x % 3 == 2) {
		cout << "O" << '\n';
	}
	else {
		cout << "S" << '\n';
	}
}