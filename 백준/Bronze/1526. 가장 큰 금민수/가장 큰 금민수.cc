#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n) {
		string s = to_string(n);
		int check = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '4' && s[i] != '7') {
				check = 0;
				break;
			}
		}
		if (check == 1) {
			cout << s << '\n';
			return 0;
		}
		n--;
	}
}