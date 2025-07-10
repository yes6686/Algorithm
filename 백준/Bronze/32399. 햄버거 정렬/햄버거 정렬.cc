#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	if (s == "(1)") {
		cout << 0 << '\n';
	}
	else if (s == ")1(") {
		cout << 2 << '\n';
	}
	else {
		cout << 1 << '\n';
	}
}