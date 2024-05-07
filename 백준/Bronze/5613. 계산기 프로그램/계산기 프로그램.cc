#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	int a;
	cin >> a;
	while (1) {
		char op;
		cin >> op;
		if (op == '=') break;
		int b;
		cin >> b;
		if (op == '+') {
			a = a + b;
		}
		else if (op == '-') {
			a = a - b;
		}
		else if (op == '*') {
			a = a * b;
		}
		else if(op=='/') {
			a = a / b;
		}
	}
	cout << a;
}