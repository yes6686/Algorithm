#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string s;
		getline(cin, s);
		if (s == "EOI") break;
		int check = 1;
		for (int i = 0; i < s.size()-3; i++) {
			string ss = "";
			ss += tolower(s[i]);
			ss += tolower(s[i+1]);
			ss += tolower(s[i+2]);
			ss += tolower(s[i+3]);
			if ("nemo" == ss) {
				check = 0;
				cout << "Found" << '\n';
				break;
			}
		}
		if (check == 1) {
			cout << "Missing" << '\n';
		}
	}
}