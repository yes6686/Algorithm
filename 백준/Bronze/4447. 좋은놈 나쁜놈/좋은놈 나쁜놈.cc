#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int gcnt = 0, bcnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'g' || s[j] == 'G') {
				gcnt++;
			}
			else if (s[j] == 'b' || s[j] == 'B') {
				bcnt++;
			}
		}
		if (gcnt > bcnt) {
			cout << s << " is GOOD" << '\n';
		}
		else if (gcnt < bcnt) {
			cout << s << " is A BADDY" << '\n';
		}
		else {
			cout << s << " is NEUTRAL" << '\n';
		}
	}
}