#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		cout << s << ' ';
		if (97 <= x && x <= 100) {
			cout << "A+" << '\n';
		}
		else if (90 <= x && x <= 96) {
			cout << "A" << '\n';
		}
		else if (87 <= x && x <= 89) {
			cout << "B+" << '\n';
		}
		else if (80 <= x && x <= 86) {
			cout << "B" << '\n';
		}
		else if (77 <= x && x <= 79) {
			cout << "C+" << '\n';
		}
		else if (70 <= x && x <= 76) {
			cout << "C" << '\n';
		}
		else if (67 <= x && x <= 69) {
			cout << "D+" << '\n';
		}
		else if (60 <= x && x <= 66) {
			cout << "D" << '\n';
		}
		else {
			cout << "F" << '\n';
		}
	}
}