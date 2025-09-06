#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);

	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			cout << s[i];
			i += 2;
		}
		else {
			cout << s[i];
		}
	}
}