#include <iostream>
using namespace std;

int main() {
	int s, k, h;
	cin >> s >> k >> h;
	if (s + k + h >= 100) {
		cout << "OK";
	}
	else {
		if (s > k) {
			if (k > h) {
				cout << "Hanyang";
			}
			else {
				cout << "Korea";
			}
		}
		else {
			if (s > h) {
				cout << "Hanyang";
			}
			else {
				cout << "Soongsil";
			}
		}
	}
}
