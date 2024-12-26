#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans;
	string s;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (s[0] == 'F' || s[0] == 'B') continue;
		ans = stoi(s) + (3 - i);
	}
	if (ans % 3 == 0 && ans % 5 == 0) {
		cout << "FizzBuzz" << '\n';
	}
	else if (ans % 3 == 0 && ans % 5 != 0) {
		cout << "Fizz" << '\n';
	}
	else if (ans % 3 != 0 && ans % 5 == 0) {
		cout << "Buzz" << '\n';
	}
	else {
		cout << ans << '\n';
	}
}