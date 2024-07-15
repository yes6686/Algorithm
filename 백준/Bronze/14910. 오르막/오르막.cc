#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a;
	cin >> a;
	while (true) {
		int b;
		cin >> b;
		if (cin.eof()) break;
		if (a > b) {
			cout << "Bad" << '\n';
			return 0;
		}
		a = b;
	}
	cout << "Good" << '\n';
}