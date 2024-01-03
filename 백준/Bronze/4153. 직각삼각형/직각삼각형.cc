#include <iostream>
using namespace std;
int main() {
	


	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 || b == 0 || c == 0) {
			break;
		}
		else {
			if (a > b) {
				if (b > c) {
					if (b * b + c * c == a * a) {
						cout << "right" << endl;
					}
					else {
						cout << "wrong" << endl;
					}
				}
				else {//b<=c
					if (a > c) {
						if (b * b + c * c == a * a) {
							cout << "right" << endl;
						}
						else {
							cout << "wrong" << endl;
						}
					}
					else {
						if (b * b + a * a == c * c) {
							cout << "right" << endl;
						}
						else {
							cout << "wrong" << endl;
						}
					}
				}
			}
			else {//b >=a
				if (a > c) {
					if (a * a + c * c == b * b) {
						cout << "right" << endl;
					}
					else {
						cout << "wrong" << endl;
					}
				}
				else {//c>=a
					if (b > c) {
						if (a * a + c * c == b * b) {
							cout << "right" << endl;
						}
						else {
							cout << "wrong" << endl;
						}
					}
					else {
						if (b * b + a * a == c * c) {
							cout << "right" << endl;
						}
						else {
							cout << "wrong" << endl;
						}
					}
				}
			}
		}
	}
}