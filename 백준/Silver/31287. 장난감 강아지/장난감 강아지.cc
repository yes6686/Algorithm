#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int check = 0;
	int x = 0, y = 0;
	if (k >= 2000) k = 2000;
	for (int t = 0; t < k; t++) {
		for (int i = 0; i < s.size(); i++) {

			if (s[i] == 'U') {
				y -= 1;
			}
			else if (s[i] == 'D') {
				y += 1;
			}
			else if (s[i] == 'L') {
				x -= 1;
			}
			else {
				x += 1;
			}
			if (x == 0 && y == 0) check = 1;
		}
	}
	if (check == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}