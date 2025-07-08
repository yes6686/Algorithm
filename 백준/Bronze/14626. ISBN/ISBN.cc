#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int k = 0;
	int check = 0;
	for (int i = 0;i < s.size();i++) {
		if (s[i] != '*') {
			if (i % 2 == 0) {
				k += (s[i] - '0');
			}
			else {
				k += ((s[i] - '0') * 3);
			}
		}
		else {
			if (i % 2 == 1) {
				check = 1;
			}
		}
	}

	int v = (check == 1) ? 3 : 1;

	for (int i = 0;i <= 9;i++) {
		if ((i * v + (k % 10)) % 10 == 0) {
			cout << i << '\n';
			return 0;
		}
	}
}