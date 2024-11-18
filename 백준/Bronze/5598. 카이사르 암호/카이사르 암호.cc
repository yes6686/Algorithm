#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'D') {
			cout << char(s[i] - 3);
		}
		else {
			cout << char(s[i] + 23);
		}
	}	
}