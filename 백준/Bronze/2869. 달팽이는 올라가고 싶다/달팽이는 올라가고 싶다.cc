#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;
	int s = a - b;
	if (a >= v) {
		cout << 1 << endl;
	}
	else {
		if (s == 1) {
			cout << v - b << endl;
		}
		else {
			if ((v - b) % s == 0) {
				cout << (v - b) / s << endl;
			}
			else if ((v - b) % s > 0) {
				cout << (v - b) / s + 1 << endl;
			}
			
		}
	}
}
