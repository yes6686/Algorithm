#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	int a, b;
	while (T--) {
		cin >> a >> b;
		a %= 10;
		switch (a) {
		case(1):
			cout << 1 << endl;
			break;
		case(2):
			if (b % 4 == 1) {
				cout << 2 << endl;
			}
			else if (b % 4 == 2) {
				cout << 4 << endl;
			}
			else if (b % 4 == 3) {
				cout << 8 << endl;
			}
			else {
				cout << 6 << endl;
			}
			break;
		case(3):
			if (b % 4 == 1) {
				cout << 3 << endl;
			}
			else if (b % 4 == 2) {
				cout << 9 << endl;
			}
			else if (b % 4 == 3) {
				cout << 7 << endl;
			}
			else {
				cout << 1 << endl;
			}
			break;
		case(4):
			if (b % 2 == 0) {
				cout << 6 << endl;
			}
			else {
				cout << 4 << endl;
			}
			break;
		case(5):
			cout << 5 << endl;
			break;
		case(6):
			cout << 6 << endl;
			break;
		case(7):
			if (b % 4 == 1) {
				cout << 7 << endl;
			}
			else if (b % 4 == 2) {
				cout << 9 << endl;
			}
			else if (b % 4 == 3) {
				cout << 3 << endl;
			}
			else {
				cout << 1 << endl;
			}
			break;
		case(8):
			if (b % 4 == 1) {
				cout << 8 << endl;
			}
			else if (b % 4 == 2) {
				cout << 4 << endl;
			}
			else if (b % 4 == 3) {
				cout << 2 << endl;
			}
			else {
				cout << 6 << endl;
			}
			break;
		case(9):
			if (b % 2 == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 9 << endl;
			}
			break;

		default:
			cout << 10 << endl;
			break;
		}
		
	}
	
}